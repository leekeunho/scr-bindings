
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
#include <FMX.Effects.hpp>
#pragma hdrstop

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFrmMain *FrmMain;
//---------------------------------------------------------------------------
__fastcall TFrmMain::TFrmMain(TComponent* Owner)
	: TForm(Owner),	Factor(0.8), DivFac(3),	RotationYAngle(70),	Duration(0.5)

{
}

//---------------------------------------------------------------------------
void __fastcall TFrmMain::AddFolder()
{
  String Dir, FileName;
  TLayer3D *Cover;
  TLayout *Layout;
  TImage *Image;
  TReflectionEffect *Effect;
  int i, j;
  TRectangle *L ;
  TPointF imageSize;
  TImageThread *imageThread;

  // get the codec instance from Delphi code

  TBitmapCodec *bitmapCodec = GetFmxCodecInstance();

  OpenDialog1->Filter = "All Images|" + bitmapCodec->GetFileTypes();

  if (OpenDialog1->Execute())
  {

	Coverflow->DeleteChildren();
	AniIndicator1->Visible = true;
	Dir = ExtractFilePath(OpenDialog1->FileName);
	i = 0;

	 // create a FilterPredicate and get the image file list

	TDirectory::_di_TFilterPredicate predicate(new TFlowFilterPredicate());
	System::TStringDynArray files = TDirectory::GetFiles(Dir,	predicate);

	for (j = 0; j < files.Length; j++)
	{
	  // Create Cover
	  Cover = new TLayer3D(this);
	  Cover->Parent = Coverflow;

	  Cover->Projection = TProjection::pjScreen;
	  Cover->Width = int(Coverflow->Height * Factor);
	  Cover->Height = int(int(Coverflow->Height * Factor) * 1.5);
	  Cover->ZWrite = True;
	  Cover->Fill->Color = Viewport3D1->Color;
	  Cover->Fill->Kind  = TBrushKind::bkSolid;
	  Cover->Transparency = True;
	  Cover->OnLayerMouseDown = DoCoverMouseDown;
	  Cover->Tag = i;
	  Cover->Padding->Rect = TRectF(0, 0, 0, 0);
	  Cover->Position->Y = int((Coverflow->Height - int(Coverflow->Height * Factor)) / 2);
	  Cover->Cursor = crHandPoint;

	  if (i == 0)
		Cover->Position->X = i * int(Coverflow->Height * Factor);
	  else
	  {
		Cover->Position->X = (i + 1) * (int(Coverflow->Height * Factor) / DivFac);
		Cover->Position->Z = int(Coverflow->Height * Factor) * 2;
		Cover->RotationAngle->Y = RotationYAngle;
	  };

	  // Child
	  Layout = new TLayout(this);
	  Layout->Parent = Cover;
	  Layout->Align = TAlignLayout::alTop;
	  Layout->Height = int(Cover->Height / 2); // original = 2
	  Layout->Padding->Rect = TRectF(0, 0, 0, 0);
	  Layout->Cursor = crHandPoint;

	  // This rectangle is necessary to avoid blank lines on the image
	  L = new TRectangle(this);
	  L->Parent = Layout;
	  L->Align = TAlignLayout::alTop;
	  L->Height = int(Cover->Height / 2);
	  L->Fill->Kind = TBrushKind::bkNone;
	  L->Stroke->Color = Viewport3D1->Color;
	  L->Stroke->Kind = TBrushKind::bkNone;

	  Image = new TImage(this);
	  Image->Parent = Layout;
	  Image->Padding->Rect = TRectF(0, 0, 0, 0);
	  Image->TagString = files[j];

	  imageSize = bitmapCodec->GetImageSize(Image->TagString);
	  Image->Width = imageSize.X;
	  Image->Height = imageSize.Y;


	  Image->WrapMode = TImageWrapMode::iwStretch;
	  Image->Align = TAlignLayout::alFit;
	  Image->HitTest = true;
	  Image->Cursor = crHandPoint;
	  imageThread = new TImageThread(*Image, Image->TagString);
	  imageThread->Start();
	  Image->OnMouseDown = DoCoverMouseDown;
//      Image->OnMouseWheel = CoverflowMouseWheel;

	  Image->Tag = i++;

	  Effect = new TReflectionEffect(this);
	  Effect->Parent = Image;
	  Effect->Opacity = 0.6;

	  // Opacity animation
	  Cover->Opacity = 0.01;
	  Cover->AnimateFloat("Opacity", 1, Duration);

	  // Load thumb
	  Cover->TagObject = Image;
	  Application->ProcessMessages();
	}

	CoverIndex = 0;
	AniIndicator1->Visible = False;
	TrackBar1->Max = Coverflow->ChildrenCount-1;
	TrackBar1->Value = 0;
	TrackBar1->Visible = True;
	TrackBar1->SetFocus();
  }
}

void __fastcall TFrmMain::CoverScrollChange(TObject *Sender)
{
  SetCoverIndex(int(TrackBar1->Value));
}

//---------------------------------------------------------------------------
void __fastcall TFrmMain::SetCoverIndex(int AIndex)
{
  int i;
  TLayer3D *Cover;
  float PercCoeff, Coeff;

  if (AniIndicator1->Visible || Coverflow->ChildrenCount == 0)
  {
	 TrackBar1->Value = CoverIndex;
	 return;
  };

  PercCoeff = 0.6;


  if (AIndex < 0)
	AIndex = 0;
  if (AIndex >= Coverflow->ChildrenCount)
	AIndex = Coverflow->ChildrenCount - 1;
  if (AIndex != CoverIndex)
  {

	// translate all; move the pictures in the back.
	// note here that the properties passed to AnimateFloat etc. use Delphi punctuation

	for (i = 0; i < Coverflow->ChildrenCount; i++)
	{

	  Cover = (TLayer3D *)Coverflow->Children[i];
	  Cover->StopPropertyAnimation("Position.X");
	  Cover->AnimateFloat("Position.X", Cover->Position->X + ((CoverIndex - AIndex) * (int(Coverflow->Height * Factor) / DivFac)), Duration);
	};

	// transform between old an new value
	i = CoverIndex;
	while (i != AIndex)
	{
	  Coeff = (0.1 + (abs(AIndex - i) / abs(AIndex - CoverIndex))) * (PercCoeff + 0.1);

	  Cover = (TLayer3D *)Coverflow->Children[i];
	  Cover->StopPropertyAnimation("Position.X");
	  Cover->StopPropertyAnimation("RotationAngle.Y");

	  if (CoverIndex > AIndex)
	  {
		Cover->AnimateFloat("RotationAngle.Y", RotationYAngle, Duration );
		if (i == CoverIndex)
		  Cover->AnimateFloat("Position.X", Cover->Position->X + (1 * (int(Coverflow->Height * Factor) / DivFac)), Duration * Coeff);
		else
		  Cover->AnimateFloat("Position.X", Cover->Position->X + (2 * (int(Coverflow->Height * Factor) / DivFac)), Duration * Coeff);
	  }
	  else
	  {
		Cover->AnimateFloat("RotationAngle.Y", RotationYAngle*-1, Duration );
		if (i == CoverIndex)
		  Cover->AnimateFloat("Position.X", Cover->Position->X - (1 * (int(Coverflow->Height * Factor) / DivFac)), Duration * Coeff);
		else
		  Cover->AnimateFloat("Position.X", Cover->Position->X - (2 * (int(Coverflow->Height * Factor) / DivFac)), Duration * Coeff);
	  };
	  Cover->AnimateFloat("Position.Z", int(Coverflow->Height * Factor) * 2, Duration);
	  if (AIndex > CoverIndex)
		i++;
	  else
		i--;
	};

	Cover = (TLayer3D *)Coverflow->Children[AIndex];

	Cover->StopPropertyAnimation("Position.X");
	Cover->StopPropertyAnimation("Position.Z");

	Cover->AnimateFloat("RotationAngle.Y", 0, Duration);
	Cover->AnimateFloat("Position.Z", 0, Duration);
	if (CoverIndex > AIndex)
	   Cover->AnimateFloat("Position.X", Cover->Position->X + (1 * (int(Coverflow->Height * Factor) / DivFac)), Duration);
	else
	  Cover->AnimateFloat("Position.X", Cover->Position->X - (1 * (int(Coverflow->Height * Factor) / DivFac)), Duration);

	CoverIndex = AIndex;

  };

}
//---------------------------------------------------------------------------
void __fastcall TFrmMain::DoCoverMouseDown(TObject *Sender, TMouseButton Button,
  TShiftState Shift, float X, float Y)
{
  TrackBar1->Value = int(StrToFloat(IntToStr(((TImage *)(Sender))->Tag)));
}
//---------------------------------------------------------------------------

void __fastcall TFrmMain::CoverflowMouseWheel(TObject *Sender, TShiftState Shift,
		  int WheelDelta, bool &Handled)
{
  TrackBar1->Value = CoverIndex - (WheelDelta / 120);
  Handled = true;

}
//---------------------------------------------------------------------------
void __fastcall TFrmMain::TrackBar1Change(TObject *Sender)
{
  SetCoverIndex(int(TrackBar1->Value));
}
//---------------------------------------------------------------------------
void __fastcall TFrmMain::Button1Click(TObject *Sender)
{
  AddFolder();
}
//---------------------------------------------------------------------------

void __fastcall TImageThread::Execute()
{
  FTempBitmap = new TBitmap(0, 0);
  FTempBitmap->LoadThumbnailFromFile(FFileName,
	const_cast<TImage*>(FImage)->Width,
	const_cast<TImage*>(FImage)->Height, false);
  Synchronize(Finished);
}
void __fastcall TImageThread::Finished()
{
  FImage->Bitmap->Assign(FTempBitmap);
  FTempBitmap->Free();
}

__fastcall TImageThread::TImageThread(const TImage &AImage, const String AFileName):
	 TThread(true), FImage(&AImage), FFileName(AFileName)
{
  FreeOnTerminate = True;
}


