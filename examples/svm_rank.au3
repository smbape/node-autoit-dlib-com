#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/master/python_examples/svm_rank.py

#include "..\autoit-dlib-com\udf\dlib_udf_utils.au3"

_Dlib_Open_And_Register(_Dlib_FindDLL("opencv_world4*", "opencv-4.*\opencv"), _Dlib_FindDLL("autoit_dlib_com-*"))
OnAutoItExitRegister("_OnAutoItExit")

Example()

Func Example()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return

	; Now let's make some testing data.  To make it really simple, let's suppose
	; that we are ranking 2D vectors and that vectors with positive values in the
	; first dimension should rank higher than other vectors.  So what we do is make
	; examples of relevant (i.e. high ranking) and non-relevant (i.e. low ranking)
	; vectors and store them into a ranking_pair object like so:
	Local $data = _Dlib_ranking_pair()
	; Here we add two examples.  In real applications, you would want lots of
	; examples of relevant and non-relevant vectors.
	$data.relevant.push_back(_Dlib_vector(_Dlib_Tuple(1, 0)))
	$data.nonrelevant.push_back(_Dlib_vector(_Dlib_Tuple(0, 1)))

	; Now that we have some data, we can use a machine learning method to learn a
	; function that will give high scores to the relevant vectors and low scores to
	; the non-relevant vectors.
	Local $trainer = _Dlib_ObjCreate("svm_rank_trainer")
	; Note that the trainer object has some parameters that control how it behaves.
	; For example, since this is the SVM-Rank algorithm it has a C parameter that
	; controls the trade-off between trying to fit the training data exactly or
	; selecting a "simpler" solution which might generalize better.
	$trainer.c = 10

	; So let's do the training.
	Local $rank = $trainer.train($data)

	; Now if you call rank on a vector it will output a ranking score.  In
	; particular, the ranking score for relevant vectors should be larger than the
	; score for non-relevant vectors.
	ConsoleWrite("Ranking score for a relevant vector:     " & _
			$rank.call($data.relevant.at(0)) & @CRLF)
	ConsoleWrite("Ranking score for a non-relevant vector: " & _
			$rank.call($data.nonrelevant.at(0)) & @CRLF)
	; The output is the following:
	;    ranking score for a relevant vector:     0.5
	;    ranking score for a non-relevant vector: -0.5


	; If we want an overall measure of ranking accuracy we can compute the ordering
	; accuracy and mean average precision values by calling test_ranking_function().
	; In this case, the ordering accuracy tells us how often a non-relevant vector
	; was ranked ahead of a relevant vector.  In this case, it returns 1 for both
	; metrics, indicating that the rank function outputs a perfect ranking.
	ConsoleWrite($dlib.test_ranking_function($rank, $data).ToString() & @CRLF)

	; The ranking scores are computed by taking the dot product between a learned
	; weight vector and a data vector.  If you want to see the learned weight vector
	; you can display it like so:
	ConsoleWrite("Weights: " & $rank.weights.ToString() & @CRLF)
	; In this case the weights are:
	;  0.5
	; -0.5

	; In the above example, our data contains just two sets of objects.  The
	; relevant set and non-relevant set.  The trainer is attempting to find a
	; ranking function that gives every relevant vector a higher score than every
	; non-relevant vector.  Sometimes what you want to do is a little more complex
	; than this.
	;
	; For example, in the web page ranking example we have to rank pages based on a
	; user's query.  In this case, each query will have its own set of relevant and
	; non-relevant documents.  What might be relevant to one query may well be
	; non-relevant to another.  So in this case we don't have a single global set of
	; relevant web pages and another set of non-relevant web pages.
	;
	; To handle cases like this, we can simply give multiple ranking_pair instances
	; to the trainer.  Therefore, each ranking_pair would represent the
	; relevant/non-relevant sets for a particular query.  An example is shown below
	; (for simplicity, we reuse our data from above to make 4 identical "queries").
	Local $queries = _Dlib_ranking_pairs()
	$queries.push_back($data)
	$queries.push_back($data)
	$queries.push_back($data)
	$queries.push_back($data)

	; We can train just as before.
	$rank = $trainer.train($queries)

	; Now that we have multiple ranking_pair instances, we can also use
	; cross_validate_ranking_trainer().  This performs cross-validation by splitting
	; the queries up into folds.  That is, it lets the trainer train on a subset of
	; ranking_pair instances and tests on the rest.  It does this over 4 different
	; splits and returns the overall ranking accuracy based on the held out data.
	; Just like test_ranking_function(), it reports both the ordering accuracy and
	; mean average precision.
	ConsoleWrite("Cross validation results: " & _
			$dlib.cross_validate_ranking_trainer($trainer, $queries, 4).ToString() & @CRLF)

	; Finally, note that the ranking tools also support the use of sparse vectors in
	; addition to dense vectors (which we used above).  So if we wanted to do
	; exactly what we did in the first part of the example program above but using
	; sparse vectors we would do it like so:

	$data = _Dlib_sparse_ranking_pair()
	Local $samp = _Dlib_sparse_vector()

	; Make samp represent the same vector as dlib.vector([1, 0]).  In dlib, a sparse
	; vector is just an array of pair objects.  Each pair stores an index and a
	; value.  Moreover, the svm-ranking tools require sparse vectors to be sorted
	; and to have unique indices.  This means that the indices are listed in
	; increasing order and no index value shows up more than once.  If necessary,
	; you can use the dlib.make_sparse_vector() routine to make a sparse vector
	; object properly sorted and contain unique indices.
	$samp.push_back(_DLib_Tuple(0, 1))
	$data.relevant.push_back($samp)

	; Now make samp represent the same vector as dlib.vector([0, 1])
	$samp.clear()
	$samp.push_back(_DLib_Tuple(1, 1))
	$data.nonrelevant.push_back($samp)

	$trainer = _Dlib_ObjCreate("svm_rank_trainer_sparse")
	$rank = $trainer.train($data)
	ConsoleWrite("Ranking score for a relevant vector:     " & _
			$rank.call($data.relevant.at(0)) & @CRLF)
	ConsoleWrite("Ranking score for a non-relevant vector: " & _
			$rank.call($data.nonrelevant.at(0)) & @CRLF)
	; Just as before, the output is the following:
	;    ranking score for a relevant vector:     0.5
	;    ranking score for a non-relevant vector: -0.5

EndFunc   ;==>Example

Func _OnAutoItExit()
	_Dlib_Unregister_And_Close()
EndFunc   ;==>_OnAutoItExit
