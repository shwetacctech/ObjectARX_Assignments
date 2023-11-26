// ObjectARX_ASSIGNMENT6.h : main header file for the ObjectARX_ASSIGNMENT6 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// CObjectARXASSIGNMENT6App
// See ObjectARX_ASSIGNMENT6.cpp for the implementation of this class
//

class CObjectARXASSIGNMENT6App : public CWinApp
{
public:
	CObjectARXASSIGNMENT6App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void ListObjects();

	DECLARE_MESSAGE_MAP()
};
int AcRxEntryPoint(AcRx::AppMsgCode Msg, void* pkt);