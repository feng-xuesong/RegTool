// RegTool.h : main header file for the REGTOOL application
//

#if !defined(AFX_REGTOOL_H__FD2DAFDD_81C9_48D4_9027_C0C4C05F59CF__INCLUDED_)
#define AFX_REGTOOL_H__FD2DAFDD_81C9_48D4_9027_C0C4C05F59CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

extern char g_appPath[MAX_PATH];

/////////////////////////////////////////////////////////////////////////////
// CRegToolApp:
// See RegTool.cpp for the implementation of this class
//

class CRegToolApp : public CWinApp
{
public:
	CRegToolApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegToolApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRegToolApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGTOOL_H__FD2DAFDD_81C9_48D4_9027_C0C4C05F59CF__INCLUDED_)
