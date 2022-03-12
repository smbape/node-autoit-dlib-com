#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/master/python_examples/face_detector.py

#include <Misc.au3>
#include "..\..\autoit-dlib-com\udf\dlib_udf_utils.au3"

_Dlib_Open_And_Register(_Dlib_FindDLL("opencv_world4*", "opencv-4.*\opencv"), _Dlib_FindDLL("autoit_dlib_com-*"))
OnAutoItExitRegister("_OnAutoItExit")

Example()

Func Example()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return
	Local Const $DLIB_SAMPLES_FACES_PATH = _Dlib_FindFile("examples\faces")

	Local $detector = $dlib.get_frontal_face_detector()
	Local $win = _Dlib_ObjCreate("image_window")

	Local Const $aFiles = _Dlib_FindFiles("*.jpg", $DLIB_SAMPLES_FACES_PATH)

	Local $f, $img, $dets, $d, $scores, $idx

	For $j = 0 To UBound($aFiles) - 1
		$f = $DLIB_SAMPLES_FACES_PATH & "\" & $aFiles[$j]
		ToolTip("Processing file: " & $f, 0, 0)
		ConsoleWrite("Processing file: " & $f & @CRLF)
		$img = $dlib.load_rgb_image($f)

		$win.clear_overlay()
		$win.set_image($img)

		; The 1 in the second argument indicates that we should upsample the image
		; 1 time.  This will make everything bigger and allow us to detect more
		; faces.
		$dets = $detector.call($img, 1)
		ConsoleWrite("Number of faces detected: " & UBound($dets) & @CRLF)
		For $i = 0 To UBound($dets) - 1
			$d = $dets[$i]
			ConsoleWrite(StringFormat("Detection %d: Left: %d Top: %d Right: %d Bottom: %d", _
					$i, $d.left(), $d.top(), $d.right(), $d.bottom()) & @CRLF)
		Next

		$win.add_overlay($dets)
		hit_to_continue()
	Next

	; Finally, if you really want to you can ask the detector to tell you the score
	; for each detection.  The score is bigger for more confident detections.
	; The third argument to run is an optional adjustment to the detection threshold,
	; where a negative value will return more detections and a positive value fewer.
	; Also, the idx tells you which of the face sub-detectors matched.  This can be
	; used to broadly identify faces in different orientations.
	If UBound($aFiles) > 0 Then
		$img = $dlib.load_rgb_image($DLIB_SAMPLES_FACES_PATH & "\" & $aFiles[0])
		$detector.run($img, 1, -1)
		$dets = $dlib.extended[0]
		$scores = $dlib.extended[1]
		$idx = $dlib.extended[2]
		For $i = 0 To UBound($dets) - 1
			$d = $dets[$i]
			ConsoleWrite(StringFormat("Detection %s, score: %f, face_type: %d" & @CRLF, _
					$d.ToString(), $scores[$i], $idx[$i]))
		Next
	EndIf
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
