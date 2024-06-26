#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/v19.24/python_examples/face_landmark_detection.py

#include <InetConstants.au3>
#include <Misc.au3>
#include "..\..\autoit-dlib-com\udf\dlib_udf_utils.au3"

_Dlib_Open(_Dlib_FindDLL("opencv_world4100*"), _Dlib_FindDLL("autoit_dlib_com-*-4100*"))
OnAutoItExitRegister("_OnAutoItExit")

Example()

Func Example()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return
	Local Const $AUTOIT_SAMPLES_DATA_PATH = _Dlib_FindFile("examples\data")

	_DownloadAndUnpackData($AUTOIT_SAMPLES_DATA_PATH & "\shape_predictor_68_face_landmarks.dat", _
			$AUTOIT_SAMPLES_DATA_PATH & "\shape_predictor_68_face_landmarks.dat.bz2", _
			"https://github.com/davisking/dlib-models/raw/master/shape_predictor_68_face_landmarks.dat.bz2")

	Local $predictor_path = $AUTOIT_SAMPLES_DATA_PATH & "\shape_predictor_68_face_landmarks.dat"
	Local $faces_folder_path = _Dlib_FindFile("examples\faces")

	Local $detector = $dlib.get_frontal_face_detector()
	Local $predictor = _Dlib_ObjCreate("shape_predictor").create($predictor_path)
	Local $win = _Dlib_ObjCreate("image_window")

	Local Const $aFiles = _Dlib_FindFiles("*.jpg", $faces_folder_path)

	Local $img, $dets, $d, $shape

	For $f In $aFiles
		$f = $faces_folder_path & "\" & $f
		ToolTip("Processing file: " & $f, 0, 0)
		ConsoleWrite("Processing file: " & $f & @CRLF)
		$img = $dlib.load_rgb_image($f)

		$win.clear_overlay()
		$win.set_image($img)

		; Ask the detector to find the bounding boxes of each face. The 1 in the
		; second argument indicates that we should upsample the image 1 time. This
		; will make everything bigger and allow us to detect more faces.
		$dets = $detector($img, 1)
		ConsoleWrite("Number of faces detected: " & UBound($dets) & @CRLF)

		For $k = 0 To UBound($dets) - 1
			$d = $dets[$k]
			ConsoleWrite(StringFormat("Detection %d: Left: %d Top: %d Right: %d Bottom: %d", _
					$k, $d.left(), $d.top(), $d.right(), $d.bottom()) & @CRLF)

			; Get the landmarks/parts for the face in box d.
			$shape = $predictor($img, $d)
			ConsoleWrite(StringFormat("Part 0: %s, Part 1: %s ...", $shape.part(0).ToString(), _
					$shape.part(1).ToString()) & @CRLF)

			; Draw the face landmarks on the screen.
			$win.add_overlay($shape)
		Next

		$win.add_overlay($dets)
		hit_to_continue()
	Next

EndFunc   ;==>Example

Func _DownloadData($sFilePath, $sUrl)
	Local $iActualSize = FileGetSize($sFilePath)
	Local $iExpectedSize = InetGetSize($sUrl)

	If @error Or $iExpectedSize <= 0 Or (FileExists($sFilePath) And $iActualSize == $iExpectedSize) Then Return

	ConsoleWrite('@@ Debug(' & @ScriptLineNumber & ') : File        ' & $sFilePath & @CRLF) ;### Debug Console
	ConsoleWrite('@@ Debug(' & @ScriptLineNumber & ') : FileGetSize ' & $iActualSize & @CRLF) ;### Debug Console
	ConsoleWrite('@@ Debug(' & @ScriptLineNumber & ') : InetGetSize ' & $iExpectedSize & @CRLF) ;### Debug Console
	ConsoleWrite('@@ Debug(' & @ScriptLineNumber & ') : Downloading ' & $sUrl & @CRLF) ;### Debug Console
	InetGet($sUrl, $sFilePath, $INET_FORCERELOAD)
EndFunc   ;==>_DownloadData

Func _UnpackData($sArchive, $sFilePath)
	Local $sDrive = "", $sDir = "", $sFileName = "", $sExtension = ""
	_PathSplit($sFilePath, $sDrive, $sDir, $sFileName, $sExtension)
	ShellExecuteWait("7z", "x -y " & $sArchive & " -o" & $sDrive & $sDir)
EndFunc   ;==>_UnpackData

Func _DownloadAndUnpackData($sFilePath, $sArchive, $sUrl)
	Local $iActualSize = FileGetSize($sFilePath)
	If $iActualSize <> 0 Then Return
	_DownloadData($sArchive, $sUrl)
	_UnpackData($sArchive, $sFilePath)
EndFunc   ;==>_DownloadAndUnpackData

Func hit_to_continue()
	ToolTip("Hit ESC to continue", 0, 0)
	ConsoleWrite("Hit ESC to continue" & @CRLF)
	Do
		Sleep(50)
	Until _IsPressed("1B")
EndFunc   ;==>hit_to_continue

Func _OnAutoItExit()
	_Dlib_Close()
EndFunc   ;==>_OnAutoItExit
