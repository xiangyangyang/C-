// ClockBackground.cpp: implementation of the CClockBackground class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyClockProject.h"
#include "ClockBackground.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClockBackground::CClockBackground()
{

}

CClockBackground::~CClockBackground()
{

}
void CClockBackground::Draw(CDC *pDC)
{
	//prepare device context 
	
	CPen pen(PS_SOLID,1,m_crPen),pen1(PS_SOLID,4,m_crPen);;
	CBrush brush(m_crBrush);
	CPen *pOldPen = pDC->SelectObject(&pen);
	CBrush *pOldBrush = pDC->SelectObject(&brush);
	CPoint ptCenter = m_rcRegion.CenterPoint();
	//draw clock circle
	pDC->Ellipse(ptCenter.x-m_nRadius,ptCenter.y+m_nRadius,ptCenter.x+m_nRadius,ptCenter.y-m_nRadius);
	int nRadius = m_nRadius - 8;
	//draw degree scale points
	for(int i=0; i<60; i++)
	{
		CPoint ptEnd = ptCenter;
		ptEnd.Offset((int)(nRadius * sin(2 * PI * (i % 60) / 60)),
			(int)(-nRadius * cos(2 * PI * (i % 60) / 60)));
		CRect rcDot(-2, -2, 2, 2);
		rcDot.OffsetRect(ptEnd);
		pDC->Ellipse(rcDot);
	}
	//draw hour's line
	pOldPen = pDC->SelectObject(&pen1);
	for(i=0; i<12; i++)
	{
		CPoint ptEnd1 = ptCenter;
        CPoint ptEnd2 = ptCenter;
		double fRadian = 2 * PI * (i % 12) / 12;
		ptEnd1.Offset((int)((nRadius-7) * sin(fRadian)),(int)((-nRadius+7) * cos(fRadian)));
		ptEnd2.Offset((int)(nRadius * sin(fRadian)),	(int)(-nRadius * cos(fRadian)));

    	pDC->MoveTo(ptEnd1);
		pDC->LineTo(ptEnd2);
	}

	//restore device context
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}
