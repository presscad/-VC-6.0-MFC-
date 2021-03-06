// TeacherCheckIn.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "TeacherCheckIn.h"
#include "TeacherCheckInDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTeacherCheckInApp

BEGIN_MESSAGE_MAP(CTeacherCheckInApp, CWinApp)
	//{{AFX_MSG_MAP(CTeacherCheckInApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTeacherCheckInApp construction

CTeacherCheckInApp::CTeacherCheckInApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTeacherCheckInApp object

CTeacherCheckInApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTeacherCheckInApp initialization

BOOL CTeacherCheckInApp::InitInstance()
{
	AfxEnableControlContainer();
    //初始换comm环境,创建ADO连接
	AfxOleInit();
	//CoInitialize(NULL);
	m_pConnection.CreateInstance(__uuidof(Connection));
	try
	{
		
		m_pConnection->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=TeacherLogIn.mdb","","",adModeUnknown);
	}
	catch(_com_error e)
	{	
		AfxMessageBox("数据库连接失败,确定数据库TeacherLogIn.mdb是否在当前目录中");
		return FALSE;
	}
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CTeacherCheckInDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return TRUE;
}

int CTeacherCheckInApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_pConnection->GetState())
	{
		m_pConnection->Close();
		m_pConnection = NULL;
	}
	return CWinApp::ExitInstance();
}
