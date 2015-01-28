//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbPoint2d.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib // TbPoint2d
{
	TbPoint2d::TbPoint2d()
	{
		x = new TbPoint1d();
		y = new TbPoint1d();
	}

	TbPoint2d::TbPoint2d(const TbAPoint2d *point)
	{
		x = new TbPoint1d();
		y = new TbPoint1d();
		if(point)
		{
			coordinate(point->getX(), point->getY());
		}
    }

	TbPoint2d::TbPoint2d(const double &x, const double &y)
	{
		this->x = new TbPoint1d(x);
		this->y = new TbPoint1d(y);
	}

	TbPoint2d::TbPoint2d(TbPoint1d *x, TbPoint1d *y)
	{
		this->x = new TbPoint1d(x);
		this->y = new TbPoint1d(y);
    }

	TbPoint2d::~TbPoint2d()
	{
		delete x;
		delete y;
	}

	double TbPoint2d::getX()const
	{
		return x->getValue();
	}

	double TbPoint2d::getY()const
	{
		return y->getValue();
	}

	TbPoint1d* TbPoint2d::getXProjection()const
	{
		return x;
	}

	TbPoint1d* TbPoint2d::getYProjection()const
	{
    	return y;
	}

	void TbPoint2d::setX(const double &x)
	{
		this->x->setValue(x);
	}

	void TbPoint2d::setY(const double &y)
	{
    	this->y->setValue(y);
	}

	void TbPoint2d::coordinate(const double &x, const double &y)
	{
        setX(x);
		setY(y);
	}

	void TbPoint2d::coordinate(const TbAPoint2d *point)
	{
    	coordinate(point->getX(), point->getY());
    }

	void TbPoint2d::reverse()
	{
		reverseX();
        reverseY();
	}

	void TbPoint2d::reverseX()
	{
		setX(-getX());
	}

	void TbPoint2d::reverseY()
	{
		setY(-getY());
	}

	void TbPoint2d::reverse(const TbAPoint2d *center)
	{
		if(center)
		{
			double xc = center->getX();
			double yc = center->getY();
			setX(xc + xc - getX());
			setY(yc + yc - getY());
        }
	}

	double TbPoint2d::getDistanceTo(const TbAPoint2d *point)
	{
		return getDistance(this, point);
	}

	double TbPoint2d::getDistanceTo(const double &x, const double &y)
	{
    	return getDistance(getX(), getY(), x, y);
	}

	double TbPoint2d::getDistanceSqTo(const TbAPoint2d *point)
	{
		return getDistanceSq(this, point);
	}

	double TbPoint2d::getDistanceSqTo(const double &x, const double &y)
	{
    	return getDistanceSq(getX(), getY(), x, y);
	}

	TbPoint2d* TbPoint2d::getMiddlePoint(const TbAPoint2d *p1,
				const TbAPoint2d *p2)
	{
		double x1 = (p1 ? p1->getX() : 0);
		double y1 = (p1 ? p1->getY() : 0);
		double x2 = (p2 ? p2->getX() : 0);
		double y2 = (p2 ? p2->getY() : 0);
		return getMiddlePoint(x1, y1, x2, y2);
	}

	TbPoint2d* TbPoint2d::getMiddlePoint(const double &x1, const double &y1,
				const double &x2, const double &y2)
	{
		return new TbPoint2d((x1 + x2) / 2, (y1 + y2) / 2);
	}

	TbPoint2d* TbPoint2d::getMiddlePoint(const double &x1, const double &y1,
				const double &weight1, const double &x2, const double &y2,
				const double &weight2)
	{
		TbPoint2d *point = NULL;
		if(weight1 > 0 && weight2 > 0)
		{
			double weight = weight1 + weight2;
			point = new TbPoint2d((x1 + x2) * weight1 / weight,
				(y1 + y2) * weight1 / weight);
		}
		return point;
    }
}
//---------------------------------------------------------------------------

