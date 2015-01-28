//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbAPoint2d.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib
{
	TbAPoint2d::~TbAPoint2d()
	{
	}

	double TbAPoint2d::getDistance(const TbAPoint2d *p1,
		const TbAPoint2d *p2)
	{
		return sqrt(getDistanceSq(p1, p2));
	}

	double TbAPoint2d::getDistanceSq(const TbAPoint2d *p1,
		const TbAPoint2d *p2)
	{
		double x1 = (p1 ? p1->getX() : 0);
		double y1 = (p1 ? p1->getY() : 0);
		double x2 = (p2 ? p2->getX() : 0);
		double y2 = (p2 ? p2->getY() : 0);
		return getDistanceSq(x1, y1, x2, y2);
	}

	double TbAPoint2d::getDistance(const double &x1, const double &y1,
				const double &x2, const double &y2)
	{
		return sqrt(getDistanceSq(x1, y1, x2, y2));
	}

	double TbAPoint2d::getDistanceSq(const double &x1, const double &y1,
		const double &x2, const double &y2)
	{
		double dx = x1 - x2;
		double dy = y1 - y2;
		return dx * dx + dy * dy;
	}

	int TbAPoint2d::getQuarter(const TbAPoint2d *point)
	{
		double x = (point ? point->getX() : 0);
		double y = (point ? point->getY() : 0);
        return getQuarter(x, y);
	}

	int TbAPoint2d::getQuarter(const TbAPoint2d *point,
				const TbAPoint2d *center)
	{
		double x = (point ? point->getX() : 0) - (center ? center->getX() : 0);
		double y = (point ? point->getY() : 0) - (center ? center->getY() : 0);
		return getQuarter(x, y);
	}

	int TbAPoint2d::getQuarter(const double &x, const double &y)
	{
     	int quarter = 0; // first
		if(x >= 0)
		{
			if(y < 0)
			{
				quarter = 3; // fourth
			}
		}
		else
		{
			if(y >= 0)
			{
				quarter = 1; // second
			}
			else
			{
				quarter = 2; // third
			}
		}
		return quarter;
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
