//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbGroupState.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace automaton
	{
		TbGroupState::TbGroupState(TbScene *scene, const int &nameId)
		{
			this->scene = scene;
			this->nameId = nameId;
			firstState = NULL;
		}

		void TbGroupState::addState(TbState *state)
		{
			if(state)
			{
				if(!firstState)
				{
					firstState = state;
					state->setGroup(this);
				}
				else
				if(state != firstState)
				{
					states.insert(state);
					state->setGroup(this);
                }
            }
		}

		void TbGroupState::removeState(TbState *state)
		{
			if(state == firstState)
			{
				firstState = NULL;
			}
			else
			{
				states.erase(state);
            }
		}

		void TbGroupState::removeLinkTo(TbState *state)
		{
			if(state)
			{
            	for(set<TbState*>::iterator it = states.begin();
					it != states.end(); ++it)
				{
					(*it)->removeLink(state);
				}
            }
        }

		void TbGroupState::setFirstState(TbState *firstState)
		{
			if(firstState)
			{
				if(hasState(firstState))
				{
					states.erase(firstState);
				}
			}
			this->firstState = firstState;
		}

		bool TbGroupState::hasState(TbState *state)
		{
			return states.find(state) != states.end();
		}

		TbState* TbGroupState::getFirstState()const
		{
        	return firstState;
		}

		set<TbState*>* TbGroupState::getStates()
		{
        	return &states;
		}

		int TbGroupState::getNameId()const
		{
         	return nameId;
		}

		void TbGroupState::addStatesFrom(TbGroupState *group)
		{
			if(group && group != this)
			{
				if(group->firstState)
				{
					scene->moveState(group->firstState->getNameId(), this->getNameId());
				}
				while(group->states.begin() != group->states.end())
				{
					scene->moveState((*(group->states.begin()))->getNameId(), this->getNameId());
				}
			}
		}

		TbPoint2d** TbGroupState::getStateStations()
		{
			int size = (firstState != 0) + states.size();
			TbPoint2d **stations = NULL;
			if(size > 0)
			{
				stations = new TbPoint2d* [size];
				int i = 0;
				if(firstState)
				{
					stations[i] = firstState->getGoing()->getStation();
					i = 1;
				}
				for(set<TbState*>::iterator it = states.begin();
					it != states.end(); ++it)
				{
					stations[i] = (*it)->getGoing()->getStation();
					i++;
                }
			}
			return stations;
		}

		double TbGroupState::getX()const
		{
			return scene->getX() + going->getPosition()->getX();
		}

		double TbGroupState::getY()const
		{
        	return scene->getY() + going->getPosition()->getY();
		}

		void TbGroupState::paint(TCanvas *canvas, TbAName *stateName)
		{
			if(firstState)
			{
				TColor col = canvas->Brush->Color;
				canvas->Brush->Color = clYellow;
				firstState->paint(canvas, stateName);
				canvas->Brush->Color = col;
			}
			for(set<TbState*>::iterator it = states.begin();
				it != states.end(); ++it)
			{
				(*it)->paint(canvas, stateName);
			}
		}

		int TbGroupState::perform()
		{
			int res = 0;
			if(getStateCount() > 0)
			{
				res = going->moveToStation();
				if(firstState)
				{
					res += firstState->perform();
                }
				for(set<TbState*>::iterator it = states.begin();
					it != states.end(); ++it)
				{
					res += (*it)->perform();
				}
			}
			else
			{
            	going->moveToStation();
            }
			return res;
		}

		TbGoing* TbGroupState::getGoing()const
		{
        	return going;
		}

		void TbGroupState::resize()
		{
        	TbPoint2d **points = getStateStations();
			if(points)
			{
				TbPoint2d *center = new TbPoint2d();
				allocateOnCircle(getStateCount(), getDistanceBetweenStates(),
					points, center, 0);
				delete center;
				delete points;
			}
		}

		int TbGroupState::getStateCount()const
		{
			return states.size() + (firstState != NULL);
		}

		int TbGroupState::getDistanceBetweenStates()const
		{
        	return 40;
        }

		void TbGroupState::setGoing(TbGoing *going)
		{
        	this->going = going;
		}

		double TbGroupState::getRadius()const
		{
			int count = getStateCount();
            double radius = 0;
			if(count > 1)
			{
				double dr = 2 * M_PI / count;
				radius = getDistanceBetweenStates() / sin(dr / 2);
			}
			return radius;
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
