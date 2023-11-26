// ObjectARX_ASSIGNMENT6.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "ObjectARX_ASSIGNMENT6.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
void CObjectARXASSIGNMENT6App::ListObjects() {
    // Get the current database
    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
    // Get the current space object
    AcDbBlockTableRecord* pBlockTableRecord;
    Acad::ErrorStatus es = acdbOpenObject(pBlockTableRecord,
        pDb->currentSpaceId(),
        AcDb::kForRead);
    // Create a new block iterator that will be used to
    // step through each object in the current space
    AcDbBlockTableRecordIterator* pItr;
    pBlockTableRecord->newIterator(pItr);
    // Create a variable AcDbEntity type which is a generic
    // object to represent a Line, Circle, Arc, among other objects
    AcDbEntity* pEnt;
    // Step through each object in the current space
    for (pItr->start(); !pItr->done(); pItr->step())
    {
        // Get the entity and open it for read
        pItr->getEntity(pEnt, AcDb::kForRead);
        // Display the class name for the entity before
        // closing the object
        acutPrintf(_T("\nClass name: %s"), pEnt->isA()->name());
        pEnt->close();
    }
    // Close the current space object
    pBlockTableRecord->close();
    // Remove the block iterator object from memory
    delete pItr;
    // Display the AutoCAD Text Window
    acedTextScr();
}
extern "C"
int acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt) {
    switch (Msg) {
    case AcRx::kInitAppMsg:acrxUnlockApplication(pkt);
        acrxRegisterAppMDIAware(pkt);
        acutPrintf(L"\n Command Loaded");
        acedRegCmds->addCommand(L"MyGroup", _T("LISTOBJ"), _T("LISTOBJ"), ACRX_CMD_MODAL, &CObjectARXASSIGNMENT6App::ListObjects);
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

// CObjectARXASSIGNMENT6App

BEGIN_MESSAGE_MAP(CObjectARXASSIGNMENT6App, CWinApp)
END_MESSAGE_MAP()


// CObjectARXASSIGNMENT6App construction

CObjectARXASSIGNMENT6App::CObjectARXASSIGNMENT6App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CObjectARXASSIGNMENT6App object

CObjectARXASSIGNMENT6App theApp;


// CObjectARXASSIGNMENT6App initialization

BOOL CObjectARXASSIGNMENT6App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
