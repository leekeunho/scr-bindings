//---------------------------------------------------------------------------

#ifndef anidemofrmH
#define anidemofrmH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layers3D.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Objects3D.hpp>
#include <FMX.Types.hpp>
#include <FMX.Types3D.hpp>
#include <FMX.Ani.hpp>
//---------------------------------------------------------------------------
class TfrmAniDemo : public TForm3D
{
__published:	// IDE-managed Components
	TLight *Light1;
	TLayer3D *ObjectLayer1;
	TLayout *Background1;
	TPath *Path1;
	TRoundRect *RoundRect1;
	TPlane *Plane1;
	TTextLayer3D *Text4;
	TRoundCube *RoundCube1;
	TFloatAnimation *FloatAnimation3;
	TSphere *Sphere1;
	TColorAnimation *ColorAnimation1;
	TColorAnimation *ColorAnimation2;
	TTextLayer3D *Text1;
	TSphere *Sphere2;
	TFloatAnimation *FloatAnimation1;
	TTextLayer3D *Text2;
	TStrokeCube *StrokeCube1;
	TCube *Cube1;
	TFloatAnimation *FloatAnimation2;
	TTextLayer3D *Text3;
	TPathAnimation *PathAni;
	TText *Text5;
	TText3D *Text3D1;
	TFloatAnimation *FloatAnimation4;
private:	// User declarations
public:		// User declarations
	__fastcall TfrmAniDemo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAniDemo *frmAniDemo;
//---------------------------------------------------------------------------
#endif
