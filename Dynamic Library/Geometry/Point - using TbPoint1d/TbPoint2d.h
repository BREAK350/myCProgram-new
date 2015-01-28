//---------------------------------------------------------------------------
#ifndef TbPoint2dH
#define TbPoint2dH
//---------------------------------------------------------------------------
// classes
namespace dynlib
{
	/**
		@author Dmytro
	*/
	class TbPoint2d;
}
//---------------------------------------------------------------------------
// includes
#include "TbAPoint2d.h"
#include "TbPoint1d.h"
#include <vector.h>
//---------------------------------------------------------------------------
namespace dynlib
{
	class TbPoint2d: public TbAPoint2d
	{
		private:
			TbPoint1d *x; // value, завжди є
			TbPoint1d *y; // value, завжди є
		public:
			TbPoint2d();
			TbPoint2d(const TbAPoint2d *point);
			TbPoint2d(const double &x, const double &y);
			TbPoint2d(TbPoint1d *x, TbPoint1d *y);
			virtual ~TbPoint2d();

			virtual double getDistanceTo(const TbAPoint2d *point);
			virtual double getDistanceTo(const double &x, const double &y);
			virtual double getDistanceSqTo(const TbAPoint2d *point);
			virtual double getDistanceSqTo(const double &x, const double &y);
			virtual double getX()const;
			virtual double getY()const;

			virtual TbPoint1d* getXProjection()const;
			virtual TbPoint1d* getYProjection()const;

			virtual void coordinate(const TbAPoint2d *point);
			virtual void coordinate(const double &x, const double &y);
			virtual void reverse();
			virtual void reverse(const TbAPoint2d *center);
			virtual void reverseX();
			virtual void reverseY();
			virtual void setX(const double &x);
			virtual void setY(const double &y);

			/**

			*/
			static TbPoint2d* getMiddlePoint(const TbAPoint2d *p1,
				const TbAPoint2d *p2);
			/**

			*/
			static TbPoint2d* getMiddlePoint(const double &x1, const double &y1,
				const double &x2, const double &y2);
			/**

			*/
			static TbPoint2d* getMiddlePoint(const double &x1, const double &y1,
				const double &weight1, const double &x2, const double &y2,
				const double &weight2);

    };
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
