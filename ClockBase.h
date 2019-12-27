// ClockBase.h: interface for the CClockBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLOCKBASE_H__C983A390_6691_4F35_9E32_F3C0CEFE0D67__INCLUDED_)
#define AFX_CLOCKBASE_H__C983A390_6691_4F35_9E32_F3C0CEFE0D67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<math.h>
#define PI 3.1415926535

class CClockBase  
{
protected:
	COLORREF	m_crPen;	//Pen color
	COLORREF	m_crBrush;	//Brush color
	CTime	m_tmCur;	//current time
	CRect	m_rcRegion;	//draw region
	int		m_nRadius;	// colck's radius
public:
	void SetColor(COLORREF crMain);
	void SetColor(COLORREF crMain, COLORREF crOther);
	void SetTime(const CTime &tmCur);
	void SetRadius(LPRECT lprcRect);
	virtual void Draw(CDC *pDC) = 0;
	CClockBase();
	virtual ~CClockBase();

};

#endif // !defined(AFX_CLOCKBASE_H__C983A390_6691_4F35_9E32_F3C0CEFE0D67__INCLUDED_)
