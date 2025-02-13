#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/v19.24.9/tools/python/test/test_global_optimization.py

#include "..\..\autoit-dlib-com\udf\dlib_udf_utils.au3"

_Dlib_Open(_Dlib_FindDLL("opencv_world4110*"), _Dlib_FindDLL("autoit_dlib_com-*-4110*"))
OnAutoItExitRegister("_OnAutoItExit")

Global Const $dlib = _Dlib_get()
Global Const $h_holder_table = DllCallbackRegister("holder_table", "double", "double;double")
Global Const $h_sum = DllCallbackRegister("sum", "double", "double;double;double")

test_global_optimization_nargs()
test_global_function_search()
test_on_holder_table()

Func test_global_optimization_nargs()
	$dlib.find_max_global(DllCallbackGetPtr($h_sum), _Dlib_Tuple(0, 0, 0), _Dlib_Tuple(1, 1, 1), 10)
	AssertEqTuple($dlib.extended, _Dlib_Tuple(_Dlib_Tuple(1, 1, 1), 3))
	$dlib.find_min_global(DllCallbackGetPtr($h_sum), _Dlib_Tuple(0, 0, 0), _Dlib_Tuple(1, 1, 1), 10)
	AssertEqTuple($dlib.extended, _Dlib_Tuple(_Dlib_Tuple(0, 0, 0), 0))
EndFunc   ;==>test_global_optimization_nargs

Func sum($a, $b, $c)
	Return $a + $b + $c
EndFunc   ;==>sum

Func F($a, $b)
	Return -pow($a - 2, 2.0) - pow($b - 4, 2.0)
EndFunc   ;==>F

Func G($x)
	Return 2 - pow($x - 5, 2.0) ;
EndFunc   ;==>G

Func test_global_function_search()
	Local $spec_F = _Dlib_ObjCreate("function_spec").create(_Dlib_Tuple(-10, -10), _Dlib_Tuple(10, 10))
	Local $spec_G = _Dlib_ObjCreate("function_spec").create(_Dlib_Tuple(-2), _Dlib_Tuple(6))

	Local $opt = _Dlib_ObjCreate("global_function_search").create(_Dlib_Tuple($spec_F, $spec_G))

	Local $next, $a, $b, $x, $y, $function_idx
	For $i = 0 To 14
		$next = $opt.get_next_x()
		; ConsoleWrite(StringFormat("next x is for function %u and has coordinates %s", $next.function_idx, $next.x.ToString()) & @CRLF)

		If $next.function_idx == 0 Then
			$a = $next.x(0)
			$b = $next.x(1)
			$next.set(F($a, $b))
		Else
			$x = $next.x(0)
			$next.set(G($x))
		EndIf
	Next

	$opt.get_best_function_eval()
	$x = $dlib.extended[0]
	$y = $dlib.extended[1]
	$function_idx = $dlib.extended[2]

	; ConsoleWrite(StringFormat("best function was %u, with y of %f, and x of %s", $function_idx, $y, $x.ToString()) & @CRLF)

	Assert(Abs($y - 2) < 1E-7)
	Assert(Abs($x(0) - 5) < 1E-7)
	Assert($function_idx == 1)
EndFunc   ;==>test_global_function_search

Func holder_table($x0, $x1)
	Local Const $PI = 3.141592653589793
	Local Const $result = -Abs(Sin($x0) * Cos($x1) * Exp(Abs(1 - Sqrt($x0 * $x0 + $x1 * $x1) / $PI)))
	Return $result
EndFunc   ;==>holder_table

Func test_on_holder_table()
	$dlib.find_min_global(DllCallbackGetPtr($h_holder_table), _
			_Dlib_Tuple(-10, -10), _
			_Dlib_Tuple(10, 10), _
			200)
	Local $x = $dlib.extended[0]
	Local $y = $dlib.extended[1]

	Assert(Abs($x[0] - -8.05502349647872) < 1E-7)
	Assert(Abs($x[1] - -9.664589998516973) < 1E-7)
	Assert(Abs($y - -19.2085025679) < 1E-6)
EndFunc   ;==>test_on_holder_table

Func pow($a, $b)
	Return $a ^ $b
EndFunc   ;==>pow

Func AssertEqTuple($a, $b, $sMsg = "assertion failed", $iLine = @ScriptLineNumber, $bExit = True)
	If Not Assert(IsArray($a), $sMsg, $iLine, $bExit) Then
		Return False
	EndIf
	If Not Assert(IsArray($b), $sMsg, $iLine, $bExit) Then
		Return False
	EndIf
	If Not Assert(UBound($a) == UBound($b), $sMsg, $iLine, $bExit) Then
		Return False
	EndIf
	For $i = 0 To UBound($a) - 1
		If (IsArray($a[$i])) Then
			If Not AssertEqTuple($a[$i], $b[$i], $sMsg, $iLine, $bExit) Then
				Return False
			EndIf
		ElseIf Not Assert($a[$i] == $b[$i], $sMsg, $iLine, $bExit) Then
			Return False
		EndIf
	Next
	Return True
EndFunc   ;==>AssertEqTuple

Func Assert($sCondition, $sMsg = "assertion failed", $iLine = @ScriptLineNumber, $bExit = True)
	If Execute($sCondition) Then Return True
	If $sCondition == False Then
		ConsoleWrite("@@ Debug(" & $iLine & ") : " & $sMsg & @CRLF)
	Else
		ConsoleWrite("@@ Debug(" & $iLine & ") : " & $sCondition & " - " & $sMsg & @CRLF)
	EndIf

	If $bExit Then Exit 1
	Return False
EndFunc   ;==>Assert

Func _OnAutoItExit()
	DllCallbackFree($h_sum)
	DllCallbackFree($h_holder_table)
	_Dlib_Close()
EndFunc   ;==>_OnAutoItExit
