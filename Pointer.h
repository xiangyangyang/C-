// Pointer.h: interface for the CPointer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINTER_H__BC5A9FC6_0C2C_44ED_B2F7_8A10D4343ADC__INCLUDED_)
#define AFX_POINTER_H__BC5A9FC6_0C2C_44ED_B2F7_8A10D4343ADC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ClockBase.h"

class CPointer : public CClockBase  
{
public:
	CPointer();
	virtual void Draw(CDC *pDC);
	virtual ~CPointer();

};

#endif // !defined(AFX_POINTER_H__BC5A9FC6_0C2C_44ED_B2F7_8A10D4343ADC__INCLUDED_)
