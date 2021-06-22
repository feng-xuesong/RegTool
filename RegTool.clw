; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGaoSu
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "RegTool.h"

ClassCount=5
Class1=CRegToolApp
Class2=CRegToolDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_REGTOOL_DIALOG
Resource4=IDD_DIALOG1
Class4=CGaoSu
Class5=CYinHang
Resource5=IDD_DIALOG2

[CLS:CRegToolApp]
Type=0
HeaderFile=RegTool.h
ImplementationFile=RegTool.cpp
Filter=N

[CLS:CRegToolDlg]
Type=0
HeaderFile=RegToolDlg.h
ImplementationFile=RegToolDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_TAB1

[CLS:CAboutDlg]
Type=0
HeaderFile=RegToolDlg.h
ImplementationFile=RegToolDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_REGTOOL_DIALOG]
Type=1
Class=CRegToolDlg
ControlCount=1
Control1=IDC_TAB1,SysTabControl32,1342177280

[DLG:IDD_DIALOG1]
Type=1
Class=CGaoSu
ControlCount=20
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_COMBO1,combobox,1344340226
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,static,1342308352
Control7=IDC_COMBO2,combobox,1344340226
Control8=IDC_STATIC,static,1342308352
Control9=IDC_COMBO3,combobox,1344340226
Control10=IDC_BUTTON3,button,1342242816
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT2,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT3,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_EDIT4,edit,1350631552
Control17=IDC_STATIC,static,1342308352
Control18=IDC_EDIT7,edit,1350631552
Control19=IDC_STATIC,static,1342308352
Control20=IDC_EDIT8,edit,1350631552

[DLG:IDD_DIALOG2]
Type=1
Class=CYinHang
ControlCount=26
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_IPADDRESS1,SysIPAddress32,1342242816
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT1,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_IPADDRESS2,SysIPAddress32,1342242816
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT2,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_IPADDRESS3,SysIPAddress32,1342242816
Control15=IDC_STATIC,static,1342308352
Control16=IDC_EDIT3,edit,1350631552
Control17=IDC_STATIC,static,1342308352
Control18=IDC_IPADDRESS4,SysIPAddress32,1342242816
Control19=IDC_STATIC,static,1342308352
Control20=IDC_EDIT4,edit,1350631552
Control21=IDC_BUTTON2,button,1342242816
Control22=IDC_STATIC,static,1342308352
Control23=IDC_EDIT5,edit,1350631552
Control24=IDC_CHECK1,button,1342242819
Control25=IDC_STATIC,static,1342308352
Control26=IDC_EDIT6,edit,1350631552

[CLS:CGaoSu]
Type=0
HeaderFile=GaoSu.h
ImplementationFile=GaoSu.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_BUTTON3

[CLS:CYinHang]
Type=0
HeaderFile=YinHang.h
ImplementationFile=YinHang.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT6

