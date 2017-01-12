object MainForm: TMainForm
  Left = 374
  Top = 161
  Caption = 'Docking Demo'
  ClientHeight = 261
  ClientWidth = 465
  Color = clWindow
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object VSplitter: TSplitter
    Left = 0
    Top = 48
    Width = 4
    Height = 209
    Visible = False
    ExplicitHeight = 217
  end
  object HSplitter: TSplitter
    Left = 0
    Top = 257
    Width = 465
    Height = 4
    Cursor = crVSplit
    Align = alBottom
    Visible = False
    ExplicitTop = 265
  end
  object CoolBar1: TCoolBar
    Left = 0
    Top = 0
    Width = 465
    Height = 48
    AutoSize = True
    BandMaximize = bmDblClick
    Bands = <
      item
        Break = False
        Control = ToolBar1
        ImageIndex = -1
        MinHeight = 21
        Width = 461
      end
      item
        Control = ToolBar2
        ImageIndex = -1
        MinHeight = 21
        Width = 461
      end>
    Color = clMenu
    DockSite = True
    ParentColor = False
    OnDockOver = CoolBar1DockOver
    object ToolBar1: TToolBar
      Left = 9
      Top = 0
      Width = 280
      Height = 21
      AutoSize = True
      ButtonHeight = 21
      ButtonWidth = 59
      Caption = 'ToolBar1'
      Constraints.MaxWidth = 280
      DragKind = dkDock
      DragMode = dmAutomatic
      ShowCaptions = True
      TabOrder = 0
      Transparent = True
      Wrapable = False
      object ToolButton13: TToolButton
        Left = 0
        Top = 0
        Caption = 'E&xit'
        OnClick = ExitActionExecute
      end
      object ToolButton16: TToolButton
        Left = 59
        Top = 0
        Width = 14
        Caption = 'ToolButton16'
        ImageIndex = 7
        Style = tbsSeparator
      end
      object tbToolBar1: TToolButton
        Left = 73
        Top = 0
        Caption = 'ToolBar &1'
        Down = True
        Style = tbsCheck
        OnClick = ViewToolBar1Execute
      end
      object tbToolBar2: TToolButton
        Left = 132
        Top = 0
        Caption = 'ToolBar &2'
        Down = True
        Style = tbsCheck
        OnClick = ViewToolBar2Execute
      end
    end
    object ToolBar2: TToolBar
      Left = 9
      Top = 23
      Width = 390
      Height = 21
      AutoSize = True
      ButtonHeight = 21
      ButtonWidth = 43
      Caption = 'ToolBar2'
      Constraints.MaxWidth = 390
      DragKind = dkDock
      DragMode = dmAutomatic
      ShowCaptions = True
      TabOrder = 1
      Transparent = True
      Wrapable = False
      object tbWhite: TToolButton
        Left = 0
        Top = 0
        AutoSize = True
        Caption = '&White'
        OnClick = GenericViewWindowExecute
      end
      object tbBlue: TToolButton
        Tag = 1
        Left = 39
        Top = 0
        Action = ViewBlueWindow
        AutoSize = True
      end
      object tbGreen: TToolButton
        Tag = 2
        Left = 71
        Top = 0
        Action = ViewGreenWindow
        AutoSize = True
      end
      object tbRed: TToolButton
        Tag = 3
        Left = 111
        Top = 0
        Action = ViewRedWindow
        AutoSize = True
      end
      object tbTeal: TToolButton
        Tag = 4
        Left = 142
        Top = 0
        Action = ViewTealWindow
        AutoSize = True
      end
      object tbPurple: TToolButton
        Tag = 5
        Left = 174
        Top = 0
        Action = ViewPurpleWindow
        AutoSize = True
      end
      object tbLime: TToolButton
        Tag = 6
        Left = 215
        Top = 0
        Action = ViewLimeWindow
        AutoSize = True
      end
    end
  end
  object LeftDockPanel: TPanel
    Left = 4
    Top = 48
    Width = 0
    Height = 209
    Align = alLeft
    DockSite = True
    TabOrder = 1
    OnDockDrop = LeftDockPanelDockDrop
    OnDockOver = LeftDockPanelDockOver
    OnGetSiteInfo = LeftDockPanelGetSiteInfo
    OnUnDock = LeftDockPanelUnDock
    ExplicitHeight = 217
  end
  object BottomDockPanel: TPanel
    Left = 0
    Top = 257
    Width = 465
    Height = 0
    Align = alBottom
    DockSite = True
    TabOrder = 2
    OnDockDrop = LeftDockPanelDockDrop
    OnDockOver = BottomDockPanelDockOver
    OnGetSiteInfo = LeftDockPanelGetSiteInfo
    OnUnDock = LeftDockPanelUnDock
    ExplicitTop = 265
  end
  object ActionList1: TActionList
    Left = 112
    Top = 80
    object ViewToolBar1: TAction
      Category = 'ViewToolBars'
      Caption = 'ToolBar &1'
      Checked = True
      ImageIndex = 1
      OnExecute = ViewToolBar1Execute
    end
    object ViewToolBar2: TAction
      Category = 'ViewToolBars'
      Caption = 'ToolBar &2'
      Checked = True
      ImageIndex = 2
      OnExecute = ViewToolBar2Execute
    end
    object ViewWhiteWindow: TAction
      Category = 'ViewWindows'
      Caption = '&White'
      Hint = 'View white window'
      OnExecute = GenericViewWindowExecute
    end
    object ExitAction: TAction
      Caption = 'E&xit'
      OnExecute = ExitActionExecute
    end
    object ViewBlueWindow: TAction
      Tag = 1
      Category = 'ViewWindows'
      Caption = '&Blue'
      OnExecute = GenericViewWindowExecute
    end
    object ViewGreenWindow: TAction
      Tag = 2
      Category = 'ViewWindows'
      Caption = '&Green'
      OnExecute = GenericViewWindowExecute
    end
    object ViewRedWindow: TAction
      Tag = 3
      Category = 'ViewWindows'
      Caption = '&Red'
      OnExecute = GenericViewWindowExecute
    end
    object ViewTealWindow: TAction
      Tag = 4
      Category = 'ViewWindows'
      Caption = '&Teal'
      OnExecute = GenericViewWindowExecute
    end
    object ViewPurpleWindow: TAction
      Tag = 5
      Category = 'ViewWindows'
      Caption = '&Purple'
      OnExecute = GenericViewWindowExecute
    end
    object ViewLimeWindow: TAction
      Tag = 6
      Category = 'ViewWindows'
      Caption = '&Lime'
      OnExecute = GenericViewWindowExecute
    end
  end
  object MainMenu1: TMainMenu
    Left = 176
    Top = 80
    object File2: TMenuItem
      Caption = '&File'
      object Exit2: TMenuItem
        Action = ExitAction
      end
    end
    object View2: TMenuItem
      Caption = '&View'
      object ToolBar11: TMenuItem
        Action = ViewToolBar1
      end
      object ToolBar21: TMenuItem
        Action = ViewToolBar2
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object mnuWhite: TMenuItem
        Action = ViewWhiteWindow
      end
      object mnuBlue: TMenuItem
        Action = ViewBlueWindow
      end
      object mnuGreen: TMenuItem
        Action = ViewGreenWindow
      end
      object mnuRed: TMenuItem
        Action = ViewRedWindow
      end
      object mnuTeal: TMenuItem
        Action = ViewTealWindow
      end
      object mnuPurple: TMenuItem
        Action = ViewPurpleWindow
      end
      object mnuLime: TMenuItem
        Action = ViewLimeWindow
      end
    end
  end
end
