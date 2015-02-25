//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbStateContainer.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace automaton
	{
		TbStateContainer::TbStateContainer()
		{
			count = 0;
			states_ = new map<int, TbState*>();
		}

		TbStateContainer::~TbStateContainer()
		{
			count = 0;
			forEach(removeState);
			delete states_;
			states_ = NULL;
		}

		TbState* TbStateContainer::addState()
		{
			int id = count++;
			TbState *state_ = new TbState();
			(*states_)[id] = state_;
			state_->setId(id);
			return state_;
		}

		TbState* TbStateContainer::getState(const int &id)
		{
			TbState *state = NULL;
			if(id >= 0 && id < count)
			{
				state = states_->operator [](id);
			}
			return state;
		}

		void TbStateContainer::removeState(TbState *state)
		{
        	delete state;
        }

		void TbStateContainer::forEach(StateAction stateAction)
		{
        	for(map<int, TbState*>::iterator it = states_->begin();
				it != states_->end(); ++it)
			{
				stateAction(it->second);
			}
        }
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
