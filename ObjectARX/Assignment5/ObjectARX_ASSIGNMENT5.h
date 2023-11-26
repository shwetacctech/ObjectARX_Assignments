// ObjectARX_ASSIGNMENT5.h : main header file for the ObjectARX_ASSIGNMENT5 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>


// CObjectARXASSIGNMENT5App
// See ObjectARX_ASSIGNMENT5.cpp for the implementation of this class
//

class CObjectARXASSIGNMENT5App : public CWinApp
{
public:
	CObjectARXASSIGNMENT5App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void addLayer();

	DECLARE_MESSAGE_MAP()
};
int AcRxEntryPoint(AcRx::AppMsgCode Msg, void* pkt);