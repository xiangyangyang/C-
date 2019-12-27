#if !defined(AFX_CLOCKEXE_H__11DC8BEC_E6E4_4FFB_8FE1_3A763D341D57__INCLUDED_)
#define AFX_CLOCKEXE_H__11DC8BEC_E6E4_4FFB_8FE1_3A763D341D57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClockExe.h : header file

#include"Pointer.h"
#include"ClockBackground.h"
//

/////////////////////////////////////////////////////////////////////////////
// CClockExe window

class CClockExe : public CStatic
{
// Construction
public:
	CClockExe();

// Attributes
private:
	CClockBackground	m_clockBK;	
	CPointer m_pointer;
    CRect	 m_rcClient; 
	void DrawClock(CDC *pDC);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClockExe)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CClockExe();

	// Generated message map functions
protected:
	//{{AFX_MSG(CClockExe)
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOCKEXE_H__11DC8BEC_E6E4_4FFB_8FE1_3A763D341D57__INCLUDED_)
