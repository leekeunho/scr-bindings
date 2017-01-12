
//---------------------------------------------------------------------------

// This software is Copyright (c) 2011 Embarcadero Technologies, Inc. 
// You may only use this software if you are an authorized licensee
// of Delphi, C++Builder or RAD Studio (Embarcadero Products).
// This software is considered a Redistributable as defined under
// the software license agreement that comes with the Embarcadero Products
// and is subject to that software license agreement.

//---------------------------------------------------------------------------
program ModelViewer;

uses
  FMX.Forms,
  SysUtils,
  MV.ColladaImport in '..\..\shared\units\MV.ColladaImport.pas',
  collada_schema_1_5 in '..\..\shared\units\collada\collada_schema_1_5.pas',
  MV.Utils in '..\..\shared\units\MV.Utils.pas',
  MV.TgaBitmap in '..\..\shared\units\MV.TgaBitmap.pas',
  MV.CameraLookAt in '..\..\shared\units\MV.CameraLookAt.pas',
  uShaders in 'units\uShaders.pas',
  ufMain in 'funits\ufMain.pas' {fMain: TForm3D},
  FMX.Context.DX9 in '..\..\shared\units\FMX.Context.DX9.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TfMain, fMain);
  Application.Run;
end.
