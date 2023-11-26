// ObjectARX_ASSIGNMENT7.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "ObjectARX_ASSIGNMENT7.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
void CObjectARXASSIGNMENT7App::InputLine() {

    // Get the current space block
    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
    AcDbBlockTableRecord* pBlockTableRecord;
    Acad::ErrorStatus es = acdbOpenObject(pBlockTableRecord,
        pDb->currentSpaceId(),
        AcDb::kForWrite);
    // Create 2 variables of the old point data type
    ads_point pt1, pt2;
    // Prompt for the first point
    if (RTNORM == acedGetPoint(NULL, _T("\nSpecify first point: "), pt1))
    {
        AcGePoint3d startPt(pt1[0], pt1[1], pt1[2]);
        // Prompt for the second point
        if (RTNORM == acedGetPoint(pt1,
            _T("\nSpecify second point: "), pt2))
        {
            AcGePoint3d endPt(pt2[0], pt2[1], pt2[2]);
            // Create and append the new Line object
            AcDbLine* pLine = new AcDbLine(startPt, endPt);
            pBlockTableRecord->appendAcDbEntity(pLine);
            // Close the block table record and the Line object
            pBlockTableRecord->close();
            pLine->close();
        }
    }
}
extern "C"
int acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt) {
    switch (Msg) {
    case AcRx::kInitAppMsg:acrxUnlockApplication(pkt);
        acrxRegisterAppMDIAware(pkt);
        acutPrintf(L"\n Command Loaded");
        acedRegCmds->addCommand(L"MyGroup", _T("LISTOBJ"), _T("LISTOBJ"), ACRX_CMD_MODAL, &CObjectARXASSIGNMENT7App::InputLine);
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

// CObjectARXASSIGNMENT7App

BEGIN_MESSAGE_MAP(CObjectARXASSIGNMENT7App, CWinApp)
END_MESSAGE_MAP()


// CObjectARXASSIGNMENT7App construction

CObjectARXASSIGNMENT7App::CObjectARXASSIGNMENT7App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CObjectARXASSIGNMENT7App object

CObjectARXASSIGNMENT7App theApp;


// CObjectARXASSIGNMENT7App initialization

BOOL CObjectARXASSIGNMENT7App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
