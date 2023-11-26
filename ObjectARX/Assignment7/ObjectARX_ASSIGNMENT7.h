// ObjectARX_ASSIGNMENT7.h : main header file for the ObjectARX_ASSIGNMENT7 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// CObjectARXASSIGNMENT7App
// See ObjectARX_ASSIGNMENT7.cpp for the implementation of this class
//

class CObjectARXASSIGNMENT7App : public CWinApp
{
public:
	CObjectARXASSIGNMENT7App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void InputLine();
	DECLARE_MESSAGE_MAP()
};
int AcRxEntryPoint(AcRx::AppMsgCode Msg, void* pkt);