//---------------------------------------------------------------------------
#ifndef TbAPoint1dH
#define TbAPoint1dH
//---------------------------------------------------------------------------
// classes
namespace dynlib
{
	/**
		@author Dmytro
	*/
	class TbAPoint1d;
}
//---------------------------------------------------------------------------
// includes
#include <math.h>
//---------------------------------------------------------------------------
namespace dynlib
{
	class TbAPoint1d
	{
		public:
			virtual ~TbAPoint1d();

			virtual double getValue()const = 0;

			static double getDistance(const TbAPoint1d *p1, const TbAPoint1d *p2);
			static double getDistance(const double &v1, const double &v2);
	};
}
//---------------------------------------------------------------------------
#endif
