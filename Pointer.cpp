// Pointer.cpp: implementation of the CPointer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyClockProject.h"
#include "Pointer.h"
#include"TimeZone.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPointer::CPointer()
{
	
}

CPointer::~CPointer()
{

}

void CPointer::Draw(CDC *pDC)
{	
		int nhour,nminute,nsecond,nyear,nmonth,nday;
		nhour=CTimeZone::m_hour;
		nminute=CTimeZone::m_minute;
		nsecond=CTimeZone::m_second;
		nyear=CTimeZone::m_year;
		nmonth=CTimeZone::m_month;
		nday=CTimeZone::m_day;
       int nHTime,nMTime,nSTime;
		double f_HRadian,f_MRadian,f_SRadian;
    
	if(CTimeZone::m_csSleZone==_T("(UTC+08:00)北京，重庆，香港特别行政区，乌鲁木齐")){
		//get hour pointer location
		nHTime = (m_tmCur.GetHour() % 12) * 3600;
		nHTime += m_tmCur.GetMinute() * 60;
		nHTime += m_tmCur.GetSecond();
		//get minute pointer location
		 nMTime = m_tmCur.GetMinute() * 60;
		 nMTime += m_tmCur.GetSecond();
		//get second pointer location
		 nSTime = m_tmCur.GetSecond();
	}else{
		// get hour pointer
		   nHTime = (nhour % 12) * 3600;
	       nHTime += nminute * 60;
		   nHTime+=nsecond;
		   //get minute pointer location
			nMTime = nminute * 60;
			nMTime += nsecond;
			//get second pointer location
			nSTime =nsecond;
	}
	
	//prepare device context
	CPen penH(PS_SOLID,5,RGB(40,0,81)),penM(PS_SOLID,3,RGB(78,0,155)),penS(PS_SOLID,1,m_crPen);
	//draw hour pointer
	CPen *pOldPen = pDC->SelectObject(&penH);
	CPoint ptStart = m_rcRegion.CenterPoint();
	CPoint ptHourEnd = ptStart;
	int nHRadius = m_nRadius/2;

	 f_HRadian = 2 * PI * nHTime / 3600 / 12;

	ptHourEnd.Offset((int)(nHRadius * sin(f_HRadian)),(int)(-nHRadius * cos(f_HRadian)));
	pDC->MoveTo(ptStart);
	pDC->LineTo(ptHourEnd);

	//draw minute pointer
    pOldPen=pDC->SelectObject(&penM);
	CPoint ptMinEnd = ptStart;
	int nMRadius = m_nRadius - 30;

	f_MRadian = 2 * PI * nMTime / 3600;
	ptMinEnd.Offset((int)(nMRadius * sin(f_MRadian)),(int)(-nMRadius * cos(f_MRadian)));
	pDC->MoveTo(ptStart);
	pDC->LineTo(ptMinEnd);

	//draw second pointer
	pOldPen=pDC->SelectObject(&penS);
	CPoint ptSecEnd = ptStart;
	int nSRadius = m_nRadius - 15;

	
    f_SRadian=2 * PI * nSTime / 60;
	ptSecEnd.Offset((int)(nSRadius * sin(f_SRadian)),(int)(-nSRadius * cos(f_SRadian)));
	pDC->MoveTo(ptStart);
	pDC->LineTo(ptSecEnd);
	
	//restore device context
	pDC->SelectObject(pOldPen);
}