// ClockExe.cpp : implementation file
//

#include "stdafx.h"
#include "MyClockProject.h"
#include "ClockExe.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClockExe

CClockExe::CClockExe()
{
}

CClockExe::~CClockExe()
{
}


BEGIN_MESSAGE_MAP(CClockExe, CStatic)
	//{{AFX_MSG_MAP(CClockExe)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClockExe message handlers

void CClockExe::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	//create compatible dc and compatible bitmap draw to Prevent screen flicker
	CDC	dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap	bmp;
	bmp.CreateCompatibleBitmap(&dc, m_rcClient.Width(), m_rcClient.Height());
	dcMem.SelectObject(&bmp);
    dcMem.BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(), &dc, 0, 0, SRCCOPY);//copy dc
	DrawClock(&dcMem);
	dc.BitBlt(0, 0, m_rcClient.Width(), m_rcClient.Height(), &dcMem, 0, 0, SRCCOPY);
	// Do not call CStatic::OnPaint() for painting messages
}

void CClockExe::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	Invalidate(FALSE);
	CStatic::OnTimer(nIDEvent);
}

void CClockExe::OnSize(UINT nType, int cx, int cy) 
{
	GetClientRect(m_rcClient);
	m_clockBK.SetRadius(m_rcClient);
	m_pointer.SetRadius(m_rcClient);
	CStatic::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	
}

void CClockExe::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	GetClientRect(m_rcClient);
	m_clockBK.SetRadius(m_rcClient);
	m_pointer.SetRadius(m_rcClient);
	SetTimer(1, 100, NULL);
	CStatic::PreSubclassWindow();
}

void CClockExe::DrawClock(CDC *pDC)
{
	CTime tmCur = CTime::GetCurrentTime();
	m_clockBK.SetTime(tmCur);
	m_pointer.SetTime(tmCur);

	m_clockBK.Draw(pDC);
	m_pointer.Draw(pDC);
	
}