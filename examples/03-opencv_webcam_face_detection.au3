#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/v19.24/python_examples/opencv_webcam_face_detection.py

#include <Misc.au3>
#include "..\autoit-dlib-com\udf\dlib_udf_utils.au3"
#include "..\autoit-opencv-com\udf\opencv_udf_utils.au3"

_Dlib_Open(_Dlib_FindDLL("opencv_world4100*"), _Dlib_FindDLL("autoit_dlib_com-*-4100*"))
_OpenCV_Open(_OpenCV_FindDLL("opencv_world4100*"), _OpenCV_FindDLL("autoit_opencv_com4100*"))
OnAutoItExitRegister("_OnAutoItExit")

Example()

Func Example()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return

	Local Const $cv = _OpenCV_get()
	If Not IsObj($cv) Then Return

	Local $detector = $dlib.get_frontal_face_detector()
	Local $cam = $cv.VideoCapture(0)
	Local $color_green = _OpenCV_Tuple(0, 255, 0)
	Local $line_width = 3
	Local $img, $dets

	While True
		If $cam.read() Then
			$img = $cv.extended[1]
			$dets = $detector($img)

			For $det In $dets
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
	_OpenCV_Close()
	_Dlib_Close()
EndFunc   ;==>_OnAutoItExit
