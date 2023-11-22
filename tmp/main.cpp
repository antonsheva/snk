// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "main.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tfrm1 *frm1;

#define X_LEN 50
#define Y_LEN 50
#define HI 10
#define WT 10

#define UP  1
#define DN  2
#define LFT 3
#define RGT 4

#define EYE_LEN  9

TPanel* pnlObj[Y_LEN][X_LEN];
TEdit*  edObj[20][20];

struct snake{
	int len;
	int x,y;
	int up_wt, dn_wt, lf_wt, rt_wt;
	int brain[EYE_LEN][EYE_LEN];
	int bd_x[20];
	int bd_y[20];

}snk;

struct sens{
	int s_up;
	int s_dn;
	int s_lf;
	int s_rt;
};

sens A_block[EYE_LEN][EYE_LEN];
sens A_food [EYE_LEN][EYE_LEN];
// ---------------------------------------------------------------------------
__fastcall Tfrm1::Tfrm1(TComponent* Owner) : TForm(Owner)
{

}

void Tfrm1::AInitWts()
{
	int x,y;
	for(y = 0; y < EYE_LEN; y++){
	   for(x = 0; x < EYE_LEN; x++){
		  A_food[x][y].s_up = (y<4) ? y+1 : 4-y;
		  A_food[x][y].s_lf = (x<4) ? x+1 : 4-x;

		  A_food[x][y].s_dn = (y<4) ? 4-y : y+1;
		  A_food[x][y].s_rt = (x<4) ? 4-x : x+1;


		  A_block[x][y].s_dn = (y<5) ? -y-1 : y+1;
		  A_block[x][y].s_rt = (x<5) ? -x-1 : x+1;

		  A_block[x][y].s_up = (y<5) ? y+1 : -y-1;
		  A_block[x][y].s_lf = (x<5) ? x+1 : -x-1;

	   }
	}

	for(y = 0; y < 18; y+=2){
	   for(x = 0; x < 18; x+=2){
		  edObj[x][y]->Text = A_food[x/2][y/2].s_up;
		  edObj[x][y+1]->Text = A_food[x/2][y/2].s_lf;

		  edObj[x+1][y]->Text = A_food[x/2][y/2].s_rt;
		  edObj[x+1][y+1]->Text = A_food[x/2][y/2].s_dn;
	   }
	}

}

void Tfrm1::AScanSpace()
{
	int x,y,i;
	int x1, y1;

	for(y1 = 0; y1 < EYE_LEN; y1++) {
		for(x1 = 0; x1 < EYE_LEN; x1++) {
			x = snk.x-EYE_LEN/2+x1;
			y = snk.y-EYE_LEN/2+y1;

			pnlObj[x][y]->Color = clYellow;

		}
	}
    AShowSnake();
}

void Tfrm1::AShowSnake()
{
   int x,y,i;
   pnlObj[snk.x][snk.y]->Color = clRed;
   for(i = 0; i < snk.len; i++) {
	  pnlObj[snk.bd_x[i]][snk.bd_y[i]]->Color = clLime;
   }

}

void Tfrm1::AClearSnakeBody()
{
  int c;
  for(c = 0; c < 20; c++){
	snk.bd_x[c] = 0;
	snk.bd_y[c] = 0;
  }
}

void Tfrm1::AInitSnake()
{
   int x,y,i;
   snk.len = 10;
   snk.x = 25;
   snk.y = 29;
   for(y = 0; y < EYE_LEN; y++)
	 for(x = 0; x < EYE_LEN; x++)
			snk.brain[x][y] = 1;

   for(i = 0; i < snk.len; i++){
		snk.bd_x[i] = 25;
		snk.bd_y[i] = 30+i;
   }
   AInitWts();
}

void Tfrm1::AClearFild()
{
   int x,y;
   for(y = 0; y < 50; y++)
	 for(x = 0; x < 50; x++)
		pnlObj[x][y]->Color = clGray;
   Application->ProcessMessages();
}

void Tfrm1::AShiftSnke(int dir)
{
   int i, tmp_x, tmp_y;
   tmp_x = snk.x;
   tmp_y = snk.y;
   switch(dir){
		case UP :snk.y--; break;
		case DN :snk.y++; break;
		case LFT:snk.x--; break;
		case RGT:snk.x++; break;
   }
   for(i = snk.len-1; i > 0; i--) {
	  snk.bd_x[i] = snk.bd_x[i-1];
	  snk.bd_y[i] = snk.bd_y[i-1];
   }
   snk.bd_x[0] = tmp_x;
   snk.bd_y[0] = tmp_y;
}

void Tfrm1::ACreatePanelsFields()
 {
	int x, y;
	for (y = 0; y < Y_LEN; y++) {
		for (x = 0; x < X_LEN; x++) {
			pnlObj[x][y] = new TPanel(frm1);
			pnlObj[x][y]->Parent = GroupBox1;
			pnlObj[x][y]->Height = HI;
			pnlObj[x][y]->Width = WT;
			pnlObj[x][y]->Top = y * HI+5;
			pnlObj[x][y]->Left = x * WT + 5;
			pnlObj[x][y]->Visible = true;
			pnlObj[x][y]->Color = clGray;
			pnlObj[x][y]->ParentBackground = False;
			pnlObj[x][y]->Ctl3D = false;

		}
	}
}

void Tfrm1::ACreateInfoFields()
 {
	int x, y, tmp;
	tmp = 3;
	for (y = 0; y < 18; y++) {
	   //	tmp = (!(y%2)) ? tmp+2 : tmp;
		for (x = 0; x < 18; x++) {

			edObj[x][y] = new TEdit(frm1);
			edObj[x][y]->Parent = GroupBox2;
			edObj[x][y]->Height = 18;
			edObj[x][y]->Width = 18;
			edObj[x][y]->Top = (!(y%2)) ? (y * 22+10+tmp) : (y * 22+10);
			edObj[x][y]->Left = (!(x%2)) ? (x * 22+10+tmp) : (x * 22+10);
			edObj[x][y]->Visible = true;
			edObj[x][y]->Color = clWindow;
			edObj[x][y]->Ctl3D = false;

		}
	}
}


void __fastcall Tfrm1::FormShow(TObject *Sender)
{
ACreatePanelsFields();
ACreateInfoFields();
  AInitSnake();
  AShowSnake();
}
//---------------------------------------------------------------------------

void __fastcall Tfrm1::btUpClick(TObject *Sender)
{
  AClearFild();
  AShiftSnke(UP);
  AShowSnake();
}
//---------------------------------------------------------------------------

void __fastcall Tfrm1::btDnClick(TObject *Sender)
{
  AClearFild();
  AShiftSnke(DN);
  AShowSnake();

}
//---------------------------------------------------------------------------

void __fastcall Tfrm1::btLftClick(TObject *Sender)
{
  AClearFild();
  AShiftSnke(LFT);
  AShowSnake();

}
//---------------------------------------------------------------------------

void __fastcall Tfrm1::btRgtClick(TObject *Sender)
{
  AClearFild();
  AShiftSnke(RGT);
  AShowSnake();

}
//---------------------------------------------------------------------------

void __fastcall Tfrm1::Button1Click(TObject *Sender)
{
	AScanSpace();
}
//---------------------------------------------------------------------------

