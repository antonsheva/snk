object frm1: Tfrm1
  Left = 0
  Top = 0
  Caption = 'frm1'
  ClientHeight = 703
  ClientWidth = 1031
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
    Left = 440
    Top = 145
    Width = 510
    Height = 510
    Color = clBtnFace
    ParentBackground = False
    ParentColor = False
    TabOrder = 0
  end
  object btUp: TButton
    Left = 91
    Top = 35
    Width = 41
    Height = 40
    Caption = 'btUp'
    TabOrder = 1
    OnClick = btUpClick
  end
  object btDn: TButton
    Left = 91
    Top = 91
    Width = 41
    Height = 40
    Caption = 'btDn'
    TabOrder = 2
    OnClick = btDnClick
  end
  object btLft: TButton
    Left = 49
    Top = 64
    Width = 41
    Height = 35
    Caption = 'btLft'
    TabOrder = 3
    OnClick = btLftClick
  end
  object btRgt: TButton
    Left = 133
    Top = 64
    Width = 41
    Height = 35
    Caption = 'btRgt'
    TabOrder = 4
    OnClick = btRgtClick
  end
  object GroupBox2: TGroupBox
    Left = 16
    Top = 145
    Width = 401
    Height = 399
    TabOrder = 5
  end
  object GroupBox3: TGroupBox
    Left = 216
    Top = 8
    Width = 105
    Height = 105
    TabOrder = 6
  end
  object chk1: TCheckBox
    Left = 327
    Top = 8
    Width = 33
    Height = 17
    Caption = 'food'
    TabOrder = 7
  end
  object edWtsLf: TEdit
    Left = 327
    Top = 54
    Width = 45
    Height = 21
    TabOrder = 8
    Text = 'edWtsLf'
  end
  object edWtsUp: TEdit
    Left = 378
    Top = 27
    Width = 45
    Height = 21
    TabOrder = 9
    Text = 'Edit1'
  end
  object edWtsDn: TEdit
    Left = 378
    Top = 81
    Width = 45
    Height = 21
    TabOrder = 10
    Text = 'Edit1'
  end
  object edWtsRt: TEdit
    Left = 427
    Top = 54
    Width = 45
    Height = 21
    TabOrder = 11
    Text = 'Edit1'
  end
  object edResult: TEdit
    Left = 495
    Top = 8
    Width = 101
    Height = 21
    TabOrder = 12
    Text = 'edResult'
  end
  object Button1: TButton
    Left = 2
    Top = 8
    Width = 41
    Height = 21
    Caption = 'Button1'
    TabOrder = 13
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 2
    Top = 35
    Width = 41
    Height = 25
    Caption = 'Button2'
    TabOrder = 14
  end
  object chkAuto: TCheckBox
    Left = 499
    Top = 91
    Width = 54
    Height = 17
    Caption = 'auto'
    TabOrder = 15
  end
  object ed1: TEdit
    Left = 680
    Top = 27
    Width = 121
    Height = 21
    TabOrder = 16
    Text = 'ed1'
  end
  object ed2: TEdit
    Left = 807
    Top = 27
    Width = 121
    Height = 21
    TabOrder = 17
    Text = 'ed2'
  end
  object Timer1: TTimer
    Interval = 1
    OnTimer = Timer1Timer
    Left = 584
    Top = 64
  end
end
