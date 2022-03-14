#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/master/python_examples/sequence_segmenter.py

#include "..\..\autoit-dlib-com\udf\dlib_udf_utils.au3"

_Dlib_Open_And_Register(_Dlib_FindDLL("opencv_world4*", "opencv-4.*\opencv"), _Dlib_FindDLL("autoit_dlib_com-*"))
OnAutoItExitRegister("_OnAutoItExit")

Example()

Func Example()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return

	; Now let's make some training data.  Each example is a sentence as well as a
	; set of ranges which indicate the locations of any names.
	Local $names = _Dlib_ranges()     ; make an array of dlib.range objects.
	Local $segments = _Dlib_rangess() ; make an array of arrays of dlib.range objects.
	Local $sentences = _Dlib_ObjCreate("VectorOfString")

	$sentences.Add("The other day I saw a man named Jim Smith")
	; We want to detect person names.  So we note that the name is located within
	; the range [8, 10).  Note that we use half open ranges to identify segments.
	; So in this case, the segment identifies the string "Jim Smith".
	$names.Add(_DLib_Tuple(8, 10))
	$segments.Add($names)
	$names.clear() ; make names empty for use again below

	$sentences.Add("Davis King is the main author of the dlib Library")
	$names.Add(_DLib_Tuple(0, 2))
	$segments.Add($names)
	$names.clear()

	$sentences.Add("Bob Jones is a name and so is George Clinton")
	$names.Add(_DLib_Tuple(0, 2))
	$names.Add(_DLib_Tuple(8, 10))
	$segments.Add($names)
	$names.clear()

	$sentences.Add("My dog is named Bob Barker")
	$names.Add(_DLib_Tuple(4, 6))
	$segments.Add($names)
	$names.clear()

	$sentences.Add("ABC is an acronym but John James Smith is a name")
	$names.Add(_DLib_Tuple(5, 8))
	$segments.Add($names)
	$names.clear()

	$sentences.Add("No names in this sentence at all")
	$segments.Add($names)
	$names.clear()


	; Now before we can pass these training sentences to the dlib tools we need to
	; convert them into arrays of vectors as discussed above.  We can use either a
	; sparse or dense representation depending on our needs.  In this example, we
	; show how to do it both ways.
	Local $use_sparse_vects = False
	Local $training_sequences, $s
	If $use_sparse_vects Then
		; Make an array of arrays of dlib.sparse_vector objects.
		$training_sequences = _Dlib_sparse_vectorss()
		For $i = 0 To $sentences.size() - 1
			$s = $sentences.at($i)
			$training_sequences.Add(sentence_to_sparse_vectors($s))
		Next
	Else
		; Make an array of arrays of dlib.vector objects.
		$training_sequences = _Dlib_vectorss()
		For $i = 0 To $sentences.size() - 1
			$s = $sentences.at($i)
			$training_sequences.Add(sentence_to_vectors($s))
		Next
	EndIf

	; Now that we have a simple training set we can train a sequence segmenter.
	; However, the sequence segmentation trainer has some optional parameters we can
	; set.  These parameters determine properties of the segmentation model we will
	; learn.  See the dlib documentation for the sequence_segmenter object for a
	; full discussion of their meanings.
	Local $params = _Dlib_ObjCreate("segmenter_params")
	$params.window_size = 3
	$params.use_high_order_features = True
	$params.use_BIO_model = True
	; This is the common SVM C parameter.  Larger values encourage the trainer to
	; attempt to fit the data exactly but might overfit.  In general, you determine
	; this parameter by cross-validation.
	$params.C = 10

	; Train a model.  The model object is responsible for predicting the locations
	; of names in new sentences.
	Local $model = $dlib.train_sequence_segmenter($training_sequences, $segments, $params)

	; Let's print out the things the model thinks are names.  The output is a set
	; of ranges which are predicted to contain names.  If you run this example
	; program you will see that it gets them all correct.
	For $i = 0 To $sentences.size() - 1
		$s = $sentences.at($i)
		print_segment($s, $model.call($training_sequences.at($i)))
	Next

	; Let's also try segmenting a new sentence.  This will print out "Bob Bucket".
	; Note that we need to remember to use the same vector representation as we used
	; during training.
	Local $test_sentence = "There once was a man from Nantucket " & _
			"whose name rhymed with Bob Bucket"
	If $use_sparse_vects Then
		print_segment($test_sentence, $model.call(sentence_to_sparse_vectors($test_sentence)))
	Else
		print_segment($test_sentence, $model.call(sentence_to_vectors($test_sentence)))
	EndIf

	; We can also measure the accuracy of a model relative to some labeled data.
	; This statement prints the precision, recall, and F1-score of the model
	; relative to the data in training_sequences/segments.
	ConsoleWrite("Test on training data: " & _
			$dlib.test_sequence_segmenter($model, $training_sequences, $segments).ToString() & @CRLF)

	; We can also do 5-fold cross-validation and print the resulting precision,
	; recall, and F1-score.
	ConsoleWrite("Cross validation: " & _
			$dlib.cross_validate_sequence_segmenter($training_sequences, $segments, 5, _
			$params).ToString() & @CRLF)

EndFunc   ;==>Example

; The sequence segmentation models we work with in this example are chain
; structured conditional random field style models.  Therefore, central to a
; sequence segmentation model is some method for converting the elements of a
; sequence into feature vectors. That is, while you might start out representing
; your sequence as an array of strings, the dlib interface works in terms of
; arrays of feature vectors.  Each feature vector should capture important
; information about its corresponding element in the original raw sequence.  So
; in this example, since we work with sequences of words and want to identify
; names, we will create feature vectors that tell us if the word is capitalized
; or not.  In our simple data, this will be enough to identify names.
; Therefore, we define sentence_to_vectors() which takes a sentence represented
; as a string and converts it into an array of words and then associates a
; feature vector with each word.
Func sentence_to_vectors($sentence)
	; Create an empty array of vectors
	Local $vects = _Dlib_vectors()
	Local $words = StringSplit($sentence, " ")
	Local $word
	For $i = 1 To $words[0]
		$word = $words[$i]
		; Our vectors are very simple 1-dimensional vectors.  The value of the
		; single feature is 1 if the first letter of the word is capitalized and
		; 0 otherwise.
		If StringIsUpper(StringMid($word, 1, 1)) Then
			$vects.Add(_Dlib_vector(_DLib_Tuple(1)))
		Else
			$vects.Add(_Dlib_vector(_DLib_Tuple(0)))
		EndIf
	Next
	Return $vects
EndFunc   ;==>sentence_to_vectors

; Dlib also supports the use of a sparse vector representation.  This is more
; efficient than the above form when you have very high dimensional vectors that
; are mostly full of zeros.  In dlib, each sparse vector is represented as an
; array of pair objects.  Each pair contains an index and value.  Any index not
; listed in the vector is implicitly associated with a value of zero.
; Additionally, when using sparse vectors with dlib.train_sequence_segmenter()
; you can use "unsorted" sparse vectors.  This means you can add the index/value
; pairs into your sparse vectors in any order you want and don't need to worry
; about them being in sorted order.
Func sentence_to_sparse_vectors($sentence)
	Local $vects = _Dlib_sparse_vectors()
	Local $has_cap = _Dlib_sparse_vector()
	Local $no_cap = _Dlib_sparse_vector()
	; make has_cap equivalent to dlib.vector([1])
	$has_cap.Add(_DLib_Tuple(0, 1))

	; Since we didn't add anything to no_cap it is equivalent to
	; dlib.vector([0])
	Local $words = StringSplit($sentence, " ")
	Local $word
	For $i = 1 To $words[0]
		$word = $words[$i]
		If StringIsUpper(StringMid($word, 1, 1)) Then
			$vects.Add($has_cap)
		Else
			$vects.Add($no_cap)
		EndIf
	Next
	Return $vects
EndFunc   ;==>sentence_to_sparse_vectors

Func print_segment($sentence, $names)
	Local $words = StringSplit($sentence, " ")
	Local $i
	For $name In $names
		For $i = $name[0] To ($name[1] - 1)
			ConsoleWrite($words[$i + 1] & " ")
		Next
		ConsoleWrite(@CRLF)
	Next
EndFunc   ;==>print_segment

Func _OnAutoItExit()
	_Dlib_Unregister_And_Close()
EndFunc   ;==>_OnAutoItExit
