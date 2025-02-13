#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://pyimagesearch.com/2017/04/10/detect-eyes-nose-lips-jaw-dlib-opencv-python/

#include <ButtonConstants.au3>
#include <EditConstants.au3>
#include <GUIConstantsEx.au3>
#include <StaticConstants.au3>
#include <WindowsConstants.au3>
#include "..\..\autoit-dlib-com\udf\dlib_udf_utils.au3"
#include "..\..\autoit-opencv-com\udf\opencv_udf_utils.au3"

_Dlib_Open(_Dlib_FindDLL("opencv_world4110*"), _Dlib_FindDLL("autoit_dlib_com-*-4110*"))
_OpenCV_Open(_OpenCV_FindDLL("opencv_world4110*"), _OpenCV_FindDLL("autoit_opencv_com4110*"))
OnAutoItExitRegister("_OnAutoItExit")

Global Const $AUTOIT_SAMPLES_DATA_PATH = _Dlib_FindFile("examples\data")
Global Const $DLIB_SAMPLES_FACES_PATH = _Dlib_FindFile("examples\faces")

#Region ### START Koda GUI section ### Form=
Global Const $FormGUI = GUICreate("Facial landmarks with dlib, OpenCV, and AutoIt", 1001, 708, 192, 95)

Global Const $InputImg = GUICtrlCreateInput($DLIB_SAMPLES_FACES_PATH & "\Tom_Cruise_avp_2014_4.jpg", 230, 16, 449, 21)
Global Const $BtnImg = GUICtrlCreateButton("Image", 689, 14, 115, 25)

Global Const $InputShapePredictor = GUICtrlCreateInput($AUTOIT_SAMPLES_DATA_PATH & "\shape_predictor_68_face_landmarks.dat", 230, 52, 449, 21)
Global Const $BtnShapePredictor = GUICtrlCreateButton("Shape predictor", 689, 50, 115, 25)

Global Const $BtnExec = GUICtrlCreateButton("Execute", 832, 48, 75, 25)

Global Const $GroupFaces = GUICtrlCreateGroup("", 20, 86, 958, 616)
Global Const $PicFaces = GUICtrlCreatePic("", 25, 97, 948, 600)
GUICtrlCreateGroup("", -99, -99, 1, 1)

GUISetState(@SW_SHOW)
#EndRegion ### END Koda GUI section ###

; define a dictionary that maps the indexes of the facial
; landmarks to specific face regions
Global Const $FACIAL_LANDMARKS_IDXS = Scripting_Dictionary(_Dlib_Tuple( _
		_Dlib_Tuple("mouth", _Dlib_Tuple(48, 68, _Dlib_Tuple(19, 199, 109))), _
		_Dlib_Tuple("right_eyebrow", _Dlib_Tuple(17, 22, _Dlib_Tuple(79, 76, 240))), _
		_Dlib_Tuple("left_eyebrow", _Dlib_Tuple(22, 27, _Dlib_Tuple(230, 159, 23))), _
		_Dlib_Tuple("right_eye", _Dlib_Tuple(36, 42, _Dlib_Tuple(168, 100, 168))), _
		_Dlib_Tuple("left_eye", _Dlib_Tuple(42, 48, _Dlib_Tuple(158, 163, 32))), _
		_Dlib_Tuple("nose", _Dlib_Tuple(27, 35, _Dlib_Tuple(163, 38, 32))), _
		_Dlib_Tuple("jaw", _Dlib_Tuple(0, 17, _Dlib_Tuple(180, 42, 220))) _
		))

Global $sImg, $sShapePredictor, $predictor
Global $predictor_has_changed = True

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
				$predictor_has_changed = StringCompare(ControlGetText($FormGUI, "", $InputShapePredictor), $sShapePredictor) == 0
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
	If @error Then Return

	$sShapePredictor = ControlGetText($FormGUI, "", $InputShapePredictor)
	If Not FileExists($sShapePredictor) Then
		ConsoleWriteError("!>Error: " & $sShapePredictor & " does not exists" & @CRLF)
		Return
	EndIf

	; load the input image, resize it, and convert it to grayscale
	$image = _OpenCV_resizeAndCenter($image, 500)
	_OpenCV_imshow_ControlPic($image, $FormGUI, $PicFaces)
	Local $gray = $cv.cvtColor($image, $CV_COLOR_BGR2GRAY)

	; initialize dlib's face detector (HOG-based)
	Local Const $detector = $dlib.get_frontal_face_detector()

	If $predictor_has_changed Then
		; create the facial landmark predictor
		$predictor = _Dlib_ObjCreate("shape_predictor").create($sShapePredictor)
		$predictor_has_changed = False
	EndIf

	; detect faces in the grayscale image
	Local $rects = $detector($gray, 1)

	Local $rect, $shape
	Local $output = $image

	For $rect In $rects
		; Get the landmarks/parts for the face in box rect.
		$shape = $predictor($image, $rect)

		; visualize all facial landmarks with a transparent overlay
		$output = visualize_facial_landmarks($output, $shape)
	Next

	_OpenCV_imshow_ControlPic($output, $FormGUI, $PicFaces)
EndFunc   ;==>Main

Func Scripting_Dictionary($vPairs)
	Local $oDictionary = ObjCreate("Scripting.Dictionary")
	For $vPair In $vPairs
		$oDictionary.Add($vPair[0], $vPair[1])
	Next
	Return $oDictionary
EndFunc   ;==>Scripting_Dictionary

Func visualize_facial_landmarks($image, $shape, $colors = Default, $alpha = 0.75)
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return

	Local Const $cv = _OpenCV_get()
	If Not IsObj($cv) Then Return

	; create two copies of the input image -- one for the
	; overlay and one for the final output image
	Local $overlay = $image.clone()
	Local $output = $image.clone()

	Local $pts = _OpenCV_ObjCreate("VectorOfPoint")

	Local $aKeys = $FACIAL_LANDMARKS_IDXS.Keys

	Local $name, $idx, $j, $point, $ptA, $ptB, $color, $hull

	; loop over the facial landmark regions individually
	For $i = 0 To $FACIAL_LANDMARKS_IDXS.Count - 1
		$name = $aKeys[$i]

		; grab the (x, y)-coordinates associated with the
		; face landmark
		$idx = $FACIAL_LANDMARKS_IDXS($name)
		$pts.clear()
		For $j = $idx[0] To $idx[1] - 1
			$point = $shape.part($j)
			$pts.Add(_OpenCV_Tuple($point.x(), $point.y()))
		Next

		; get the contour color
		$color = $colors == Default ? $idx[2] : $colors[$i]

		; check if are supposed to draw the jawline
		If $name == "jaw" Then
			; since the jawline is a non-enclosed facial region,
			; just draw lines between the (x, y)-coordinates
			For $l = 1 To $pts.Count - 1
				$ptA = $pts($l - 1)
				$ptB = $pts($l)
				$cv.line($overlay, $ptA, $ptB, $color, 2)
			Next
			; otherwise, compute the convex hull of the facial
			; landmark coordinates points and display it
		Else
			$hull = $cv.convexHull($pts)
			$cv.drawContours($overlay, _OpenCV_Tuple($hull), -1, $color, $CV_FILLED)
		EndIf
	Next

	; apply the transparent overlay
	$cv.addWeighted($overlay, $alpha, $output, 1 - $alpha, 0, $output)

	; return the output image
	Return $output
EndFunc   ;==>visualize_facial_landmarks

Func _OnAutoItExit()
	_OpenCV_Close()
	_Dlib_Close()
EndFunc   ;==>_OnAutoItExit
