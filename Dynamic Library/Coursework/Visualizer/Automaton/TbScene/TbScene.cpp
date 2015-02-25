//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbScene.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace automaton
	{
		TbScene::TbScene()
		{
			currStateName = 0;
			currGroupName = 0;

			stateName = new TbIdName();

			resizable = true;
		}

		TbScene::~TbScene()
		{
			delete stateName;
		}

		TbGoing* TbScene::generateGoing(const TbAPoint2d *center)const
		{
        	TbGoing *going = new TbGoing();
			TbPoint2d *station = getBeginStation_(center);
			TbVector2d *position = new TbVector2d();
			TbEvenSpeedable *speed = new TbEvenSpeedable();
			speed->setSpeed(2);
			going->setPosition(position);
			going->setStation(station);
			going->setSpeedable(speed);
			return going;
        }

		int TbScene::addGroup()
		{
			TbGroupState *group = new TbGroupState(this, currGroupName);

			TbGoing *going = generateGoing(this);

			group->setGoing(going);
			groups[currGroupName] = group;
			resize();
			return currGroupName++;
		}

		int TbScene::addState(const int &groupId)
		{
			TbGroupState *group = getGroup(groupId);
			if(group)
			{
				TbState *state = new TbState(group, currStateName);

				TbGoing *going = generateGoing(group);

				state->setGoing(going);
				states[currStateName] = state;
				group->addState(state);
				statesInGroup[state] = group;

				resize();
				return currStateName++;
			}
			return -1;
		}

		void TbScene::resize()
		{
			if(resizable)
			{
				TbPoint2d **points = getGroupStations();
				if(points)
				{
					for(map<int, TbGroupState*>::iterator it = groups.begin();
						it != groups.end(); ++it)
					{
						it->second->resize();
					}
					TbPoint2d *center = new TbPoint2d();
					allocateOnCircle(getGroupCount(), getDistanceBetweenGroups(),
						points, center, 0);
					delete center;
					delete points;
				}
            }
		}

		int TbScene::groupResizable(TbGroupState *group)
		{
			group->resize();
			return 0;
        }

		int TbScene::forEachGroup(func_for_group fg)
		{
			int res = 0;
			for(map<int, TbGroupState*>::iterator it = groups.begin();
				it != groups.end(); ++it)
			{
				res += fg(it->second);
			}
			return res;
        }

		void TbScene::addLink(const int &fromStateId, const int &toStateId, const wchar_t &symbol)
		{
			TbState *stateFrom = getState(fromStateId);
			TbState *stateTo = getState(toStateId);
			if(stateFrom && stateTo)
			{
				stateFrom->addLink(stateTo, symbol);
			}
		}

		TbGroupState* TbScene::getGroup(const int &groupId)
		{
			TbGroupState *group = NULL;
			map<int, TbGroupState*>::iterator it = groups.find(groupId);
			if(it != groups.end())
			{
				group = it->second;
			}
			return group;
		}

		TbState* TbScene::getState(const int &stateId)
		{
			TbState *state = NULL;
			map<int, TbState*>::iterator it = states.find(stateId);
			if(it != states.end())
			{
				state = it->second;
			}
			return state;
		}

		void TbScene::removeGroup(const int &groupId)
		{
			TbGroupState *group = getGroup(groupId);
			if(group)
			{

				groups.erase(groupId);
            }
		}

		void TbScene::removeState(const int &stateId)
		{
			removeStateWithoutResizable(stateId);
			resize();
		}

		void TbScene::removeLinkTo(TbState *state)
		{
        	for(map<int, TbGroupState*>::iterator it = groups.begin();
				it != groups.end(); ++it)
			{
				it->second->removeLinkTo(state);
			}
		}

		void TbScene::removeStateWithoutResizable(const int &stateId)
		{
        	TbState *state = getState(stateId);
			if(state)
			{
				removeState(state);
				states.erase(stateId);
				statesInGroup.erase(state);
				delete state;
			}
        }

		void TbScene::removeState(TbState *state)
		{
			removeLinkTo(state);
        }

		TbGroupState* TbScene::getGroup(TbState *state)
		{
        	return statesInGroup[state];
        }

		int TbScene::moveState(const int &stateId, const int &toGroupId)
		{
			TbState *state = getState(stateId);
			if(state)
			{
				TbGroupState *fromGroup = getGroup(state);
				TbGroupState *toGroup = getGroup(toGroupId);
				if(fromGroup != toGroup && toGroup)
				{
					fromGroup->removeState(state);
					toGroup->addState(state);
					TbVector2d *shift_ = TbVector2d::instance_(toGroup, fromGroup);
					state->getGoing()->getPosition()->shift(shift_);
					delete shift_;
					statesInGroup[state] = toGroup;
					resize();
					return 1;
                }
			}
			return 0;
		}

		void TbScene::makeFirstState(const int &stateId)
		{
			TbState *state = getState(stateId);
            TbGroupState *group = getGroup(state);
			if(state && group)
			{
                group->setFirstState(state);
            }
		}

		int TbScene::unionGroups(const int &count, const int *groupsId)
		{
			resizable = false;
			int groupId = addGroup();
			TbGroupState *newGroup = getGroup(groupId);
			for(int i = 0; i < count; i++)
			{
				TbGroupState *group = getGroup(groupsId[i]);
				if(group)
				{
					newGroup->addStatesFrom(group);
				}
			}
			resizable = true;
			resize();
			return groupId;
		}

		double TbScene::getX()const
		{
			return position->getX();
		}

		double TbScene::getY()const
		{
        	return position->getY();
		}

		void TbScene::paint(TCanvas *canvas)
		{
			for(map<int, TbGroupState*>::iterator it = groups.begin();
				it != groups.end(); ++it)
			{
				it->second->paint(canvas, stateName);
			}
		}

		void TbScene::makeFinaleState(const int &stateId)
		{
			TbState *state = getState(stateId);
			if(state)
			{
				state->makeFinale();
			}
		}

		int TbScene::perform()
		{
			int res = 0;
			for(map<int, TbGroupState*>::iterator it = groups.begin();
				it != groups.end(); ++it)
			{
				res += it->second->perform();
			}
			return res;
		}

		int TbScene::getGroupCount()const
		{
			return groups.size();
		}

		int TbScene::getStateCount()const
		{
			return states.size();
		}

		TbPoint2d** TbScene::getGroupStations()
		{
			int size = groups.size();
			TbPoint2d **stations = NULL;
			if(size > 0)
			{
				stations = new TbPoint2d* [size];
				int i = 0;
				for(map<int, TbGroupState*>::iterator it = groups.begin();
					it != groups.end(); ++it)
				{
					stations[i] = it->second->getGoing()->getStation();
					i++;
				}
			}
			return stations;
		}

		int TbScene::getDistanceBetweenGroups()
		{
			double maxRadius = 0;
			for(map<int, TbGroupState*>::iterator it = groups.begin();
				it != groups.end(); ++it)
			{
				double radius = it->second->getRadius();
				if(radius > maxRadius)
				{
					maxRadius = radius;
				}
			}
			return maxRadius + 40;
		}

		void TbScene::setPosition(TbPoint2d *position)
		{
			this->position = position;
		}

		void TbScene::setStartPosition(TbPoint2d *startPosition)
		{
			this->startPosition = startPosition;
		}

		TbPoint2d* TbScene::getBeginStation_(const TbAPoint2d *center)const
		{
        	return TbVector2d::instance_(center, startPosition);
        }
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
