#include-once

#include "dlib_udf.au3"

#include <GDIPlus.au3>
#include <Math.au3>
#include <StaticConstants.au3>
#include <WindowsConstants.au3>
#include <WinAPI.au3>

Global Const $DLIB_UDF_SORT_ASC = 1
Global Const $DLIB_UDF_SORT_DESC = -1

Func _Dlib_FindDLL($sFile, $sFilter = Default, $sDir = Default, $bReverse = Default)
	Local $_dlib_build_type = EnvGet("DLIB_BUILD_TYPE")
	Local $sBuildType = $_dlib_build_type == "Debug" ? "Debug" : "Release"
	Local $sPostfix = $_dlib_build_type == "Debug" ? "d" : ""

	Local $aSearchPaths[] = [ _
			".", _
			"autoit-dlib-com", _
			"autoit-dlib-com\build_x64\bin\" & $sBuildType, _
			"autoit-opencv-com", _
			"autoit-opencv-com\build_x64\bin\" & $sBuildType, _
			"opencv\build\x64\vc16\bin", _
			"opencv-4.11.0-*\build\x64\vc16\bin", _
			"opencv-4.11.0-*\opencv\build\x64\vc16\bin" _
			]

	Return _Dlib_FindFile($sFile & $sPostfix & ".dll", $sFilter, $sDir, $FLTA_FILES, $aSearchPaths, $bReverse)
EndFunc   ;==>_Dlib_FindDLL

; #FUNCTION# ====================================================================================================================
; Name ..........: _Dlib_GetDevices
; Description ...: Return devices
; Syntax ........: _Dlib_GetDevices([$iDeviceCategory = Default])
; Parameters ....: $iDeviceCategory     - [optional] device type to return. Default is 2.
;                                         $iDeviceCategory = 0 : Audio and Video devices
;                                         $iDeviceCategory = 1 : Audio devices
;                                         $iDeviceCategory = 2 : Video devices
; Return values .: None
; Author ........: Your Name
; Modified ......:
; Remarks .......:
; Related .......:
; Link ..........:
; Example .......: No
; ===============================================================================================================================
Func _Dlib_GetDevices($iDeviceCategory = Default)
	Local $devices = _Dlib_ObjCreate("VectorOfString")

	If $iDeviceCategory == 0 Then
		$devices.push_vector(_Dlib_GetDevices(1))
		$devices.push_vector(_Dlib_GetDevices(2))
		Return $devices
	EndIf

	;===============================================================================
	#interface "ICreateDevEnum"
	Local Static $sCLSID_SystemDeviceEnum = '{62BE5D10-60EB-11D0-BD3B-00A0C911CE86}'
	Local Static $sIID_ICreateDevEnum = '{29840822-5B84-11D0-BD3B-00A0C911CE86}'
	Local Static $tagICreateDevEnum = "CreateClassEnumerator hresult(clsid;ptr*;dword);"
	;===============================END=============================================

	;===============================================================================
	#interface "IEnumMoniker"
	Local Static $sIID_IEnumMoniker = '{00000102-0000-0000-C000-000000000046}'
	Local Static $tagIEnumMoniker = "Next hresult(dword;ptr*;dword*);" & _
			"Skip hresult(dword);" & _
			"Reset hresult();" & _
			"Clone hresult(ptr*);"
	;===============================END=============================================

	;===============================================================================
	#interface "IMoniker"
	Local Static $sIID_IMoniker = '{0000000F-0000-0000-C000-000000000046}'
	Local Static $tagIMoniker = "GetClassID hresult( clsid )" & _
			"IsDirty hresult(  );" & _
			"Load hresult( ptr );" & _
			"Save hresult( ptr, bool );" & _
			"GetSizeMax hresult( uint64 );" & _
			"BindToObject hresult( ptr;ptr;clsid;ptr*);" & _
			"BindToStorage hresult( ptr;ptr;clsid;ptr*);" & _
			"Reduce hresult( ptr;dword;ptr*;ptr*);" & _
			"ComposeWith hresult( ptr;bool;ptr*);" & _
			"Enum hresult( bool;ptr*);" & _
			"IsEqual hresult( ptr);" & _
			"Hash hresult( dword);" & _
			"IsRunning hresult( ptr;ptr;ptr);" & _
			"GetTimeOfLastChange hresult( ptr;ptr;uint64);" & _
			"Inverse hresult( ptr*);" & _
			"CommonPrefixWith hresult( ptr;ptr*);" & _
			"RelativePathTo hresult( ptr;ptr*);" & _
			"GetDisplayName hresult( ptr;ptr;ushort);" & _
			"ParseDisplayName hresult( ptr;ptr;ushort;ulong;ptr*);" & _
			"IsSystemMoniker hresult( dword);"
	;===============================END=============================================

	;===============================================================================
	#interface "IPropertyBag"
	Local Static $sIID_IPropertyBag = '{55272A00-42CB-11CE-8135-00AA004BB851}'
	Local Static $tagIPropertyBag = "Read hresult( wstr;variant*;ptr* );" & _
			"Write hresult( wstr;variant );"
	;===============================END=============================================

	Local Static $S_FALSE = 1
	Local Static $VFW_E_NOT_FOUND = 0x80040216
	Local Static $sCLSID_AudioInputDeviceCategory = '{33D9A762-90C8-11D0-BD43-00A0C911CE86}'
	Local Static $sCLSID_VideoInputDeviceCategory = '{860BB310-5D01-11D0-BD3B-00A0C911CE86}'

	Local $sCLSID_category = $iDeviceCategory == 1 ? $sCLSID_AudioInputDeviceCategory : $sCLSID_VideoInputDeviceCategory

	;  // Create a helper object To find the capture device.
	;  hr = CoCreateInstance(CLSID_SystemDeviceEnum, Null, CLSCTX_INPROC_SERVER, IID_ICreateDevEnum, (LPVOID *) & pDevEnum);
	Local $oDevEnum = ObjCreateInterface($sCLSID_SystemDeviceEnum, $sIID_ICreateDevEnum, $tagICreateDevEnum)
	If Not IsObj($oDevEnum) Then
		ConsoleWriteError('@@ Debug(' & @ScriptLineNumber & ') : Failed to create SystemDeviceEnum' & @CRLF)
		Return $devices
	EndIf

	; IEnumMoniker *pEnum = 0;
	; hr = pDevEnum->CreateClassEnumerator(CLSID_category, &pEnum, 0);
	Local $pEnum = 0
	Local $hr = $oDevEnum.CreateClassEnumerator($sCLSID_category, $pEnum, 0)
	If $hr == $S_FALSE Then
		$hr = $VFW_E_NOT_FOUND ; The category is empty. Treat as an error.
	EndIf

	If $hr < 0 Then
		ConsoleWriteError('@@ Debug(' & @ScriptLineNumber & ') : Failed to create the device enumerator' & @CRLF)
		Return $devices
	EndIf

	Local $oEnum = ObjCreateInterface(Ptr($pEnum), $sIID_IEnumMoniker, $tagIEnumMoniker)
	If Not IsObj($oEnum) Then
		ConsoleWriteError('@@ Debug(' & @ScriptLineNumber & ') : Failed to enumerate devices' & @CRLF)
	EndIf

	; IMoniker *pMoniker = 0;
	Local $pMoniker, $oMoniker, $pPropBag, $oPropBag, $var

	; while (pEnum->Next(1, &pMoniker, NULL) == S_OK) {
	While $oEnum.Next(1, $pMoniker, 0) == $S_OK
		$oMoniker = ObjCreateInterface($pMoniker, $sIID_IMoniker, $tagIMoniker)
		If Not IsObj($oMoniker) Then
			ConsoleWriteError('@@ Debug(' & @ScriptLineNumber & ') : Failed to get device' & @CRLF)
			ContinueLoop
		EndIf

		; HRESULT hr = pMoniker->BindToStorage(0, 0, IID_PPV_ARGS(&pPropBag));
		$hr = $oMoniker.BindToStorage(0, 0, $sIID_IPropertyBag, $pPropBag)
		If $hr < 0 Then
			ConsoleWriteError('@@ Debug(' & @ScriptLineNumber & ') : Failed bind device properties' & @CRLF)
			ContinueLoop
		EndIf

		$oPropBag = ObjCreateInterface($pPropBag, $sIID_IPropertyBag, $tagIPropertyBag)
		If Not IsObj($oPropBag) Then
			ConsoleWriteError('@@ Debug(' & @ScriptLineNumber & ') : Failed to get device properties' & @CRLF)
			ContinueLoop
		EndIf

		; hr = pPropBag->Read(L"Description", &var, 0);
		$hr = $oPropBag.Read('Description', $var, 0)
		If $hr < 0 Then
			; hr = pPropBag->Read(L"FriendlyName", &var, 0);
			$hr = $oPropBag.Read('FriendlyName', $var, 0)
		EndIf

		If $hr < 0 Then
			ConsoleWriteError('@@ Debug(' & @ScriptLineNumber & ') : Failed get device FriendlyName' & @CRLF)
			ContinueLoop
		EndIf

		$devices.Add($var)
	WEnd

	Return $devices
EndFunc   ;==>_Dlib_GetDevices

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
