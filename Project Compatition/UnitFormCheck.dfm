object FormCheck: TFormCheck
  Left = 663
  Top = 346
  Caption = 'FormCheck'
  ClientHeight = 197
  ClientWidth = 586
  Color = clBtnFace
  Constraints.MaxHeight = 235
  Constraints.MaxWidth = 602
  Constraints.MinHeight = 235
  Constraints.MinWidth = 602
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clBlue
  Font.Height = -19
  Font.Name = 'Lucida Console'
  Font.Style = [fsBold]
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 19
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 120
    Height = 19
    Caption = 'Expression'
  end
  object Result: TLabel
    Left = 24
    Top = 136
    Width = 84
    Height = 19
    Caption = 'Wait...'
  end
  object Expression: TEdit
    Left = 16
    Top = 48
    Width = 553
    Height = 27
    TabOrder = 0
    OnChange = ExpressionChange
  end
  object StepByStep: TCheckBox
    Left = 24
    Top = 96
    Width = 177
    Height = 17
    Caption = 'Step By Step'
    TabOrder = 1
    OnClick = StepByStepClick
  end
  object BitBtnCheck: TBitBtn
    Left = 224
    Top = 88
    Width = 137
    Height = 33
    Caption = 'Check'
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 2
    OnClick = BitBtnCheckClick
  end
end
