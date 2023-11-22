//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
//#include <System.Classes.hpp>
//#include <Vcl.Controls.hpp>
//#include <Vcl.StdCtrls.hpp>
//#include <Vcl.Forms.hpp>

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>


#define X_LEN 50
#define Y_LEN 50
#define HI 10
#define WT 10

#define UP  1
#define DN  2
#define LFT 3
#define RGT 4

#define EYE_LEN 9

#define FOOD  1
#define BLOCK 2
#define BODY  3

//---------------------------------------------------------------------------
class Tfrm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TButton *btUp;
	TButton *btDn;
	TButton *btLft;
	TButton *btRgt;
	TGroupBox *GroupBox2;
	TGroupBox *GroupBox3;
	TCheckBox *chk1;
	TEdit *edWtsLf;
	TEdit *edWtsUp;
	TEdit *edWtsDn;
	TEdit *edWtsRt;
	TEdit *edResult;
	TButton *Button1;
	TButton *Button2;
	TCheckBox *chkAuto;
	TTimer *Timer1;
	TEdit *ed1;
	TEdit *ed2;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btUpClick(TObject *Sender);
	void __fastcall btDnClick(TObject *Sender);
	void __fastcall btLftClick(TObject *Sender);
	void __fastcall btRgtClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tfrm1(TComponent* Owner);

BYTE A_space[X_LEN][Y_LEN];
BYTE A_eye[EYE_LEN][EYE_LEN];





struct snake{
	int len;
	int x,y;
	int dir;
	int food_cnt;
	int death;
	int wt_up, wt_dn, wt_lf, wt_rt;
	int brain[EYE_LEN][EYE_LEN];
	int bd_x[100];
	int bd_y[100];
}snk;

struct sens{
	int s_up;
	int s_dn;
	int s_lf;
	int s_rt;
};

sens A_block[EYE_LEN][EYE_LEN];
sens A_food [EYE_LEN][EYE_LEN];

	void ACreatePanelsFields();
	void ACreateInfoFields();
	void ACreateEyeFields();
	void AInitSnake();
	void AShowSnake();
	void AClearSnakeBody();
	void AShiftSnke(int dir);
	void ARefreshFild();
	void AScanSpace();
	void AInitWts();
	void AInitSpace();
	void AShowEye();
	void AGetWts();
	void AInitWts_1();
	void AResetSnkWts();
	void ASetSnakeBodyPos();
	void AShowWts(int type);
	void AShowBrainWts();
	void ACreateEat();
	int AMakeDecision();
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm1 *frm1;
//---------------------------------------------------------------------------
#endif
