//---------------------------------------------------------------------------
#ifndef TbActionGroupH
#define TbActionGroupH
#include "TbAbstractAction.h"
#include <vector.h>
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace automaton
	{
		typedef vector<TbAbstractAction*> TbAbstractActions;

		class TbActionGroup: public TbAbstractAction
		{
        	private:
				TbAbstractActions actions;
			public:
				TbActionGroup();
				virtual ~TbActionGroup();

                TbAbstractAction* getFirstChild()const;

				void perform(TbScene *scene);
				void addAction(TbAbstractAction *action);
        };
	}
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
