//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormWeb.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TFormWeb *FormWeb;
//---------------------------------------------------------------------------
__fastcall TFormWeb::TFormWeb(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
