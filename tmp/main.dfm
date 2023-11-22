object frm1: Tfrm1
  Left = 0
  Top = 0
  Caption = 'frm1'
  ClientHeight = 786
  ClientWidth = 1334
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 510
    Height = 510
    TabOrder = 0
  end
  object btUp: TButton
    Left = 48
    Top = 550
    Width = 40
    Height = 40
    Caption = 'btUp'
    TabOrder = 1
    OnClick = btUpClick
  end
  object btDn: TButton
    Left = 45
    Top = 644
    Width = 40
    Height = 40
    Caption = 'btDn'
    TabOrder = 2
    OnClick = btDnClick
  end
  object btLft: TButton
    Left = 5
    Top = 598
    Width = 40
    Height = 40
    Caption = 'btLft'
    TabOrder = 3
    OnClick = btLftClick
  end
  object btRgt: TButton
    Left = 91
    Top = 598
    Width = 40
    Height = 40
    Caption = 'btRgt'
    TabOrder = 4
    OnClick = btRgtClick
  end
  object Button1: TButton
    Left = 160
    Top = 605
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 5
    OnClick = Button1Click
  end
  object GroupBox2: TGroupBox
    Left = 524
    Top = 2
    Width = 725
    Height = 745
    TabOrder = 6
  end
end
