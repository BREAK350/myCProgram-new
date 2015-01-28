//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbState.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace automaton
	{
		TbState::TbState(TbGroupState *group, const int &nameId)
		{
			this->group = group;
			this->nameId = nameId;
		}

		void TbState::addLink(TbState *stateTo, const wchar_t &symbol)
		{
			TbLink *link = getLink(stateTo);
			if(!link)
			{
				link = new TbLink(this, stateTo);
				links[stateTo] = link;
			}
			link->addSymbol(symbol);
		}

		TbLink* TbState::getLink(TbState *state)
		{
			TbLink *link = NULL;
			map<TbState*, TbLink*>::iterator it = links.find(state);
			if(it != links.end())
			{
				link = it->second;
			}
			return link;
		}

		void TbState::removeLink(TbState *state)
		{
			TbLink *link = getLink(state);
			if(link)
			{
				links.erase(state);
				delete link;
            }
		}

		int TbState::getNameId()const
		{
         	return nameId;
		}

		void TbState::setGoing(TbGoing *going)
		{
			this->going = going;
        }

		TbGoing* TbState::getGoing()const
		{
        	return going;
		}

		double TbState::getX()const
		{
        	return group->getX() + going->getPosition()->getX();
		}

		double TbState::getY()const
		{
        	return group->getY() + going->getPosition()->getY();
		}

		void TbState::paint(TCanvas *canvas, TbAName *stateName)
		{
			double x = getX();
			double y = getY();
			double left = x - 10;
			double top = y - 10;
			double right = x + 10;
			double bottom = y + 10;
			canvas->Ellipse(left, top, right, bottom);
			String name = stateName->getNameById(nameId);
			int tleft = canvas->TextWidth(name) / 2;
			int ttop = canvas->TextHeight(name) / 2;
			canvas->TextOutA(x - tleft, y - ttop, name);

			paintLinks(canvas);
		}

		void TbState::paintLinks(TCanvas *canvas)
		{
			for(map<TbState*, TbLink*>::iterator it = links.begin();
				it != links.end(); ++it)
			{
				it->second->paint(canvas);
            }
		}

		void TbState::makeFinale()
		{
         	finaleState = true;
		}

		int TbState::perform()
		{
			int res = going->moveToStation();
			for(map<TbState*, TbLink*>::iterator it = links.begin();
				it!= links.end(); ++it)
			{
				res += it->second->perform();
			}
			return res;
		}

		void TbState::setGroup(TbGroupState *group)
		{
        	this->group = group;
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
