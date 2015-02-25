//---------------------------------------------------------------------------
#ifndef TbStateContainerH
#define TbStateContainerH
//---------------------------------------------------------------------------
// classes
namespace dynlib
{
	namespace automaton
	{
		class TbStateContainer;
	}
}
//---------------------------------------------------------------------------
// includes
#include "TbState.h"
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace automaton
	{
		typedef void (StateAction)(TbState *state);

		class TbStateContainer
		{
			private:
				int count;
				map<int, TbState*> *states_;
			private:
				static void removeState(TbState *state);
			public:
				TbStateContainer();
				~TbStateContainer();

				TbState* addState();
				TbState* getState(const int &id);

				void forEach(StateAction stateAction);
        };
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
