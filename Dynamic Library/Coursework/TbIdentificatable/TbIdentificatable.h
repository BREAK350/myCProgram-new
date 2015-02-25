//---------------------------------------------------------------------------
#ifndef TbIdentificatableH
#define TbIdentificatableH
//---------------------------------------------------------------------------
// classes
//---------------------------------------------------------------------------
// includes
namespace dynlib
{
	namespace automaton
	{
		class TbIdentificatable;
	}
}
//---------------------------------------------------------------------------
namespace dynlib
{
	namespace automaton
	{
		class TbIdentificatable
		{
			public:
				virtual int getId();
        };
	}
}
//---------------------------------------------------------------------------
#endif
