//---------------------------------------------------------------------------
#ifndef TbGoingH
#define TbGoingH
//---------------------------------------------------------------------------
// classes
namespace dynlib // Dynamic Library
{
	class TbGoing;
}
//---------------------------------------------------------------------------
// includes
#include "TbVector2d.h"
#include "TbSpeedable.h"
//---------------------------------------------------------------------------
namespace dynlib // Dynamic Library
{
	class TbGoing
	{
		private:
			TbVector2d *position; // value
			TbPoint2d *station; // value
			TbSpeedable *speedable; // value
		public:
			/*
				position і station завжди не порожні.
                speedable може дорівнювати NULL.
			*/
			TbGoing();
			TbGoing(TbVector2d *position, TbPoint2d *station,
				TbSpeedable *speedable);
			virtual ~TbGoing();

			bool moveToStation();

			void setPosition(TbVector2d *position);
			void setStation(TbPoint2d *station);
			void setSpeedable(TbSpeedable *speedable);

			TbVector2d* getPosition()const;

			TbPoint2d* getStation()const;

			TbSpeedable* getSpeedable()const;
    };
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
