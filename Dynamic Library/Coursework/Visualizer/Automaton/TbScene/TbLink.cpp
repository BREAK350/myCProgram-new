//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbLink.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace automaton
	{
		TbLink::TbLink(TbAPoint2d *from, TbAPoint2d *to)
		{
			length = 0;
			speed = 2;
			this->from = from;
			this->to = to;
		}

		int TbLink::perform()
		{
			double len = TbAPoint2d::getDistance(from, to);
			if(length < len - speed)
			{
                length += speed;
			}
			else
			{
                length = len;
            }
        	return length < len;
		}

		String TbLink::getSymbolsAsString()
		{
			String symbs = "";
			for(set<wchar_t>::iterator it = symbols.begin();
				it != symbols.end(); ++it)
			{
				symbs += (*it);
			}
			return symbs;
		}

		void TbLink::addSymbol(wchar_t symbol)
		{
         	symbols.insert(symbol);
        }

		void TbLink::paint(TCanvas *canvas)
		{
			canvas->MoveTo(from->getX(), from->getY());
			if(from == to) // петля
			{

			}
			else
			{
				TbVector2d *link_ = TbVector2d::instance_(from, to);
				link_->setLength(length - 10);
				link_->shift(from->getX(), from->getY());
				canvas->LineTo(link_->getX(), link_->getY());
				delete link_;
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
