//---------------------------------------------------------------------------
#ifndef TbAModPoint2dH
#define TbAModPoint2dH
//---------------------------------------------------------------------------
// classes
namespace dynlib
{
	class TbAModPoint2d;
}
//---------------------------------------------------------------------------
// includes
#include "TbAPoint2d.h"
//---------------------------------------------------------------------------
namespace dynlib
{
	class TbAModPoint2d: public TbAPoint2d
	{
		public:
			virtual ~TbAModPoint2d();

			virtual void setX(const double &x) = 0;
			virtual void setY(const double &y) = 0;

			static void coordinate(TbAModPoint2d *point, const TbAPoint2d *to);
			static void coordinate(TbAModPoint2d *point, const double &x, const double &y);
			static void reverse(TbAModPoint2d *point);
			static void reverse(TbAModPoint2d *point, const TbAPoint2d *center);
			static void reverseX(TbAModPoint2d *point);
			static void reverseY(TbAModPoint2d *point);
			static void setMiddlePoint(TbAModPoint2d *point, const TbAPoint2d *p1, const TbAPoint2d *p2);
			static void setMiddlePoint(TbAModPoint2d *point, const double &x1, const double &y1,
				const double &x2, const double &y2);
			static void setMiddlePoint(TbAModPoint2d *point, const double &x1, const double &y1,
				const double &weight1, const double &x2, const double &y2, const double &weight2);
			static void setMiddlePoint(TbAModPoint2d *point, const TbAPoint2d *p1,
				const double &weight1, const TbAPoint2d *p2, const double &weight2);
	};
}
//---------------------------------------------------------------------------
#endif
