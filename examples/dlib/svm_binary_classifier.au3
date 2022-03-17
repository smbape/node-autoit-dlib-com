#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/master/python_examples/svm_binary_classifier.py

#include "..\..\autoit-dlib-com\udf\dlib_udf_utils.au3"

_Dlib_Open_And_Register(_Dlib_FindDLL("opencv_world4*", "opencv-4.*\opencv"), _Dlib_FindDLL("autoit_dlib_com-*"))
OnAutoItExitRegister("_OnAutoItExit")

Example()

Func Example()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return

	Local $x = _Dlib_vectors()
	Local $y[0]

	; Make a training dataset.  Here we have just two training examples.  Normally
	; you would use a much larger training dataset, but for the purpose of example
	; this is plenty.  For binary classification, the y labels should all be either +1 or -1.
	$x.Add(_Dlib_vector(_Dlib_Tuple(1, 2, 3, -1, -2, -3)))
	_ArrayAdd($y, +1)

	$x.Add(_Dlib_vector(_Dlib_Tuple(-1, -2, -3, 1, 2, 3)))
	_ArrayAdd($y, -1)


	; Now make a training object.  This object is responsible for turning a
	; training dataset into a prediction model.  This one here is a SVM trainer
	; that uses a linear kernel.  If you wanted to use a RBF kernel or histogram
	; intersection kernel you could change it to one of these lines:
	;  svm = dlib.svm_c_trainer_histogram_intersection()
	;  svm = dlib.svm_c_trainer_radial_basis()
	Local $svm = _Dlib_ObjCreate("svm_c_trainer_linear")
	$svm.be_verbose()
	$svm.set_c(10)

	; Now train the model.  The return value is the trained model capable of making predictions.
	Local $classifier = $svm.train($x, $y)

	; Now run the model on our data and look at the results.
	ConsoleWrite("prediction for first sample:  " & $classifier($x(0)) & @CRLF)
	ConsoleWrite("prediction for second sample: " & $classifier($x(1)) & @CRLF)
EndFunc   ;==>Example

Func _OnAutoItExit()
	_Dlib_Unregister_And_Close()
EndFunc   ;==>_OnAutoItExit
