#Region ;**** Directives created by AutoIt3Wrapper_GUI ****
#AutoIt3Wrapper_UseX64=y
#AutoIt3Wrapper_Change2CUI=y
#AutoIt3Wrapper_Au3Check_Parameters=-d -w 1 -w 2 -w 3 -w 4 -w 5 -w 6
#AutoIt3Wrapper_AU3Check_Stop_OnWarning=y
#EndRegion ;**** Directives created by AutoIt3Wrapper_GUI ****

;~ Sources:
;~     https://github.com/davisking/dlib/blob/v19.24.9/python_examples/max_cost_assignment.py

#include "..\..\autoit-dlib-com\udf\dlib_udf_utils.au3"

_Dlib_Open(_Dlib_FindDLL("opencv_world4110*"), _Dlib_FindDLL("autoit_dlib_com-*-4110*"))
OnAutoItExitRegister("_OnAutoItExit")

Example()

Func Example()
	Local Const $dlib = _Dlib_get()
	If Not IsObj($dlib) Then Return

	; Let's imagine you need to assign N people to N jobs.  Additionally, each
	; person will make your company a certain amount of money at each job, but each
	; person has different skills so they are better at some jobs and worse at
	; others.  You would like to find the best way to assign people to these jobs.
	; In particular, you would like to maximize the amount of money the group makes
	; as a whole.  This is an example of an assignment problem and is what is solved
	; by the dlib.max_cost_assignment() routine.

	; So in this example, let's imagine we have 3 people and 3 jobs. We represent
	; the amount of money each person will produce at each job with a cost matrix.
	; Each row corresponds to a person and each column corresponds to a job. So for
	; example, below we are saying that person 0 will make $1 at job 0, $2 at job 1,
	; and $6 at job 2.
	Local $cost = _Dlib_ObjCreate("matrix").create(_DLib_Tuple(_Dlib_Tuple(1, 2, 6), _
			_Dlib_Tuple(5, 3, 6), _
			_Dlib_Tuple(4, 5, 0)))

	; To find out the best assignment of people to jobs we just need to call this
	; function.
	Local $assignment = $dlib.max_cost_assignment($cost)

	; This prints optimal assignments:  [2, 0, 1]
	; which indicates that we should assign the person from the first row of the
	; cost matrix to job 2, the middle row person to job 0, and the bottom row
	; person to job 1.
	ConsoleWrite("Optimal assignments: " & ArrayToString($assignment) & @CRLF)

	; This prints optimal cost:  16.0
	; which is correct since our optimal assignment is 6+5+5.
	ConsoleWrite("Optimal cost: " & $dlib.assignment_cost($cost, $assignment) & @CRLF)

EndFunc   ;==>Example

Func ArrayToString($v)
	Return "[" & _ArrayToString($v, ", ") & "]"
EndFunc   ;==>ArrayToString

Func _OnAutoItExit()
	_Dlib_Close()
EndFunc   ;==>_OnAutoItExit
