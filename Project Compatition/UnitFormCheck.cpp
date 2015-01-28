//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormCheck.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormCheck *FormCheck;
//---------------------------------------------------------------------------
__fastcall TFormCheck::TFormCheck(TComponent* Owner)
    : TForm(Owner)
{
    Action=0;
    CurrQ=CurrS=0;
}
//---------------------------------------------------------------------------
void __fastcall TFormCheck::ExpressionChange(TObject *Sender)
{
    Result->Caption="Wait...";
    BitBtnCheck->Caption="Check";
    Action=0;
    CurrQ=CurrS=0;
}
//---------------------------------------------------------------------------
void __fastcall TFormCheck::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    this->Action=0;
    CurrQ=CurrS=0;    
}
//---------------------------------------------------------------------------
void __fastcall TFormCheck::StepByStepClick(TObject *Sender)
{
    if(StepByStep->Checked)
    {
        FormRegularExpression->ShowMDFA();
    }
}
//---------------------------------------------------------------------------
void __fastcall TFormCheck::BitBtnCheckClick(TObject *Sender)
{
    if(StepByStep->Checked)
    {
        Expression->SetFocus();
        Expression->SelStart=CurrS;
        Expression->SelLength=1;
        TGridRect gr;
        gr.Left=FormRegularExpression->MDFA.GetSymbolIndex(Expression->Text.c_str()[CurrS])+1;
        gr.Right=gr.Left;
        gr.Top=CurrQ+1;
        gr.Bottom=CurrQ+1;

        FormRegularExpression->Table->TopRow=1;
        FormRegularExpression->Table->LeftCol=1;
        if(FormRegularExpression->Table->LeftCol+gr.Left-1>=FormRegularExpression->Table->VisibleColCount)
        {
            FormRegularExpression->Table->LeftCol=gr.Left-FormRegularExpression->Table->VisibleColCount+1;
        }
        if(FormRegularExpression->Table->TopRow+gr.Top-1>=FormRegularExpression->Table->VisibleRowCount)
        {
            FormRegularExpression->Table->TopRow=gr.Top-FormRegularExpression->Table->VisibleRowCount+1;
        }
        FormRegularExpression->Table->Selection=gr;
		bool res=FormRegularExpression->MDFA.isOwnStepByStep(Expression->Text.t_str(),Action,CurrQ,CurrS);
        if(Action==0) // again
        {
            Action=1;
            BitBtnCheck->Caption="Next";
        }
        StepByStep->Checked=res;
    }
    else
    {
        Action=0;
        CurrQ=CurrS=0;
        BitBtnCheck->Caption="Check";
        Result->Caption="Wait...";
        if(FormRegularExpression->MDFA.isOwn(Expression->Text.t_str()))
        {
            Result->Caption="Belongs.";
        }
        else
        {
            Result->Caption="Not belongs.";
        }
    }
}
//---------------------------------------------------------------------------
