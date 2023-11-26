// ObjectARX_ASSIGNMENT1.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "ObjectARX_ASSIGNMENT1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
void CObjectARXASSIGNMENT1App::GrretUser() {
	acutPrintf(_T("Hello user, Welcome to autocad"));
}
extern "C"
int acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt) {
    switch (Msg) {
    case AcRx::kInitAppMsg:acrxUnlockApplication(pkt);
        acrxRegisterAppMDIAware(pkt);
        acutPrintf(L"\n Command Loaded");
        acedRegCmds->addCommand(L"MyGroup", _T("GREET"), _T("GREET"), ACRX_CMD_MODAL, &CObjectARXASSIGNMENT1App::GrretUser);
        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\n Command unloaded"));
        break;
    }
    return AcRx::kRetOK;


}
//S
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CObjectARXASSIGNMENT1App

BEGIN_MESSAGE_MAP(CObjectARXASSIGNMENT1App, CWinApp)
END_MESSAGE_MAP()


// CObjectARXASSIGNMENT1App construction

CObjectARXASSIGNMENT1App::CObjectARXASSIGNMENT1App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CObjectARXASSIGNMENT1App object

CObjectARXASSIGNMENT1App theApp;


// CObjectARXASSIGNMENT1App initialization

BOOL CObjectARXASSIGNMENT1App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
