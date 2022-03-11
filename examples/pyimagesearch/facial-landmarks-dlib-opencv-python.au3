#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/master/python_examples/face_landmark_detection.py
;~     https://github.com/davisking/dlib/blob/master/python_examples/opencv_webcam_face_detection.py
;~     https://pyimagesearch.com/2017/04/03/facial-landmarks-dlib-opencv-python/

#include <ButtonConstants.au3>
#include <EditConstants.au3>
#include <GUIConstantsEx.au3>
#include <StaticConstants.au3>
#include <WindowsConstants.au3>
#include "..\..\autoit-dlib-com\udf\dlib_udf_utils.au3"
#include "..\..\autoit-opencv-com\udf\opencv_udf_utils.au3"

_Dlib_Open_And_Register(_Dlib_FindDLL("opencv_world4*", "opencv-4.*\opencv"), _Dlib_FindDLL("autoit_dlib_com-*"))
_OpenCV_Open_And_Register(_OpenCV_FindDLL("opencv_world4*", "opencv-4.*\opencv"), _OpenCV_FindDLL("autoit_opencv_com4*"))
OnAutoItExitRegister("_OnAutoItExit")

Global Const $AUTOIT_SAMPLES_DATA_PATH = _Dlib_FindFile("examples\data")
Global Const $DLIB_SAMPLES_FACES_PATH = _Dlib_FindFile("autoit-dlib-com\build_x64\_deps\dlib-src\examples\faces")

#Region ### START Koda GUI section ### Form=
Global Const $FormGUI = GUICreate("Facial landmarks with dlib, OpenCV, and Python", 1001, 708, 192, 95)

Global Const $InputImg = GUICtrlCreateInput($DLIB_SAMPLES_FACES_PATH & "\2008_002470.jpg", 230, 16, 449, 21)
Global Const $BtnImg = GUICtrlCreateButton("Image", 689, 14, 115, 25)

Global Const $InputShapePredictor = GUICtrlCreateInput($AUTOIT_SAMPLES_DATA_PATH & "\shape_predictor_68_face_landmarks.dat", 230, 52, 449, 21)
Global Const $BtnShapePredictor = GUICtrlCreateButton("Shape predictor", 689, 50, 115, 25)

Global Const $BtnExec = GUICtrlCreateButton("Execute", 832, 48, 75, 25)

Global Const $GroupFaces = GUICtrlCreateGroup("", 20, 86, 958, 616)
Global Const $PicFaces = GUICtrlCreatePic("", 25, 97, 948, 600)
GUICtrlCreateGroup("", -99, -99, 1, 1)

GUISetState(@SW_SHOW)
#EndRegion ### END Koda GUI section ###

Global $sImg, $sShapePredictor

Main()

Global $nMsg
While 1
	$nMsg = GUIGetMsg()
	Switch $nMsg
		Case $GUI_EVENT_CLOSE
			ExitLoop
		Case $BtnImg
			$sImg = ControlGetText($FormGUI, "", $InputImg)
			$sImg = FileOpenDialog("Select an image", $DLIB_SAMPLES_FACES_PATH, "Image files (*.bmp;*.jpg;*.jpeg;*.png;*.gif)", $FD_FILEMUSTEXIST, $sImg)
			If @error Then
				$sImg = ""
			Else
				ControlSetText($FormGUI, "", $InputImg, $sImg)
			EndIf
		Case $BtnShapePredictor
			$sShapePredictor = ControlGetText($FormGUI, "", $InputShapePredictor)
			$sShapePredictor = FileOpenDialog("Select an image", $AUTOIT_SAMPLES_DATA_PATH, "Data files (*.dat)", $FD_FILEMUSTEXIST, $sShapePredictor)
			If @error Then
				$sShapePredictor = ""
			Else
				ControlSetText($FormGUI, "", $InputShapePredictor, $sShapePredictor)
			EndIf
		Case $BtnExec
			Main()
	EndSwitch
WEnd

Func Main()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return

	Local Const $cv = _OpenCV_get()
	If Not IsObj($cv) Then Return

	$sImg = ControlGetText($FormGUI, "", $InputImg)
	Local $image = _OpenCV_imread_and_check($sImg)
	_OpenCV_imshow_ControlPic($image, $FormGUI, $PicFaces)
	If @error Then Return

	$sShapePredictor = ControlGetText($FormGUI, "", $InputShapePredictor)
	If Not FileExists($sShapePredictor) Then
		ConsoleWriteError("!>Error: " & $sShapePredictor & " does not exists" & @CRLF)
		Return
	EndIf

	Local Const $color_green = _OpenCV_Tuple(0, 255, 0)
	Local Const $color_red = _OpenCV_Tuple(0, 0, 255)
	Local Const $line_width = 2

	; initialize dlib's face detector (HOG-based) and then create
	; the facial landmark predictor
	Local $detector = $dlib.get_frontal_face_detector()
	Local $predictor = _Dlib_ObjCreate("shape_predictor").create($sShapePredictor)

	; Ask the detector to find the bounding boxes of each face. The 1 in the
	; second argument indicates that we should upsample the image 1 time. This
	; will make everything bigger and allow us to detect more faces.
	Local $dets = $detector.call($image, 1)
	ConsoleWrite("Number of faces detected: " & UBound($dets) & @CRLF)

	Local $rect, $shape, $left, $top, $right, $bottom, $point

	For $i = 0 To UBound($dets) - 1
		$rect = $dets[$i]

		$left = $rect.left()
		$top = $rect.top()
		$right = $rect.right()
		$bottom = $rect.bottom()

		$cv.rectangle($image, _OpenCV_Tuple($left, $top), _OpenCV_Tuple($right, $bottom), $color_green, $line_width)

		; show the face number
		$cv.putText($image, "Face #" & ($i + 1), _OpenCV_Tuple($left - 10, $top - 10), _
				$CV_FONT_HERSHEY_SIMPLEX, 0.5, $color_green, 1)

		; Get the landmarks/parts for the face in box rect.
		$shape = $predictor.call($image, $rect)

		; loop over the (x, y)-coordinates for the facial landmarks
		; and draw them on the image
		For $j = 0 To $shape.num_parts - 1
			$point = $shape.part($j)
			$cv.circle($image, _OpenCV_Tuple($point.x, $point.y), 1, $color_red, $CV_FILLED)
		Next
	Next

	_OpenCV_imshow_ControlPic($image, $FormGUI, $PicFaces)
EndFunc   ;==>Main

Func _OnAutoItExit()
	_OpenCV_Unregister_And_Close()
	_Dlib_Unregister_And_Close()
EndFunc   ;==>_OnAutoItExit
