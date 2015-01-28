//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormAnimation.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAnimation *FormAnimation;
Graphics::TBitmap *bmp=new Graphics::TBitmap;
//---------------------------------------------------------------------------
__fastcall TFormAnimation::TFormAnimation(TComponent* Owner)
    : TForm(Owner)
{
    Top=0;
    Left=0;
    bmp->Width=1300;
    bmp->Height=700;
    bmp->Canvas->Font=Canvas->Font;
}
//---------------------------------------------------------------------------
void __fastcall TFormAnimation::ButtonStartClick(TObject *Sender)
{
    int Number=0;
    ButtonStart->Caption="Wait...";
    TbUFAd UFA(bmp->Canvas);
    EditRegularExpression->Text=FormRegularExpression->RegularExp->Text;
    //EditRegularExpression->Repaint();
    EditRegularExpression->SetFocus();
    UFA.Create(EditRegularExpression->Text.t_str(),bmp->Canvas,Number);
    ButtonStart->Caption="Performed";
}
//---------------------------------------------------------------------------
void __fastcall TFormAnimation::FormActivate(TObject *Sender)
{
    Top=0;
    Left=0;
    ButtonStart->Caption="Start";    
}
//---------------------------------------------------------------------------
