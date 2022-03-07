#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/master/python_examples/face_clustering.py

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

	Local $predictor_path = "shape_predictor_5_face_landmarks.dat"
	Local $face_rec_model_path = "dlib_face_recognition_resnet_model_v1.dat"
	Local $faces_folder_path = "..\autoit-dlib-com\build_x64\_deps\dlib-src\examples\faces"
	Local $output_folder_path = "output_folder"

	; Load all the models we need: a detector to find the faces, a shape predictor
	; to find face landmarks so we can precisely localize the face, and finally the
	; face recognition model.
	Local $detector = $dlib.get_frontal_face_detector()
	Local $sp = _Dlib_ObjCreate("shape_predictor").create($predictor_path)
	Local $facerec = _Dlib_ObjCreate("face_recognition_model_v1").create($face_rec_model_path)

	Local $descriptors = _Dlib_ObjCreate("VectorOfSpaceVector")
	Local $images = _Dlib_ObjCreate("VectorOfVariant")

	; Now find all the faces and compute 128D face descriptors for each face.
	Local Const $aFiles = _Dlib_FindFiles($faces_folder_path & "\*.jpg")

	Local $f, $img, $dets, $d, $shape, $face_descriptor

	For $k = 0 To UBound($aFiles) - 1
		$f = $aFiles[$k]
		ToolTip("Processing file: " & $f, 0, 0)
		ConsoleWrite("Processing file: " & $f & @CRLF)
		$img = $dlib.load_rgb_image($f)

		; Ask the detector to find the bounding boxes of each face. The 1 in the
		; second argument indicates that we should upsample the image 1 time. This
		; will make everything bigger and allow us to detect more faces.
		$dets = $detector.call($img, 1)
		ConsoleWrite("Number of faces detected: " & UBound($dets) & @CRLF)

		; Now process each face we found.
		For $i = 0 To UBound($dets) - 1
			$d = $dets[$i]
			; Get the landmarks/parts for the face in box d.
			$shape = $sp.call($img, $d)

			; Compute the 128D vector that describes the face in img identified by
			; shape.
			$face_descriptor = $facerec.compute_face_descriptor($img, $shape)
			$descriptors.push_back($face_descriptor)
			$images.push_back(_DLib_Tuple($img, $shape))
		Next
	Next

	; Now let's cluster the faces.
	Local $labels = $dlib.chinese_whispers_clustering($descriptors, 0.5)
	Local $num_classes = UBound(_ArrayUnique($labels))
	ConsoleWrite("Number of clusters: " & $num_classes & @CRLF)

	; Find biggest class
	Local $biggest_class = Default
	Local $biggest_class_length = 0
	Local $class_length
	For $i = 0 To $num_classes - 1
		$class_length = UBound(_ArrayFindAll($labels, $i))
		If $class_length > $biggest_class_length Then
			$biggest_class_length = $class_length
			$biggest_class = $i
		EndIf
	Next

	ConsoleWrite("Biggest cluster id number: " & $biggest_class & @CRLF)
	ConsoleWrite("Number of faces in biggest cluster: " & $biggest_class_length & @CRLF)

	; Find the indices for the biggest class
	Local $indices = _ArrayFindAll($labels, $biggest_class)

	ConsoleWrite("Indices of images in the biggest cluster: ")
	For $i = 0 To UBound($indices) - 1
		If $i <> 0 Then ConsoleWrite(", ")
		ConsoleWrite($indices[$i])
	Next
	ConsoleWrite(@CRLF)

	; Ensure output directory exists
	If Not FileExists($output_folder_path) Then DirCreate($output_folder_path)

	; Save the extracted faces
	ConsoleWrite("Saving faces in largest cluster to output folder..." & @CRLF)
	Local $index, $tuple, $file_path
	For $i = 0 To UBound($indices) - 1
		$index = $indices[$i]
		$tuple = $images.at($index)

		$img = $tuple[0]
		$shape = $tuple[1]

		$file_path = $output_folder_path & "\face_" & $i
		; The size and padding arguments are optional with default size=150x150 and padding=0.25
		$dlib.save_face_chip($img, $shape, $file_path, 150, 0.25)
	Next
EndFunc   ;==>Example

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
	ShellExecute("7z", "x -y " & $sArchive & " -o" & @ScriptDir)
EndFunc   ;==>_UnpackData

Func _DownloadAndUnpackData($sFilePath, $sArchive, $sUrl)
	Local $iActualSize = FileGetSize($sFilePath)
	If $iActualSize <> 0 Then Return
	_DownloadData($sArchive, $sUrl)
	_UnpackData($sArchive)
EndFunc   ;==>_DownloadAndUnpackData

Func _OnAutoItExit()
	_Dlib_Unregister_And_Close()
EndFunc   ;==>_OnAutoItExit
