//---------------------------------------------------------------------------
#pragma hdrstop
#include "animation.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace automaton // ActionGroup
{
	void ActionGroup::perform(Scene &scene)
	{
		int size = actions.size();
		for(int i = 0; i < size; i++)
		{
            actions[i]->perform(scene);
        }
	}

	ActionGroup::~ActionGroup()
	{
		int size = actions.size();
		for(int i = 0; i < size; i++)
		{
			delete actions[i];
		}
		actions.clear();
	}

	AbstractAction* ActionGroup::getFirstChild()
	{
		AbstractAction *firstChild = NULL;
		if(!actions.empty())
		{
			firstChild = actions[0];
		}
		return firstChild;
	}

	void ActionGroup::addAction(AbstractAction *action)
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
//---------------------------------------------------------------------------
namespace automaton // AbstractAction
{
	AbstractAction* AbstractAction::getNextAction()
	{
		return next;
	}

	void AbstractAction::setNextAction(AbstractAction *action)
	{
		if(next)
		{
			delete next;
		}
		next = action;
	}
}
//---------------------------------------------------------------------------
namespace automaton // CreatorState
{
	CreatorState::CreatorState()
	{

	}

	void CreatorState::setStateName(const String &name)
	{
		stateName = name;
	}

	void CreatorState::setAutomatonName(const String &name)
	{
		automatonName = name;
	}

	void CreatorState::setState(State *state)
	{
    	this->state = state;
    }

	void CreatorState::perform(Scene &scene)
	{
		if(state && !stateName.IsEmpty())
		{
			scene.addState(stateName, state);
			if(!automatonName.IsEmpty())
			{
				Automaton *a = scene.getAutomaton(automatonName);
				a->addState(stateName);
            }
        }
    }
}
//---------------------------------------------------------------------------
namespace automaton // CreatorLink
{
	void CreatorLink::setStateFrom(const String &stateFrom)
	{
		this->stateFrom = stateFrom;
	}

	void CreatorLink::setStateTo(const String &stateTo)
	{
		this->stateTo = stateTo;
	}

	void CreatorLink::setSymbol(const String &symbol)
	{
		this->symbol = symbol;
	}

	void CreatorLink::perform(Scene &scene)
	{

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
//---------------------------------------------------------------------------
