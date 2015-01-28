//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbVector2d.h"
#include "TbUnitaryVector2d.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib // TbVector2d
{
	TbVector2d::TbVector2d()
	{
		x = 0;
		y = 0;
	}

	TbVector2d::TbVector2d(const double &x, const double &y)
	{
		coordinate(x, y);
    }

	void TbVector2d::shift(const TbAbstractVector2d *dv)
	{
		if(dv)
		{
			shift(dv->getX(), dv->getY());
		}
	}

	void TbVector2d::shift(const double &dx, const double &dy)
	{
		x += dx;
		y += dy;
    }

	void TbVector2d::reverse()
	{
		reverseX();
        reverseY();
	}

	void TbVector2d::reverseX()
	{
		x = -x;
	}

	void TbVector2d::reverseY()
	{
		y = -y;
    }

	bool TbVector2d::equal(const TbVector2d *v)const
	{
		bool res = v;
		if(v)
		{
			res = (x == v->x && y == v->y);
		}
		return res;
	}

	double TbVector2d::getLength()const
	{
     	return sqrt(x * x + y * y);
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
    	double _x = x * cos_radian - y * sin_radian;
		double _y = x * sin_radian + y * cos_radian;
		coordinate(_x, _y);
	}

	void TbVector2d::rotate(const TbAbstractVector2d *rv)
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

	void TbVector2d::setRadian(const TbAbstractVector2d *rv)
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
		x *= sx;
		y *= sy;
    }

	void TbVector2d::coordinate(const double &x, const double &y)
	{
		setX(x);
		setY(y);
	}

	double TbVector2d::getX()const
	{
		return x;
	}

	double TbVector2d::getY()const
	{
		return y;
	}

	void TbVector2d::setX(const double &x)
	{
		this->x = x;
	}

	void TbVector2d::setY(const double &y)
	{
		this->y = y;
	}

	double TbVector2d::getSignedRadian()const
	{
		double radian = 0;
		if(x == 0)
		{
			if(y >= 0)
			{
				radian = M_PI / 2;
			}
			else
			{
				radian = -M_PI / 2;
			}
		}
		else
		{
			if(y == 0)
			{
				if(x > 0)
				{
					radian = 0;
				}
				else
				{
					radian = M_PI;
				}
			}
			else
			{
				radian = atan(y / x);
				if(y > 0)
				{
					if(radian < 0)
					{
						radian += M_PI;
					}
				}
				else
				{
					if(radian >= 0)
					{
						radian += -M_PI;
					}
				}
			}
		}
		return radian;
	}

	TbVector2d::TbVector2d(const TbAbstractPoint2d *from,
		const TbAbstractPoint2d *to)
	{
		if(to)
		{
			if(from)
			{
				coordinate(to->getX() - from->getX(), to->getY() - from->getY());
			}
			else
			{
				coordinate(to->getX(), to->getY());
			}
		}
		else
		{
			if(from)
			{
				coordinate(-from->getX(), -from->getY());
			}
			else
			{
            	coordinate(0, 0);
            }
        }
    }

	TbVector2d::~TbVector2d()
	{

	}

	TbAbstractVector2d* TbVector2d::getUnitaryVector()const
	{
		return new TbUnitaryVector2d(getRadian());
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
