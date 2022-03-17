#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/master/python_examples/cnn_face_detector.py

#include <InetConstants.au3>
#include <Misc.au3>
#include "..\..\autoit-dlib-com\udf\dlib_udf_utils.au3"

_Dlib_Open_And_Register(_Dlib_FindDLL("opencv_world4*", "opencv-4.*\opencv"), _Dlib_FindDLL("autoit_dlib_com-*"))
OnAutoItExitRegister("_OnAutoItExit")

Example()

Func Example()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return
	Local Const $AUTOIT_SAMPLES_DATA_PATH = _Dlib_FindFile("examples\data")
	Local Const $DLIB_SAMPLES_FACES_PATH = _Dlib_FindFile("examples\faces")

	_DownloadAndUnpackData($AUTOIT_SAMPLES_DATA_PATH & "\mmod_human_face_detector.dat", _
			$AUTOIT_SAMPLES_DATA_PATH & "\mmod_human_face_detector.dat.bz2", _
			"http://dlib.net/files/mmod_human_face_detector.dat.bz2")

	Local $cnn_face_detector = _Dlib_ObjCreate("cnn_face_detection_model_v1").create($AUTOIT_SAMPLES_DATA_PATH & "\mmod_human_face_detector.dat")
	Local $win = _Dlib_ObjCreate("image_window")

	Local Const $aFiles = _Dlib_FindFiles("*.jpg", $DLIB_SAMPLES_FACES_PATH)

	Local $img, $dets, $rects, $d

	For $f In $aFiles
		$f = $DLIB_SAMPLES_FACES_PATH & "\" & $f
		ToolTip("Processing file: " & $f, 0, 0)
		ConsoleWrite("Processing file: " & $f & @CRLF)
		$img = $dlib.load_rgb_image($f)

		$win.clear_overlay()
		$win.set_title($f)
		$win.set_image($img)

		; The 1 in the second argument indicates that we should upsample the image
		; 1 time.  This will make everything bigger and allow us to detect more
		; faces.
		$dets = $cnn_face_detector($img, 1)

		#cs
		This detector returns a mmod_rectangles object. This object contains a list of mmod_rectangle objects.
		These objects can be accessed by simply iterating over the mmod_rectangles object
		The mmod_rectangle object has two member variables, a dlib.rectangle object, and a confidence score.
		
		It is also possible to pass a list of images to the detector.
			- like this: dets = cnn_face_detector([image list], upsample_num, batch_size = 128)
		
		In this case it will return a mmod_rectangless object.
		This object behaves just like a list of lists and can be iterated over.
		#ce
		ConsoleWrite("Number of faces detected: " & UBound($dets) & @CRLF)
		For $i = 0 To UBound($dets) - 1
			$d = $dets[$i]
			ConsoleWrite(StringFormat("Detection %d: Left: %d Top: %d Right: %d Bottom: %d Confidence: %f", _
					$i, $d.rect.left(), $d.rect.top(), $d.rect.right(), $d.rect.bottom(), $d.confidence) & @CRLF)
		Next

		$rects = _Dlib_ObjCreate("VectorOfRectangle")
		For $d In $dets
			$rects.Add($d.rect)
		Next

		$win.add_overlay($rects)
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
	_Dlib_Unregister_And_Close()
EndFunc   ;==>_OnAutoItExit
