// ObjectARX_ASSIGNMENT12.h : main header file for the ObjectARX_ASSIGNMENT12 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// CObjectARXASSIGNMENT12App
// See ObjectARX_ASSIGNMENT12.cpp for the implementation of this class
//

class CObjectARXASSIGNMENT12App : public CWinApp
{
public:
	CObjectARXASSIGNMENT12App();

// Overrides
public:
	virtual BOOL InitInstance();

	static void userInfo();

	DECLARE_MESSAGE_MAP()
};
int AcRxEntryPoint(AcRx::AppMsgCode Msg, void* pkt);
