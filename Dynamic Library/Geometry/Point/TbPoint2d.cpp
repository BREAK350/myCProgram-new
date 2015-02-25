//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbPoint2d.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib // TbPoint2d
{
	TbPoint2d::TbPoint2d()
	{
		coordinate(0, 0);
	}

	TbPoint2d::~TbPoint2d()
	{
	}

	double TbPoint2d::getX()const
	{
		return x;
	}

	double TbPoint2d::getY()const
	{
		return y;
	}

	void TbPoint2d::setX(const double &x)
	{
		this->x = x;
	}

	void TbPoint2d::setY(const double &y)
	{
    	this->y = y;
	}

	void TbPoint2d::coordinate(const double &x, const double &y)
	{
        TbAModPoint2d::coordinate(this, x, y);
	}

	void TbPoint2d::coordinate(const TbAPoint2d *point)
	{
		TbAModPoint2d::coordinate(this, point);
    }

	void TbPoint2d::reverse()
	{
		TbAModPoint2d::reverse(this);
	}

	void TbPoint2d::reverseX()
	{
		TbAModPoint2d::reverseX(this);
	}

	void TbPoint2d::reverseY()
	{
		TbAModPoint2d::reverseY(this);
	}

	void TbPoint2d::reverse(const TbAPoint2d *center)
	{
		TbAModPoint2d::reverse(this, center);
	}

	double TbPoint2d::getDistanceTo(const TbAPoint2d *point)
	{
		return TbAPoint2d::getDistance(this, point);
	}

	double TbPoint2d::getDistanceTo(const double &x, const double &y)
	{
		return TbAPoint2d::getDistance(getX(), getY(), x, y);
	}

	double TbPoint2d::getDistanceSqTo(const TbAPoint2d *point)
	{
		return TbAPoint2d::getDistanceSq(this, point);
	}

	double TbPoint2d::getDistanceSqTo(const double &x, const double &y)
	{
    	return TbAPoint2d::getDistanceSq(getX(), getY(), x, y);
	}

	int TbPoint2d::getQuarter()const
	{
		return TbAPoint2d::getQuarter(this);
	}

	int TbPoint2d::getQuarter(const TbAPoint2d *point)const
	{
		return TbAPoint2d::getQuarter(this, point);
	}

	TbPoint2d* TbPoint2d::getMiddlePoint_(const TbAPoint2d *p1,
				const TbAPoint2d *p2)
	{
		double x1 = (p1 ? p1->getX() : 0);
		double y1 = (p1 ? p1->getY() : 0);
		double x2 = (p2 ? p2->getX() : 0);
		double y2 = (p2 ? p2->getY() : 0);
		return getMiddlePoint_(x1, y1, x2, y2);
	}

	TbPoint2d* TbPoint2d::getMiddlePoint_(const double &x1, const double &y1,
				const double &x2, const double &y2)
	{
		TbPoint2d *p_ = new TbPoint2d();
		p_->coordinate((x1 + x2) / 2, (y1 + y2) / 2);
		return p_;
	}

	TbPoint2d* TbPoint2d::getMiddlePoint_(const double &x1, const double &y1,
				const double &weight1, const double &x2, const double &y2,
				const double &weight2)
	{
		TbPoint2d *p_ = NULL;
		if(weight1 > 0 && weight2 > 0)
		{
			p_ = new TbPoint2d();
			double weight = weight1 + weight2;
			p_->coordinate((x1 + x2) * weight1 / weight,
				(y1 + y2) * weight1 / weight);
		}
		return p_;
	}

	TbPoint2d* TbPoint2d::getMiddlePoint_(const TbAPoint2d *p1,
				const double &weight1, const TbAPoint2d *p2, const double &weight2)
	{
		double x1 = (p1 ? p1->getX() : 0);
		double y1 = (p1 ? p1->getY() : 0);
		double x2 = (p2 ? p2->getX() : 0);
		double y2 = (p2 ? p2->getY() : 0);
		return getMiddlePoint_(x1, y1, weight1, x2, y2, weight2);
	}
}
//---------------------------------------------------------------------------

