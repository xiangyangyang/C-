// MyClockProjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyClockProject.h"
#include "MyClockProjectDlg.h"
#include"TimeZone.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyClockProjectDlg dialog

CMyClockProjectDlg::CMyClockProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyClockProjectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyClockProjectDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyClockProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyClockProjectDlg)
	DDX_Control(pDX, IDC_CLOCK, m_clock);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyClockProjectDlg, CDialog)
	//{{AFX_MSG_MAP(CMyClockProjectDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHANGEZONE, OnChangezone)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyClockProjectDlg message handlers

BOOL CMyClockProjectDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	SetTimer(1, 100, NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyClockProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyClockProjectDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyClockProjectDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyClockProjectDlg::OnChangezone() 
{
	// TODO: Add your control notification handler code here
		CTimeZone tzDig;
	    tzDig.DoModal();
}

void CMyClockProjectDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	UpdateData();
	CString str1,str2,str3;
	str3=CTimeZone::m_csSleZone;
    //initial set
	if(str3==_T("(UTC+08:00)北京，重庆，香港特别行政区，乌鲁木齐"))
	{
	CTime t = CTime::GetCurrentTime();
	
	//str1.Format("%02d:%02d:%02d",t.GetHour(),t.GetMinute(),t.GetSecond());
	str1=t.Format("%H:%M:%S");
	SetDlgItemText(IDC_TIME,str1);
	str2.Format("%04d年%02d月%02d日",t.GetYear(),t.GetMonth(),t.GetDay());
	SetDlgItemText(IDC_DATE,str2);
	SetDlgItemText(IDC_ZONE,str3);
	}else{
		
	TIME_ZONE_INFORMATION ptzi;
	GetTimeZoneInformation(&ptzi);//get current zoneInfo assign to ptzi;
	CString subkey=CTimeZone::getSubkey(CTimeZone::m_csSleZone);
	CTimeZone::getTimeZoneInfoBySubkey(ptzi,subkey);
		int nhour,nminute,nsecond,nyear,nmonth,nday;
		nhour=CTimeZone::m_hour;
		nminute=CTimeZone::m_minute;
		nsecond=CTimeZone::m_second;
		nyear=CTimeZone::m_year;
		nmonth=CTimeZone::m_month;
		nday=CTimeZone::m_day;

		str1.Format("%02d:%02d:%02d",nhour,nminute,nsecond);
		SetDlgItemText(IDC_TIME,str1);
		str2.Format("%04d年%02d月%02d日",nyear,nmonth,nday);
		SetDlgItemText(IDC_DATE,str2);
		SetDlgItemText(IDC_ZONE,str3);
	}

	CDialog::OnTimer(nIDEvent);
}
