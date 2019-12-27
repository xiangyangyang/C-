; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTimeZone
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "myclockproject.h"
LastPage=0

ClassCount=5
Class1=CClockExe
Class2=CMyClockProjectApp
Class3=CAboutDlg
Class4=CMyClockProjectDlg
Class5=CTimeZone

ResourceCount=3
Resource1=IDD_MYCLOCKPROJECT_DIALOG
Resource2=IDD_ABOUTBOX
Resource3=IDD_DIALOG1

[CLS:CClockExe]
Type=0
BaseClass=CStatic
HeaderFile=ClockExe.h
ImplementationFile=ClockExe.cpp

[CLS:CMyClockProjectApp]
Type=0
BaseClass=CWinApp
HeaderFile=MyClockProject.h
ImplementationFile=MyClockProject.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=MyClockProjectDlg.cpp
ImplementationFile=MyClockProjectDlg.cpp
LastObject=CAboutDlg

[CLS:CMyClockProjectDlg]
Type=0
BaseClass=CDialog
HeaderFile=MyClockProjectDlg.h
ImplementationFile=MyClockProjectDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CMyClockProjectDlg

[CLS:CTimeZone]
Type=0
BaseClass=CDialog
HeaderFile=TimeZone.h
ImplementationFile=TimeZone.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_ZONELIST

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MYCLOCKPROJECT_DIALOG]
Type=1
Class=CMyClockProjectDlg
ControlCount=8
Control1=IDC_CLOCK,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_DATE,static,1342308352
Control6=IDC_ZONE,static,1342308352
Control7=IDC_TIME,static,1342308352
Control8=IDC_CHANGEZONE,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=CTimeZone
ControlCount=3
Control1=IDC_ZONELIST,combobox,1344340227
Control2=IDC_OK_BUTTON,button,1342242816
Control3=IDC_CANCEL_BUTTON,button,1342242816

