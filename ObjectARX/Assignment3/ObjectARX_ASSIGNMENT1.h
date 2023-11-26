// ObjectARX_ASSIGNMENT1.h : main header file for the ObjectARX_ASSIGNMENT1 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// CObjectARXASSIGNMENT1App
// See ObjectARX_ASSIGNMENT1.cpp for the implementation of this class
//

class CObjectARXASSIGNMENT1App : public CWinApp
{
public:
	CObjectARXASSIGNMENT1App();

// Overrides
public:
	virtual BOOL InitInstance();

	static void	GrretUser();

	DECLARE_MESSAGE_MAP()
};
int AcRxEntryPoint(AcRx::AppMsgCode Msg, void* pkt);

