#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/master/python_examples/face_detector.py

#include <Misc.au3>
#include "..\autoit-dlib-com\udf\dlib_udf_utils.au3"

_Dlib_Open_And_Register(_Dlib_FindDLL("opencv_world4*", "opencv-4.*\opencv"), _Dlib_FindDLL("autoit_dlib_com-*"))
OnAutoItExitRegister("_OnAutoItExit")

Example()

Func Example()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return

	Local $detector = $dlib.get_frontal_face_detector()
	Local $win = _Dlib_ObjCreate("image_window")

	Local $image_path = _Dlib_FindFile("examples\faces\2008_002470.jpg")
	Local $img = $dlib.load_rgb_image($image_path)

	$win.set_image($img)

	; The 1 in the second argument indicates that we should upsample the image
	; 1 time.  This will make everything bigger and allow us to detect more
	; faces.
	Local $dets = $detector.call($img, 1)
	ConsoleWrite("Number of faces detected: " & UBound($dets) & @CRLF)

	Local $d
	For $i = 0 To UBound($dets) - 1
		$d = $dets[$i]
		ConsoleWrite(StringFormat("Detection %d: Left: %d Top: %d Right: %d Bottom: %d", _
				$i, $d.left(), $d.top(), $d.right(), $d.bottom()) & @CRLF)
	Next

	$win.add_overlay($dets)
	hit_to_continue()
EndFunc   ;==>Example

Func hit_to_continue()
	ToolTip("Hit ESC to continue", 0, 0)
	ConsoleWrite("Hit ESC to continue" & @CRLF)
	Do
		Sleep(50)
	Until _IsPressed("1B")
EndFunc   ;==>hit_to_continue

Func _OnAutoItExit()
	_Dlib_Unregister_And_Close()
EndFunc   ;==>_OnAutoItExit
