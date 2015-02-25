//---------------------------------------------------------------------------
#ifndef TbStateH
#define TbStateH
//---------------------------------------------------------------------------
// classes
namespace dynlib
{
	namespace automaton
	{
		class TbState;
	}
}
//---------------------------------------------------------------------------
// includes
#include <map.h>
#include <set.h>
#include "TbLink.h"
#include "TbGoing.h"
#include "TbGroupState.h"
#include <vcl.h>
#include "TbAName.h"
#include "TbIdentificatable.h"
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace automaton
	{
		class TbState: public TbAPoint2d, public TbIdentificatable
		{
			private:
				map<TbState*, TbLink*> links; // TbState* - ref, TbLink* - value
				TbGoing *going; // value
				TbGroupState *group;
				bool finaleState;
				int id;
			private:
				TbLink* getLink(TbState *stateTo);
			public:
				TbState() {}
				TbState(TbGroupState *group, const int &nameId);

				void addLink(TbState *stateTo, const wchar_t &symbol);
				void removeLink(TbState *state);
				void setGoing(TbGoing *going);
				void paint(TCanvas *canvas, TbAName *stateName);
				void paintLinks(TCanvas *canvas);
				void makeFinale();
				void setGroup(TbGroupState *group);
				void setId(const int &id);

				TbGoing* getGoing()const;

				double getX()const; // get global x
				double getY()const; // get global y

				int perform();
				int getNameId()const;
        };
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
