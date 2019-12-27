// MyClockProjectDlg.h : header file
//

#if !defined(AFX_MYCLOCKPROJECTDLG_H__980E7EC8_BD3D_4B2C_85BB_E5C9494EA091__INCLUDED_)
#define AFX_MYCLOCKPROJECTDLG_H__980E7EC8_BD3D_4B2C_85BB_E5C9494EA091__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"ClockExe.h"
#include"TimeZone.h"

/////////////////////////////////////////////////////////////////////////////
// CMyClockProjectDlg dialog

class CMyClockProjectDlg : public CDialog
{
// Construction
public:
	//CTimeZone m_timezone;
	CMyClockProjectDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyClockProjectDlg)
	enum { IDD = IDD_MYCLOCKPROJECT_DIALOG };
	CClockExe	m_clock;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyClockProjectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyClockProjectDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnChangezone();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCLOCKPROJECTDLG_H__980E7EC8_BD3D_4B2C_85BB_E5C9494EA091__INCLUDED_)
