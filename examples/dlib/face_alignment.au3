#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/master/python_examples/face_alignment.py

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

	_DownloadAndUnpackData($AUTOIT_SAMPLES_DATA_PATH & "\shape_predictor_5_face_landmarks.dat", _
			$AUTOIT_SAMPLES_DATA_PATH & "\shape_predictor_5_face_landmarks.dat.bz2", _
			"http://dlib.net/files/shape_predictor_5_face_landmarks.dat.bz2")

	Local $predictor_path = $AUTOIT_SAMPLES_DATA_PATH & "\shape_predictor_5_face_landmarks.dat"
	Local $face_file_path = $DLIB_SAMPLES_FACES_PATH & "\bald_guys.jpg"

	; Load all the models we need: a detector to find the faces, a shape predictor
	; to find face landmarks so we can precisely localize the face
	Local $detector = $dlib.get_frontal_face_detector()
	Local $sp = _Dlib_ObjCreate("shape_predictor").create($predictor_path)

	; Load the image using Dlib
	Local $img = $dlib.load_rgb_image($face_file_path)

	; Ask the detector to find the bounding boxes of each face. The 1 in the
	; second argument indicates that we should upsample the image 1 time. This
	; will make everything bigger and allow us to detect more faces.
	Local $dets = $detector.call($img, 1)

	Local $num_faces = UBound($dets)
	If $num_faces == 0 Then
		ConsoleWrite("Sorry, there were no faces found in '" & $face_file_path & "'")
		Return
	EndIf

	; Find the 5 face landmarks we need to do the alignment.
	Local $faces = _Dlib_ObjCreate("VectorOfFull_object_detection")
	For $i = 0 To UBound($dets) - 1
		Local $detection = $dets[$i]
		$faces.push_back($sp.call($img, $detection))
	Next

	Local $window = _Dlib_ObjCreate("image_window")
	Local $image

	; Get the aligned face images
	; Optionally:
	; images = dlib.get_face_chips(img, faces, size=160, padding=0.25)
	Local $images = $dlib.get_face_chips($img, $faces, 320)
	For $i = 0 To UBound($images) - 1
		$image = $images[$i]
		$window.set_image($image)
		hit_to_continue()
	Next

	; It is also possible to get a single chip
	$image = $dlib.get_face_chip($img, $faces.at(0))
	$window.set_image($image)
	hit_to_continue()

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
