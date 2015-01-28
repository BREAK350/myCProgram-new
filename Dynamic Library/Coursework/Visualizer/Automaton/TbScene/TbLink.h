//---------------------------------------------------------------------------
#ifndef TbLinkH
#define TbLinkH
//---------------------------------------------------------------------------
// classes
namespace dynlib
{
	namespace automaton
	{
     	class TbLink;
	}
}
//---------------------------------------------------------------------------
// includes
#include <set.h>
#include <vcl.h>
#include "TbState.h"
#include "TbAPoint2d.h"
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace automaton
	{
		class TbLink
		{
			private:
				set<wchar_t> symbols;
				double length;
				double speed;

				TbAPoint2d *from;
				TbAPoint2d *to;
			public:
				TbLink(TbAPoint2d *from, TbAPoint2d *to);
				void addSymbol(wchar_t symbol);
				int perform();
				String getSymbolsAsString();

				void paint(TCanvas *canvas);
        };
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
