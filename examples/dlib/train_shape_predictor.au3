#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/v19.24/python_examples/train_shape_predictor.py

#include <Misc.au3>
#include "..\..\autoit-dlib-com\udf\dlib_udf_utils.au3"

_Dlib_Open(_Dlib_FindDLL("opencv_world470*"), _Dlib_FindDLL("autoit_dlib_com-*-470*"))
OnAutoItExitRegister("_OnAutoItExit")

Example()

Func Example()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return
	Local Const $AUTOIT_SAMPLES_DATA_PATH = _Dlib_FindFile("examples\data")

	Local $faces_folder = _Dlib_FindFile("examples\faces")

	Local $options = _Dlib_ObjCreate("shape_predictor_training_options")
	; Now make the object responsible for training the model.
	; This algorithm has a bunch of parameters you can mess with.  The
	; documentation for the shape_predictor_trainer explains all of them.
	; You should also read Kazemi's paper which explains all the parameters
	; in great detail.  However, here I'm just setting three of them
	; differently than their default values.  I'm doing this because we
	; have a very small dataset.  In particular, setting the oversampling
	; to a high amount (300) effectively boosts the training set size, so
	; that helps this example.
	$options.oversampling_amount = 300
	; I'm also reducing the capacity of the model by explicitly increasing
	; the regularization (making nu smaller) and by using trees with
	; smaller depths.
	$options.nu = 0.05
	$options.tree_depth = 2
	$options.be_verbose = True

	; dlib.train_shape_predictor() does the actual training.  It will save the
	; final predictor to predictor.dat.  The input is an XML file that lists the
	; images in the training dataset and also contains the positions of the face
	; parts.
	Local $training_xml_path = $faces_folder & "\training_with_face_landmarks.xml"
	$dlib.train_shape_predictor($training_xml_path, $AUTOIT_SAMPLES_DATA_PATH & "\predictor.dat", $options)

	; Now that we have a model we can test it.  dlib.test_shape_predictor()
	; measures the average distance between a face landmark output by the
	; shape_predictor and where it should be according to the truth data.
	ConsoleWrite(@CRLF & "Training accuracy: " & _
			$dlib.test_shape_predictor($training_xml_path, $AUTOIT_SAMPLES_DATA_PATH & "\predictor.dat") & @CRLF)
	; The real test is to see how well it does on data it wasn't trained on.  We
	; trained it on a very small dataset so the accuracy is not extremely high, but
	; it's still doing quite good.  Moreover, if you train it on one of the large
	; face landmarking datasets you will obtain state-of-the-art results, as shown
	; in the Kazemi paper.
	Local $testing_xml_path = $faces_folder & "\testing_with_face_landmarks.xml"
	ConsoleWrite("Testing accuracy: " & _
			$dlib.test_shape_predictor($testing_xml_path, $AUTOIT_SAMPLES_DATA_PATH & "\predictor.dat") & @CRLF)

	; Now let's use it as you would in a normal application.  First we will load it
	; from disk. We also need to load a face detector to provide the initial
	; estimate of the facial location.
	Local $predictor = _Dlib_ObjCreate("shape_predictor").create($AUTOIT_SAMPLES_DATA_PATH & "\predictor.dat")
	Local $detector = $dlib.get_frontal_face_detector()

	; Now let's run the detector and shape_predictor over the images in the faces
	; folder and display the results.
	ConsoleWrite("Showing detections and predictions on the images in the faces folder..." & @CRLF)
	Local $win = _Dlib_ObjCreate("image_window")

	Local Const $aFiles = _Dlib_FindFiles("*.jpg", $faces_folder)

	Local $img, $dets, $d, $shape

	For $f In $aFiles
		$f = $faces_folder & "\" & $f
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
