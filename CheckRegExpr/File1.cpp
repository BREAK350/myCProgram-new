//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#pragma argsused
#include <iostream.h>
#include <conio.h>
#include "regex.h"
using namespace regex;
//---------------------------------------------------------------------------
typedef bool (*corr_symb)(const char &ch);
//---------------------------------------------------------------------------
bool isCorrectSymbol(const char &ch)
{
    return ch == '0' | ch == '1';
}
//---------------------------------------------------------------------------
bool check(const String &regexp, corr_symb cs)
{
	bool correct = false;
	if(!regexp.IsEmpty())
	{
		correct = true;
		int i = 0;
		int br = 0;
		int symb = 0; // 0 - нема попереднього символа
		while(correct && regexp[i + 1])
		{
			if(regexp[i + 1] == '(')
			{
				br++;
				symb = 0;
			}
			else
			if(regexp[i + 1] == ')')
			{
				br--;
				correct = (br >= 0 && symb == 1);
				symb = 1;
			}
			else
			if(regexp[i + 1] == '|')
			{
				correct = (symb == 1);
				symb = 0;
			}
			else
			if(regexp[i + 1] == '*')
			{
            	correct = (symb == 1);
			}
			else
			{
				correct = corr_symb(regexp[i + 1]);
				symb = 1;
			}
			i++;
		}
		correct = (correct && br >= 0 && !regexp[i + 1] && symb == 1);
	}
	return correct;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void simplifyBracketsChange(int *temp, const int &begin, const int &end,
	const int &level)
{
	int imin = begin;
	while(imin < end && temp[imin] < 0)
	{
		imin++;
	}
	if(imin < end)
	{
		int i = imin + 1;
		while(i < end && temp[imin] > level)
		{
			if(temp[i] >=0)
			{
				if(temp[imin] > temp[i])
				{
                    imin = i;
                }
			}
			i++;
		}
		if(temp[imin] > level)
		{
			int diff = temp[imin] - level;
			for(i = begin; i < end; i++)
			{
				temp[i] = temp[i] - diff;
			}
		}
		if(temp[i] == level)
		{
			imin = begin;
			for(i = begin; i < end; i++)
			{
				if(temp[i] == level)
				{
					while(temp[i] == level)
					{
						i++;
					}
					simplifyBracketsChange(temp, imin, i, level + 1);
					imin = i;
				}
			}
            simplifyBracketsChange(temp, imin, end, level + 1);
        }
	}
}
//---------------------------------------------------------------------------
// regexp - уже перевірений рядок функцією check.
void simplifyBrackets(char *regexp)
{
	if(regexp)
	{
		int n = strlen(regexp);
		int *temp = new int [n];
		int br = 0;
		for(int i = 0; i < n; i++)
		{
			if(regexp[i] == '(')
			{
				br++;
				temp[i] = -1;
			}
			else
			if(regexp[i] == ')')
			{
				br--;
				temp[i] = -1;
			}
			else
			{
				temp[i] = br;
            }
		}

		simplifyBracketsChange(temp, 0, n, 0);
		int len = 0;
		for(int i = 0; i < n; i++)
		{
			if(temp[i] < 0)
			{
				if(len == 1)
				{
                    temp[i - 1]--;
                }
				len = 0;
			}
			else
			{
				len++;
            }
        }

		//cout<<endl;
		for(int i = 0; i < n; i++)
		{
			if(temp[i] < 0)
			{
				cout<<"-";
			}
			else
			{
				cout<<(char)('0' + temp[i]);
			}
			//cout<<temp[i]<<endl;
		}
		delete[] temp;
    }
}
//---------------------------------------------------------------------------
void test1()
{
	cout<<"Hi"<<endl;
	char *s[] =
		{
			"(042(545(((((4)))))))",
			"(10|01|111)*0(10*1)*",
			"()",
			"001(110(10)0(0))",
			"0|1|0|111|",
			"(00)*1(0)|((1)(00))"
		};
	for(int i = 0; i < 6; i++)
	{
		//cout<<s[i]<<" is "<<check(s[i], isCorrectSymbol)<<endl;
	}
	for(int i = 0; i < 6; i++)
	{
		cout<<s[i]<<" : ";
		simplifyBrackets(s[i]);
		cout<<endl;
	}
	String str;
}
//---------------------------------------------------------------------------
void test_regex()
{
	String s = "(xx|yy|xyyx|xyxy|yxyx|yxxy)*";
	ExpressionBuilder *rb = new RegexBuilder();
	AbstractExpression *expr = rb->parse(s);
	String res = expr->getExpression();
	cout<<res.t_str();
}
//---------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
    test_regex();
	getch();
	return 0;
}
//---------------------------------------------------------------------------
