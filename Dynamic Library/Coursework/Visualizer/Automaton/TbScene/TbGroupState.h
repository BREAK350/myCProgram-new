//---------------------------------------------------------------------------
#ifndef TbGroupStateH
#define TbGroupStateH
//---------------------------------------------------------------------------
// classes
namespace dynlib
{
	namespace automaton
	{
		class TbGroupState;
	}
}
//---------------------------------------------------------------------------
// includes
#include "TbState.h"
#include <set.h>
#include "TbScene.h"
#include "TbAName.h"
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace automaton
	{
		class TbGroupState: public TbAPoint2d
		{
			private:
				TbState *firstState; // ref, не міститься в states
				set<TbState*> states; // ref

				TbGoing *going; // value

				TbScene *scene; // ref
				int nameId;
			public:
				TbGroupState(TbScene *scene, const int &nameId);

				bool hasState(TbState *state);

				void addState(TbState *state);
				void addStatesFrom(TbGroupState *group);
				void removeState(TbState *state);
				void removeLinkTo(TbState *state);
				void setFirstState(TbState *firstState);
				void paint(TCanvas *canvas, TbAName *stateName);
				void resize();
				void setGoing(TbGoing *going);

				TbState* getFirstState()const;
				set<TbState*>* getStates();

				TbGoing* getGoing()const;

				TbPoint2d** getStateStations();

				double getX()const; // get global x
				double getY()const; // get global y

				double getRadius()const;

				int perform();
				int getStateCount()const;
				int getDistanceBetweenStates()const;
				int getNameId()const;
        };
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
