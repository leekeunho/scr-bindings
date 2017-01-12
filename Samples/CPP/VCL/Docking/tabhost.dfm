object TabDockHost: TTabDockHost
  Left = 280
  Top = 330
  Width = 409
  Height = 197
  Caption = 'TabDockHost'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 120
  TextHeight = 16
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 401
    Height = 165
    Align = alClient
    DockSite = True
    TabOrder = 0
    OnDockOver = PageControl1DockOver
    OnGetSiteInfo = PageControl1GetSiteInfo
    OnUnDock = PageControl1UnDock
  end
end
