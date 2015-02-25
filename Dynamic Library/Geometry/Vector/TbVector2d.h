//---------------------------------------------------------------------------
#ifndef TbVector2dH
#define TbVector2dH
//---------------------------------------------------------------------------
// classes
namespace dynlib
{
	class TbVector2d;
}
//---------------------------------------------------------------------------
// includes
#include <math.h>
#include "TbAVector2d.h"
#include "TbUnitaryVector2d.h"
#include "TbPoint2d.h"
//---------------------------------------------------------------------------
namespace dynlib // Dynamic Library
{
	class TbVector2d:public TbPoint2d, public TbAVector2d
	{
		public:
			TbVector2d();
            virtual ~TbVector2d();

			virtual TbUnitaryVector2d* getUnitaryVector_()const;

			virtual double getX()const;
			virtual double getY()const;

			virtual void mult(const double &d);
			virtual void normalize();
			virtual void rotate(const double &radian);
			virtual void rotate(const TbAVector2d *rv);
			virtual void rotate(const double &sin_radian, const double &cos_radian);
            virtual void scale(const double &sx, const double &sy);
			virtual void setLength(const double &newLength);
			virtual void setRadian(const double &radian);
			virtual void setRadian(const TbAVector2d *rv);
			virtual void setRadian(const double &sin_radian, const double &cos_radian);
			virtual void shift(const TbAVector2d *dv);
			virtual void shift(const double &dx, const double &dy);

			static TbVector2d* instance_(const TbAPoint2d *from,
				const TbAPoint2d *to);
    };
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
