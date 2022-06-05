#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/master/python_examples/find_candidate_object_locations.py

#include "..\..\autoit-dlib-com\udf\dlib_udf_utils.au3"

_Dlib_Open_And_Register(_Dlib_FindDLL("opencv_world4*", "opencv-4.*\opencv"), _Dlib_FindDLL("autoit_dlib_com-*"))
OnAutoItExitRegister("_OnAutoItExit")

Example()

Func Example()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return

	Local $image_file = _Dlib_FindFile("examples\faces\2009_004587.jpg")
	Local $img = $dlib.load_rgb_image($image_file)

	; Locations of candidate objects will be saved into rects
	Local $rects = $dlib.find_candidate_object_locations($img, _Dlib_Params("min_size", 500))

	ConsoleWrite("number of rectangles found " & UBound($rects) & @CRLF)

	Local $d
	For $k = 0 To UBound($rects) - 1
		$d = $rects[$k]
		ConsoleWrite(StringFormat("Detection %d: Left: %d Top: %d Right: %d Bottom: %d", _
				$k, $d.left(), $d.top(), $d.right(), $d.bottom()) & @CRLF)
	Next

EndFunc   ;==>Example

Func _OnAutoItExit()
	_Dlib_Unregister_And_Close()
EndFunc   ;==>_OnAutoItExit
