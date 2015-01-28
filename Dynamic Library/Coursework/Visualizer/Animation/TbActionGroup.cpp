//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbActionGroup.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace automaton
	{
		TbActionGroup::TbActionGroup()
		{

		}

		void TbActionGroup::perform(TbScene *scene)
		{
			int size = actions.size();
			for(int i = 0; i < size; i++)
			{
				actions[i]->perform(scene);
			}
		}

		TbActionGroup::~TbActionGroup()
		{
			int size = actions.size();
			for(int i = 0; i < size; i++)
			{
				delete actions[i];
			}
			actions.clear();
		}

		TbAbstractAction* TbActionGroup::getFirstChild()const
		{
			TbAbstractAction *firstChild = NULL;
			if(!actions.empty())
			{
				firstChild = actions[0];
			}
			return firstChild;
		}

		void TbActionGroup::addAction(TbAbstractAction *action)
		{
			if(action)
			{
				actions.push_back(action);
				int size = actions.size();
				if(size > 1)
				{
					actions[size - 2]->setNextAction(action);
				}
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
