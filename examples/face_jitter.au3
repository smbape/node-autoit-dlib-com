#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/master/python_examples/face_jitter.py

#include <InetConstants.au3>
#include <Misc.au3>
#include "..\autoit-dlib-com\udf\dlib_udf_utils.au3"

_Dlib_Open_And_Register(_Dlib_FindDLL("opencv_world4*", "opencv-4.*\opencv"), _Dlib_FindDLL("autoit_dlib_com-*"))
OnAutoItExitRegister("_OnAutoItExit")

Example()

Func Example()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return

	_DownloadAndUnpackData("shape_predictor_5_face_landmarks.dat", "shape_predictor_5_face_landmarks.dat.bz2", "http://dlib.net/files/shape_predictor_5_face_landmarks.dat.bz2")

	Local $predictor_path = "shape_predictor_5_face_landmarks.dat"
	Local $face_file_path = "..\autoit-dlib-com\build_x64\_deps\dlib-src\examples\faces\Tom_Cruise_avp_2014_4.jpg"

	; Load all the models we need: a detector to find the faces, a shape predictor
	; to find face landmarks so we can precisely localize the face
	Local $detector = $dlib.get_frontal_face_detector()
	Local $sp = _Dlib_ObjCreate("shape_predictor").create($predictor_path)

	; Load the image using dlib
	Local $img = $dlib.load_rgb_image($face_file_path)

	; Ask the detector to find the bounding boxes of each face.
	Local $dets = $detector.call($img)

	Local $num_faces = UBound($dets)

	; Find the 5 face landmarks we need to do the alignment.
	Local $faces = _Dlib_ObjCreate("VectorOfFull_object_detection")
	For $i = 0 To $num_faces - 1
		Local $detection = $dets[$i]
		$faces.push_back($sp.call($img, $detection))
	Next

	; Get the aligned face image and show it
	Local $image = $dlib.get_face_chip($img, $faces.at(0), 320)
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

	ConsoleWrite('@@ Debug(' & @ScriptLineNumber & ') : FileGetSize ' & $iActualSize & @CRLF) ;### Debug Console
	ConsoleWrite('@@ Debug(' & @ScriptLineNumber & ') : InetGetSize ' & $iExpectedSize & @CRLF) ;### Debug Console
	ConsoleWrite('@@ Debug(' & @ScriptLineNumber & ') : Downloading ' & $sUrl & @CRLF) ;### Debug Console
	InetGet($sUrl, $sFilePath, $INET_FORCERELOAD)
EndFunc   ;==>_DownloadData

Func _UnpackData($sArchive)
	ShellExecuteWait("7z", "x -y " & $sArchive & " -o" & @ScriptDir)
EndFunc   ;==>_UnpackData

Func _DownloadAndUnpackData($sFilePath, $sArchive, $sUrl)
	Local $iActualSize = FileGetSize($sFilePath)
	If $iActualSize <> 0 Then Return
	_DownloadData($sArchive, $sUrl)
	_UnpackData($sArchive)
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
	_Dlib_Unregister_And_Close()
EndFunc   ;==>_OnAutoItExit