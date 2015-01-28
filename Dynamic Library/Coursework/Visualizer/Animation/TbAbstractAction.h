//---------------------------------------------------------------------------
#ifndef TbAbstractActionH
#define TbAbstractActionH
#include "TbScene.h"
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace automaton
	{
		class TbAbstractAction
		{
			private:
				TbAbstractAction *nextAction;
			public:
				TbAbstractAction();
				TbAbstractAction(TbAbstractAction *nextAction);
				virtual ~TbAbstractAction();

				virtual void perform(TbScene *scene) = 0;
				virtual TbAbstractAction* getNextAction()const;

				void setNextAction(TbAbstractAction *nextAction);
		};
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
