#include-once

#include "dlib_udf.au3"

#include <File.au3>
#include <GDIPlus.au3>
#include <Math.au3>
#include <StaticConstants.au3>
#include <WindowsConstants.au3>
#include <WinAPI.au3>

Global Const $DLIB_UDF_SORT_ASC = 1
Global Const $DLIB_UDF_SORT_DESC = -1

Func _Dlib_FindFiles($aParts, $sDir = Default, $iFlag = Default, $bReturnPath = Default, $bReverse = Default)
	If $sDir == Default Then $sDir = @ScriptDir
	If $iFlag == Default Then $iFlag = $FLTA_FILESFOLDERS
	If $bReturnPath == Default Then $bReturnPath = False
	If $bReverse == Default Then $bReverse = False

	If IsString($aParts) Then
		$aParts = StringSplit($aParts, "\", $STR_NOCOUNT)
	EndIf

	Local $aMatches[0]
	Local $bFound = False
	Local $aNextParts[0]
	Local $aFileList[0]
	Local $aNextFileList[0]
	Local $iParts = UBound($aParts)
	Local $iFound = 0, $iNextFound = 0
	Local $iLen = StringLen($sDir)
	Local $sPath = "", $iiFlags = 0

	For $i = 0 To $iParts - 1
		$bFound = False

		If ($iFlag == $FLTA_FILESFOLDERS Or $i <> $iParts - 1) And StringInStr($aParts[$i], "?") == 0 And StringInStr($aParts[$i], "*") == 0 Then
			_Dlib_DebugMsg("Looking for " & $sDir & "\" & $aParts[$i])
			$bFound = FileExists($sDir & "\" & $aParts[$i])
			If Not $bFound Then
				ExitLoop
			EndIf

			$sDir &= "\" & $aParts[$i]
			ContinueLoop
		EndIf

		_Dlib_DebugMsg("Listing " & $sDir & "\=" & $aParts[$i])
		$iiFlags = $i == $iParts - 1 ? $iFlag : $FLTA_FILESFOLDERS

		$aFileList = _FileListToArray($sDir, $aParts[$i], $iiFlags, $bReturnPath)
		If @error Then ExitLoop

		If $i == $iParts - 1 Then
			ReDim $aMatches[$aFileList[0]]

			For $j = 1 To $aFileList[0]
				$sPath = $aFileList[$j]
				If Not $bReturnPath Then
					$sPath = $sDir & "\" & $sPath
					$sPath = StringRight($sPath, StringLen($sPath) - $iLen - 1)
				EndIf
				$aMatches[$j - 1] = $sPath
			Next

			If $bReverse Then _ArrayReverse($aMatches)
			Return $aMatches
		EndIf

		ReDim $aNextParts[$iParts - $i - 1]
		For $j = $i + 1 To $iParts - 1
			$aNextParts[$j - $i - 1] = $aParts[$j]
		Next

		For $j = 1 To $aFileList[0]
			$sPath = $aFileList[$j]
			If Not $bReturnPath Then
				$sPath = $sDir & "\" & $sPath
			EndIf

			$aNextFileList = _Dlib_FindFiles($aNextParts, $sPath, $iFlag, $bReturnPath, $bReverse)
			$iNextFound = UBound($aNextFileList)

			If $iNextFound <> 0 Then
				ReDim $aMatches[$iFound + $iNextFound]
				For $k = 0 To $iNextFound - 1
					$sPath = $aNextFileList[$k]
					If Not $bReturnPath Then
						$sPath = $sDir & "\" & $aFileList[$j] & "\" & $sPath
						$sPath = StringRight($sPath, StringLen($sPath) - $iLen - 1)
					EndIf
					$aMatches[$iFound + $k] = $sPath
				Next
				$iFound += $iNextFound
			EndIf
		Next

		If $bReverse Then _ArrayReverse($aMatches)
		Return $aMatches
	Next

	If $bFound Then
		ReDim $aMatches[1]

		If Not $bReturnPath Then
			$sDir = StringRight($sDir, StringLen($sDir) - $iLen - 1)
		EndIf

		_Dlib_DebugMsg("Found " & $sDir)
		$aMatches[0] = $sDir
	EndIf

	SetError(@error)

	If $bReverse Then _ArrayReverse($aMatches)
	Return $aMatches
EndFunc   ;==>_Dlib_FindFiles

Func _Dlib_FindFile($sFile, $sFilter = Default, $sDir = Default, $iFlag = Default, $aSearchPaths = Default, $bReverse = Default)
	If $sFilter == Default Then $sFilter = ""
	If $sDir == Default Then $sDir = @ScriptDir
	If $aSearchPaths == Default Then $aSearchPaths = _Dlib_Tuple(1, ".")

	_Dlib_DebugMsg("_Dlib_FindFile('" & $sFile & "', '" & $sDir & "') " & VarGetType($aSearchPaths))

	Local $sFound = "", $sPath, $aFileList
	Local $sDrive = "", $sFileName = "", $sExtension = ""

	While 1
		For $i = 1 To $aSearchPaths[0]
			$sPath = ""

			If $sFilter <> "" Then
				$sPath = $sFilter
			EndIf

			If StringCompare($aSearchPaths[$i], ".") <> 0 Then
				If $sPath == "" Then
					$sPath = $aSearchPaths[$i]
				Else
					$sPath &= "\" & $aSearchPaths[$i]
				EndIf
			EndIf

			If $sPath == "" Then
				$sPath = $sFile
			Else
				$sPath &= "\" & $sFile
			EndIf

			$aFileList = _Dlib_FindFiles($sPath, $sDir, $iFlag, True, $bReverse)
			$sFound = UBound($aFileList) == 0 ? "" : $aFileList[0]

			If $sFound <> "" Then
				_Dlib_DebugMsg("Found " & $sFound & @CRLF)
				ExitLoop 2
			EndIf
		Next

		_PathSplit($sDir, $sDrive, $sDir, $sFileName, $sExtension)
		If $sDir == "" Then
			ExitLoop
		EndIf
		$sDir = $sDrive & StringLeft($sDir, StringLen($sDir) - 1)
	WEnd

	Return $sFound
EndFunc   ;==>_Dlib_FindFile

Func _Dlib_FindDLL($sFile, $sFilter = Default, $sDir = Default, $bReverse = Default)
	Local $sBuildType = $_dlib_build_type == "Debug" ? "Debug" : "Release"
	Local $sPostfix = $_dlib_build_type == "Debug" ? "d" : ""

	Local $aSearchPaths[] = [ _
			0, _
			".", _
			"build_x64", _
			"build_x64\" & $sBuildType, _
			"build", _
			"build\x64", _
			"build\x64\vc15\bin", _
			"autoit-dlib-com", _
			"autoit-dlib-com\build_x64", _
			"autoit-dlib-com\build_x64\" & $sBuildType _
			]
	$aSearchPaths[0] = UBound($aSearchPaths) - 1

	Return _Dlib_FindFile($sFile & $sPostfix & ".dll", $sFilter, $sDir, $FLTA_FILES, $aSearchPaths, $bReverse)
EndFunc   ;==>_Dlib_FindDLL

Func _Dlib_vector($list = Default)
	Local $vector = _Dlib_ObjCreate("vector")
	If IsArray($list) And UBound($list) <> 0 Then
		Return $vector.create($list)
	EndIf
	Return $vector
EndFunc   ;==>_Dlib_vector

Func _Dlib_vectors()
	Return _Dlib_ObjCreate("VectorOfSpaceVector")
EndFunc   ;==>_Dlib_vectors

Func _Dlib_vectorss()
	Return _Dlib_ObjCreate("VectorOfVectorOfSpaceVector")
EndFunc   ;==>_Dlib_vectorss

Func _Dlib_sparse_vector()
	Return _Dlib_ObjCreate("VectorOfPairOfULONGAndDouble")
EndFunc   ;==>_Dlib_sparse_vector

Func _Dlib_sparse_vectors()
	Return _Dlib_ObjCreate("VectorOfVectorOfPairOfULONGAndDouble")
EndFunc   ;==>_Dlib_sparse_vectors

Func _Dlib_sparse_vectorss()
	Return _Dlib_ObjCreate("VectorOfVectorOfVectorOfPairOfULONGAndDouble")
EndFunc   ;==>_Dlib_sparse_vectorss

Func _Dlib_ranges()
	Return _Dlib_ObjCreate("VectorOfPairOfULONGAndULONG")
EndFunc   ;==>_Dlib_ranges

Func _Dlib_rangess()
	Return _Dlib_ObjCreate("VectorOfVectorOfPairOfULONGAndULONG")
EndFunc   ;==>_Dlib_rangess

Func _Dlib_rectangle($left = 0, $top = 0, $right = 0, $bottom = 0)
	Local $rectangle = _Dlib_ObjCreate("rectangle")

	If @NumParams == 1 Then
		$rectangle = $rectangle.create($left)
	Else
		$rectangle = $rectangle.create($left, $top, $right, $bottom)
	EndIf

	Return $rectangle ;
EndFunc   ;==>_Dlib_rectangle

Func _Dlib_rectangles()
	Return _Dlib_ObjCreate("VectorOfRectangle")
EndFunc   ;==>_Dlib_rectangles

Func _Dlib_drectangle($left = 0, $top = 0, $right = 0, $bottom = 0)
	Local $drectangle = _Dlib_ObjCreate("drectangle")

	If @NumParams == 1 Then
		$drectangle = $drectangle.create($left)
	Else
		$drectangle = $drectangle.create($left, $top, $right, $bottom)
	EndIf

	Return $drectangle ;
EndFunc   ;==>_Dlib_drectangle

Func _Dlib_drectangles()
	Return _Dlib_ObjCreate("VectorOfDrectangle")
EndFunc   ;==>_Dlib_drectangles

Func _Dlib_ranking_pair()
	Return _Dlib_ObjCreate("ranking_pair")
EndFunc   ;==>_Dlib_ranking_pair

Func _Dlib_ranking_pairs()
	Return _Dlib_ObjCreate("VectorOfVec_ranking_pair")
EndFunc   ;==>_Dlib_ranking_pairs

Func _Dlib_sparse_ranking_pair()
	Return _Dlib_ObjCreate("sparse_ranking_pair")
EndFunc   ;==>_Dlib_sparse_ranking_pair

Func _Dlib_sparse_ranking_pairs()
	Return _Dlib_ObjCreate("VectorOfSparse_ranking_pair")
EndFunc   ;==>_Dlib_sparse_ranking_pairs

Func _Dlib_rect_to_bb($rect)
	Local $x = $rect.left()
	Local $y = $rect.top()
	Return _Dlib_Tuple($x, $y, $rect.right() - $x + 1, $rect.bottom() - $y + 1)
EndFunc   ;==>_Dlib_rect_to_bb

Func _Dlib_shape_to_points($shape)
	Local Const $num_parts = $shape.num_parts
	Local $points[$num_parts]
	Local $point
	For $i = 0 To $num_parts - 1
		$point = $shape.part($i)
		$points[$i] = _Dlib_Tuple($point.x, $point.y)
	Next
	Return $points
EndFunc   ;==>_Dlib_shape_to_points

Func _Dlib_ArraySort(ByRef $aArray, $sCompare = Default, $iOrder = Default, $iStart = Default, $iEnd = Default)
	_Dlib_Sort($aArray, "__Dlib_ArraySize", "__Dlib_ArrayGetter", "__Dlib_ArraySetter", $sCompare, $iOrder, $iStart, $iEnd)
EndFunc   ;==>_Dlib_ArraySort

Func _Dlib_VectorSort(ByRef $oVector, $sCompare = Default, $iOrder = Default, $iStart = Default, $iEnd = Default)
	_Dlib_Sort($oVector, "__Dlib_VectorSize", "__Dlib_VectorGetter", "__Dlib_VectorSetter", $sCompare, $iOrder, $iStart, $iEnd)
EndFunc   ;==>_Dlib_VectorSort

; #FUNCTION# ====================================================================================================================
; Name ..........: _Dlib_Sort
; Description ...: Sort a collection using a custom comapator, getter, setter
; Syntax ........: _Dlib_ArraySort(ByRef $aArray[, $sCompare = Default[, $iOrder = Default[, $iStart = Default[,
;                  $iEnd = Default]]]])
; Parameters ....: $aArray              - [in/out] array to sort.
;                  $sGetSize            - [optional] get size function. Default is array UBound
;                  $sGetter             - [optional] getter function. Default is array getter
;                  $sSetter             - [optional] setter function. Default is array setter
;                  $sCompare            - [optional] comparator function. Default is "StringCompare".
;                  $iOrder              - [optional] sorting order. 1 for asc, -1 for desc. Default is 1.
;                  $iStart              - [optional] index of array to start sorting at. Default is 0
;                  $iEnd                - [optional] index of array to stop sorting at (included). Default is UBound($aArray) - 1
; Return values .: None
; Author ........: Stéphane MBAPE
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func _Dlib_Sort(ByRef $aArray, $sGetSize, $sGetter, $sSetter, $sCompare = Default, $iOrder = Default, $iStart = Default, $iEnd = Default)
	Local $iUBound = Call($sGetSize, $aArray) - 1

	If $sCompare == Default Then $sCompare = "StringCompare"
	If $iOrder == Default Then $iOrder = $DLIB_UDF_SORT_ASC
	If $iStart < 0 Or $iStart = Default Then $iStart = 0
	If $iEnd < 1 Or $iEnd > $iUBound Or $iEnd = Default Then $iEnd = $iUBound
	If $iEnd <= $iStart Then Return

	__Dlib_QuickSort($aArray, $sGetter, $sSetter, $sCompare, $iOrder, $iStart, $iEnd)
EndFunc   ;==>_Dlib_Sort

; #FUNCTION# ====================================================================================================================
; Name ..........: __Dlib_QuickSort
; Description ...: Helper function for sorting collections
; Syntax ........: __Dlib_QuickSort(ByRef $aArray, Const ByRef $sCompare, Const ByRef $iStart, Const ByRef $iEnd)
; Parameters ....: $aArray              - [in/out] array to sort.
;                  $sGetter             - [in/out and const] getter function.
;                  $sSetter             - [in/out and const] setter function.
;                  $sCompare            - [in/out and const] comparator function.
;                  $iOrder              - [optional] sorting order. 1 for asc, -1 for desc. Default is 1.
;                  $iStart              - [in/out and const] index of array to start sorting at.
;                  $iEnd                - [in/out and const] index of array to stop sorting at (included).
; Return values .: None
; Author ........: Stéphane MBAPE
; Modified ......:
; Remarks .......: A modified version of Array.au3 __ArrayQuickSort1D
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func __Dlib_QuickSort(ByRef $aArray, Const ByRef $sGetter, Const ByRef $sSetter, Const ByRef $sCompare, Const ByRef $iOrder, Const ByRef $iStart, Const ByRef $iEnd)
	If $iEnd <= $iStart Then Return

	Local $vTmp, $vValue

	; InsertionSort (faster for smaller segments)
	If ($iEnd - $iStart) <= 16 Then
		For $i = $iStart + 1 To $iEnd
			$vTmp = Call($sGetter, $aArray, $i)

			For $j = $i - 1 To $iStart Step -1
				$vValue = Call($sGetter, $aArray, $j)
				If Call($sCompare, $vTmp, $vValue) * $iOrder >= 0 Then ExitLoop
				Call($sSetter, $aArray, $j + 1, $vValue)
			Next

			Call($sSetter, $aArray, $j + 1, $vTmp)
		Next
		Return
	EndIf

	; QuickSort
	Local $L = $iStart, $R = $iEnd, $vPivot = Call($sGetter, $aArray, Int(($iStart + $iEnd) / 2))
	Do
		While Call($sCompare, Call($sGetter, $aArray, $L), $vPivot) * $iOrder < 0
			$L += 1
		WEnd
		While Call($sCompare, Call($sGetter, $aArray, $R), $vPivot) * $iOrder > 0
			$R -= 1
		WEnd

		; Swap
		If $L <= $R Then
			If $L <> $R Then
				$vTmp = Call($sGetter, $aArray, $L)
				Call($sSetter, $aArray, $L, Call($sGetter, $aArray, $R))
				Call($sSetter, $aArray, $R, $vTmp)
			EndIf
			$L += 1
			$R -= 1
		EndIf
	Until $L > $R

	__Dlib_QuickSort($aArray, $sGetter, $sSetter, $sCompare, $iOrder, $iStart, $R)
	__Dlib_QuickSort($aArray, $sGetter, $sSetter, $sCompare, $iOrder, $L, $iEnd)
EndFunc   ;==>__Dlib_QuickSort

Func __Dlib_ArraySize(ByRef $aArray)
	Return UBound($aArray)
EndFunc   ;==>__Dlib_ArraySize

Func __Dlib_ArrayGetter(ByRef $aArray, $i)
	Return $aArray[$i]
EndFunc   ;==>__Dlib_ArrayGetter

Func __Dlib_ArraySetter(ByRef $aArray, $i, $vValue)
	$aArray[$i] = $vValue
EndFunc   ;==>__Dlib_ArraySetter

Func __Dlib_VectorSize(ByRef $oVector)
	Return $oVector.size()
EndFunc   ;==>__Dlib_VectorSize

Func __Dlib_VectorGetter(ByRef $oVector, $i)
	Return $oVector.at($i)
EndFunc   ;==>__Dlib_VectorGetter

Func __Dlib_VectorSetter(ByRef $oVector, $i, $vValue)
	$oVector.at($i, $vValue)
EndFunc   ;==>__Dlib_VectorSetter
