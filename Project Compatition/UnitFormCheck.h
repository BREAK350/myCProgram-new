//---------------------------------------------------------------------------

#ifndef UnitFormCheckH
#define UnitFormCheckH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include "UnitFormRegularExpression.h"
//---------------------------------------------------------------------------
class TFormCheck : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TEdit *Expression;
    TCheckBox *StepByStep;
    TBitBtn *BitBtnCheck;
    TLabel *Result;
    void __fastcall ExpressionChange(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall StepByStepClick(TObject *Sender);
    void __fastcall BitBtnCheckClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    int CurrQ,CurrS,Action;
    __fastcall TFormCheck(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCheck *FormCheck;
//---------------------------------------------------------------------------
#endif
