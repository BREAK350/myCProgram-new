//---------------------------------------------------------------------------
#pragma hdrstop
#include "regex.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace regex // AbstractExpression
{
	AbstractExpression::~AbstractExpression()
	{
    }
}
//---------------------------------------------------------------------------
namespace regex // ExpressionBuilder
{
	AbstractExpression* ExpressionBuilder::parse(const String &regex)
	{
		return parse(regex, 0, regex.Length());
	}
}
//---------------------------------------------------------------------------
namespace regex
{
	AbstractExpression* RegexBuilder::parse(const String &regex,
				const int &begin, const int &end)
	{
		if(regex.IsEmpty())
		{
			Symbol *symbol = new Symbol();
			symbol->setSymbol('e');
			return symbol;
		}
		// search alternative
		vector<AbstractExpression*> alternative =
			searchAlternative(regex, begin, end);
		if(!alternative.empty())
		{
			GroupExpression *g_expr = new GroupExpression();
			g_expr->setOperation('|');
			g_expr->addOperands(alternative);
			return g_expr;
		}
		// search concatenation
		vector<AbstractExpression*> concatenations =
			searchConcatenation(regex, begin, end);
		if(!concatenations.empty())
		{
			if(concatenations.size() == 1)
			{
				return concatenations[0];
            }
			GroupExpression *g_expr = new GroupExpression();
			g_expr->setOperation('.');
			g_expr->addOperands(concatenations);
			return g_expr;
        }
		return NULL;
	}

	vector<AbstractExpression*> RegexBuilder::searchAlternative(
		const String &regex, const int &begin, const int &end)
	{
		vector<AbstractExpression*> exprs;
		int br = 0;
		int b = begin;
		for(int i = begin; i < end; i++)
		{
			if(br == 0)
			{
				if(regex[i + 1] == '|')
				{
					AbstractExpression *temp_expr = parse(regex, b, i);
					if(temp_expr)
					{
						exprs.push_back(temp_expr);
					}
					b = i + 1;
				}
			}
			if(regex[i + 1] == '(')
			{
				br++;
			}
			else
			if(regex[i + 1] == ')')
			{
				br--;
			}
		}
		if(b > begin)
		{
        	AbstractExpression *temp_expr = parse(regex, b, end);
			if(temp_expr)
			{
				exprs.push_back(temp_expr);
			}
        }
		return exprs;
	}

	vector<AbstractExpression*> RegexBuilder::searchConcatenation(
		const String &regex, const int &begin, const int &end)
	{
		vector<AbstractExpression*> exprs;
		int br = 0;
		int b = begin;
		int i = begin;
		while(i < end)
		{
			if(regex[i + 1] == '(')
			{
				br++;
				i++;
			}
			else
			if(regex[i + 1] == ')')
			{
				br--;
				if(br == 0)
				{
					int close_br = i;
					i++;
					while(i < end && regex[i + 1] == '*')
					{
						i++;
					}
					AbstractExpression *inside = parse(regex, b + 1, close_br);
					Brackets *brackets = new Brackets();
					brackets->setInside(inside);
					AbstractExpression *temp_expr = brackets;
					if(i - close_br > 1) // have '*'
					{
                    	Iteration *iteration = new Iteration();
						iteration->setOperand(brackets);
						temp_expr = iteration;
                    }
					exprs.push_back(temp_expr);
					b = i;
				}
			}
			else
			if(br == 0)
			{
				i++;
				while(i < end && regex[i + 1] == '*')
				{
					i++;
				}
				Symbol *symbol = new Symbol();
				symbol->setSymbol(regex[b + 1]);
				AbstractExpression *temp_expr = symbol;
				if(i - b > 1) // have '*'
				{
					Iteration *iteration = new Iteration();
					iteration->setOperand(symbol);
					temp_expr = iteration;
				}
                exprs.push_back(temp_expr);
				b = i;
			}
			else
			{
                i++;
            }
		}
		return exprs;
    }
}
//---------------------------------------------------------------------------
namespace regex // GroupExpression
{
	String GroupExpression::getExpression()
	{
		String expr = "";
		int size = operands.size();
		if(size > 1)
		{
			for(int i = 0; i < size - 1; i++)
			{
				expr += operands[i]->getExpression() + operation;
			}
			expr += operands[size - 1]->getExpression();
		}
		return expr;
	}

	void GroupExpression::setOperation(const String &operation)
	{
    	this->operation = operation;
	}

	void GroupExpression::addOperands(vector<AbstractExpression*> &operands)
	{
    	this->operands = operands;
    }
}
//---------------------------------------------------------------------------
namespace regex // Symbol
{
	String Symbol::getExpression()
	{
    	return symbol;
	}

	void Symbol::setSymbol(const String &symbol)
	{
    	this->symbol = symbol;
    }
}
//---------------------------------------------------------------------------
namespace regex // Brackets
{
	String Brackets::getExpression()
	{
    	return String('(') + inside->getExpression() + String(')');
	}

	void Brackets::setInside(AbstractExpression *inside)
	{
    	this->inside = inside;
    }
}
//---------------------------------------------------------------------------
namespace regex // Iteration
{
	void Iteration::setOperand(AbstractExpression *operand)
	{
		this->operand = operand;
	}

	String Iteration::getExpression()
	{
		return operand->getExpression() + '*';
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
