//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbPoint1d.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib
{
	TbPoint1d::TbPoint1d()
	{
		setValue(0);
	}

	TbPoint1d::TbPoint1d(const TbPoint1d *point)
	{
		setValue(point ? point->getValue() : 0);
	}

	TbPoint1d::TbPoint1d(const double &value)
	{
		setValue(value);
	}

	TbPoint1d::~TbPoint1d()
	{
	}

	void TbPoint1d::setValue(const double &value)
	{
    	this->value = value;
	}

	double TbPoint1d::getValue()const
	{
    	return value;
	}

	void TbPoint1d::reverse()
	{
		setValue(-getValue());
	}

	void TbPoint1d::reverse(const TbAPoint1d *center)
	{
		if(center)
		{
			double cv = center->getValue();
			if(cv)
			{
				double v = getValue() - cv;
                setValue(-v + cv);
			}
			else
			{
				reverse();
            }
		}
		else
		{
			reverse();
        }
	}

	TbPoint1d* TbPoint1d::getMiddlePoint(const TbAPoint1d *p1,
				const TbAPoint1d *p2)
	{
    	return getMiddlePoint(p1 ? p1->getValue() : 0, p2 ? p2->getValue() : 0);
	}

	TbPoint1d* TbPoint1d::getMiddlePoint(const double &v1, const double &v2)
	{
    	return new TbPoint1d((v1 + v2) / 2);
	}

	double TbPoint1d::getDistanceTo(const TbAPoint1d *point)
	{
    	return getDistance(this, point);
	}

	double TbPoint1d::getDistanceTo(const double &v)
	{
    	return getDistance(getValue(), v);
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

