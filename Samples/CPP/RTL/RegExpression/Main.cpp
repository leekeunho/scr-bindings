//---------------------------------------------------------------------------

// This software is Copyright (c) 2011 Embarcadero Technologies, Inc.
// You may only use this software if you are an authorized licensee
// of Delphi, C++Builder or RAD Studio (Embarcadero Products).
// This software is considered a Redistributable as defined under
// the software license agreement that comes with the Embarcadero Products
// and is subject to that software license agreement.

//---------------------------------------------------------------------------


#include <fmx.h>
#pragma hdrstop

#include "Main.h"
#include "System.RegularExpressions.hpp"
#include "System.UITypes.hpp"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::lbRegExpChange(TObject *Sender) {
	switch (lbRegExp->ItemIndex) {
	case 0:
		lbType->Text = "Email for validation";

		MemoRegEx->Text =
			"^((?>[a-zA-Z\d!#$%&''*+\\-/=?^_`{|}~]+\\x20*" "|\"((?=[\\x01-\\x7f])[^\"\\\\]|\\\\[\\x01-\\x7f])*\"\\"
			"x20*)*(?<angle><))?((?!\\.)(?>\.?[a-zA-Z\d!" "#$%&''*+\\-/=?^_`{|}~]+)+|\"\"((?=[\\x01-\\x7f])"
			"[^\"\\\\]|\\\\[\\x01-\\x7f])*\")@(((?!-)[a-zA-Z\\d\\" "-]+(?<!-)\\.)+[a-zA-Z]{2,}|\\[(((?(?<!\\[)\\.)"
			"(25[0-5]|2[0-4]\\d|[01]?\\d?\\d)){4}|[a-zA-Z\\" "d\\-]*[a-zA-Z\\d]:((?=[\\x01-\\x7f])[^\\\\\\[\\]]|"
			"\\\\[\\x01-\\x7f])+)\\])(?(angle)>)$";

		break;
	case 1: {
			// Accept IP address between 0..255
			lbType->Text = "IP address for validation (0..255)";
			MemoRegEx->Text =
				"\\b(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\" ".(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
				"(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\." "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b";
			break;

		}
	case 2: {
			// Data interval format mm-dd-yyyy
			lbType->Text =
				"Date in mm-dd-yyyy format from between 01-01-1900 and 12-31-2099";
			MemoRegEx->Text =
				"^(0[1-9]|1[012])[- /.](0[1-9]|[12][0-9]|3[" "01])[- /.](19|20)\\d\\d$";
			break;

		}
	case 3: {
			// Data interval format mm-dd-yyyy
			lbType->Text =
				"Date in dd-mm-yyyy format from between 01-01-1900 and 31-12-2099";
			MemoRegEx->Text =
				"^(0[1-9]|[12][0-9]|3[01])[- /.](0[1-9]|1[01" "2])[- /.](19|20)\\d\\d$";
			break;

		}
	}
	EditTextChangeTracking(EditText);

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::EditTextChangeTracking(TObject *Sender) {
	if (TRegEx::IsMatch(EditText->Text, MemoRegEx->Text)) {
		SEResult->ShadowColor = TAlphaColors::Green;
	}
	else
		SEResult->ShadowColor = TAlphaColors::Red;

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender) {
	lbRegExpChange(lbRegExp);
}
// ---------------------------------------------------------------------------
