program Text3DEditor;

uses
  FMX.Forms,
  Main in 'Main.pas' {FrmMain: TForm3D};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TFrmMain, FrmMain);
  Application.Run;
end.
