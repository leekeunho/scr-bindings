//---------------------------------------------------------------------------
// C++Builder
// Copyright (c) 1995-2010 Embarcadero Technologies, Inc.

// You may only use this software if you are an authorized licensee
// of Delphi, C++Builder or RAD Studio (Embarcadero Products).
// This software is considered a Redistributable as defined under
// the software license agreement that comes with the Embarcadero Products
// and is subject to that software license agreement.
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include <WinHelpViewer.hpp>
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("pickdate.cpp", BrDateForm);
USEFORM("main.cpp", MainForm);
USEFORM("edparts.cpp", EdPartsForm);
USEFORM("pickinvc.cpp", PickOrderNoDlg);
USEFORM("srchdlg.cpp", SearchDlg);
USEFORM("splash.cpp", SplashForm);
USEFORM("qrycust.cpp", QueryCustDlg);
USEFORM("edorders.cpp", EdOrderForm);
USEFORM("datamod.cpp", MastData);
USEFORM("about.cpp", AboutBox);
USEFORM("edcust.cpp", EdCustForm);
USEFORM("brparts.cpp", BrPartsForm);
USEFORM("brcstord.cpp", BrCustOrdForm);
//---------------------------------------------------------------------------
#include "splash.h"
//#pragma link "WinHelpViewer.obj"

WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	 try
	 {
	   SplashForm = new TSplashForm(Application);
	   SplashForm->Show();
	   SplashForm->Update();

	   Application->Initialize();
	   Application->Title = "Marine Adventures Order Entry";
	   Application->HelpFile = "Mastapp.hlp";
	   Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TMastData), &MastData);
		Application->CreateForm(__classid(TAboutBox), &AboutBox);
		Application->CreateForm(__classid(TQueryCustDlg), &QueryCustDlg);
		Application->CreateForm(__classid(TBrPartsForm), &BrPartsForm);
		Application->CreateForm(__classid(TBrCustOrdForm), &BrCustOrdForm);
		Application->CreateForm(__classid(TEdCustForm), &EdCustForm);
		Application->CreateForm(__classid(TBrDateForm), &BrDateForm);
		Application->CreateForm(__classid(TSearchDlg), &SearchDlg);
		Application->CreateForm(__classid(TEdPartsForm), &EdPartsForm);
		Application->CreateForm(__classid(TEdOrderForm), &EdOrderForm);
		Application->CreateForm(__classid(TPickOrderNoDlg), &PickOrderNoDlg);
		SplashForm->Hide();
       SplashForm->Close();
       Application->Run();
   }
   catch (Exception &exception)
   {
       Application->ShowException(&exception);
   }
       return 0;
}
//---------------------------------------------------------------------------
