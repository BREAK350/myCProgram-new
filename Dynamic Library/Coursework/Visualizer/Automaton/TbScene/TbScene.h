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
					������� ���� ����� (�������), ������� ����� �����.
				*/
				int addGroup();

				/*
					������� ����� ����, ������� ���� � ����� � id = groupId,
					������� ����� �����.
				*/
				int addState(const int &groupId);

				/*
					������� ��'���� � ����� stateIdFrom � ���� stateIdTo ��
					������� symbol.
				*/
				void addLink(const int &fromStateId, const int &toStateId, const wchar_t &symbol);

				/*
					������� ����� groupId �� �� ����, �� ������� � �� �����.
				*/
				void removeGroup(const int &groupId);

				/*
					������� ���� stateId � �� ��'���� � ����� �����, ��
					�� ��'���� �� ����� �����.
				*/
				void removeState(const int &stateId);

				int removeLink(const int &fromStateId, const int &toStateId, const wchar_t &symbol);

				void makeFirstState(const int &stateId);

				int moveState(const int &stateId, const int &toGroupId);

				/*
					����������� ���� ����� � ���� groupsId,
					������ ���� ��� ���� firstStateId.
					����������� ����� �������� �����.
				*/
				int unionGroups(const int &count, const int *groupsId);

				/*   ?
					������� (new) ����� ���� �����, �� ������� � �����.
				*/
				int* getStates(const int &groupId);

				int getGroupCount()const;

				int getStateCount()const;

				void makeFinaleState(const int &stateId);

				/*
					��� ���������
				*/
				int hideGroup(const int &groupId);

				double getX()const; // get global x
				double getY()const; // get global y

				void paint(TCanvas *canvas);

				/*
					������� 0, ���� ��� ��������, ������ >0
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
