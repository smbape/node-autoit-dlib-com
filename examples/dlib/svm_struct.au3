#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/v19.24/python_examples/svm_struct.py

#include "..\..\autoit-dlib-com\udf\dlib_udf_utils.au3"

_Dlib_Open(_Dlib_FindDLL("opencv_world470*"), _Dlib_FindDLL("autoit_dlib_com-*-470*"))
OnAutoItExitRegister("_OnAutoItExit")

Global Const $h_get_truth_joint_feature_vector = DllCallbackRegister('get_truth_joint_feature_vector', 'none', 'ptr;long')
Global Const $h_separation_oracle = DllCallbackRegister('separation_oracle', 'none', 'ptr;long;ptr')

Global Const $samples = _Dlib_Tuple( _
		_Dlib_Tuple(0, 2, 0), _
		_Dlib_Tuple(1, 0, 0), _
		_Dlib_Tuple(0, 4, 0), _
		_Dlib_Tuple(0, 0, 3) _
		)

Global Const $labels = _Dlib_Tuple(1, 0, 1, 2)

Global Const $dlib = _Dlib_get()
Global Const $vector = _Dlib_ObjCreate("vector") ;

Example()

Func Example()
	If Not IsObj($dlib) Then Return

	Local $problem = _Dlib_ObjCreate("structural_svm_problem")

	$problem.C = 1
	$problem.num_samples = UBound($samples)
	$problem.num_dimensions = UBound($samples[0]) * 3
	$problem.get_truth_joint_feature_vector = DllCallbackGetPtr($h_get_truth_joint_feature_vector)
	$problem.separation_oracle = DllCallbackGetPtr($h_separation_oracle)

	Local $weights = $dlib.solve_structural_svm_problem($problem)
	ConsoleWrite($weights.ToString() & @CRLF)

	Local $s, $msg
	For $k = 0 To UBound($samples) - 1
		$s = $samples[$k]
		$msg = StringFormat("Predicted label for sample[%d]: %d", $k, predict_label($weights, $s))
		ConsoleWrite($msg & @CRLF)
	Next
EndFunc   ;==>Example

Func predict_label($weights, $sample)
	$sample = $vector.create($sample)
	Local $w0 = $weights.slice(0, 3)
	Local $w1 = $weights.slice(3, 6)
	Local $w2 = $weights.slice(6, 9)
	Local $scores = _Dlib_Tuple($dlib.dot($w0, $sample), $dlib.dot($w1, $sample), $dlib.dot($w2, $sample))
	Local $max_scoring_label = _ArrayMaxIndex($scores, 1)
	Return $max_scoring_label
EndFunc   ;==>predict_label

Func make_psi($self, $x, $label)
	Local $dims = UBound($x)
	Local $psi = $vector.create()

	$psi.resize($self.num_dimensions)

	If $label == 0 Then
		For $i = 0 To $dims - 1
			$psi.set($i, $x[$i])
		Next
	ElseIf $label == 1 Then
		For $i = $dims To 2 * $dims - 1
			$psi.set($i, $x[$i - $dims])
		Next
	Else ; the label must be 2
		For $i = 2 * $dims To 3 * $dims - 1
			$psi.set($i, $x[$i - 2 * $dims])
		Next
	EndIf

	Return $psi
EndFunc   ;==>make_psi

Func get_truth_joint_feature_vector($pself, $idx)
	Local $self = $dlib.variant($pself)
	$self.result = make_psi($self, $samples[$idx], $labels[$idx])
EndFunc   ;==>get_truth_joint_feature_vector

Func separation_oracle($pself, $idx, $p_current_solution)
	Local $self = $dlib.variant($pself)
	Local Const $current_solution = $dlib.variant($p_current_solution)

	Local $samp = $samples[$idx]
	Local $dims = UBound($samp)
	Local $scores = _Dlib_Tuple(0, 0, 0)

	; compute scores for each of the three classifiers
	Local $vsamp = $vector.create($samp)

	$scores[0] = $dlib.dot($current_solution.slice(0, $dims), $vsamp)
	$scores[1] = $dlib.dot($current_solution.slice($dims, 2 * $dims), $vsamp)
	$scores[2] = $dlib.dot($current_solution.slice(2 * $dims, 3 * $dims), $vsamp)

	; Add in the loss-augmentation.  Recall that we maximize
	; LOSS(idx,y) + F(X,y) in the separate oracle, not just F(X,y) as we
	; normally would in predict_label(). Therefore, we must add in this
	; extra amount to account for the loss-augmentation. For our simple
	; multi-class classifier, we incur a loss of 1 if we don't predict the
	; correct label and a loss of 0 if we get the right label.
	If $labels[$idx] <> 0 Then
		$scores[0] += 1
	EndIf
	If $labels[$idx] <> 1 Then
		$scores[1] += 1
	EndIf
	If $labels[$idx] <> 2 Then
		$scores[2] += 1
	EndIf

	; Now figure out which classifier has the largest loss-augmented score.
	Local $max_scoring_label = _ArrayMaxIndex($scores, 1)
	Local $loss
	; And finally record the loss that was associated with that predicted
	; label. Again, the loss is 1 if the label is incorrect and 0 otherwise.
	If $max_scoring_label == $labels[$idx] Then
		$loss = 0
	Else
		$loss = 1
	EndIf

	; Finally, return the loss and PSI vector corresponding to the label
	; we just found.
	Local $psi = make_psi($self, $samp, $max_scoring_label)
	$self.result = _Dlib_Tuple($loss, $psi)
EndFunc   ;==>separation_oracle

Func _OnAutoItExit()
	DllCallbackFree($h_separation_oracle)
	DllCallbackFree($h_get_truth_joint_feature_vector)
	_Dlib_Close()
EndFunc   ;==>_OnAutoItExit
