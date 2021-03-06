//---------------------------------------------------------------------------
#ifndef TbAPoint2dH
#define TbAPoint2dH
//---------------------------------------------------------------------------
// classes
namespace dynlib
{
	/**
		The TbAPoint2d class defines a point representing a location
		in (x, y) coordinate space.
		This class is only the abstract superclass for all objects that store
		2D coordinate. The actual storage representation of the coordinates
		is left to the subclass.

		@author Dmytro
	*/
	class TbAPoint2d;
}
//---------------------------------------------------------------------------
// includes
#include <math.h>
//---------------------------------------------------------------------------
namespace dynlib
{
	class TbAPoint2d
	{
		public:
			/**
				Method description
			*/
			virtual ~TbAPoint2d();
			/**
				Method description
				@returns ...
			*/
			virtual double getX()const = 0;
			/**
				Method description
				@returns ...
			*/
			virtual double getY()const = 0;
		// static
			/**
				Method description
				@param p1 ...
				@param p2 ...
				@returns ...
			*/
			static double getDistance(const TbAPoint2d *p1,
				const TbAPoint2d *p2);
			/**

			*/
			static double getDistance(const double &x1, const double &y1,
				const double &x2, const double &y2);
			/**

			*/
			static double getDistanceSq(const TbAPoint2d *p1,
				const TbAPoint2d *p2);
			/**

			*/
			static double getDistanceSq(const double &x1, const double &y1,
				const double &x2, const double &y2);
			/**
            	� ��� �������� ������� �����
			*/
	};
}
//---------------------------------------------------------------------------
#endif
