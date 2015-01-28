//---------------------------------------------------------------------------

#ifndef UnitFormWebH
#define UnitFormWebH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "SHDocVw_OCX.h"
#include <OleCtrls.hpp>
//---------------------------------------------------------------------------
class TFormWeb : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TCppWebBrowser *CppWebBrowser1;
private:	// User declarations
public:		// User declarations
    __fastcall TFormWeb(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormWeb *FormWeb;
//---------------------------------------------------------------------------
#endif
