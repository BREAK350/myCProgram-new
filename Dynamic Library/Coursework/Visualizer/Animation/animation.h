//---------------------------------------------------------------------------
#ifndef animationH
#define animationH
#include "ns_automaton.h"
#include <iostream.h>
//---------------------------------------------------------------------------
namespace automaton
{
	class AbstractAction
	{
		private:
			AbstractAction *next;
		public:
            AbstractAction() { next = NULL; }
			virtual void 			perform(Scene &scene) {}
			virtual AbstractAction* getNextAction();
					void 			setNextAction(AbstractAction *action);
	};

	class ActionGroup: public AbstractAction
	{
		private:
			vector<AbstractAction*> actions;
		public:
			void perform(Scene &scene);
			AbstractAction* getFirstChild();
			void addAction(AbstractAction *action);
			~ActionGroup();
	};

	class CreatorAutomaton: public AbstractAction
	{

	};

	class CreatorLink: public AbstractAction
	{
		private:
			String stateFrom;
			String stateTo;
			String symbol;
		public:
			void setStateFrom(const String &stateFrom);
			void setStateTo(const String &stateTo);
			void setSymbol(const String &symbol);
			void perform(Scene &scene);
	};

	class CreatorState: public AbstractAction
	{
		private:
			String automatonName;
			String stateName;
			State *state;
		public:
			CreatorState();
			void setStateName(const String &name);
			void setAutomatonName(const String &name);
			void setState(State *state);
			void perform(Scene &scene);
    };
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
