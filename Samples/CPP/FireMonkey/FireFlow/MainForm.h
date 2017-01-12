//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Layers3D.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include <FMX.Types3D.hpp>
#include <FMX.Effects.hpp>
#include <System.IOUtils.hpp>
#include "GetCodecInstance.hpp"
//---------------------------------------------------------------------------
class TFrmMain : public TForm
{
__published:	// IDE-managed Components
	TRectangle *Rectangle1;
	TAniIndicator *AniIndicator1;
	TButton *Button1;
	TTrackBar *TrackBar1;
	TStyleBook *ResourcesDark;
	TViewport3D *Viewport3D1;
	TLayout3D *Coverflow;
	TOpenDialog *OpenDialog1;
	void __fastcall CoverScrollChange(TObject *Sender);
	void __fastcall CoverflowMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
		  bool &Handled);
	void __fastcall TrackBar1Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	int CoverIndex;

	void __fastcall AddFolder();
	void __fastcall SetCoverIndex(int AIndex);
	void __fastcall DoCoverMouseDown(TObject *Sender, TMouseButton Button,
	  TShiftState Shift, float X, float Y);

	const float Factor;// 0.8;
	const int DivFac; // 3;
	const int RotationYAngle; //  70;
	const float Duration; // 0.5;
public:		// User declarations
	__fastcall TFrmMain(TComponent* Owner);
};


/*
 **************************************************************
  TFlowFilterPredicate - defines a class containing the
  TFilterPredicate callback to retrieve the OS image file
  extensions, used here to validate the user-selected file.
 **************************************************************
*/

class TFlowFilterPredicate : public TCppInterfacedObject<TDirectory::TFilterPredicate> {
public:
  bool __fastcall Invoke(const System::UnicodeString Path,
						 const System::Sysutils::TSearchRec &SearchRec)
  {
	 bool filterResult;

	 TBitmapCodec *bitmapCodec = GetFmxCodecInstance();

	 filterResult = (System::Ioutils::TPath::MatchesPattern(SearchRec.Name, "*.*", False));
	 if (filterResult)  // Find out if it is an image file
	   filterResult =
		 bitmapCodec->GetFileTypes().Pos( LowerCase(ExtractFileExt(SearchRec.Name))) > 0;
	 return filterResult;
  }
};


class TImageThread : public TThread
{
private:
	const TImage *FImage;
	TBitmap *FTempBitmap;
	String FFileName;
protected:
	void __fastcall Execute();
	void __fastcall Finished();
public:
	__fastcall TImageThread(const TImage &AImage, const String AFileName);
};


//---------------------------------------------------------------------------
extern PACKAGE TFrmMain *FrmMain;
//---------------------------------------------------------------------------
#endif
