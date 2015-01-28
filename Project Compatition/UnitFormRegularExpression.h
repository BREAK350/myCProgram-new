//---------------------------------------------------------------------------
#ifndef UnitFormRegularExpressionH
#define UnitFormRegularExpressionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
#include "TbUFA.h"
#include "TbDFA.h"
#include "UnitFormCheck.h"
#include "UnitFormAnimation.h"
//---------------------------------------------------------------------------
class TFormRegularExpression : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TEdit *RegularExp;
    TBitBtn *BitBtnCreate;
    TRadioButton *RadioButtonUndetermined;
    TRadioButton *RadioButtonDetermined;
    TRadioButton *RadioButtonMinimized;
    TStringGrid *Table;
    TBitBtn *BitBtnShow;
    TBitBtn *BitBtnCheck;
    TBitBtn *BitBtnHelp;
    void __fastcall RegularExpChange(TObject *Sender);
    void __fastcall RadioButtonUndeterminedClick(TObject *Sender);
    void __fastcall RadioButtonDeterminedClick(TObject *Sender);
    void __fastcall RadioButtonMinimizedClick(TObject *Sender);
    void __fastcall BitBtnHelpClick(TObject *Sender);
    void __fastcall BitBtnCreateClick(TObject *Sender);
    void __fastcall BitBtnCheckClick(TObject *Sender);
    void __fastcall BitBtnShowClick(TObject *Sender);
private:	// User declarations
    bool RegChanges;
public:		// User declarations
    TbUFA UFA;
    TbDFA DFA,MDFA;
    void ShowUFA();
    void ShowDFA(const TbDFA &DFA);
    void ShowMDFA();
    __fastcall TFormRegularExpression(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRegularExpression *FormRegularExpression;
//---------------------------------------------------------------------------
#endif
