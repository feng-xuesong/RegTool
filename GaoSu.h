#if !defined(AFX_GAOSU_H__404854BA_46C9_4CE5_8711_095522A2E4D2__INCLUDED_)
#define AFX_GAOSU_H__404854BA_46C9_4CE5_8711_095522A2E4D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GaoSu.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CGaoSu dialog

class CGaoSu : public CDialog
{
// Construction
public:
	CGaoSu(CWnd* pParent = NULL);   // standard constructor
	BOOL OnInitDialog();
	void InitComb();
// Dialog Data
	//{{AFX_DATA(CGaoSu)
	enum { IDD = IDD_DIALOG1 };
	CComboBox	m_comb3;
	CComboBox	m_comb2;
	CComboBox	m_comb1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGaoSu)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGaoSu)
	afx_msg void OnRegBtn();
	afx_msg void OnSelchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAOSU_H__404854BA_46C9_4CE5_8711_095522A2E4D2__INCLUDED_)
