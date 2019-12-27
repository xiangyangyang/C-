// MyClockProject.h : main header file for the MYCLOCKPROJECT application
//

#if !defined(AFX_MYCLOCKPROJECT_H__FAB5FAED_32C6_4491_8B70_C0EFF67A8775__INCLUDED_)
#define AFX_MYCLOCKPROJECT_H__FAB5FAED_32C6_4491_8B70_C0EFF67A8775__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyClockProjectApp:
// See MyClockProject.cpp for the implementation of this class
//

class CMyClockProjectApp : public CWinApp
{
public:
	CMyClockProjectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyClockProjectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyClockProjectApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCLOCKPROJECT_H__FAB5FAED_32C6_4491_8B70_C0EFF67A8775__INCLUDED_)
