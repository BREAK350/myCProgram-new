//---------------------------------------------------------------------------
#ifndef TbUnitaryVector2dH
#define TbUnitaryVector2dH
//---------------------------------------------------------------------------
// classes
namespace dynlib
{
	class TbUnitaryVector2d;
}
//---------------------------------------------------------------------------
// includes
#include "TbVector2d.h"
#include <math.h>
//---------------------------------------------------------------------------
namespace dynlib
{
	class TbUnitaryVector2d: public TbAVector2d
	{
		private:
			double radian;
		public:
			TbUnitaryVector2d();
			TbUnitaryVector2d(const double &radian);
			TbUnitaryVector2d(const TbAVector2d *rv);
			virtual ~TbUnitaryVector2d();

			virtual TbVector2d* getTbVector2d();

			virtual double getX()const;
			virtual double getY()const;
			virtual double getLength()const;
			virtual double getSignedRadian()const;

			virtual void reverse();
			virtual void reverseX();
			virtual void reverseY();
			virtual void rotate(const double &radian);
			virtual void rotate(const TbAVector2d *rv);
			virtual void setRadian(const double &radian);
			virtual void setRadian(const TbAVector2d *rv);
    };
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
