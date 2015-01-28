//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbAModPoint2d.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib
{
	TbAModPoint2d::~TbAModPoint2d()
	{
	}

	void TbAModPoint2d::coordinate(TbAModPoint2d *point, const TbAPoint2d *to)
	{
		coordinate(point, to ? to->getX() : 0, to ? to->getY() : 0);
	}

	void TbAModPoint2d::coordinate(TbAModPoint2d *point, const double &x, const double &y)
	{
		point->setX(x);
		point->setY(y);
	}

	void TbAModPoint2d::reverse(TbAModPoint2d *point)
	{
		reverseX(point);
		reverseY(point);
	}

	void TbAModPoint2d::reverse(TbAModPoint2d *point, const TbAPoint2d *center)
	{
		double xc = (center ? center->getX() : 0);
		double yc = (center ? center->getY() : 0);
		point->setX(xc + xc - point->getX());
		point->setY(yc + yc - point->getY());
	}

	void TbAModPoint2d::reverseX(TbAModPoint2d *point)
	{
		point->setX(-point->getX());
	}

	void TbAModPoint2d::reverseY(TbAModPoint2d *point)
	{
		point->setY(point->getY());
	}

	void TbAModPoint2d::setMiddlePoint(TbAModPoint2d *point, const TbAPoint2d *p1, const TbAPoint2d *p2)
	{
    	double x1 = (p1 ? p1->getX() : 0);
		double y1 = (p1 ? p1->getY() : 0);
		double x2 = (p2 ? p2->getX() : 0);
		double y2 = (p2 ? p2->getY() : 0);
        setMiddlePoint(point, x1, y1, x2, y2);
	}

	void TbAModPoint2d::setMiddlePoint(TbAModPoint2d *point, const double &x1, const double &y1,
				const double &x2, const double &y2)
	{
		coordinate(point, (x1 + x2) / 2, (y1 + y2) / 2);
	}

	void TbAModPoint2d::setMiddlePoint(TbAModPoint2d *point, const double &x1, const double &y1,
				const double &weight1, const double &x2, const double &y2, const double &weight2)
	{
		if(weight1 > 0 && weight2 > 0)
		{
			double weight = weight1 + weight2;
			coordinate(point, (x1 + x2) * weight1 / weight, (y1 + y2) * weight1 / weight);
		}
	}

	void TbAModPoint2d::setMiddlePoint(TbAModPoint2d *point, const TbAPoint2d *p1,
				const double &weight1, const TbAPoint2d *p2, const double &weight2)
	{
        double x1 = (p1 ? p1->getX() : 0);
		double y1 = (p1 ? p1->getY() : 0);
		double x2 = (p2 ? p2->getX() : 0);
		double y2 = (p2 ? p2->getY() : 0);
		setMiddlePoint(point, x1, y1, weight1, x2, y2, weight2);
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
