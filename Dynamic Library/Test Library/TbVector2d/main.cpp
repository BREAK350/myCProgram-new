//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "TbVector2d.h"
#include <iostream.h>
#include <tchar.h>
#pragma argsused
#include <conio.h>
#include "TbPoint2d.h"
#define extends :public
//---------------------------------------------------------------------------
using namespace dynlib;
//---------------------------------------------------------------------------
class TbVector3d extends TbVector2d
{
	private:
		double z;
};
//---------------------------------------------------------------------------
void testTbVector2d()
{
	TbVector2d *v = new TbVector2d(4, 7);
	TbAPoint2d *ap;
	ap = (TbPoint2d*)v;
	cout<<ap->getX();
}
//---------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	TbPoint2d p;
	testTbVector2d();
	getch();
	return 0;
}
//---------------------------------------------------------------------------
