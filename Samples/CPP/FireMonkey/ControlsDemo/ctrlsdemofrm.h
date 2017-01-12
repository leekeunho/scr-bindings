//---------------------------------------------------------------------------

#ifndef ctrlsdemofrmH
#define ctrlsdemofrmH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Menus.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include <FMX.ListBox.hpp>
  #include <FMX.Objects.hpp>
  #include <FMX.ExtCtrls.hpp>
  #include <FMX.TreeView.hpp>
  #include <FMX.Effects.hpp>
  #include <FMX.Memo.hpp>
  #include <FMX.Colors.hpp>
  #include <FMX.Layers3D.hpp>
  #include <FMX.Types3D.hpp>
#include "aboutboxfrm.h"
//---------------------------------------------------------------------------
class TfrmCtrlsDemo : public TForm
{
__published:	// IDE-managed Components
	TMenuBar *MenuBar1;
	TMenuItem *MenuItem1;
	TMenuItem *MenuItem2;
	TMenuItem *MenuItem3;
	TMenuItem *MenuItem4;
	TMenuItem *MenuItem5;
	TMenuItem *MenuItem6;
	TOpenDialog *OpenDialog1;
	TLayout *ScaleRoot;
	TLayout *ControlRoot;
	TStatusBar *StatusBar1;
	TTabControl *TabControl1;
	TTabItem *TabItem1;
	TTabItem *TabItem2;
	TTabItem *TabItem3;
	TTabItem *TabItem4;
	TTabItem *TabItem5;
	TTabItem *TabItem6;
	TTabItem *TabItem7;
	TTabItem *TabItem8;
	TButton *Button1;
	TListBox *ListBox1;
	TListBoxItem *ListBoxItem1;
	TListBoxItem *ListBoxItem2;
	TListBoxItem *ListBoxItem3;
	TListBoxItem *ListBoxItem4;
	TListBox *ListBox2;
	TListBoxItem *ListBoxItem5;
	TListBoxItem *ListBoxItem6;
	TListBoxItem *ListBoxItem7;
	TListBoxItem *ListBoxItem8;
	TListBoxItem *ListBoxItem9;
	TListBoxItem *ListBoxItem10;
	TListBoxItem *ListBoxItem11;
	TListBoxItem *ListBoxItem12;
	TListBoxItem *ListBoxItem13;
	TListBoxItem *ListBoxItem14;
	TListBoxItem *ListBoxItem15;
	TListBoxItem *ListBoxItem16;
	TListBoxItem *ListBoxItem17;
	TListBoxItem *ListBoxItem18;
	TListBoxItem *ListBoxItem19;
	TListBoxItem *ListBoxItem20;
	TButton *Button2;
	TExpander *Expander1;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TGroupBox *GroupBox1;
	TButton *Button6;
	TTrackBar *ScaleTrack;
	TArcDial *AngleButton3;
	TArcDial *AngleButton2;
	TTrackBar *TrackBar1;
	TTrackBar *TrackBar2;
	TTrackBar *TrackBar3;
	TTrackBar *TrackBar4;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TCheckBox *CheckBox5;
	TCheckBox *CheckBox6;
	TDropTarget *DropTarget1;
	TCheckBox *CheckBox7;
	TCalloutPanel *CalloutPanel1;
	TRadioButton *calloutBottom;
	TAniIndicator *AniIndicator1;
	TLabel *Label1;
	TPanel *Panel1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *Label19;
	TButton *SpeedButton2;
	TButton *SpeedButton3;
	TProgressBar *ProgressBar1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TScrollBar *ScrollBar1;
	TScrollBar *ScrollBar2;
	TSmallScrollBar *SmallScrollBar1;
	TLabel *Text1;
	TLabel *Text2;
	TLabel *Text3;
	TLabel *Text4;
	TEdit *TextBox1;
	TTrack *Track1;
	TRadioButton *calloutLeft;
	TRadioButton *calloutTop;
	TRadioButton *calloutRight;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label26;
	TLabel *Label27;
	TLabel *Label28;
	TLabel *Label29;
	TPanel *Panel2;
	TScrollBox *ScrollBox1;
	TRectangle *Rectangle1;
	TPanel *Rectangle2;
	TVertScrollBox *VertScrollBox1;
	TExpander *Expander2;
	TExpander *Expander3;
	TExpander *Expander4;
	TEdit *TextBox5;
	TSplitter *Splitter1;
	TTreeView *TreeView1;
	TTreeViewItem *TreeViewItem1;
	TTreeViewItem *TreeViewItem2;
	TTreeViewItem *TreeViewItem3;
	TTreeViewItem *TreeViewItem4;
	TTreeViewItem *TreeViewItem5;
	TTreeViewItem *TreeViewItem6;
	TTreeViewItem *TreeViewItem7;
	TTreeViewItem *TreeViewItem8;
	TTreeViewItem *TreeViewItem9;
	TTreeViewItem *TreeViewItem10;
	TTreeViewItem *TreeViewItem11;
	TTreeViewItem *TreeViewItem12;
	TTreeViewItem *TreeViewItem13;
	TTreeViewItem *TreeViewItem14;
	TTreeViewItem *TreeViewItem15;
	TTreeViewItem *TreeViewItem16;
	TCalendar *Calendar1;
	TCalendarBox *CalendarBox1;
	TCalendarEdit *CalendarTextBox1;
	TMemo *Memo1;
	TNumberBox *NumberBox1;
	TPopupBox *PopupBox1;
	TClearingEdit *ClearingEdit1;
	TEllipse *Ellipse1;
	TListBox *ListTransform;
	TAlphaTrackBar *AlphaTrackBar1;
	TBWTrackBar *BWTrackBar1;
	TComboColorBox *ComboColorBox1;
	TComboEdit *ComboEdit1;
	TComboTrackBar *ComboTrackBar1;
	TCornerButton *CornerButton1;
	TCornerButton *CornerButton2;
	TCornerButton *CornerButton3;
	TCornerButton *CornerButton4;
	TCornerButton *CornerButton5;
	TCornerButton *CornerButton6;
	TPath *Path1;
	TPath *Path2;
	TPath *Path3;
	THueTrackBar *HueTrackBar1;
	TSpinBox *SpinBox1;
	TClearingEdit *TextBoxClearBtn1;
	TTreeView *TreeView2;
	TTreeViewItem *TreeViewItem17;
	TTreeViewItem *TreeViewItem18;
	TTreeViewItem *TreeViewItem19;
	TTreeViewItem *TreeViewItem20;
	TTreeViewItem *TreeViewItem21;
	TTreeViewItem *TreeViewItem22;
	TTreeViewItem *TreeViewItem23;
	TMemo *Memo2;
	TTreeViewItem *TreeViewItem24;
	TTreeViewItem *TreeViewItem25;
	TTreeViewItem *TreeViewItem26;
	TTreeViewItem *TreeViewItem27;
	TTreeViewItem *TreeViewItem28;
	TTreeViewItem *TreeViewItem29;
	TTreeViewItem *TreeViewItem30;
	TTreeViewItem *TreeViewItem31;
	TTreeViewItem *TreeViewItem32;
	TTreeViewItem *TreeViewItem33;
	TTreeViewItem *TreeViewItem34;
	TTreeViewItem *TreeViewItem35;
	TTreeViewItem *TreeViewItem36;
	TTreeViewItem *TreeViewItem37;
	TTreeViewItem *TreeViewItem38;
	TListBox *StringListBox1;
	TListBoxItem *ListBoxItem21;
	TListBoxItem *ListBoxItem22;
	TListBoxItem *ListBoxItem23;
	TListBoxItem *ListBoxItem24;
	TListBoxItem *ListBoxItem25;
	TListBoxItem *ListBoxItem26;
	TListBoxItem *ListBoxItem27;
	TListBoxItem *ListBoxItem28;
	TListBoxItem *ListBoxItem29;
	TListBoxItem *ListBoxItem30;
	TListBoxItem *ListBoxItem31;
	TListBoxItem *ListBoxItem32;
	TListBoxItem *ListBoxItem33;
	TListBoxItem *ListBoxItem34;
	TListBoxItem *ListBoxItem35;
	TLabel *TextScale;
	TArcDial *AngleButton1;
	TEdit *TextBox4;
	void __fastcall MenuItem6Click(TObject *Sender);
	void __fastcall MenuItem4Click(TObject *Sender);
	void __fastcall MenuItem2Click(TObject *Sender);
	void __fastcall MenuItem1Click(TObject *Sender);
	void __fastcall CheckBox2Change(TObject *Sender);
	void __fastcall calloutBottomChange(TObject *Sender);
	void __fastcall MenuItem3Click(TObject *Sender);
	void __fastcall ScaleTrackChange(TObject *Sender);
	void __fastcall AngleButtonl1Change(TObject *Sender);
	void __fastcall AngleButton3Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall AngleButton2Change(TObject *Sender);
	void __fastcall TrackBar2Change(TObject *Sender);
	void __fastcall TrackBar3Change(TObject *Sender);
	void __fastcall TrackBar4Change(TObject *Sender);
	void __fastcall CheckBox6Change(TObject *Sender);
	void __fastcall CheckBox5Change(TObject *Sender);
	void __fastcall CheckBox4Change(TObject *Sender);
	void __fastcall CheckBox3Change(TObject *Sender);
	void __fastcall DropTarget1DragOver(TObject *Sender, const TDragObject &Data, const TPointF &Point,
          bool &Accept);
	void __fastcall CheckBox7Change(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall MenuItem7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmCtrlsDemo(TComponent* Owner);
};

long rndm(long max);

//---------------------------------------------------------------------------
extern PACKAGE TfrmCtrlsDemo *frmCtrlsDemo;
//---------------------------------------------------------------------------
#endif
