//---------------------------------------------------------------------------
#ifndef TbSceneH
#define TbSceneH
//---------------------------------------------------------------------------
// classes
namespace dynlib
{
	namespace automaton
	{
		class TbScene;
	}
}
//---------------------------------------------------------------------------
// includes
#include <map.h>
#include <set.h>
#include "TbGroupState.h"
#include <vcl.h>
#include "scene_func.h"
#include "TbEvenSpeedable.h"
#include "TbIdName.h"
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace automaton
	{
		typedef int (*func_for_group)(TbGroupState *group);

		class TbScene: public TbAPoint2d
		{
			private:
				int currGroupName;
				map<int, TbGroupState*> groups;

				int currStateName;
				map<int, TbState*> states;

				map<TbState*, TbGroupState*> statesInGroup;

                TbAName *stateName;

				TbPoint2d *position;

				TbPoint2d *startPosition;

				bool resizable;
			private:
				TbGroupState* getGroup(const int &groupId);
				TbGroupState* getGroup(TbState *state);
				TbState* getState(const int &stateId);
				TbPoint2d** getGroupStations();

				void resize();
				int getDistanceBetweenGroups();
				int forEachGroup(func_for_group fg);
				int groupResizable(TbGroupState *group);
				TbGoing* generateGoing(const TbAPoint2d *center)const;
				void removeLinkTo(TbState *state);
				void removeState(TbState *state);
				void removeStateWithoutResizable(const int &stateId);
				TbPoint2d* getBeginStation(const TbAPoint2d *center)const;
			public:
				TbScene();
				~TbScene();
				/*
					Створює нову групу (порожню), повертає назву групи.
				*/
				int addGroup();

				/*
					Створює новий стан, додаючи його в групу з id = groupId,
					повертає назву стану.
				*/
				int addState(const int &groupId);

				/*
					Створює зв'язок з стану stateIdFrom в стан stateIdTo по
					символу symbol.
				*/
				void addLink(const int &fromStateId, const int &toStateId, const wchar_t &symbol);

				/*
					Видаляє групу groupId та усі стан, що входили в цю групу.
				*/
				void removeGroup(const int &groupId);

				/*
					Видаляє стан stateId і усі зв'язки з цього стану, та
					усі зв'язки до цього стану.
				*/
				void removeState(const int &stateId);

				int removeLink(const int &fromStateId, const int &toStateId, const wchar_t &symbol);

				void makeFirstState(const int &stateId);

				int moveState(const int &stateId, const int &toGroupId);

				/*
					Створюється нова група з груп groupsId,
					перший стан якої буде firstStateId.
					Повертається назва створеної групи.
				*/
				int unionGroups(const int &count, const int *groupsId);

				/*   ?
					Створює (new) масив назв станів, що входять в групу.
				*/
				int* getStates(const int &groupId);

				int getGroupCount()const;

				int getStateCount()const;

				void makeFinaleState(const int &stateId);

				/*
					Для малювання
				*/
				int hideGroup(const int &groupId);

				double getX()const; // get global x
				double getY()const; // get global y

				void paint(TCanvas *canvas);

				/*
					Повертає 0, якщо усе виконано, інакше >0
				*/
				int perform();

				void setPosition(TbPoint2d *position);
				void setStartPosition(TbPoint2d *startPosition);
		};
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
