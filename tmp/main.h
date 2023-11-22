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

//---------------------------------------------------------------------------
class Tfrm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TButton *btUp;
	TButton *btDn;
	TButton *btLft;
	TButton *btRgt;
	TButton *Button1;
	TGroupBox *GroupBox2;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btUpClick(TObject *Sender);
	void __fastcall btDnClick(TObject *Sender);
	void __fastcall btLftClick(TObject *Sender);
	void __fastcall btRgtClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall Tfrm1(TComponent* Owner);

	void ACreatePanelsFields();
    void ACreateInfoFields();
	void AInitSnake();
	void AShowSnake();
	void AClearSnakeBody();
	void AShiftSnke(int dir);
	void AClearFild();
	void AScanSpace();
	void AInitWts();
};
//---------------------------------------------------------------------------
extern PACKAGE Tfrm1 *frm1;
//---------------------------------------------------------------------------
#endif
