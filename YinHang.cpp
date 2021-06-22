// YinHang.cpp : implementation file
//

#include "stdafx.h"
#include "RegTool.h"
#include "YinHang.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CYinHang dialog


CYinHang::CYinHang(CWnd* pParent /*=NULL*/)
	: CDialog(CYinHang::IDD, pParent)
{
	//{{AFX_DATA_INIT(CYinHang)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CYinHang::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CYinHang)
	DDX_Control(pDX, IDC_EDIT6, m_edit6);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	DDX_Control(pDX, IDC_IPADDRESS4, m_ip4);
	DDX_Control(pDX, IDC_IPADDRESS3, m_ip3);
	DDX_Control(pDX, IDC_IPADDRESS2, m_ip2);
	DDX_Control(pDX, IDC_IPADDRESS1, m_ip1);
	DDX_Control(pDX, IDC_EDIT5, m_edit5);
	DDX_Control(pDX, IDC_EDIT4, m_edit4);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CYinHang, CDialog)
	//{{AFX_MSG_MAP(CYinHang)
	ON_BN_CLICKED(IDC_BUTTON2, OnRegBtn)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CYinHang message handlers
BOOL CYinHang::OnInitDialog()
{
	CDialog::OnInitDialog();
	InitCtrl();
	return TRUE;
}

void CYinHang::InitCtrl()
{
	char vfj[260] = {0};
	sprintf(vfj, "%s", ".\\vfj.ini");

	char ip[20] = {0};
	char port[10] = {0};
	char com[3] = {0};
	char netId[15] = {0};
	char flag[2] = {0};

	//[VFJ]
	::GetPrivateProfileString("server", "ip", "", ip, 20, vfj);
	::GetPrivateProfileString("server", "port", "", port, 10, vfj);
	::GetPrivateProfileString("server", "comm", "", com, 3, vfj);
	GetConf("net_id", netId);

	m_ip1.SetWindowText(ip);
	m_edit1.SetWindowText(port);
	m_edit5.SetWindowText(com);
	m_edit6.SetWindowText(netId);

	//[FTP]
	::GetPrivateProfileString("ftp", "ip", "", ip, 20, vfj);
	::GetPrivateProfileString("ftp", "port", "", port, 10, vfj);
	m_ip2.SetWindowText(ip);
	m_edit2.SetWindowText(port);

	//[SOCKET]
	::GetPrivateProfileString("socket", "ip", "", ip, 20, vfj);
	::GetPrivateProfileString("socket", "port", "", port, 10, vfj);
	m_ip3.SetWindowText(ip);
	m_edit3.SetWindowText(port);

	//[CHARGE]
	::GetPrivateProfileString("charge", "ip", "", ip, 20, vfj);
	::GetPrivateProfileString("charge", "port", "", port, 10, vfj);
	m_ip4.SetWindowText(ip);
	m_edit4.SetWindowText(port);

	::GetPrivateProfileString("charge", "flag", "", flag, 2, vfj);
	if(strncmp(flag, "1", 1) == 0)
	{
		m_check1.SetCheck(1);
		m_ip4.EnableWindow(true);
		m_edit4.EnableWindow(true);
	}
	else
	{
		m_check1.SetCheck(0);
		m_ip4.EnableWindow(false);
		m_edit4.EnableWindow(false);
	}
}

void CYinHang::OnRegBtn() 
{
	char vfj[260] = {0};
	sprintf(vfj, "%s", ".\\vfj.ini");

	char config[260] = {0};
	sprintf(config, "%s", ".\\config.txt");

	CString str;

	char serv_Ip[20] = {0};
	char serv_Port[10] = {0};
	char net_Id[15] = {0};
	char szTmp[200] = {0};
	
	//vfj
	m_ip1.GetWindowText(str);
	::WritePrivateProfileString("server", "ip", str.GetBuffer(0), vfj);
	sprintf(serv_Ip, "%s", str.GetBuffer(0));

	m_edit1.GetWindowText(str);
	::WritePrivateProfileString("server", "port", str.GetBuffer(0), vfj);
	sprintf(serv_Port, "%s", str.GetBuffer(0));

	m_edit5.GetWindowText(str);
	::WritePrivateProfileString("server", "comm", str.GetBuffer(0), vfj);

	m_edit6.GetWindowText(str);
	sprintf(net_Id, "%s", str.GetBuffer(0));

	sprintf(szTmp, "serv_Ip=%s\nserv_Port=%s\nnet_id=%s\nter_id=%s0001\norg_id=01\n", serv_Ip, serv_Port, net_Id, net_Id);
	WriteConf(szTmp);

	//ftp
	m_ip2.GetWindowText(str);
	::WritePrivateProfileString("ftp", "ip", str.GetBuffer(0), vfj);

	m_edit2.GetWindowText(str);
	::WritePrivateProfileString("ftp", "port", str.GetBuffer(0), vfj);

	//socket
	m_ip3.GetWindowText(str);
	::WritePrivateProfileString("socket", "ip", str.GetBuffer(0), vfj);

	m_edit3.GetWindowText(str);
	::WritePrivateProfileString("socket", "port", str.GetBuffer(0), vfj);

	//charge
	m_ip4.GetWindowText(str);
	::WritePrivateProfileString("charge", "ip", str.GetBuffer(0), vfj);
	m_edit4.GetWindowText(str);
	::WritePrivateProfileString("charge", "port", str.GetBuffer(0), vfj);

	if(m_check1.GetCheck())
	{
		::WritePrivateProfileString("charge", "flag", "1", vfj);
	}
	else
	{
		::WritePrivateProfileString("charge", "flag", "0", vfj);
	}

	WinExec("setup.bat", SW_HIDE);
}

void CYinHang::OnCheck1() 
{
	if(m_check1.GetCheck())
	{
		m_ip4.EnableWindow(true);
		m_edit4.EnableWindow(true);
	}
	else
	{
		m_ip4.EnableWindow(false);
		m_edit4.EnableWindow(false);
	}
}
