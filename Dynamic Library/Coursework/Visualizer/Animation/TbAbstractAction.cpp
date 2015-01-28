//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbAbstractAction.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace automaton
	{
		TbAbstractAction::TbAbstractAction()
		{
			nextAction = 0;
		}

		TbAbstractAction::TbAbstractAction(TbAbstractAction *nextAction)
		{
			this->nextAction = nextAction;
		}

		TbAbstractAction::~TbAbstractAction()
		{
			nextAction = 0;
		}

		TbAbstractAction* TbAbstractAction::getNextAction()const
		{
			return nextAction;
        }

		void TbAbstractAction::setNextAction(TbAbstractAction *nextAction)
		{
			nextAction = nextAction;
        }
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
