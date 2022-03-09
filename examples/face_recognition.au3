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
#include "..\autoit-dlib-com\udf\dlib_udf_utils.au3"

_Dlib_Open_And_Register(_Dlib_FindDLL("opencv_world4*", "opencv-4.*\opencv"), _Dlib_FindDLL("autoit_dlib_com-*"))
OnAutoItExitRegister("_OnAutoItExit")

Example()

Func Example()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return

	_DownloadAndUnpackData("shape_predictor_5_face_landmarks.dat", "shape_predictor_5_face_landmarks.dat.bz2", "http://dlib.net/files/shape_predictor_5_face_landmarks.dat.bz2")
	_DownloadAndUnpackData("dlib_face_recognition_resnet_model_v1.dat", "dlib_face_recognition_resnet_model_v1.dat.bz2", "http://dlib.net/files/dlib_face_recognition_resnet_model_v1.dat.bz2")

	; _Dlib_FindFiles
	Local $predictor_path = "shape_predictor_5_face_landmarks.dat"
	Local $face_rec_model_path = "dlib_face_recognition_resnet_model_v1.dat"
	Local $faces_folder_path = "..\autoit-dlib-com\build_x64\_deps\dlib-src\examples\faces"

	; Load all the models we need: a detector to find the faces, a shape predictor
	; to find face landmarks so we can precisely localize the face, and finally the
	; face recognition model.
	Local $detector = $dlib.get_frontal_face_detector()
	Local $sp = _Dlib_ObjCreate("shape_predictor").create($predictor_path)
	Local $facerec = _Dlib_ObjCreate("face_recognition_model_v1").create($face_rec_model_path)

	Local $win = _Dlib_ObjCreate("image_window").create()

	Local Const $aFiles = _Dlib_FindFiles($faces_folder_path & "\*.jpg")

	Local $f, $img, $dets, $d, $shape, $face_descriptor, $face_chip, $face_descriptor_from_prealigned_image

	; Now process all the images
	For $j = 0 To UBound($aFiles) - 1
		$f = $aFiles[$j]
		ToolTip("Processing file: " & $f, 0, 0)
		ConsoleWrite("Processing file: " & $f & @CRLF)
		$img = $dlib.load_rgb_image($f)

		$win.clear_overlay()
		$win.set_image($img)

		; Ask the detector to find the bounding boxes of each face. The 1 in the
		; second argument indicates that we should upsample the image 1 time. This
		; will make everything bigger and allow us to detect more faces.
		$dets = $detector.call($img, 1)
		ConsoleWrite("Number of faces detected: " & UBound($dets) & @CRLF)

		; Now process each face we found.
		For $k = 0 To UBound($dets) - 1
			$d = $dets[$k]
			ConsoleWrite(StringFormat("Detection %d: Left: %d Top: %d Right: %d Bottom: %d", _
					$k, $d.left(), $d.top(), $d.right(), $d.bottom()) & @CRLF)
			; Get the landmarks/parts for the face in box d.
			$shape = $sp.call($img, $d)
			; Draw the face landmarks on the screen so we can see what face is currently being processed.
			$win.clear_overlay()
			$win.add_overlay($d)
			$win.add_overlay($shape)

			; Compute the 128D vector that describes the face in img identified by
			; shape.  In general, if two face descriptor vectors have a Euclidean
			; distance between them less than 0.6 then they are from the same
			; person, otherwise they are from different people. Here we just print
			; the vector to the screen.
            ToolTip("Compute the 128D vector ..", 0, 0)
			$face_descriptor = $facerec.compute_face_descriptor($img, $shape)
			ConsoleWrite($face_descriptor.ToString() & @CRLF)
			; It should also be noted that you can also call this function like this:
			;  face_descriptor = facerec.compute_face_descriptor(img, shape, 100, 0.25)
			; The version of the call without the 100 gets 99.13% accuracy on LFW
			; while the version with 100 gets 99.38%.  However, the 100 makes the
			; call 100x slower to execute, so choose whatever version you like.  To
			; explain a little, the 3rd argument tells the code how many times to
			; jitter/resample the image.  When you set it to 100 it executes the
			; face descriptor extraction 100 times on slightly modified versions of
			; the face and returns the average result.  You could also pick a more
			; middle value, such as 10, which is only 10x slower but still gets an
			; LFW accuracy of 99.3%.
			; 4th value (0.25) is padding around the face. If padding == 0 then the chip will
			; be closely cropped around the face. Setting larger padding values will result a looser cropping.
			; In particular, a padding of 0.5 would double the width of the cropped area, a value of 1.
			; would triple it, and so forth.

			; There is another overload of compute_face_descriptor that can take
			; as an input an aligned image.
			;
			; Note that it is important to generate the aligned image as
			; dlib.get_face_chip would do it i.e. the size must be 150x150,
			; centered and scaled.
			;
			; Here is a sample usage of that

			ToolTip("Computing descriptor on aligned image ..", 0, 0)
            ConsoleWrite("Computing descriptor on aligned image .." & @CRLF)

			; Let's generate the aligned image using get_face_chip
			$face_chip = $dlib.get_face_chip($img, $shape)

			; Now we simply pass this chip (aligned image) to the api
			$face_descriptor_from_prealigned_image = $facerec.compute_face_descriptor($face_chip)
			ConsoleWrite($face_descriptor_from_prealigned_image.ToString() & @CRLF)

			hit_to_continue()
		Next
	Next

EndFunc   ;==>Example

Func _DownloadData($sFilePath, $sUrl)
	Local $iActualSize = FileGetSize($sFilePath)
	Local $iExpectedSize = InetGetSize($sUrl)

	If @error Or $iExpectedSize <= 0 Or (FileExists($sFilePath) And $iActualSize == $iExpectedSize) Then Return

	ConsoleWrite('@@ Debug(' & @ScriptLineNumber & ') : FileGetSize ' & $iActualSize & @CRLF) ;;;; Debug Console
	ConsoleWrite('@@ Debug(' & @ScriptLineNumber & ') : InetGetSize ' & $iExpectedSize & @CRLF) ;;;; Debug Console
	ConsoleWrite('@@ Debug(' & @ScriptLineNumber & ') : Downloading ' & $sUrl & @CRLF) ;;;; Debug Console
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
