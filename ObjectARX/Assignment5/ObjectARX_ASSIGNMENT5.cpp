// ObjectARX_ASSIGNMENT5.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "ObjectARX_ASSIGNMENT5.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
void CObjectARXASSIGNMENT5App::addLayer() {
    // Open the Layer table for read
    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
    AcDbLayerTable* pLayerTable;
    pDb->getLayerTable(pLayerTable, AcDb::kForRead);
    // Check to see if the layer exists
    if (pLayerTable->has(_T("OBJ")) == false)
    {
        // Open the Layer table for write
        pLayerTable->upgradeOpen();
        // Create the new layer and assign it the name 'OBJ'
        AcDbLayerTableRecord* pLayerTableRecord =
            new AcDbLayerTableRecord();
        pLayerTableRecord->setName(_T("OBJ"));
        // Set the color of the layer to cyan
        AcCmColor color;
        color.setColorIndex(4);
        pLayerTableRecord->setColor(color);
        // Add the new layer to the Layer table
        pLayerTable->add(pLayerTableRecord);
        // Close the Layer table and record
        pLayerTable->close();
        pLayerTableRecord->close();
    }
}
extern "C"
int acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt) {
    switch (Msg) {
    case AcRx::kInitAppMsg:acrxUnlockApplication(pkt);
        acrxRegisterAppMDIAware(pkt);
        acutPrintf(L"\n Command Loaded");
        acedRegCmds->addCommand(L"MyGroup", _T("ADDLAYER"), _T("ADDLAYER"), ACRX_CMD_MODAL, &CObjectARXASSIGNMENT5App::addLayer);
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

// CObjectARXASSIGNMENT5App

BEGIN_MESSAGE_MAP(CObjectARXASSIGNMENT5App, CWinApp)
END_MESSAGE_MAP()


// CObjectARXASSIGNMENT5App construction

CObjectARXASSIGNMENT5App::CObjectARXASSIGNMENT5App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CObjectARXASSIGNMENT5App object

CObjectARXASSIGNMENT5App theApp;


// CObjectARXASSIGNMENT5App initialization

BOOL CObjectARXASSIGNMENT5App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
