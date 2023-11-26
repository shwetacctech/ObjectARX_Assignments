// ObjectARX_ASSIGNMENT8.h : main header file for the ObjectARX_ASSIGNMENT8 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>


// CObjectARXASSIGNMENT8App
// See ObjectARX_ASSIGNMENT8.cpp for the implementation of this class
//

class CObjectARXASSIGNMENT8App : public CWinApp
{
public:
	CObjectARXASSIGNMENT8App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void colorChange();

	DECLARE_MESSAGE_MAP()
};
int AcRxEntryPoint(AcRx::AppMsgCode Msg, void* pkt);