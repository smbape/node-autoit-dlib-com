#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/v19.24/python_examples/correlation_tracker.py

#include <Misc.au3>
#include "..\..\autoit-dlib-com\udf\dlib_udf_utils.au3"

_Dlib_Open(_Dlib_FindDLL("opencv_world470*"), _Dlib_FindDLL("autoit_dlib_com-*-470*"))
OnAutoItExitRegister("_OnAutoItExit")

Example()

Func Example()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return

	; Path to the video frames
	Local $video_folder = _Dlib_FindFile("examples\video_frames")

	; Create the correlation tracker - the object needs to be initialized
	; before it can be used
	Local $tracker = _Dlib_ObjCreate("correlation_tracker")

	Local $win = _Dlib_ObjCreate("image_window")

	; We will track the frames as we load them off of disk
	Local Const $aFiles = _Dlib_FindFiles("*.jpg", $video_folder)
	Local Const $Rectangle = _Dlib_ObjCreate("rectangle")
	Local $f, $img

	ToolTip("Hit ESC to stop", 0, 0)
	ConsoleWrite("Hit ESC to stop" & @CRLF)

	While True
		$win.set_title("correlation tracker")

		For $k = 0 To UBound($aFiles) - 1
			$f = $video_folder & "\" & $aFiles[$k]
			; ToolTip("Processing file: " & $f, 0, 0)
			; ConsoleWrite("Processing file: " & $f & @CRLF)
			$img = $dlib.load_rgb_image($f)

			$win.set_image($img)

			; We need to initialize the tracker on the first frame
			If $k == 0 Then
				; Start a track on the juice box. If you look at the first frame you
				; will see that the juice box is contained within the bounding
				; box (74, 67, 112, 153).
				$tracker.start_track($img, $Rectangle.create(74, 67, 112, 153))
			Else
				; Else we just attempt to track from the previous frame
				$tracker.update($img)
			EndIf

			$win.clear_overlay()
			$win.add_overlay($tracker.get_position())

			Sleep(50)
			If _IsPressed("1B") Then ExitLoop 2
		Next

		If _IsPressed("1B") Then ExitLoop
	WEnd

EndFunc   ;==>Example

Func _OnAutoItExit()
	_Dlib_Close()
EndFunc   ;==>_OnAutoItExit
