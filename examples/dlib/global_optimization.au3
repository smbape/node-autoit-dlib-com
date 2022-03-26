#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/master/python_examples/global_optimization.py

#include "..\..\autoit-dlib-com\udf\dlib_udf_utils.au3"

_Dlib_Open_And_Register(_Dlib_FindDLL("opencv_world4*", "opencv-4.*\opencv"), _Dlib_FindDLL("autoit_dlib_com-*"))
OnAutoItExitRegister("_OnAutoItExit")

Global Const $h_holder_table = DllCallbackRegister("holder_table", "double", "double;double")

Example()

Func Example()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return

	; Find the optimal inputs to holder_table().  The print statements that follow
	; show that find_min_global() finds the optimal settings to high precision.
	$dlib.find_min_global(DllCallbackGetPtr($h_holder_table), _
			_Dlib_Tuple(-10, -10), _  ; Lower bound constraints on x0 and x1 respectively
			_Dlib_Tuple(10, 10), _    ; Upper bound constraints on x0 and x1 respectively
			80)                       ; The number of times find_min_global() will call holder_table()

	Local $x = $dlib.extended[0]
	Local $y = $dlib.extended[1]

	ConsoleWrite("optimal inputs: " & ArrayToString($x) & @CRLF)
	ConsoleWrite("optimal output: " & $y & @CRLF)

EndFunc   ;==>Example

; This is a standard test function for these kinds of optimization problems.
; It has a bunch of local minima, with the global minimum resulting in
; holder_table()==-19.2085025679.
Func holder_table($x0, $x1)
	Local Const $PI = 3.141592653589793
	Return -Abs(Sin($x0) * Cos($x1) * Exp(Abs(1 - Sqrt($x0 * $x0 + $x1 * $x1) / $PI)))
EndFunc   ;==>holder_table

Func ArrayToString($v)
	Return "[" & _ArrayToString($v, ", ") & "]"
EndFunc   ;==>ArrayToString

Func _OnAutoItExit()
	DllCallbackFree($h_holder_table)
	_Dlib_Unregister_And_Close()
EndFunc   ;==>_OnAutoItExit
