// RegToolDlg.h : header file
//

#if !defined(AFX_REGTOOLDLG_H__E6585E6A_D450_4998_9C2F_FCD8FDA6390D__INCLUDED_)
#define AFX_REGTOOLDLG_H__E6585E6A_D450_4998_9C2F_FCD8FDA6390D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GaoSu.h"
#include "YinHang.h"
/////////////////////////////////////////////////////////////////////////////
// CRegToolDlg dialog

class CRegToolDlg : public CDialog
{
// Construction
public:
	CRegToolDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRegToolDlg)
	enum { IDD = IDD_REGTOOL_DIALOG };
	CTabCtrl	m_tab1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegToolDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRegToolDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CGaoSu m_gs;
	CYinHang m_yh;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGTOOLDLG_H__E6585E6A_D450_4998_9C2F_FCD8FDA6390D__INCLUDED_)
