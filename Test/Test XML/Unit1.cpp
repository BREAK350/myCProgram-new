//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	char *fileName = "test xml.xml";
	rapidxml::file<> f= rapidxml::file<>(fileName);
	xml_document<> doc;
	doc.parse<0>(f.data());
	for(xml_node<> *node = doc.first_node("xml");
		node;
		node = node->next_sibling())
	{
		Memo1->Lines->Add(node->value());
	}
	char *temp = doc.allocate_string(0, 100);
	Memo1->Lines->Add(temp);

    std::filebuf fb;
	fb.open("temp.txt", std::ios::out);
	std::ostream os(&fb);
	rapidxml::print(os, doc);
	fb.close();
}
//---------------------------------------------------------------------------

