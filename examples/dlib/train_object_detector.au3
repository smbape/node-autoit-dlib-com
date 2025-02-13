#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/v19.24.9/python_examples/train_object_detector.py

#include <Misc.au3>
#include "..\..\autoit-dlib-com\udf\dlib_udf_utils.au3"

_Dlib_Open(_Dlib_FindDLL("opencv_world4110*"), _Dlib_FindDLL("autoit_dlib_com-*-4110*"))
OnAutoItExitRegister("_OnAutoItExit")

Example()

Func Example()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return
	Local Const $AUTOIT_SAMPLES_DATA_PATH = _Dlib_FindFile("examples\data")

	Local $faces_folder = _Dlib_FindFile("examples\faces")

	; Now let's do the training.  The train_simple_object_detector() function has a
	; bunch of options, all of which come with reasonable default values.  The next
	; few lines goes over some of these options.
	Local $options = _Dlib_ObjCreate("simple_object_detector_training_options")
	; Since faces are left/right symmetric we can tell the trainer to train a
	; symmetric detector.  This helps it get the most value out of the training
	; data.
	$options.add_left_right_image_flips = True
	; The trainer is a kind of support vector machine and therefore has the usual
	; SVM C parameter.  In general, a bigger C encourages it to fit the training
	; data better but might lead to overfitting.  You must find the best C value
	; empirically by checking how well the trained detector works on a test set of
	; images you haven't trained on.  Don't just leave the value set at 5.  Try a
	; few different C values and see what works best for your data.
	$options.C = 5
	; Tell the code how many CPU cores your computer has for the fastest training.
	$options.num_threads = 4
	$options.be_verbose = True


	Local $training_xml_path = $faces_folder & "\training.xml"
	Local $testing_xml_path = $faces_folder & "\testing.xml"
	; This function does the actual training.  It will save the final detector to
	; detector.svm.  The input is an XML file that lists the images in the training
	; dataset and also contains the positions of the face boxes.  To create your
	; own XML files you can use the imglab tool which can be found in the
	; tools/imglab folder.  It is a simple graphical tool for labeling objects in
	; images with boxes.  To see how to use it read the tools/imglab/README.txt
	; file.  But for this example, we just use the training.xml file included with
	; dlib.
	$dlib.train_simple_object_detector($training_xml_path, $AUTOIT_SAMPLES_DATA_PATH & "\detector.svm", $options)


	; Now that we have a face detector we can test it.  The first statement tests
	; it on the training data.  It will print(the precision, recall, and then)
	; average precision.
	ConsoleWrite(@CRLF)  ; Print blank line to create gap from previous output
	ConsoleWrite("Training accuracy: " & _
			$dlib.test_simple_object_detector($training_xml_path, $AUTOIT_SAMPLES_DATA_PATH & "\detector.svm").ToString() & @CRLF)
	; However, to get an idea if it really worked without overfitting we need to
	; run it on images it wasn't trained on.  The next line does this.  Happily, we
	; see that the object detector works perfectly on the testing images.
	ConsoleWrite("Testing accuracy: " & _
			$dlib.test_simple_object_detector($testing_xml_path, $AUTOIT_SAMPLES_DATA_PATH & "\detector.svm").ToString() & @CRLF)


	; Now let's use the detector as you would in a normal application.  First we
	; will load it from disk.
	Local $detector = _Dlib_ObjCreate("simple_object_detector").create($AUTOIT_SAMPLES_DATA_PATH & "\detector.svm")

	; We can look at the HOG filter we learned.  It should look like a face.  Neat!
	Local $win_det = _Dlib_ObjCreate("image_window")
	$win_det.set_image($detector)

	; Now let's run the detector over the images in the faces folder and display the
	; results.
	ConsoleWrite("Showing detections on the images in the faces folder..." & @CRLF)
	Local $win = _Dlib_ObjCreate("image_window")

	Local Const $aFiles = _Dlib_FindFiles("*.jpg", $faces_folder)

	Local $f, $img, $dets, $d

	For $f In $aFiles
		$f = $faces_folder & "\" & $f
		ToolTip("Processing file: " & $f, 0, 0)
		ConsoleWrite("Processing file: " & $f & @CRLF)
		$img = $dlib.load_rgb_image($f)

		$win.clear_overlay()
		$win.set_image($img)

		$dets = $detector($img)
		ConsoleWrite("Number of faces detected: " & UBound($dets) & @CRLF)

		For $k = 0 To UBound($dets) - 1
			$d = $dets[$k]
			ConsoleWrite(StringFormat("Detection %d: Left: %d Top: %d Right: %d Bottom: %d", _
					$k, $d.left(), $d.top(), $d.right(), $d.bottom()) & @CRLF)
		Next

		$win.add_overlay($dets)
		hit_to_continue()
	Next

	Local $fhog_object_detector = _Dlib_ObjCreate("fhog_object_detector")

	; Next, suppose you have trained multiple detectors and you want to run them
	; efficiently as a group.  You can do this as follows:
	Local $detector1 = $fhog_object_detector.create($AUTOIT_SAMPLES_DATA_PATH & "\detector.svm")
	; In this example we load detector.svm again since it's the only one we have on
	; hand. But in general it would be a different detector.
	Local $detector2 = $fhog_object_detector.create($AUTOIT_SAMPLES_DATA_PATH & "\detector.svm")
	; make a list of all the detectors you want to run.  Here we have 2, but you
	; could have any number.
	Local $detectors = _Dlib_Tuple($detector1, $detector2)
	Local $image = $dlib.load_rgb_image($faces_folder & "\2008_002506.jpg")
	$fhog_object_detector.run_multiple($detectors, $image, 1, 0.0)
	Local $boxes = $dlib.extended[0]
	Local $confidences = $dlib.extended[1]
	Local $detector_idxs = $dlib.extended[2]
	For $i = 0 To UBound($boxes) - 1
		ConsoleWrite(StringFormat("detector %i found box %s with confidence %f.", $detector_idxs[$i], $boxes[$i], $confidences[$i]) & @CRLF)
	Next

	; Finally, note that you don't have to use the XML based input to
	; train_simple_object_detector().  If you have already loaded your training
	; images and bounding boxes for the objects then you can call it as shown
	; below.

	; You just need to put your images into a list.
	Local $images = _Dlib_Tuple($dlib.load_rgb_image($faces_folder & "\2008_002506.jpg"), _
			$dlib.load_rgb_image($faces_folder & "\2009_004587.jpg"))
	; Then for each image you make a list of rectangles which give the pixel
	; locations of the edges of the boxes.
	Local $boxes_img1 = _Dlib_Tuple(_Dlib_rectangle(329, 78, 437, 186), _
			_Dlib_rectangle(224, 95, 314, 185), _
			_Dlib_rectangle(125, 65, 214, 155))
	Local $boxes_img2 = _Dlib_Tuple(_Dlib_rectangle(154, 46, 228, 121), _
			_Dlib_rectangle(266, 280, 328, 342))
	; And then you aggregate those lists of boxes into one big list and then call
	; train_simple_object_detector().
	$boxes = _Dlib_Tuple($boxes_img1, $boxes_img2)

	$detector2 = $dlib.train_simple_object_detector($images, $boxes, $options)
	; We could save this detector to disk by uncommenting the following.
	;detector2.save('detector2.svm')

	; Now let's look at its HOG filter!
	$win_det.set_image($detector2)
	hit_to_continue()

	; Note that you don't have to use the XML based input to
	; test_simple_object_detector().  If you have already loaded your training
	; images and bounding boxes for the objects then you can call it as shown
	; below.
	ConsoleWrite(@CRLF & "Training accuracy: " & _
			$dlib.test_simple_object_detector($images, $boxes, $detector2).ToString() & @CRLF)

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
