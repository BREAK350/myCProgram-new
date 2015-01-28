//---------------------------------------------------------------------------
#ifndef regexH
#define regexH
#include <vcl.h>
#include <vector.h>
//---------------------------------------------------------------------------
namespace regex
{
	class AbstractExpression
	{
		private:
		public:
			virtual String getExpression() = 0;
			virtual ~AbstractExpression();
	};

	/*
		Описує послідовність операндів, між якими є операція.
		Приклад:
			a*b*c*d, де
				a,b,c,d - довільні вирази,
					  * - деяка операція, яка є асоціативною, тобто:
                a*b*c == a*(b*c) == (a*b)*c;
	*/
	class GroupExpression: public AbstractExpression
	{
		private:
			String operation;
			vector<AbstractExpression*> operands;
		public:
			void setOperation(const String &operation);
			void addOperand(AbstractExpression*);
			void addOperands(vector<AbstractExpression*> &operands);
            String getExpression();
	};

	class Symbol: public AbstractExpression
	{
		private:
			String symbol;
		public:
			void setSymbol(const String &symbol);
			String getExpression();
	};

	class Iteration: public AbstractExpression
	{
		private:
			AbstractExpression *operand;
		public:
			void setOperand(AbstractExpression *operand);
			String getExpression();
	};

	class Brackets: public AbstractExpression
	{
    	private:
			AbstractExpression *inside;
		public:
			void setInside(AbstractExpression *inside);
			String getExpression();
    };

	class ExpressionBuilder
	{
		public:
			AbstractExpression* parse(const String &regex);
			virtual AbstractExpression* parse(const String &regex,
				const int &begin, const int &end) = 0;
	};

	class RegexBuilder: public ExpressionBuilder
	{
		private:
			vector<AbstractExpression*> searchAlternative(const String &regex,
				const int &begin, const int &end);
			vector<AbstractExpression*> searchConcatenation(const String &regex,
				const int &begin, const int &end);
		public:
			AbstractExpression* parse(const String &regex,
				const int &begin, const int &end);
	};

	int index(const int &i)
	{
        return i + 1;
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
