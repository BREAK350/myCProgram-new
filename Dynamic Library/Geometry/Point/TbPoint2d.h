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
#include "TbAModPoint2d.h"
#include <vector.h>
//---------------------------------------------------------------------------
namespace dynlib
{
	class TbPoint2d: public TbAModPoint2d
	{
		private:
			double x;
			double y;
		public:
			TbPoint2d();
			TbPoint2d(const TbAPoint2d *point);
			TbPoint2d(const double &x, const double &y);
			virtual ~TbPoint2d();

			virtual double getDistanceTo(const TbAPoint2d *point);
			virtual double getDistanceTo(const double &x, const double &y);
			virtual double getDistanceSqTo(const TbAPoint2d *point);
			virtual double getDistanceSqTo(const double &x, const double &y);
			virtual double getX()const;
			virtual double getY()const;

			virtual void coordinate(const TbAPoint2d *point);
			virtual void coordinate(const double &x, const double &y);
			virtual void reverse();
			virtual void reverse(const TbAPoint2d *center);
			virtual void reverseX();
			virtual void reverseY();
			virtual void setX(const double &x);
			virtual void setY(const double &y);

			virtual int getQuarter()const;
			virtual int getQuarter(const TbAPoint2d *point)const;

			/**

			*/
			static TbPoint2d* getMiddlePoint(const TbAPoint2d *p1,
				const TbAPoint2d *p2);
			/**

			*/
			static TbPoint2d* getMiddlePoint(const TbAPoint2d *p1,
				const double &weight1, const TbAPoint2d *p2, const double &weight2);
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
