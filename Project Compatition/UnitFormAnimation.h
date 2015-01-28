//---------------------------------------------------------------------------

#ifndef UnitFormAnimationH
#define UnitFormAnimationH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "TbUFAd.h"
#include "UnitFormRegularExpression.h"
//---------------------------------------------------------------------------
class TFormAnimation : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TButton *ButtonStart;
    TEdit *EditRegularExpression;
    void __fastcall ButtonStartClick(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFormAnimation(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAnimation *FormAnimation;
extern Graphics::TBitmap *bmp;
//---------------------------------------------------------------------------
#endif
