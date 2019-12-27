// ClockBase.cpp: implementation of the CClockBase class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyClockProject.h"
#include "ClockBase.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClockBase::CClockBase()
{
	m_nRadius = 0;
	m_crBrush = RGB(215, 180, 255);
	m_crPen = RGB(128, 0, 255);
}

CClockBase::~CClockBase()
{

}

void CClockBase::SetRadius(LPRECT lprcRect)
{
	m_rcRegion = lprcRect;
	m_nRadius = m_rcRegion.Width() / 2;
	if (m_rcRegion.Width() > m_rcRegion.Height())
	{
		m_nRadius = m_rcRegion.Height() / 2;
	}
}

void CClockBase::SetTime(const CTime &tmCur)
{
	m_tmCur = tmCur;
}

void CClockBase::SetColor(COLORREF crPen,COLORREF crBrush)
{
	m_crPen = crPen;
	m_crBrush= crBrush;
}
