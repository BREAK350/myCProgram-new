//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbAVector2d.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib
{
	TbAVector2d::~TbAVector2d()
	{

	}

	double TbAVector2d::getSignedRadian()const
	{
		double x = getX();
		double y = getY();
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

	double TbAVector2d::getRadian()const
	{
    	double radian = getSignedRadian();
		if(radian < 0)
		{
			radian += 2 * M_PI;
		}
		return radian;
	}

	double TbAVector2d::getSignedRadianBetween(const TbAVector2d *v)const
	{
		return getSignedRadianBetween(this, v);
	}

	double TbAVector2d::getSignedRadianBetween(const TbAVector2d *v1,
				const TbAVector2d *v2)
	{
    	double radian = 0;
		if(v1 && v2)
		{
			radian = v2->getSignedRadian() - v1->getSignedRadian();
			if(radian > M_PI)
			{
				radian = radian - 2 * M_PI;
			}
		}
		return radian;
    }

	double TbAVector2d::getRadianBetween(const TbAVector2d *v)const
	{
    	return fabs(getSignedRadianBetween(v));
	}

	double TbAVector2d::scalar(const TbAVector2d *v)const
	{
		return getX() * v->getX() + getY() * v->getY();
	}

	double TbAVector2d::getLength()const
	{
     	return sqrt(getLengthSq());
	}

	double TbAVector2d::getLengthSq()const
	{
		double x = getX();
		double y = getY();
		return x * x + y * y;
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
//---------------------------------------------------------------------------
