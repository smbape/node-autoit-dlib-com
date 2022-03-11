#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/master/python_examples/opencv_webcam_face_detection.py

#include <Misc.au3>
#include "..\autoit-dlib-com\udf\dlib_udf_utils.au3"
#include "..\autoit-opencv-com\udf\opencv_udf_utils.au3"

_Dlib_Open_And_Register(_Dlib_FindDLL("opencv_world4*", "opencv-4.*\opencv"), _Dlib_FindDLL("autoit_dlib_com-*"))
_OpenCV_Open_And_Register(_OpenCV_FindDLL("opencv_world4*", "opencv-4.*\opencv"), _OpenCV_FindDLL("autoit_opencv_com4*"))
OnAutoItExitRegister("_OnAutoItExit")

Example()

Func Example()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return

	Local Const $cv = _OpenCV_get()
	If Not IsObj($cv) Then Return

	Local $detector = $dlib.get_frontal_face_detector()
	Local $cam = _OpenCV_ObjCreate("VideoCapture").create(0)
	Local $color_green = _OpenCV_Tuple(0, 255, 0)
	Local $line_width = 3
	Local $img, $dets, $det

	While True
		If $cam.read() Then
			$img = $cv.extended[1]
			$dets = $detector.call(Ptr($img.self))

			For $i = 0 To UBound($dets) - 1
				$det = $dets[$i]
				$cv.rectangle($img, _OpenCV_Tuple($det.left(), $det.top()), _OpenCV_Tuple($det.right(), $det.bottom()), $color_green, $line_width)
			Next

			;; Flip the image horizontally to give the mirror impression
			$cv.imshow("my webcam", $cv.flip($img, 1))
		EndIf

		If _IsPressed("1B") Then
			ExitLoop  ; esc to quit
		EndIf

		Sleep(1)
	WEnd

	$cv.destroyAllWindows()
EndFunc   ;==>Example

Func _OnAutoItExit()
	_OpenCV_Unregister_And_Close()
	_Dlib_Unregister_And_Close()
EndFunc   ;==>_OnAutoItExit
