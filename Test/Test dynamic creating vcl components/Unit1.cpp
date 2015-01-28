//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
class TOnClick
{
	public:
		void onClick(TObject *sender);
};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	TButton *button = new TButton(this);
	button->SetBounds(10, 10, 130, 30);
	button->Caption = "Dynamic button";
	button->OnClick = buttonOnClick;

	this->InsertControl(button);
}
//---------------------------------------------------------------------------
void __fastcall  TForm1::buttonOnClick(TObject *sender)
{
	ShowMessage("Clicked!!!");
}
//---------------------------------------------------------------------------

