//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbVector2d.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib // TbVector2d
{
	TbVector2d::TbVector2d(): TbPoint2d()
	{
	}

	TbVector2d* TbVector2d::instance_(const TbAPoint2d *from,
		const TbAPoint2d *to)
	{
		TbVector2d *v_ = new TbVector2d();
		if(to)
		{
			if(from)
			{
				v_->coordinate(to->getX() - from->getX(), to->getY() - from->getY());
			}
			else
			{
				v_->coordinate(to->getX(), to->getY());
			}
		}
		else
		{
			if(from)
			{
				v_->coordinate(-from->getX(), -from->getY());
			}
			else
			{
				v_->coordinate(0, 0);
			}
		}
		return v_;
	}

	void TbVector2d::shift(const TbAVector2d *dv)
	{
		if(dv)
		{
			shift(dv->getX(), dv->getY());
		}
	}

	void TbVector2d::shift(const double &dx, const double &dy)
	{
		coordinate(getX() + dx, getY() + dy);
    }

	void TbVector2d::normalize()
	{
		setLength(1.0);
	}

	void TbVector2d::setLength(const double &newLength)
	{
		double oldLength = getLength();
		if(oldLength)
		{
			double k = newLength / oldLength;
			scale(k, k);
		}
	}

	void TbVector2d::mult(const double &d)
	{
		scale(d, d);
	}

	void TbVector2d::rotate(const double &radian)
	{
		rotate(sin(radian), cos(radian));
	}

	void TbVector2d::rotate(const double &sin_radian, const double &cos_radian)
	{
		double x = getX();
		double y = getY();
    	double _x = x * cos_radian - y * sin_radian;
		double _y = x * sin_radian + y * cos_radian;
		coordinate(_x, _y);
	}

	void TbVector2d::rotate(const TbAVector2d *rv)
	{
		if(rv)
		{
			rotate(rv->getY(), rv->getX());
        }
	}

	void TbVector2d::setRadian(const double &radian)
	{
		setRadian(sin(radian), cos(radian));
	}

	void TbVector2d::setRadian(const TbAVector2d *rv)
	{
		if(rv)
		{
			setRadian(rv->getY(), rv->getX());
        }
    }

	void TbVector2d::setRadian(const double &sin_radian, const double &cos_radian)
	{
		double length = getLength();
		if(length)
		{
			coordinate(length * cos_radian, length * sin_radian);
        }
    }

	void TbVector2d::scale(const double &sx, const double &sy)
	{
		coordinate(getX() * sx, getY() * sy);
	}

	double TbVector2d::getX()const
	{
		return TbPoint2d::getX();
	}

	double TbVector2d::getY()const
	{
		return TbPoint2d::getY();
	}

	TbVector2d::~TbVector2d()
	{

	}

	TbUnitaryVector2d* TbVector2d::getUnitaryVector_()const
	{
		TbUnitaryVector2d *uv_ = new TbUnitaryVector2d();
		uv_->setRadian(getRadian());
		return uv_;
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
