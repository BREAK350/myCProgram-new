//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int groupCount;
int groupId;
Graphics::TBitmap * bmp = new Graphics::TBitmap();
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	center = new TbVector2d();
	whenMouseDown = NULL;
	scene = new TbScene();
	scene->setPosition(center);
	scene->addGroup();
	groupCount = 1;
	groupId = 0;

	mouseInfinity = true;
	sceneOnPause = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	//int groupId = random(groupCount);
	groupId++;
	if(groupId >= groupCount)
	{
        groupId = 0;
    }
	scene->addState(groupId);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	int perform = sceneOnPause ? 0 : scene->perform();
	if(perform > 0 || whenMouseDown)
	{
		bmp->Canvas->Rectangle(0, 0, bmp->Width, bmp->Height);
		scene->paint(bmp->Canvas);
		Canvas->Draw(Padding->Left, Padding->Top, bmp);
	}
	Button1->Caption = perform;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	scene->addGroup();
	groupCount++;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
	bmp->SetSize(ClientWidth - Padding->Left - Padding->Right, ClientHeight - Padding->Top - Padding->Bottom);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::mouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
 	whenMouseDown = new TbPoint2d(X, Y);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::mouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	if(whenMouseDown)
	{
		TbPoint2d *mouse = new TbPoint2d(X, Y);
		TbVector2d *dir = new TbVector2d(whenMouseDown, mouse);
		center->shift(dir);
		whenMouseDown->coordinate(mouse);
		delete mouse;
		delete dir;

		if(mouseInfinity)
		{
			int left = Padding->Left;
			int top = Padding->Top;
			int width = ClientWidth - Padding->Left - Padding->Right;
			int height = ClientHeight - Padding->Top - Padding->Bottom;
			TPoint pos;
			GetCursorPos(&pos);

			if(X <= left)
			{
				int x = pos.x + width - 1;
				whenMouseDown->coordinate(X + width - 1, Y);
				SetCursorPos(x, pos.y);
			}
			else
			if(X >= width + left)
			{
				int x = pos.x - width + 1;
				whenMouseDown->coordinate(X - width + 1, Y);
				SetCursorPos(x, pos.y);
			}
			if(Y <= top)
			{
				int y = pos.y + height - 1;
				whenMouseDown->coordinate(X, Y + height - 1);
				SetCursorPos(pos.x, y);
			}
			else
			if(Y >= height + top)
			{
				int y = pos.y - height + 1;
				whenMouseDown->coordinate(X, Y - height + 1);
				SetCursorPos(pos.x, y);
            }
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::mouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
  	delete whenMouseDown;
	whenMouseDown = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int stateId;
	int toGroupId;
	do
	{
		stateId = random(scene->getStateCount());
		toGroupId = random(scene->getGroupCount());
	}
	while(scene->moveState(stateId, toGroupId) == 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int *groupsId = new int [groupCount];
	for(int i = 0; i < groupCount; i++)
	{
		groupsId[i] = i;
	}
	scene->unionGroups(groupCount, groupsId);
	groupCount++;
	delete groupsId;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	int s1 = random(scene->getStateCount());
	int s2 = s1;
	do
	{
		s2 = random(scene->getStateCount());
	}
	while(s1 == s2);
	scene->addLink(s1, s2, L'l');
}
//---------------------------------------------------------------------------

