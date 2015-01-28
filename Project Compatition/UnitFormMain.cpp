//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "UnitFormMain.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::BitBtnRegularExpressionClick(TObject *Sender)
{
    FormRegularExpression->Show();     
}
//---------------------------------------------------------------------------

