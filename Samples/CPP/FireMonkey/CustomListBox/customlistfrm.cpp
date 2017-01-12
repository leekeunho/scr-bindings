
//---------------------------------------------------------------------------

// This software is Copyright (c) 2011 Embarcadero Technologies, Inc. 
// You may only use this software if you are an authorized licensee
// of Delphi, C++Builder or RAD Studio (Embarcadero Products).
// This software is considered a Redistributable as defined under
// the software license agreement that comes with the Embarcadero Products
// and is subject to that software license agreement.

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "customlistfrm.h"
#include "GetCodecInstance.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

long rndm(long max)
{
#ifdef __APPLE__
	return (random() % ((max + 1) + max));
#else
	return random(max);
#endif
}

TfrmCustomList *frmCustomList;
//---------------------------------------------------------------------------
__fastcall TfrmCustomList::TfrmCustomList(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TfrmCustomList::DoInfoClick(TObject *Sender)
{
  InfoLabel->Text = "Info Button click on " + IntToStr(ListBox1->ItemIndex) + " listbox item";
}
//---------------------------------------------------------------------------
void __fastcall TfrmCustomList::DoVisibleChange(TObject *Sender)
{
  InfoLabel->Text = "Checkbox changed " + IntToStr(ListBox1->ItemIndex) + " listbox item to " + BoolToStr(ListBox1->Selected->Binding["visible"], true);
}
//---------------------------------------------------------------------------
void __fastcall TfrmCustomList::DoApplyStyleLookup(TObject *Sender)
{
  TBitmap *B;
  TListBoxItem *Item;

  Item = (TListBoxItem *)Sender;
  // create thumbnail
  B = new TBitmap(10 + rndm(50), 10 + rndm(50));
  B->Clear(0xFF000000 | TAlphaColor(rndm(0xFFFFFF)));

  // use this to set our child controls value - this code use BindingName in style to search
  Item->Binding["image"] = ObjectToVariant(B); // set thumbnail
  Item->Binding["text"] = "item " + IntToStr(Item->Index); // set filename
  Item->Binding["resolution"] = IntToStr(B->Width) + "x" + IntToStr(B->Height) + " px"; // set size
  Item->Binding["depth"] = "32 bit";
  Item->Binding["visible"] = true; // set Checkbox value
  Item->Binding["visible"] = EventToVariant(DoVisibleChange); // set OnChange value
  Item->Binding["info"] = EventToVariant(DoInfoClick); // set OnClick value
  // free thumbnail
  B->Free();

}

//---------------------------------------------------------------------------
void __fastcall TfrmCustomList::Button1Click(TObject *Sender)
{
  TListBoxItem  *Item;
  TBitmap *B;
  TPointF S;

  // get the codec instance from Delphi code

  TBitmapCodec *bitmapCodec = GetFmxCodecInstance();
  OpenDialog1->Filter = bitmapCodec->GetFileTypes();

  if (OpenDialog1->Execute())
  {
	// create thumbnail
	B = new TBitmap(1, 1);
	B->LoadThumbnailFromFile(OpenDialog1->FileName, 100, 100, true);
	// get image size
	S = bitmapCodec->GetImageSize(OpenDialog1->FileName);
	// create custom item
	Item = new TListBoxItem(this);
	Item->Parent = ListBox1;
	// this code force our style to new item
	Item->StyleLookup = "CustomItem";
	// use this to set our child controls value - this code use BindingName in style to search
	Item->Binding["image"] = ObjectToVariant(B); // set thumbnail
	Item->Binding["text"] = ExtractFileName(OpenDialog1->FileName); // set filename
	Item->Binding["resolution"] = IntToStr((int)(S.X)) + "x" + IntToStr((int)(S.Y)) + " px"; // set size
	Item->Binding["depth"] = "32 bit";
	Item->Binding["visible"] = EventToVariant(DoVisibleChange); // set OnChange value
	Item->Binding["info"] = EventToVariant(DoInfoClick); // set OnClick value
	// free thumbnail
	B->Free();
  };
}
//---------------------------------------------------------------------------
void __fastcall TfrmCustomList::Button2Click(TObject *Sender)
{
  TListBoxItem *Item;

  // create custom item
  Item = new TListBoxItem(this);
  Item->Parent = ListBox1;
  // this code set event - when we need to setup item
  Item->OnApplyStyleLookup = DoApplyStyleLookup;
  // this set our style to new item
  Item->StyleLookup = "CustomItem";

}
//---------------------------------------------------------------------------

void __fastcall TfrmCustomList::CheckBox1Change(TObject *Sender)
{
  ListBox1->AllowDrag = CheckBox1->IsChecked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmCustomList::Button3Click(TObject *Sender)
{
  int i;

  ListBox1->BeginUpdate();
  for (i = 1; i < 1000; i++)
	Button2Click(Sender);
  ListBox1->EndUpdate();
}
//---------------------------------------------------------------------------

