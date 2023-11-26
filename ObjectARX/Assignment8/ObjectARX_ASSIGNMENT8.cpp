// ObjectARX_ASSIGNMENT8.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "ObjectARX_ASSIGNMENT8.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
void CObjectARXASSIGNMENT8App::colorChange() {
    ads_name sset, ename;
    // Prompt the user for objects to modify
    if (acedSSGet(NULL, NULL, NULL, NULL, sset) == RTNORM)
    {
        int lSSCnt = 0;
        acedSSLength(sset, &lSSCnt);
        // Display the number of objects selected
        acutPrintf(_T("\nObjects selected: %i"), lSSCnt);
        TCHAR kWord[30] = _T("");
        TCHAR kDef[30] = _T("Red");
        // Prompt the user for a keyword/option
        acedInitGet(0, _T("1 2 3 Red Yellow Green Bylayer"));
        int retVal = acedGetKword(
            _T("\nEnter a color [Red/Yellow/Green/Bylayer] <Red>: "),
            kWord);
        // User entered a keyword or pressed enter
        if (retVal == RTNORM || retVal == RTNONE)
        {
            // Set the value that should be current
            // if the user presses Enter
            if (retVal == RTNONE)
            {
                wcscpy_s(kWord, kDef);
            }
            // Loop through all the objects
            for (int loopCnt = 0; loopCnt < lSSCnt; loopCnt++)
            {
                // Get the next object from the selection set
                acedSSName(sset, loopCnt, ename);
                // Get the object id for the object
                // from the selection set
                AcDbObjectId objId;
                acdbGetObjectId(objId, ename);
                // Open the object for write
                AcDbEntity* pEnt;
                acdbOpenObject(pEnt, objId, AcDb::kForWrite);
                // Change the object's color based on
                // the keyword entered
                AcCmColor color;
                color.setColorIndex(AcCmEntityColor::kByACI);
                // Determine which color to assign to the object
                if (_tcscmp(kWord, _T("1")) == 0 ||
                    _tcscmp(kWord, _T("Red")) == 0)
                {
                    color.setColorIndex(1);
                }
                else if (_tcscmp(kWord, _T("2")) == 0 ||
                    _tcscmp(kWord, _T("Yellow")) == 0) {
                    color.setColorIndex(2);
                }
                else if (_tcscmp(kWord, _T("3")) == 0 ||
                    _tcscmp(kWord, _T("Green")) == 0) {
                    color.setColorIndex(3);
                }
                else if (_tcscmp(kWord, _T("Bylayer")) == 0) {
                    color.setColorIndex(AcCmEntityColor::kByLayer);
                }
                // Set the color for the object and then close it
                pEnt->setColor(color);
                pEnt->close();
            }
        }
    }
}
extern "C"
int acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt) {
    switch (Msg) {
    case AcRx::kInitAppMsg:acrxUnlockApplication(pkt);
        acrxRegisterAppMDIAware(pkt);
        acutPrintf(L"\n Command Loaded");
        acedRegCmds->addCommand(L"MyGroup", _T("LISTOBJ"), _T("LISTOBJ"), ACRX_CMD_MODAL, &CObjectARXASSIGNMENT8App::colorChange);
        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\n Command unloaded"));
        break;
    }
    return AcRx::kRetOK;


}
//
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

// CObjectARXASSIGNMENT8App

BEGIN_MESSAGE_MAP(CObjectARXASSIGNMENT8App, CWinApp)
END_MESSAGE_MAP()


// CObjectARXASSIGNMENT8App construction

CObjectARXASSIGNMENT8App::CObjectARXASSIGNMENT8App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CObjectARXASSIGNMENT8App object

CObjectARXASSIGNMENT8App theApp;


// CObjectARXASSIGNMENT8App initialization

BOOL CObjectARXASSIGNMENT8App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
