// ObjectARX_ASSIGNMENT.h : main header file for the ObjectARX_ASSIGNMENT DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif
//adding the precompilation header files here
#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// CObjectARXASSIGNMENTApp
// See ObjectARX_ASSIGNMENT.cpp for the implementation of this class
//

class CObjectARXASSIGNMENTApp : public CWinApp
{
public:
	CObjectARXASSIGNMENTApp();

// Overrides
public:
	virtual BOOL InitInstance();
	static void addLine();

	DECLARE_MESSAGE_MAP()
};
int AcRxEntryPoint(AcRx::AppMsgCode Msg, void* pkt);