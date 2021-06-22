#if !defined(AFX_YINHANG_H__2BA75B75_58CA_49CC_860F_1BA872F2F285__INCLUDED_)
#define AFX_YINHANG_H__2BA75B75_58CA_49CC_860F_1BA872F2F285__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// YinHang.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CYinHang dialog

class CYinHang : public CDialog
{
// Construction
public:
	CYinHang(CWnd* pParent = NULL);   // standard constructor
	BOOL OnInitDialog();
	void InitCtrl();

// Dialog Data
	//{{AFX_DATA(CYinHang)
	enum { IDD = IDD_DIALOG2 };
	CEdit	m_edit6;
	CButton	m_check1;
	CIPAddressCtrl	m_ip4;
	CIPAddressCtrl	m_ip3;
	CIPAddressCtrl	m_ip2;
	CIPAddressCtrl	m_ip1;
	CEdit	m_edit5;
	CEdit	m_edit4;
	CEdit	m_edit3;
	CEdit	m_edit2;
	CEdit	m_edit1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CYinHang)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CYinHang)
	afx_msg void OnRegBtn();
	afx_msg void OnCheck1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YINHANG_H__2BA75B75_58CA_49CC_860F_1BA872F2F285__INCLUDED_)
