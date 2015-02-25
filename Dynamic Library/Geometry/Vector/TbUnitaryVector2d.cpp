//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbUnitaryVector2d.h"
#include "TbVector2d.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib
{
	TbUnitaryVector2d::TbUnitaryVector2d()
	{
    	radian = 0;
	}

	TbUnitaryVector2d::~TbUnitaryVector2d()
	{

	}

	double TbUnitaryVector2d::getX()const
	{
    	return cos(radian);
	}

	double TbUnitaryVector2d::getY()const
	{
		return sin(radian);
	}

	double TbUnitaryVector2d::getLength()const
	{
		return 1;
	}

	double TbUnitaryVector2d::getSignedRadian()const
	{
		return radian;
	}

	void TbUnitaryVector2d::rotate(const double &radian)
	{
		if(radian)
		{
			setRadian(this->radian + radian);
		}
	}

	void TbUnitaryVector2d::reverse()
	{
    	rotate(M_PI);
	}

	void TbUnitaryVector2d::reverseX()
	{
		if(radian >= 0)
		{
			radian = M_PI - radian;
		}
		else
		{
        	radian = - M_PI - radian;
        }
	}

	void TbUnitaryVector2d::reverseY()
	{
    	radian = -radian;
	}

	void TbUnitaryVector2d::rotate(const TbAVector2d *rv)
	{
		if(rv)
		{
			rotate(rv->getRadian());
		}
	}

	void TbUnitaryVector2d::setRadian(const double &radian)
	{
		double sr = radian + M_PI;
		int k = sr / (2 * M_PI);
		this->radian = sr - k * 2 * M_PI - M_PI;
	}

	void TbUnitaryVector2d::setRadian(const TbAVector2d *rv)
	{
		if(rv)
		{
			setRadian(rv->getRadian());
        }
	}

	TbVector2d* TbUnitaryVector2d::getTbVector2d_()
	{
		TbVector2d *v_ = new TbVector2d();
		v_->coordinate(getX(), getY());
		return v_;
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
