//---------------------------------------------------------------------------
#ifndef TbVector2dH
#define TbVector2dH
#include <math.h>
#include "TbAbstractVector2d.h"
//---------------------------------------------------------------------------
namespace dynlib // Dynamic Library
{
	class TbVector2d: public TbAbstractVector2d
	{
		private:
			double x;
			double y;
		public:
			TbVector2d();
			TbVector2d(const double &x, const double &y);
			TbVector2d(const TbAbstractPoint2d *from,
				const TbAbstractPoint2d *to);
            virtual ~TbVector2d();

			TbAbstractVector2d* getUnitaryVector()const;

			bool equal(const TbVector2d *v)const;

			double getX()const;
			double getY()const;
			double getLength()const;
			double getSignedRadian()const;

			void setX(const double &x);
			void setY(const double &y);
			void setLength(const double &newLength);
			void setRadian(const double &radian);
			void setRadian(const TbAbstractVector2d *rv);
			void setRadian(const double &sin_radian, const double &cos_radian);
			void coordinate(const double &x, const double &y);
			void shift(const TbAbstractVector2d *dv);
			void shift(const double &dx, const double &dy);
			void reverse();
			void reverseX();
			void reverseY();
			void normalize();
			void mult(const double &d);
			void rotate(const double &radian);
			void rotate(const TbAbstractVector2d *rv);
			void rotate(const double &sin_radian, const double &cos_radian);
			void scale(const double &sx, const double &sy);
    };
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
