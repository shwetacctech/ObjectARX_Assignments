// ObjectARX_ASSIGNMENT11.h : main header file for the ObjectARX_ASSIGNMENT11 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>
#include "acedCmdNF.h"
// CObjectARXASSIGNMENT11App
// See ObjectARX_ASSIGNMENT11.cpp for the implementation of this class
//

class CObjectARXASSIGNMENT11App : public CWinApp
{
public:
	CObjectARXASSIGNMENT11App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void customSysvar();
	DECLARE_MESSAGE_MAP()
};
int AcRxEntryPoint(AcRx::AppMsgCode Msg, void* pkt);