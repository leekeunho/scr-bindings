object FormMain: TFormMain
  Left = 200
  Top = 114
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Tray Icon'
  ClientHeight = 175
  ClientWidth = 289
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Default'
  Font.Style = []
  OldCreateOrder = False
  PopupMenu = PopupMenu1
  Position = poScreenCenter
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Image2: TImage
    Left = 82
    Top = 120
    Width = 33
    Height = 41
    Picture.Data = {
      055449636F6E0000010002002020100000000000E80200002600000010101000
      00000000280100000E0300002800000020000000400000000100040000000000
      8002000000000000000000000000000000000000000000000000800000800000
      00808000800000008000800080800000C0C0C000808080000000FF0000FF0000
      00FFFF00FF000000FF00FF00FFFF0000FFFFFF00000000000008000000008000
      0000000000000000800048480848000800000000000000800484848404848480
      0800000000000808787878780878884840800000000080888888888408888884
      8408000000080878787878780878787878408000008087878787878807878788
      8484080000087878787777780777777878784000080787878787777807777787
      888480800077777777777AA80AA777777878740000878787777AAAA80AAAA777
      8788480080777777772AAAA80AAAAA777778740807777777772AAAA80AAAAA77
      778787400777777772AAAAA80AAAAAA7777888800F7F7FFFF2AAAAA80AAAAAA7
      7777774008888888888888888888888888888880000000000000000000000000
      000000000777777772AAAAA80AAAAAA7778784800777777772AAAAA80AAAAAA7
      777878400F7F7F7F7F2AAAA80AAAAA777787848080777777772AAAA80AAAAA77
      77787808007F7F7F7F722AA80AA22F777787840000F7F7FFFFF7F22802277777
      77787800080F7F7FFF7F7F780F7F7F77778780800007F7FFFFFFF7F80FF77777
      7777700000807F7FFFFF7F780F7F7F7F77870800000807FFFFFFF7F80FF77777
      777080000000807F7F7F7F780F7F7F7F7708000000000807F7F7F7F80FF77777
      70800000000000800F7F7F780F7F7F7008000000000000008000F7F80FF70008
      0000000000000000000800000000800000000000FFE007FFFF0000FFFC00003F
      F800001FF000000FE0000007C0000003C0000003800000018000000180000001
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000800000018000000180000001C0000003C0000003E0000007
      F000000FF800001FFC00003FFF0000FFFFE007FF280000001000000020000000
      0100040000000000C00000000000000000000000000000000000000000000000
      000080000080000000808000800000008000800080800000C0C0C00080808000
      0000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF0000008000
      00080000008008480480080008084878078480800087878808784800807877A8
      0A77840807777AA80AA774800F7F2AA80AAA7740088888888888888000000000
      0000000007772AA80AAA77400F7F72A80AA77480807FF72802777708007FFFF8
      0FF778000807FF780F7F7080008007F80F7008000000800000080000F00F0000
      C003000080010000800100000000000000000000000000000000000000000000
      0000000000000000000000008001000080010000C0030000F00F0000}
  end
  object Image1: TImage
    Left = 82
    Top = 64
    Width = 33
    Height = 41
    Picture.Data = {
      055449636F6E0000010002002020100000000000E80200002600000010101000
      00000000280100000E0300002800000020000000400000000100040000000000
      8002000000000000000000000000000000000000000000000000800000800000
      00808000800000008000800080800000C0C0C000808080000000FF0000FF0000
      00FFFF00FF000000FF00FF00FFFF0000FFFFFF00000000000008000000008000
      0000000000000000800048480848000800000000000000800484848404848480
      0800000000000808787878780878884840800000000080888888888408888884
      8408000000080878787878780878787878408000008087878787878807878788
      8484080000087878787777780777777878784000080787878787777807777787
      8884808000777777777779980997777778787400008787877779999809999777
      8788480080777777771999980999997777787408077777777719999809999977
      77878740077777777199999809999997777888800F7F7FFFF199999809999997
      7777774008888888888888888888888888888880000000000000000000000000
      0000000007777777719999980999999777878480077777777199999809999997
      777878400F7F7F7F7F1999980999997777878480807777777719999809999977
      77787808007F7F7F7F71199809911F777787840000F7F7FFFFF7F11801177777
      77787800080F7F7FFF7F7F780F7F7F77778780800007F7FFFFFFF7F80FF77777
      7777700000807F7FFFFF7F780F7F7F7F77870800000807FFFFFFF7F80FF77777
      777080000000807F7F7F7F780F7F7F7F7708000000000807F7F7F7F80FF77777
      70800000000000800F7F7F780F7F7F7008000000000000008000F7F80FF70008
      0000000000000000000800000000800000000000FFE007FFFF0000FFFC00003F
      F800001FF000000FE0000007C0000003C0000003800000018000000180000001
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000800000018000000180000001C0000003C0000003E0000007
      F000000FF800001FFC00003FFF0000FFFFE007FF280000001000000020000000
      0100040000000000C00000000000000000000000000000000000000000000000
      000080000080000000808000800000008000800080800000C0C0C00080808000
      0000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF0000008000
      0008000000800848048008000808487807848080008787880878480080787798
      0977840807777998099774800F7F199809997740088888888888888000000000
      0000000007771998099977400F7F719809977480807FF71801777708007FFFF8
      0FF778000807FF780F7F7080008007F80F7008000000800000080000F00F0000
      C003000080010000800100000000000000000000000000000000000000000000
      0000000000000000000000008001000080010000C0030000F00F0000}
  end
  object Label1: TLabel
    Left = 136
    Top = 72
    Width = 18
    Height = 13
    Caption = 'Tip:'
  end
  object Label2: TLabel
    Left = 136
    Top = 128
    Width = 18
    Height = 13
    Caption = 'Tip:'
  end
  object Button1: TButton
    Left = 203
    Top = 16
    Width = 75
    Height = 25
    Caption = '&Hide'
    Enabled = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object CheckBox1: TCheckBox
    Left = 8
    Top = 16
    Width = 105
    Height = 17
    Caption = '&Place on tray'
    TabOrder = 1
    OnClick = CheckBox1Click
  end
  object RadioButton1: TRadioButton
    Left = 8
    Top = 72
    Width = 65
    Height = 17
    Caption = 'State &1'
    Checked = True
    TabOrder = 2
    TabStop = True
    OnClick = RadioButtonClick
  end
  object RadioButton2: TRadioButton
    Left = 8
    Top = 128
    Width = 65
    Height = 17
    Caption = 'State &2'
    TabOrder = 3
    OnClick = RadioButtonClick
  end
  object Edit1: TEdit
    Left = 159
    Top = 69
    Width = 121
    Height = 21
    TabOrder = 4
    Text = 'Off'
    OnKeyUp = EditKeyUp
  end
  object Edit2: TEdit
    Left = 159
    Top = 125
    Width = 121
    Height = 21
    TabOrder = 5
    Text = 'On'
    OnKeyUp = EditKeyUp
  end
  object PopupMenu1: TPopupMenu
    Left = 136
    Top = 16
    object Properties1: TMenuItem
      Caption = '&Properties'
      OnClick = Properties1Click
    end
    object ToggleState1: TMenuItem
      Caption = '&Toggle State'
      OnClick = ToggleState1Click
    end
    object Shutdown1: TMenuItem
      Caption = '&Shutdown'
      OnClick = Shutdown1Click
    end
  end
end