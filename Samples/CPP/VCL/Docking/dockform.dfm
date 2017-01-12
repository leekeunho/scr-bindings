object DockableForm: TDockableForm
  Left = 285
  Top = 409
  Caption = 'DockableForm'
  ClientHeight = 191
  ClientWidth = 331
  Color = clBtnFace
  DockSite = True
  DragKind = dkDock
  DragMode = dmAutomatic
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnDockOver = FormDockOver
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 331
    Height = 191
    Align = alClient
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
end
