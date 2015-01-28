//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbAPoint1d.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib
{
	TbAPoint1d::~TbAPoint1d()
	{

	}

	double TbAPoint1d::getDistance(const TbAPoint1d *p1, const TbAPoint1d *p2)
	{
		double v1 = (p1 ? p1->getValue() : 0);
		double v2 = (p2 ? p2->getValue() : 0);
		return getDistance(v1, v2);
	}

	double TbAPoint1d::getDistance(const double &v1, const double &v2)
	{
		return fabs(v1 - v2);
	}
}
//---------------------------------------------------------------------------

