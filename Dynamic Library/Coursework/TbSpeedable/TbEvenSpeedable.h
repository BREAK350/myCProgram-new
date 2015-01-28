//---------------------------------------------------------------------------
#ifndef TbEvenSpeedableH
#define TbEvenSpeedableH
#include "TbSpeedable.h"
//---------------------------------------------------------------------------
namespace dynlib // Dynamic Library
{
	class TbEvenSpeedable: public TbSpeedable
	{
		private:
			double speed;
		public:
			TbEvenSpeedable();
			TbEvenSpeedable(const double &speed);
			~TbEvenSpeedable();

			double getSpeed()const;

			void setSpeed(const double &speed);
    };
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
