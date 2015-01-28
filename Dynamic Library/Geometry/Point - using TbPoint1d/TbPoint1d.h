//---------------------------------------------------------------------------
#ifndef TbPoint1dH
#define TbPoint1dH
//---------------------------------------------------------------------------
// classes
namespace dynlib
{
	/**
		@author Dmytro
	*/
	class TbPoint1d;
}
//---------------------------------------------------------------------------
// includes
#include "TbAPoint1d.h"
//---------------------------------------------------------------------------
namespace dynlib
{
	class TbPoint1d: public TbAPoint1d
	{
		private:
			double value;
		public:
			TbPoint1d();
			TbPoint1d(const TbPoint1d *point);
			TbPoint1d(const double &value);
			virtual ~TbPoint1d();

			virtual double getDistanceTo(const TbAPoint1d *point);
			virtual double getDistanceTo(const double &v);
			double getValue()const;

			virtual void setValue(const double &value);
			virtual void reverse();
			virtual void reverse(const TbAPoint1d *center);
			/**

			*/
			static TbPoint1d* getMiddlePoint(const TbAPoint1d *p1,
				const TbAPoint1d *p2);
			/**

			*/
			static TbPoint1d* getMiddlePoint(const double &v1, const double &v2);
	};
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
