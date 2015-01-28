//---------------------------------------------------------------------------
#ifndef TbAVector2dH
#define TbAVector2dH
//---------------------------------------------------------------------------
// classes
namespace dynlib
{
	/**
		@author Dmytro
	*/
	class TbVector2d;
}
//---------------------------------------------------------------------------
// includes
#include "TbAPoint2d.h"
#include <math.h>
//---------------------------------------------------------------------------
namespace dynlib
{
	class TbAVector2d: public TbAPoint2d
	{
		public:
			~TbAVector2d();

			/**

			*/
			virtual double getLength()const;
			/**

			*/
			virtual double getLengthSq()const;
			/**
				Повертає кут в межах [0; 2 * M_PI]
			*/
			virtual double getRadian()const;
			/**
				Повертає кут в межах [-M_PI; M_PI]
			*/
			virtual double getSignedRadian()const;
			/**

			*/
			virtual double getSignedRadianBetween(const TbAVector2d *v)const;
			/**

			*/
			virtual double getRadianBetween(const TbAVector2d *v)const;
			/**

			*/
			virtual double scalar(const TbAVector2d *v)const;
			/**

			*/
			static double getSignedRadianBetween(const TbAVector2d *v1,
				const TbAVector2d *v2);
			/**
            	Чи є вектори колінеарні (парарельні)
			*/
    };
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
