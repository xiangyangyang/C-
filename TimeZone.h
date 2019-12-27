#if !defined(AFX_TIMEZONE_H__6456C249_246D_4C54_BF18_BEB9AF6ED0AB__INCLUDED_)
#define AFX_TIMEZONE_H__6456C249_246D_4C54_BF18_BEB9AF6ED0AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TimeZone.h : header file


//

/////////////////////////////////////////////////////////////////////////////
// CTimeZone dialog

class CTimeZone : public CDialog
{
public:
    static CString m_csSleZone;
	static int m_hour;
    static int m_minute;
    static int m_second;
	static int m_year;
	static int m_month;
	static int m_day;
	
// Construction
public:
	
	static	void getTimeZoneInfoBySubkey(TIME_ZONE_INFORMATION ptzi, CString Subkey);
	static	CString getSubkey(CString display);

	CTimeZone(CWnd* pParent = NULL); // standard constructor
	  
// Dialog Data
	//{{AFX_DATA(CTimeZone)
	enum { IDD = IDD_DIALOG1 };
   
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeZone)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTimeZone)
	virtual BOOL OnInitDialog();
	afx_msg void OnOkButton();
	afx_msg void OnCancelButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMEZONE_H__6456C249_246D_4C54_BF18_BEB9AF6ED0AB__INCLUDED_)
