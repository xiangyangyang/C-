// TimeZone.cpp : implementation file
//

#include "stdafx.h"
#include "myclockproject.h"
#include "windows.h"
#include "TimeZone.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

typedef struct _REG_TZI_FORMAT  
{  
    LONG Bias;  
    LONG StandardBias;  
    LONG DaylightBias;  
    SYSTEMTIME StandardDate;  
    SYSTEMTIME DaylightDate;  
} REG_TZI_FORMAT;



typedef struct DISPLYKEY{
		CString subkey;
		CString display;
}DISPLYKEY,LPDISPLYKEY;
DISPLYKEY *kdisplay=new DISPLYKEY[110];
//DISPLYKEY kdisplay[110];//定义一个全局数组

/////////////////////////////////////////////////////////////////////////////
//CTimeZone dialog
CString CTimeZone::m_csSleZone=_T("(UTC+08:00)北京，重庆，香港特别行政区，乌鲁木齐");
CTime t=CTime::GetCurrentTime();
int CTimeZone::m_hour=t.GetHour();
int CTimeZone::m_minute=t.GetMinute();
int CTimeZone::m_second=t.GetSecond();
int CTimeZone::m_year=t.GetYear();
int CTimeZone::m_month=t.GetMonth();
int CTimeZone::m_day=t.GetDay();

 
CTimeZone::CTimeZone(CWnd* pParent /*=NULL*/)
	: CDialog(CTimeZone::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTimeZone)
	
	//}}AFX_DATA_INIT

}


void CTimeZone::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimeZone)
	DDX_CBString(pDX, IDC_ZONELIST, m_csSleZone);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTimeZone, CDialog)
	//{{AFX_MSG_MAP(CTimeZone)
	ON_BN_CLICKED(IDC_OK_BUTTON, OnOkButton)
	ON_BN_CLICKED(IDC_CANCEL_BUTTON, OnCancelButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimeZone message handlers


BOOL CTimeZone::OnInitDialog() 
{
	CDialog::OnInitDialog();


	// TODO: Add extra initialization here
	// Enable the required privilege to access registry
	HANDLE hToken;
    TOKEN_PRIVILEGES tkp;
    OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY, &hToken);
    LookupPrivilegeValue(NULL, TEXT("SeTimeZonePrivilege"), &tkp.Privileges[0].Luid);
    tkp.PrivilegeCount = 1;
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
	//open time zones
    HKEY hKey, hsubKey;
    CString keyName = _T("Software\\Microsoft\\Windows NT\\CurrentVersion\\Time Zones");
	RegOpenKey(HKEY_LOCAL_MACHINE, keyName, &hKey);

	TCHAR    lpName[MAX_KEY_LENGTH];
	DWORD   cSubKeys,cbMaxSubKey,cbName;
	CString	 subKeyName;
	int listIndex=-1;
	
    // get subkeys info
	if(RegQueryInfoKey(hKey,NULL,NULL,NULL,&cSubKeys,&cbMaxSubKey,NULL,NULL,NULL,NULL,NULL,NULL)==ERROR_SUCCESS)
	{
		for (DWORD i=0; i<cSubKeys; i++) 
        { 
			cbName = MAX_KEY_LENGTH;
			RegEnumKeyEx(hKey, i,lpName,&cbName,NULL,NULL,NULL,NULL);
			subKeyName=keyName+"\\"+lpName;
			RegOpenKey(HKEY_LOCAL_MACHINE, subKeyName, &hsubKey);
			DWORD dwSize;
			//get value's size;
	      	RegQueryValueEx(hsubKey, TEXT("Display"), NULL, NULL,  NULL, &dwSize);
			char *dwDisplay = new char[dwSize+1];
			//get value
			RegQueryValueEx(hsubKey, TEXT("Display"), NULL, NULL,(LPBYTE)dwDisplay, &dwSize);
            //add zone's display value to List
            CString str(dwDisplay);
	        ((CComboBox*)GetDlgItem(IDC_ZONELIST))->AddString(str);
            kdisplay[i].subkey=lpName;
            kdisplay[i].display=str;
				
		}
			
	}else
	
		return FALSE;
	
	((CComboBox*)GetDlgItem(IDC_ZONELIST))->SetCurSel(47);//set default zone
	// Disable the privilege
	
    tkp.Privileges[0].Attributes = 0; 
    AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES) NULL, 0);
	RegCloseKey(hKey);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTimeZone::OnOkButton() 
{
	
    ((CComboBox*)GetDlgItem(IDC_ZONELIST))->GetWindowText(m_csSleZone);
	CDialog::OnOK(); 
}

void CTimeZone::OnCancelButton() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}


CString CTimeZone::getSubkey(CString display)
{
	for(int i=0;i<108;i++)
	{
		if(kdisplay[i].display==display){
			return kdisplay[i].subkey;
		}
			
	}
	return "";	
}


void CTimeZone::getTimeZoneInfoBySubkey(TIME_ZONE_INFORMATION ptzi, CString Subkey)
{
	//open subkey form registry
	CString keyName = _T("Software\\Microsoft\\Windows NT\\CurrentVersion\\Time Zones");
	CString subkeyName=keyName+_T("\\")+Subkey;
	HKEY hsubKey;	
	RegOpenKey(HKEY_LOCAL_MACHINE, subkeyName, &hsubKey);
		//copy zone Info
		DWORD dwBufdlt,dwBufstd,dwBuftzi;
		unsigned short dwDlt[32];
		unsigned short dwStd[32];
		DWORD dwtzi;
		RegQueryValueEx(hsubKey, TEXT("Dlt"), NULL,NULL,(LPBYTE)&dwDlt,&dwBufdlt);	
		RegQueryValueEx(hsubKey, TEXT("Std"), NULL, NULL,(LPBYTE)&dwStd,&dwBufstd);
		RegQueryValueEx(hsubKey, TEXT("TZI"), NULL, NULL,(LPBYTE)&dwtzi,&dwBuftzi);
			//assign value to TZI
			REG_TZI_FORMAT regTZI;
			ZeroMemory(&ptzi, sizeof(ptzi));
			memcpy((LPBYTE)&regTZI,(LPBYTE)&dwtzi,dwBuftzi);
			ptzi.Bias=regTZI.Bias;
			ptzi.DaylightBias=regTZI.DaylightBias;
			ptzi.StandardBias=regTZI.StandardBias;

			ptzi.DaylightDate.wDay=regTZI.DaylightDate.wDay;
			ptzi.DaylightDate.wHour=regTZI.DaylightDate.wHour;
			ptzi.DaylightDate.wMilliseconds=regTZI.DaylightDate.wMilliseconds;
			ptzi.DaylightDate.wMinute=regTZI.DaylightDate.wMinute;
			ptzi.DaylightDate.wDayOfWeek=regTZI.DaylightDate.wDayOfWeek;
			ptzi.DaylightDate.wMonth=regTZI.DaylightDate.wMonth;
			ptzi.DaylightDate.wSecond=regTZI.DaylightDate.wSecond;
			ptzi.DaylightDate.wYear=regTZI.DaylightDate.wYear;

			ptzi.DaylightDate.wDay=regTZI.StandardDate.wDay;
			ptzi.StandardDate.wHour=regTZI.StandardDate.wHour;
			ptzi.StandardDate.wMilliseconds=regTZI.StandardDate.wMilliseconds;
			ptzi.StandardDate.wMinute=regTZI.StandardDate.wMinute;
			ptzi.StandardDate.wDayOfWeek=regTZI.StandardDate.wDayOfWeek;
			ptzi.StandardDate.wMonth=regTZI.StandardDate.wMonth;
			ptzi.StandardDate.wSecond=regTZI.StandardDate.wSecond;
			ptzi.StandardDate.wYear=regTZI.StandardDate.wYear;
   
			wcscpy(ptzi.DaylightName,dwDlt);
			wcscpy(ptzi.StandardName,dwStd);
			//get local time according zone	
			   SYSTEMTIME ssutc,ssloc;
			   GetSystemTime(&ssutc);
			   SystemTimeToTzSpecificLocalTime(&ptzi,&ssutc,&ssloc);
			   m_hour=ssloc.wHour;
			   m_minute=ssloc.wMinute;
			   m_second=ssloc.wSecond;
			   m_year=ssloc.wYear;
			   m_month=ssloc.wMonth;
			   m_day=ssloc.wDay;

}

