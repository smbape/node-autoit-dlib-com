#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/v19.24/python_examples/face_jitter.py

#include <InetConstants.au3>
#include <Misc.au3>
#include "..\..\autoit-dlib-com\udf\dlib_udf_utils.au3"

_Dlib_Open(_Dlib_FindDLL("opencv_world470*"), _Dlib_FindDLL("autoit_dlib_com-*-470*"))
OnAutoItExitRegister("_OnAutoItExit")

Example()

Func Example()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return
	Local Const $AUTOIT_SAMPLES_DATA_PATH = _Dlib_FindFile("examples\data")
	Local Const $DLIB_SAMPLES_FACES_PATH = _Dlib_FindFile("examples\faces")

	_DownloadAndUnpackData($AUTOIT_SAMPLES_DATA_PATH & "\shape_predictor_5_face_landmarks.dat", _
			$AUTOIT_SAMPLES_DATA_PATH & "\shape_predictor_5_face_landmarks.dat.bz2", _
			"https://github.com/davisking/dlib-models/raw/master/shape_predictor_5_face_landmarks.dat.bz2")

	Local $predictor_path = $AUTOIT_SAMPLES_DATA_PATH & "\shape_predictor_5_face_landmarks.dat"
	Local $face_file_path = $DLIB_SAMPLES_FACES_PATH & "\Tom_Cruise_avp_2014_4.jpg"

	; Load all the models we need: a detector to find the faces, a shape predictor
	; to find face landmarks so we can precisely localize the face
	Local $detector = $dlib.get_frontal_face_detector()
	Local $sp = _Dlib_ObjCreate("shape_predictor").create($predictor_path)

	; Load the image using dlib
	Local $img = $dlib.load_rgb_image($face_file_path)

	; Ask the detector to find the bounding boxes of each face.
	Local $dets = $detector($img)

	; Find the 5 face landmarks we need to do the alignment.
	Local $faces = _Dlib_ObjCreate("VectorOfFull_object_detection")
	For $detection In $dets
		$faces.Add($sp($img, $detection))
	Next

	; Get the aligned face image and show it
	Local $image = $dlib.get_face_chip($img, $faces(0), 320)
	Local $window = _Dlib_ObjCreate("image_window")
	$window.set_image($image)
	hit_to_continue("get_face_chip: ")

	; Show 5 jittered images without data augmentation
	Local $jittered_images = $dlib.jitter_image($image, 5)
	show_jittered_images($window, $jittered_images)

	; Show 5 jittered images with data augmentation
	$jittered_images = $dlib.jitter_image($image, 5, True)
	show_jittered_images($window, $jittered_images)

EndFunc   ;==>Example

Func show_jittered_images($window, $jittered_images)
	#cs
	    Shows the specified jittered images one by one
	#ce
	For $i = 0 To UBound($jittered_images) - 1
		Local $img = $jittered_images[$i]
		$window.set_image($img)
		hit_to_continue("jittered image " & $i & ": ")
	Next
EndFunc   ;==>show_jittered_images

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

Func hit_to_continue($msg = "")
	ToolTip($msg & "Hit ESC to continue", 0, 0)
	ConsoleWrite($msg & "Hit ESC to continue" & @CRLF)
	Do
		Sleep(50)
	Until _IsPressed("1B")
	Sleep(50)
EndFunc   ;==>hit_to_continue

Func _OnAutoItExit()
	_Dlib_Close()
EndFunc   ;==>_OnAutoItExit
