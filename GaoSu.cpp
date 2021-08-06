// GaoSu.cpp : implementation file
//

#include "stdafx.h"
#include "RegTool.h"
#include "GaoSu.h"
#include "io.h"
#include "RegToolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGaoSu dialog


CGaoSu::CGaoSu(CWnd* pParent /*=NULL*/)
	: CDialog(CGaoSu::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGaoSu)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CGaoSu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGaoSu)
	DDX_Control(pDX, IDC_COMBO3, m_comb3);
	DDX_Control(pDX, IDC_COMBO2, m_comb2);
	DDX_Control(pDX, IDC_COMBO1, m_comb1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGaoSu, CDialog)
	//{{AFX_MSG_MAP(CGaoSu)
	ON_BN_CLICKED(IDC_BUTTON3, OnRegBtn)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CGaoSu::OnInitDialog()
{
	CDialog::OnInitDialog();
	InitComb();
	return TRUE;
}

void CGaoSu::InitComb()
{
	char reg[MAX_PATH] = {0};
	char vfj[MAX_PATH] = {0};

	if(_access("C:\\HpTmp\\reg.ini", 0) == 0)
	{
		sprintf(reg, "%s", "C:\\HpTmp\\reg.ini");
	}
	else
	{
		sprintf(reg, "%s", ".\\reg.ini");
	}
	
	sprintf(vfj, "%s", ".\\vfj.ini");
	
	char net[MAX_PATH] = {0};
	char ip1[MAX_PATH] = {0};
	char ip2[MAX_PATH] = {0};
	char com[MAX_PATH] = {0};
	char port[MAX_PATH] = {0};
	char netId[MAX_PATH] = {0};

	/***** SERVER *****/
	int pos = -1;
	m_comb1.ResetContent();
	::GetPrivateProfileString("vfj", "Nets", "", net, MAX_PATH, reg);
	::GetPrivateProfileString("server", "ip", "", ip1, MAX_PATH, vfj);

	char *p = strtok(net, "|");
	int i = 0;
	while(p != NULL)
	{
		m_comb1.InsertString(i, p);

		::GetPrivateProfileString("vfj", p, "", ip2, MAX_PATH, reg);
		if(strcmp(ip1, ip2) == 0)
		{	
			pos = i;
		}

		i++;
		p = strtok(NULL, "|");
	}
	m_comb1.SetCurSel(pos);

	::GetPrivateProfileString("server", "comm", "", com, MAX_PATH, vfj);
	GetDlgItem(IDC_EDIT2)->SetWindowText(com);

	::GetPrivateProfileString("server", "port", "", port, MAX_PATH, vfj);
	GetDlgItem(IDC_EDIT3)->SetWindowText(port);

	GetConf("net_id", netId);
	GetDlgItem(IDC_EDIT4)->SetWindowText(netId);

	/***** FTP *****/
	//ip
	pos = -1;
	m_comb2.ResetContent();
	::GetPrivateProfileString("ftp", "Nets", "", net, MAX_PATH, reg);
	::GetPrivateProfileString("ftp", "ip", "", ip1, MAX_PATH, vfj);

	p = strtok(net, "|");
	i = 0;
	while(p != NULL)
	{
		m_comb2.InsertString(i, p);

		::GetPrivateProfileString("ftp", p, "", ip2, MAX_PATH, reg);
		if(strcmp(ip1, ip2) == 0)
		{	
			pos = i;
		}

		i++;
		p = strtok(NULL, "|");
	}
	m_comb2.SetCurSel(pos);

	//port
	char fPort[MAX_PATH] = {0};
	::GetPrivateProfileString("ftp", "port", "", fPort, MAX_PATH, vfj);
	GetDlgItem(IDC_EDIT7)->SetWindowText(fPort);

	/***** SOCKET *****/
	pos = -1;
	m_comb3.ResetContent();
	::GetPrivateProfileString("socket", "Nets", "", net, MAX_PATH, reg);
	::GetPrivateProfileString("socket", "ip", "", ip1, MAX_PATH, vfj);

	p = strtok(net, "|");
	i = 0;
	while(p != NULL)
	{
		m_comb3.InsertString(i, p);

		::GetPrivateProfileString("socket", p, "", ip2, MAX_PATH, reg);
		if(strcmp(ip1, ip2) == 0)
		{	
			pos = i;
		}

		i++;
		p = strtok(NULL, "|");
	}
	m_comb3.SetCurSel(pos);

	//port
	char sPort[MAX_PATH] = {0};
	::GetPrivateProfileString("socket", "port", "", sPort, MAX_PATH, vfj);
	GetDlgItem(IDC_EDIT8)->SetWindowText(sPort);
}

/////////////////////////////////////////////////////////////////////////////
// CGaoSu message handlers

void CGaoSu::OnRegBtn() 
{
	char ip[MAX_PATH] = {0};
	char szTmp[MAX_PATH] = {0};
	char vfj[MAX_PATH] = {0};
	char reg[MAX_PATH] = {0};

	sprintf(vfj, "%s", ".\\vfj.ini");
	sprintf(reg, "%s", ".\\reg.ini");

	char serv_Ip[MAX_PATH] = {0};
	char serv_Port[MAX_PATH] = {0};
	char net_Id[MAX_PATH] = {0};

	//server
	CString str;
	m_comb1.GetWindowText(str);
	::GetPrivateProfileString("vfj", str.GetBuffer(0), "", ip, MAX_PATH, reg);
	::WritePrivateProfileString("server", "ip", ip, vfj);
	sprintf(serv_Ip, "%s", ip);

	GetDlgItem(IDC_EDIT3)->GetWindowText(str);
	::WritePrivateProfileString("server", "port", str.GetBuffer(0), vfj);
	sprintf(serv_Port, "%s", str.GetBuffer(0));

	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	::WritePrivateProfileString("server", "comm", str.GetBuffer(0), vfj);

	GetDlgItem(IDC_EDIT4)->GetWindowText(str);
	sprintf(net_Id, "%s", str.GetBuffer(0));

	sprintf(szTmp, "serv_Ip=%s\nserv_Port=%s\nnet_id=%s\nter_id=%s0001\norg_id=01\n", serv_Ip, serv_Port, net_Id, net_Id);
	WriteConf(szTmp);

	//ftp
	m_comb2.GetWindowText(str);
	::GetPrivateProfileString("ftp", str.GetBuffer(0), "", ip, MAX_PATH, reg);
	::WritePrivateProfileString("ftp", "ip", ip, vfj);

	GetDlgItem(IDC_EDIT7)->GetWindowText(str);
	::WritePrivateProfileString("ftp", "port", str.GetBuffer(0), vfj);

	//socket
	m_comb3.GetWindowText(str);
	::GetPrivateProfileString("socket", str.GetBuffer(0), "", ip, MAX_PATH, reg);
	::WritePrivateProfileString("socket", "ip", ip, vfj);

	GetDlgItem(IDC_EDIT8)->GetWindowText(str);
	::WritePrivateProfileString("socket", "port", str.GetBuffer(0), vfj);

	//charge
	::WritePrivateProfileString("charge", "flag", "0", vfj);

	WinExec("setup.bat", SW_HIDE);
}

void CGaoSu::OnSelchangeCombo1() 
{
	CString str;
	m_comb1.GetLBText(m_comb1.GetCurSel(), str);

	int pos = m_comb2.SelectString(0, str);
	if(pos != CB_ERR)
	{
		m_comb2.SetCurSel(pos);
	}

	pos = m_comb3.SelectString(0, str);
	if(pos != CB_ERR)
	{
		m_comb3.SetCurSel(pos);
	}
}
