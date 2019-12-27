// ClockBackground.h: interface for the CClockBackground class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLOCKBACKGROUND_H__4C9F56FD_75D8_4669_AD4C_69BB7375638D__INCLUDED_)
#define AFX_CLOCKBACKGROUND_H__4C9F56FD_75D8_4669_AD4C_69BB7375638D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ClockBase.h"

class CClockBackground : public CClockBase  
{
public:
	CClockBackground();
	virtual	void Draw(CDC *pDC);
	virtual ~CClockBackground();

};

#endif // !defined(AFX_CLOCKBACKGROUND_H__4C9F56FD_75D8_4669_AD4C_69BB7375638D__INCLUDED_)
