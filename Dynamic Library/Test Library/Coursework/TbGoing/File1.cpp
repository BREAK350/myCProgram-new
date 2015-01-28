//---------------------------------------------------------------------------
#define _UNICODE
#include <vcl.h>
#pragma hdrstop

#include <tchar.h>
#include "TbGoing.h"
#pragma argsused
#include "TbUnitaryVector2d.h"
#include "TbEvenSpeedable.h"
#include <iostream.h>

using namespace dynlib;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void f()
{
	TbSpeedable *speed = new TbEvenSpeedable(4);
	TbVector2d *position = new TbVector2d(0.0, 0.0);
	TbAbstractPoint2d *station = new TbVector2d(100, 100);

	TbGoing *go = new TbGoing(position, station, speed);
	go->moveToStation();

	delete go;
}
//---------------------------------------------------------------------------
int main()
{
	TCHAR c;
	String s("вікно й двері");
	_TCHAR *ws = s.c_str();
	cout<<ws[0];
	getchar();
	return 0;
}
//---------------------------------------------------------------------------

