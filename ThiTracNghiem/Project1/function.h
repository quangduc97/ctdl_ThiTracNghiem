#include <time.h>
#include <Windows.h> 
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <string>
#include "config.h"
#include "XyLy.h"
#include "DoHoa.h"
#include "XyLyNhap.h"


using namespace std;

void TrimWord(string& Word);
int EmptyLop(DSLOP& dslop) { return (dslop.n == 0 ? TRUE : FALSE); }
int fullLop(DSLOP dslop) { return(dslop.n == DSLOP_MAX ? TRUE : FALSE); }
int fullMH(DSMH dsmh) { return(dsmh.n == DSMH_MAX ? TRUE : FALSE); }
void ThemPhanTuVaoCuoiDSLop(DSLOP& dslop, int i, LOP lop);
bool NhapLop(DSLOP& dslop);
void InDSLop(DSLOP dslop);
void NhapSV(DSLOP& dslop);
void XuatSV(DSLOP& dslop);
bool NhapMonHoc(DSMH& dsmh);
void XuatMonHoc(DSMH dsmh);
void XoaMonHoc(DSMH& dsmh);
void SuaMonHoc(DSMH& dsmh);
void DocFileCH(DSCH& dsch, int arr[], DSMH& dsmh);
void ThemCauHoiThi(nodetree& root, DSMH& dsmh, int arr[]);
void DuyetTree(nodetree root, ofstream& FileOut);
void TestDuyetTree(nodetree root);
void ThiTracNghiem(DSLOP& L, DSCH CH, DSMH t, string MaSV, int toadoX, int toadoY);
bool CheckXemCauHoiThi1SV(DSLOP dslop, DSMH dsmh);
bool CheckXemBangDiem1Lop(DSLOP dslop, DSMH dsmh, string &malop, string &mamh);
void XuatBangDiem(DSLOP dslop, DSMH dsmh, string malop, string mamh);
void DeleteMemory(DSMH& t, DSLOP& L, nodetree& CH);
void Save(DSLOP& dslop, DSCH& dsch);
void DSCauHoiThi1MonCua1SinhVien(DSMH t, DSLOP L, int toadoX, int toadoY);

//===================================================== End muc luc ==============================================================

//==================================================== Kiem tra dang nhap ========================================================
bool CheckSVLogin(DSLOP& dslop, string TK, string MK) {
	//cout << "aaaaaaaaaaa";
	for (int i = 0; i < dslop.n; i++) {
		for (SV* check = dslop.nodes[i]->ptrDSSV.phead; check != NULL; check = check->pnext) {
			if (TK == check->MASV && MK == check->PASSWORD) {
				return true;
			}
			
		}
	}
	return false;
}

bool RunDangNhap(DSLOP& dslop, string& TK, string& MK)
{
	int pointer1 = 18;
	int pointer2 = 75;
	GiaoDienDangNhap();
	while (true)
	{
		if (pointer1 == 18)
		{
			gotoXY(76 + TK.length(), pointer1);
			XuLyNhapTK(TK, 76, pointer1);
			if (pointer1 < 18)
			{
				pointer1 = 24;
			}
		}
		else if (pointer1 == 21)
		{
			gotoXY(76 + MK.length(), pointer1);
			XuLyNhapMK(MK, 76, pointer1);
		}
		else if (pointer1 == 24)
		{
			ShowCur(0);
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						if (pointer2 == 75 && !TK.empty() && !MK.empty())
						{
							if (TK == "GV" && MK == "GV")
							{
								system("cls");
								return true;
							}
							else if (CheckSVLogin(dslop, TK, MK))
							{
								system("cls");
								return false;
							}
							else
							{
								gotoXY(0, 29);
								cout << "                                                    ";
								gotoXY(0, 29);
								cout << CanDeuChuoi("Tai Khoan Hoac Mat Khau Khong Dung", 176);
							}
						}
						else if (pointer2 == 95)
						{
							exit(0);
						}
						else
						{
							gotoXY(0, 29);
							cout << "                                               ";
							gotoXY(0, 29);
							cout << CanDeuChuoi("Vui Long Nhap Day Du Thong Tin", 176);
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							textcolor(7);
							gotoXY(95, 25);
							cout << "Exit";
							gotoXY(75, 25);
							cout << "Xac Nhan";
							pointer1 = pointer1 - 3;
							ShowCur(1);
							break;
						}
						else if (c == 80)
						{
							textcolor(7);
							gotoXY(95, 25);
							cout << "Exit";
							gotoXY(75, 25);
							cout << "Xac Nhan";
							ShowCur(1);
							pointer1 = 18;
							break;
						}
						else if (c == 75)
						{
							if (pointer2 == 75)
							{
								pointer2 = 95;
							}
							else
								pointer2 = 75;
						}
						else if (c == 77)
						{
							if (pointer2 == 75)
							{
								pointer2 = 95;
							}
							else
								pointer2 = 75;
						}
						gotoXY(pointer2, 25);
					}
				}

				//				SetColor(5);
				textcolor(125);
				gotoXY(pointer2, pointer1 + 1);
				if (pointer2 == 75)
				{
					cout << "Xac Nhan";
					textcolor(7);
					gotoXY(95, 25);
					cout << "Exit";
				}
				else
				{
					cout << "Exit";
					textcolor(7);
					gotoXY(75, 25);
					cout << "Xac Nhan";
				}
			}
		}
	}
}
//================================================== End kiem tra dang nhap ======================================================

//==================================================== Menu ============================================================

//menu
string strMNMain[] = {
"              Them Lop                ", //1
"            Danh Sach Lop             ", //2
"           Them Sinh Vien             ", //3
"            Them Mon Hoc              ", //4
"            Sua Mon Hoc               ", //5
"            Xoa Mon Hoc               ", //6
"          Them Cau Hoi Thi            ", //7
"          Thi Trac Nghiem             ", //8
"    Cau Hoi Thi 1 Mon Hoc Cua 1 SV    ", //9
"    Bang Diem Thi Trac Nghiem 1 Lop   ", //10
"               Thoat                  "  //0
};
void Menu()
{
	//textcolor(240);
	int j = 19;
	for (int i = 0; i < sizeof(strMNMain) / sizeof(*strMNMain); i++)
	{
		gotoXY(6, j++);
		cout << strMNMain[i];
	}
}
void RunMenu(DSLOP& dslop, DSMH& dsmh, DSCH& dsch, int arr[])
{
	if (kbhit())
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == 72)
			{
				if (pointer == 19)
				{
					Menu();
					pointer = 19 - 1 + sizeof(strMNMain) / sizeof(*strMNMain);
				}
				else
				{
					Menu();
					pointer--;
				}
			}
			else if (c == 80)
			{
				if (pointer == 19 - 1 + sizeof(strMNMain) / sizeof(*strMNMain))
				{
					Menu();
					pointer = 19;
				}
				else
				{
					Menu();
					pointer++;
				}
			}
		}
		else if (c == 13)
		{
			textcolor(188);
			gotoXY(6, pointer);
			cout << "                                      ";
			gotoXY(6, pointer);
			cout << strMNMain[pointer - 19];
			textcolor(7);
			switch (pointer)
			{
			case 19://1
				XoaManHinhTuyChon(52, 6, 126, 24);
				if (fullLop(dslop)) {
					Error("Danh sach bi day.");
					getch();
					XoaManHinhTuyChon(52, 6, 126, 30);
					break;
				}
				else {
					if (NhapLop(dslop)) {
						XoaManHinhTuyChon(70, 6, 100, 24);
						Success("Them lop thanh cong.");
						break;
					}
					else {
						XoaManHinhTuyChon(52, 6, 126, 30);
						break;
					}
				}
			case 20://2
				XoaManHinhTuyChon(52, 6, 126, 30);

				if (EmptyLop(dslop)) {
					Error("Chua co lop trong danh sach.");
					getch();
					XoaManHinhTuyChon(52, 6, 126, 30);
					break;
				}
				else {
					InDSLop(dslop);
					//XuatSV(dslop);
					XoaManHinhTuyChon(52, 6, 126, 30);
					break;
				}
			case 21://3
				XoaManHinhTuyChon(52, 6, 126, 30);
				if (EmptyLop(dslop)) {
					Error("Chua co lop trong danh sach.");
					getch();
					XoaManHinhTuyChon(52, 6, 126, 30);
					break;
				}
				else {
					NhapSV(dslop);
					break;
				}
			case 22://4
				XoaManHinhTuyChon(52, 6, 126, 30);
				if (fullMH(dsmh)) {
					Error("Danh sach bi day.");
					getch();
					XoaManHinhTuyChon(52, 6, 126, 30);
					break;
				}
				else {
					if (NhapMonHoc(dsmh)) {
						XoaManHinhTuyChon(70, 6, 100, 30);
						Success("Them mon hoc thanh cong.");
						break;
					}
					else {
						XoaManHinhTuyChon(52, 6, 126, 30);
						break;
					}
				}
			case 23://5
				XoaManHinhTuyChon(52, 6, 126, 30);
				if (dsmh.n == 0) {
					Error("Chua co mon hoc trong danh sach.");
					getch();
					XoaManHinhTuyChon(52, 6, 126, 30);
					break;
				}
				else {
					SuaMonHoc(dsmh);
					break;
				}
			case 24://6
				XoaManHinhTuyChon(52, 6, 126, 30);
				if (dsmh.n == 0) {
					Error("Chua co mon hoc trong danh sach.");
					getch();
					XoaManHinhTuyChon(52, 6, 126, 30);
					break;
				}
				else {
					XoaMonHoc(dsmh);
					break;
				}
			case 25://7
				XoaManHinhTuyChon(52, 6, 126, 30);
				ThemCauHoiThi(dsch.root, dsmh, arr);
				break;
			case 26://8
				XoaManHinhTuyChon(52, 6, 126, 30);
				ThiTracNghiem(dslop, dsch, dsmh, "", 95, 17);
				XoaManHinhTuyChon(52, 6, 126, 32);
				break;
			case 27://9
				XoaManHinhTuyChon(52, 6, 126, 30);
				DSCauHoiThi1MonCua1SinhVien(dsmh, dslop, 95, 17);
				XoaManHinhTuyChon(52, 6, 126, 30);
				break;
			case 28://10
				XoaManHinhTuyChon(52, 6, 126, 30);
				if (CheckXemBangDiem1Lop(dslop, dsmh, malop_xuatbangdiem1lop, mamh_xuatbangdiem1lop)) {
					XoaManHinhTuyChon(52, 6, 126, 30);
					GiaoDienXuatBangDiem1Lop(65, 6, 13);
					XuatBangDiem(dslop, dsmh, malop_xuatbangdiem1lop, mamh_xuatbangdiem1lop);
					getch();
				}
				XoaManHinhTuyChon(52, 6, 126, 30);
				break;
			case 29://0
				Save(dslop, dsch);

				ofstream FileOut;
				FileOut.open("data\\dsmh.txt", ios::out);
				FileOut << dsmh.n << endl;
				for (int i = 0; i < dsmh.n; i++) {
					FileOut << dsmh.mh[i]->MAMH << ",";
					FileOut << dsmh.mh[i]->TENMH << endl;
				}
				FileOut.close();

				FileOut.open("data\\cauhoithi.txt", ios::out);
				FileOut << dsch.n << endl;
				DuyetTree(dsch.root, FileOut);
				FileOut.close();

				GhiFileSoNgauNhien(arr, soluongsongaunhien);

				DeleteMemory(dsmh, dslop, dsch.root);

				exit(0);
			}

			XoaManHinhTuyChon(0, 0, 52, 40);
			XoaManHinhTuyChon(52, 0, 126, 6);
			GiaoDienMain();
			Menu();
		}
		else if (c == 27)
		{
			exit(0);
		}
	}

	// to mau 
	textcolor(180);
	gotoXY(6, pointer);
	cout << strMNMain[pointer - 19];
	textcolor(7);
}

void Khoitao(DSLOP& dslop, DSMH& dsmh, DSCH& dsch, int arr[])
{
	resizeConsole(1450, 650);
	string TK;
	string MK;
	dslop.n = 0;
	dsmh.n = 0;
	dsch.root = NULL;
	dsch.n = 0;
	DocFileSoNgauNhien(arr);
	DocFileLop(dslop);
	DocFileMH(dsmh);
	DocFileCH(dsch, arr, dsmh);
	
	if (!RunDangNhap(dslop, TK, MK))
	{
		GiaoDienSinhVienDangNhap();
		ThiTracNghiem(dslop, dsch, dsmh, TK, 95, 17);
		Save(dslop, dsch);
		DeleteMemory(dsmh, dslop, dsch.root);
		exit(0);
	}
	else {
		HCNTextDong(4, 13, 42, 22);
		GiaoDienMain();
		Menu();
	}
}
//=============================================== End menu =============================================================

//===================================================== Nhap lop =================================================================


bool NhapLop(DSLOP& dslop) {
	LOP* lop = new LOP;
	int pointer1 = 18;
	int pointer2 = 105;
	string malop;
	string tenlop;

	GiaoDienNhapLop();
	ShowCur(1);
	while (true)
	{
		if (pointer1 == 18)
		{
			gotoXY(91 + malop.length(), pointer1);
			XuLyNhapMaMonHoc(malop, 91, pointer1);
			if (pointer1 < 18)
			{
				pointer1 = 24;
			}
		}
		else if (pointer1 == 21)
		{
			gotoXY(91 + tenlop.length(), pointer1);
			XuLyNhap_Chu(tenlop, 91, pointer1, 30);
		}
		else if (pointer1 == 24)
		{
			ShowCur(0);
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						if (pointer2 == 105)
						{
							bool kt = false;
							for (int i = 0; i < dslop.n; i++) {
								if (malop == dslop.nodes[i]->MALOP) {
									VeHCN(90, 31, 50, 2, 15);
									textcolor(4);
									for (int i = 0; i < 48; i++) {
										gotoXY(91 + i, 32);
										cout << ".";
										Sleep(10);
									}
									for (int i = 0; i < 48; i++) {
										gotoXY(91 + i, 32);
										cout << " ";
									}
									gotoXY(91, 32);
									cout << CanDeuChuoi("Ma lop da bi trung !!!", 50);
									kt = true;
									pointer1 = 18;
									textcolor(7);
									gotoXY(pointer2, 27);
									cout << "Them";
									ShowCur(1);
								}
							}
							if (malop == "" || tenlop == "") {
								kt = true;
								VeHCN(90, 31, 50, 2, 15);
								textcolor(4);
								for (int i = 0; i < 48; i++) {
									gotoXY(91 + i, 32);
									cout << ".";
									Sleep(10);
								}
								for (int i = 0; i < 48; i++) {
									gotoXY(91 + i, 32);
									cout << " ";
								}
								gotoXY(91, 32);
								cout << CanDeuChuoi("Vui long nhap day du thong tin !!!", 50);
								pointer1 = 18;
								textcolor(7);
								gotoXY(pointer2, 27);
								cout << "Them";
								ShowCur(1);
							}
							if (!kt) {
								lop->MALOP = malop;
								lop->TENLOP = tenlop;
								dslop.nodes[dslop.n] = lop;
								dslop.n++;
								return TRUE;
							}
							break;
						}
						else if (pointer2 == 120)
						{
							return FALSE;
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							textcolor(7);
							gotoXY(120, 27);
							cout << "Thoat";
							gotoXY(105, 27);
							cout << "Them";
							pointer1 = pointer1 - 3;
							ShowCur(1);
							break;
						}
						else if (c == 80)
						{
							textcolor(7);
							gotoXY(120, 27);
							cout << "Thoat";
							gotoXY(105, 27);
							cout << "Them";
							ShowCur(1);
							pointer1 = 18;
							break;
						}
						else if (c == 75)
						{
							if (pointer2 == 105)
							{
								pointer2 = 120;
							}
							else
								pointer2 = 105;
						}
						else if (c == 77)
						{
							if (pointer2 == 105)
							{
								pointer2 = 120;
							}
							else
								pointer2 = 105;
						}
						gotoXY(pointer2, 27);
					}
				}
				textcolor(125);
				gotoXY(pointer2, 27);
				if (pointer2 == 105)
				{
					cout << "Them";
					textcolor(7);
					gotoXY(120, 27);
					cout << "Thoat";
				}
				else
				{
					cout << "Thoat";
					textcolor(7);
					gotoXY(105, 27);
					cout << "Them";
				}
			}
		}
	}
}
//=================================================== End nhap lop ===============================================================

//================================================= In danh sach lop =============================================================
void InDSLop(DSLOP dslop) {
	GiaoDienXuatDanhSachLop(63, 7, dslop.n);
	for (int i = 0; i < dslop.n; i++) {
		gotoXY(64, 11 + i * 2);
		//cout << dslop.nodes[i]->MALOP;
		cout << CanDeuChuoi(dslop.nodes[i]->MALOP, 29);
		gotoXY(95, 11 + i * 2);
		//cout << dslop.nodes[i]->TENLOP;
		cout << CanDeuChuoi(dslop.nodes[i]->TENLOP, 69);
	}
	gotoXY(51, 11 + dslop.n * 2);
	cout << CanDeuChuoi("An nut bat ki de thoat", 126);
	getch();
}
//=============================================== End in danh sach lop ===========================================================

//============================================== Nhap sinh vien cua lop ==========================================================
bool ThemSV(DSSV& dssv) {
	SV* sv = new SV();
	int pointer1 = 12;
	int pointer2 = 120;
	string Phai, masv, ho, ten, password;

	GiaoDienNhapSinhVien();
	ShowCur(1);
	while (true)
	{
		if (pointer1 == 12) {
			gotoXY(106 + password.length(), pointer1);
			XuLyNhapMK(password, 106, pointer1);
			if (pointer1 < 12)
			{
				pointer1 = 27;
			}
		}
		else if (pointer1 == 15)
		{
			gotoXY(106 + masv.length(), pointer1);
			XuLyNhapMaMonHoc(masv, 106, pointer1);
		}
		else if (pointer1 == 18)
		{
			gotoXY(106 + ho.length(), pointer1);
			XuLyNhap_Chu(ho, 106, pointer1, 47);
		}
		else if (pointer1 == 21)
		{
			gotoXY(106 + ten.length(), pointer1);
			XuLyNhap_Chu(ten, 106, pointer1, 47);
		}
		else if (pointer1 == 24)
		{
			ChonPhai(110, 24, Phai, pointer1);
		}
		else if (pointer1 == 27)
		{
			ShowCur(0);
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						if (pointer2 == 120)
						{
							bool kt = false;
							for (SV* check = dssv.phead; check != NULL; check = check->pnext) {
								if (masv == check->MASV) {
									VeHCN(90, 31, 50, 2, 15);
									textcolor(4);
									for (int i = 0; i < 48; i++) {
										gotoXY(91 + i, 32);
										cout << ".";
										Sleep(10);
									}
									for (int i = 0; i < 48; i++) {
										gotoXY(91 + i, 32);
										cout << " ";
									}
									gotoXY(91, 32);
									cout << CanDeuChuoi("Ma sinh vien da bi trung !!!", 50);
									kt = true;
									pointer1 = 12;
									textcolor(7);
									gotoXY(pointer2, 27);
									cout << "Them";
									ShowCur(1);
								}
							}
							if (masv == "" || ho == "" || ten == "" || Phai == "" || password == "") {
								VeHCN(90, 31, 50, 2, 15);
								textcolor(4);
								for (int i = 0; i < 48; i++) {
									gotoXY(91 + i, 32);
									cout << ".";
									Sleep(10);
								}
								for (int i = 0; i < 48; i++) {
									gotoXY(91 + i, 32);
									cout << " ";
								}
								gotoXY(91, 32);
								cout << CanDeuChuoi("Vui Long Nhap Day Du Thong Tin !!!", 50);
								kt = true;
								pointer1 = 12;
								textcolor(7);
								gotoXY(pointer2, 27);
								cout << "Them";
								ShowCur(1);
							}
							if (!kt) {
								sv->MASV = masv;
								sv->HO = ho;
								sv->TEN = ten;
								sv->PHAI = Phai;
								sv->PASSWORD = password;
								sv->slmondathi = 0;
								sv->ptrDSDT.phead = NULL;
								//	them dau
								if (dssv.phead == NULL) {
									sv->pnext = NULL;
									dssv.phead = sv;
									dssv.n++;
								}
								else {
									sv->pnext = dssv.phead;
									dssv.phead = sv;
									dssv.n++;
								}
								Success("Them sinh vien thanh cong.");
								ClearText(106, 12, 48);
								ClearText(106, 15, 48);
								ClearText(106, 18, 48);
								ClearText(106, 21, 48);
								ClearText(131, 24, 13);
								return TRUE;
							}
							break;
						}
						else if (pointer2 == 135)
						{
							XoaManHinhTuyChon(52, 6, 126, 30);
							return FALSE;
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							textcolor(7);
							gotoXY(135, 27);
							cout << "Thoat";
							gotoXY(120, 27);
							cout << "Them";
							pointer1 = pointer1 - 3;
							ShowCur(1);
							break;
						}
						else if (c == 80)
						{
							textcolor(7);
							gotoXY(135, 27);
							cout << "Thoat";
							gotoXY(120, 27);
							cout << "Them";
							ShowCur(1);
							pointer1 = 12;
							break;
						}
						else if (c == 75)
						{
							if (pointer2 == 120)
							{
								pointer2 = 135;
							}
							else
								pointer2 = 120;
						}
						else if (c == 77)
						{
							if (pointer2 == 120)
							{
								pointer2 = 135;
							}
							else
								pointer2 = 120;
						}
						gotoXY(pointer2, 27);
					}
				}

				//				SetColor(5);
				textcolor(125);
				gotoXY(pointer2, 27);
				if (pointer2 == 120)
				{
					cout << "Them";
					textcolor(7);
					gotoXY(135, 27);
					cout << "Thoat";
				}
				else
				{
					cout << "Thoat";
					textcolor(7);
					gotoXY(120, 27);
					cout << "Them";
				}
			}
		}
	}
}

int isMaLop(DSLOP dslop, string ml) {
	for (int i = 0; i < dslop.n; i++) {
		if (ml == dslop.nodes[i]->MALOP) {
			return i;
		}
	}
	return -1;
}
void NhapSV(DSLOP& dslop) {
	string ml;
	GiaoDienNhapMaLop();
	ShowCur(1);
	gotoXY(91, 18);
	XuLyNhapMaLop(ml, 91, 18);
	if (isMaLop(dslop, ml) != -1) {
		XoaManHinhTuyChon(70, 15, 80, 15);
		while (true) {
			if (ThemSV(dslop.nodes[isMaLop(dslop, ml)]->ptrDSSV)) {
				dslop.nodes[isMaLop(dslop, ml)]->ptrDSSV.n++;
				continue;
			}
			else {
				return;
			}
		}
	}
	else {
		XoaManHinhTuyChon(52, 6, 126, 30);
		Error("Ma lop khong ton tai");
	}


	//	getch();

	//	InDSLop(dslop);
	//	string ml;
	//	cout << "Nhap ma lop: "; cin >> ml;

}

void XuatSV(DSLOP& dslop) {
	//InDSLop(dslop);
	string ml;
	cout << "Nhap ma lop: "; cin >> ml;

	for (int i = 0; i < dslop.n; i++) {
		if (ml == dslop.nodes[i]->MALOP) {
			if (dslop.nodes[i]->ptrDSSV.phead == NULL) {
				cout << "DSSV rong";
			}
			else {
				for (SV* check = dslop.nodes[i]->ptrDSSV.phead; check != NULL; check = check->pnext) {
					cout << "MaSV: " << check->MASV << endl;
					cout << "MaSV: " << check->HO << endl;
					cout << "MaSV: " << check->TEN << endl;
					cout << "MaSV: " << check->PHAI << endl;
					cout << "MaSV: " << check->PASSWORD << endl;
				}
			}
		}

	}
	getch();
}
//============================================= End nhap sinh vien cua lop =======================================================

//============================================== Nhap mon hoc ==========================================================
bool NhapMonHoc(DSMH& dsmh) {
	MonHoc* mh = new MonHoc;

	int pointer1 = 18;
	int pointer2 = 110;
	string mamh, tenmh;
	GiaoDienDKMonHoc();
	ShowCur(1);
	while (true)
	{
		if (pointer1 == 18)
		{
			gotoXY(96 + mamh.length(), pointer1);
			XuLyNhapMaMonHoc(mamh, 96, pointer1);
			if (pointer1 < 18)
			{
				pointer1 = 24;
			}
		}
		else if (pointer1 == 21)
		{
			gotoXY(96 + tenmh.length(), pointer1);
			XuLyNhap_Chu(tenmh, 96, pointer1, 30);
		}
		else if (pointer1 == 24)
		{
			ShowCur(0);
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						if (pointer2 == 110)
						{
							bool kt = false;
							for (int i = 0; i < dsmh.n; i++) {
								if (mamh == dsmh.mh[i]->MAMH) {
									VeHCN(90, 31, 50, 2, 15);
									textcolor(4);
									for (int i = 0; i < 48; i++) {
										gotoXY(91 + i, 32);
										cout << ".";
										Sleep(10);
									}
									for (int i = 0; i < 48; i++) {
										gotoXY(91 + i, 32);
										cout << " ";
									}
									gotoXY(91, 32);
									cout << CanDeuChuoi("Ma mon hoc da bi trung !!!", 50);
									kt = true;
									pointer1 = 18;
									textcolor(7);
									gotoXY(pointer2, 24);
									cout << "Dang Ki";
									ShowCur(1);
								}
							}
							if (mamh == "" || tenmh == "") {
								VeHCN(90, 31, 50, 2, 15);
								textcolor(4);
								for (int i = 0; i < 48; i++) {
									gotoXY(91 + i, 32);
									cout << ".";
									Sleep(10);
								}
								for (int i = 0; i < 48; i++) {
									gotoXY(91 + i, 32);
									cout << " ";
								}
								gotoXY(91, 32);
								cout << CanDeuChuoi("Vui Long Nhap Day Du Thong Tin !!!", 50);
								kt = true;
								pointer1 = 18;
								textcolor(7);
								gotoXY(pointer2, 24);
								cout << "Dang Ki";
								ShowCur(1);
							}
							if (!kt) {
								mh->MAMH = mamh;
								mh->TENMH = tenmh;
								dsmh.mh[dsmh.n] = mh;
								dsmh.n++;
								return TRUE;
							}
							break;
						}
						else if (pointer2 == 125)
						{
							return FALSE;
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							textcolor(7);
							gotoXY(125, 24);
							cout << "Thoat";
							gotoXY(110, 24);
							cout << "Dang Ki";
							pointer1 = pointer1 - 3;
							ShowCur(1);
							break;
						}
						else if (c == 80)
						{
							textcolor(7);
							gotoXY(125, 24);
							cout << "Thoat";
							gotoXY(110, 24);
							cout << "Dang Ki";
							ShowCur(1);
							pointer1 = 18;
							break;
						}
						else if (c == 75)
						{
							if (pointer2 == 110)
							{
								pointer2 = 125;
							}
							else
								pointer2 = 110;
						}
						else if (c == 77)
						{
							if (pointer2 == 110)
							{
								pointer2 = 125;
							}
							else
								pointer2 = 110;
						}
						gotoXY(pointer2, 24);
					}
				}

				//				SetColor(5);
				textcolor(125);
				gotoXY(pointer2, 24);
				if (pointer2 == 110)
				{
					cout << "Dang Ki";
					textcolor(7);
					gotoXY(125, 24);
					cout << "Thoat";
				}
				else
				{
					cout << "Thoat";
					textcolor(7);
					gotoXY(110, 24);
					cout << "Dang Ki";
				}
			}
		}
	}
}

void XuatMonHoc(DSMH dsmh) {
	for (int i = 0; i < dsmh.n; i++) 
	{
		ShowCur(1);
		gotoXY(91, 15 + i);
		cout << CanDeuChuoi(dsmh.mh[i]->MAMH,10);
		gotoXY(102, 15 + i);
		cout << CanDeuChuoi(dsmh.mh[i]->TENMH, 37);
		gotoXY(140, 15 + i);
		cout << CanDeuChuoi(ChuyenSoSangString1(dsmh.mh[i]->soluongcauhoi), 10);
	}
}

void XoaMonHoc(DSMH& dsmh) {
	GiaoDienChonMocHocCanXoa(90, 12);
	XuatMonHoc(dsmh);
	int index = 0;
	int pointer = 15;
	gotoXY(88, pointer);
	cout << "->";
	ShowCur(0);
	while (true)
	{
		if (kbhit())
		{
			char c = getch();
			if (c == 13)
			{
				for (int j = index; j < dsmh.n - 1; j++) {
					dsmh.mh[j]->MAMH = dsmh.mh[j + 1]->MAMH;
					dsmh.mh[j]->TENMH = dsmh.mh[j + 1]->TENMH;
					dsmh.mh[j]->kiemtraxoa = dsmh.mh[j + 1]->kiemtraxoa;
				}
				XoaManHinhTuyChon(91, 15, 10, dsmh.n);
				XoaManHinhTuyChon(102, 15, 37, dsmh.n);
				dsmh.n--;
				XuatMonHoc(dsmh);
				if (15 + dsmh.n == pointer) {
					XoaManHinhTuyChon(88, pointer, 2, 1);
					pointer--;
					index -= 1;
					gotoXY(88, pointer);
					cout << "->";
				}
				Success("Xoa thanh cong");
				if (dsmh.n == 0) {
					XoaManHinhTuyChon(52, 6, 126, 30);
					Error("Ban da xoa het mon hoc trong danh sach.");
					getch();
					XoaManHinhTuyChon(52, 6, 126, 30);
					break;
				}
			}
			else if (c == 27) {
				XoaManHinhTuyChon(52, 6, 126, 30);
				break;
			}
			else if (c == -32)
			{
				c = getch();
				if (c == 72)
				{
					if (pointer == 15) {
						XoaManHinhTuyChon(88, pointer, 2, 1);
						//						pointer = 27;
						pointer = 15 + dsmh.n - 1;
						gotoXY(88, pointer);
						cout << "->";
						index = dsmh.n - 1;
					}
					else {
						XoaManHinhTuyChon(88, pointer, 2, 1);
						pointer = pointer - 1;
						gotoXY(88, pointer);
						cout << "->";
						index -= 1;
					}
				}
				else if (c == 80)
				{
					if (pointer >= 15 + dsmh.n - 1) {
						XoaManHinhTuyChon(88, pointer, 2, 1);
						pointer = 15;
						gotoXY(88, pointer);
						cout << "->";
						index = 0;
					}
					else {
						XoaManHinhTuyChon(88, pointer, 2, 1);
						pointer = pointer + 1;
						gotoXY(88, pointer);
						cout << "->";
						index += 1;
					}
				}
				else if (c == 75)
				{
					break;
				}
				else if (c == 77)
				{
					break;
				}
				//				gotoXY(88, 27);
			}
		}
	}
	//	string mmh;
	//	cout << "Nhap ma mon hoc: ";
	//	cin.ignore();
	//	getline(cin, mmh);
	//	for(int i=0; i<dsmh.n; i++) {
	//		if(mmh == dsmh.mh[i]->MAMH) {
	//			for(int j=i; j<dsmh.n-1; j++) {
	//				dsmh.mh[j]->MAMH = dsmh.mh[j+1]->MAMH;
	//				dsmh.mh[j]->TENMH = dsmh.mh[j+1]->TENMH;
	//				dsmh.mh[j]->kiemtraxoa = dsmh.mh[j+1]->kiemtraxoa;
	//			}
	//			dsmh.n--;
	//			break;
	//		}
	//	}
}

bool EditMH(MonHoc& mh) {
	int pointer1 = 21;
	int pointer2 = 110;
	string tenmh = mh.TENMH;
	XoaManHinhTuyChon(70, 10, 100, 25);
	GiaoDienSuaMonHoc();
	ShowCur(1);
	gotoXY(96, 18);
	cout << mh.MAMH;
	gotoXY(96, pointer1);
	cout << mh.TENMH;
	while (true)
	{
		if (pointer1 == 21)
		{
			gotoXY(96 + mh.TENMH.length(), pointer1);
			XuLyNhap_Chu(tenmh, 96, pointer1, 30);
			if (pointer1 < 21) {
				pointer1 = 24;
			}
		}
		else if (pointer1 == 24)
		{
			ShowCur(0);
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						if (pointer2 == 110)
						{
							mh.TENMH = tenmh;
							return TRUE;
						}
						else if (pointer2 == 125)
						{
							return FALSE;
						}
						else
						{
							gotoXY(0, 29);
							cout << "                                               ";
							gotoXY(0, 29);
							cout << CanDeuChuoi("Vui Long Nhap Day Du Thong Tin", 176);
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							textcolor(7);
							gotoXY(125, 24);
							cout << "Thoat";
							gotoXY(110, 24);
							cout << "Cap nhat";
							pointer1 = pointer1 - 3;
							ShowCur(1);
							break;
						}
						else if (c == 80)
						{
							textcolor(7);
							gotoXY(125, 24);
							cout << "Thoat";
							gotoXY(110, 24);
							cout << "Cap nhat";
							ShowCur(1);
							pointer1 = 21;
							break;
						}
						else if (c == 75)
						{
							if (pointer2 == 110)
							{
								pointer2 = 125;
							}
							else
								pointer2 = 110;
						}
						else if (c == 77)
						{
							if (pointer2 == 110)
							{
								pointer2 = 125;
							}
							else
								pointer2 = 110;
						}
						gotoXY(pointer2, 24);
					}
				}

				//				SetColor(5);
				textcolor(125);
				gotoXY(pointer2, 24);
				if (pointer2 == 110)
				{
					cout << "Cap nhat";
					textcolor(7);
					gotoXY(125, 24);
					cout << "Thoat";
				}
				else
				{
					cout << "Thoat";
					textcolor(7);
					gotoXY(110, 24);
					cout << "Cap nhat";
				}
			}
		}
	}
}

void SuaMonHoc(DSMH& dsmh) {
	GiaoDienNhapMocHocCanSua(90, 12);
	XuatMonHoc(dsmh);
	int index = 0;
	int pointer = 15;
	gotoXY(88, pointer);
	cout << "->";
	ShowCur(0);
	while (true)
	{
		if (kbhit())
		{
			char c = getch();
			if (c == 13)
			{
				if (EditMH(*dsmh.mh[index])) {
					Success("Sua mon hoc thanh cong.");
					XoaManHinhTuyChon(70, 10, 80, 25);
					GiaoDienNhapMocHocCanSua(90, 12);
					XuatMonHoc(dsmh);
					index = 0;
					pointer = 15;
					gotoXY(88, pointer);
					cout << "->";
					ShowCur(0);
				}
				else {
					XoaManHinhTuyChon(70, 10, 80, 25);
					GiaoDienNhapMocHocCanSua(90, 12);
					XuatMonHoc(dsmh);
					index = 0;
					pointer = 15;
					gotoXY(88, pointer);
					cout << "->";
					ShowCur(0);
				}
			}
			else if (c == 27) {
				XoaManHinhTuyChon(52, 6, 126, 30);
				break;
			}
			else if (c == -32)
			{
				c = getch();
				if (c == 72)
				{
					if (pointer == 15) {
						XoaManHinhTuyChon(88, pointer, 2, 1);
						//						pointer = 27;
						pointer = 15 + dsmh.n - 1;
						gotoXY(88, pointer);
						cout << "->";
						index = dsmh.n - 1;
					}
					else {
						XoaManHinhTuyChon(88, pointer, 2, 1);
						pointer = pointer - 1;
						gotoXY(88, pointer);
						cout << "->";
						index -= 1;
					}
				}
				else if (c == 80)
				{
					if (pointer >= 15 + dsmh.n - 1) {
						XoaManHinhTuyChon(88, pointer, 2, 1);
						pointer = 15;
						gotoXY(88, pointer);
						cout << "->";
						index = 0;
					}
					else {
						XoaManHinhTuyChon(88, pointer, 2, 1);
						pointer = pointer + 1;
						gotoXY(88, pointer);
						cout << "->";
						index += 1;
					}
				}
				else if (c == 75)
				{
					break;
				}
				else if (c == 77)
				{
					break;
				}
			}
		}
	}
}

//======================================== Them cau hoi =======================================
int Max(int a, int b)
{
	return (a > b) ? a : b;
}

int height(nodetree N)
{
	if (N == NULL)
		return 0;
	return N->bf;
}

nodetree newNodeTree(string key, string mamh, string noidung, string a, string b, string c, string d, char dapan)
{
	nodetree node = new nodeTree();
	node->data.ID = key;
	node->data.MAMH = mamh;
	node->data.NOIDUNG = noidung;
	node->data.A = a;
	node->data.B = b;
	node->data.C = c;
	node->data.D = d;
	node->data.DAPAN = dapan;
	node->pleft = NULL;
	node->pright = NULL;
	node->bf = 1; // new node is initially 
					  // added at leaf  
	return node;
}

nodetree rightRotate(nodetree y)
{
	nodetree x = y->pleft;
	nodetree T2 = x->pright;

	// Perform rotation  
	x->pright = y;
	y->pleft = T2;

	// Update heights  
	y->bf = Max(height(y->pleft),
		height(y->pright)) + 1;
	x->bf = Max(height(x->pleft),
		height(x->pright)) + 1;

	// Return new root  
	return x;
}

nodetree leftRotate(nodetree x)
{
	nodetree y = x->pright;
	nodetree T2 = y->pleft;

	// Perform rotation  
	y->pleft = x;
	x->pright = T2;

	// Update heights  
	x->bf = Max(height(x->pleft),
		height(x->pright)) + 1;
	y->bf = Max(height(y->pleft),
		height(y->pright)) + 1;

	// Return new root  
	return y;
}

int getbf(nodetree N)
{
	if (N == NULL)
		return 0;
	return height(N->pleft) - height(N->pright);
}

void ThemSoLuongCH(DSMH& dsmh, string mamh) {
	for (int i = 0; i < dsmh.n; i++) {
		if (dsmh.mh[i]->MAMH == mamh) {
			dsmh.mh[i]->soluongcauhoi++;
		}
	}
}
nodetree insert(nodetree& node, cauhoi ch, DSMH& dsmh)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL) {
		ThemSoLuongCH(dsmh, ch.MAMH);
		return(newNodeTree(ch.ID, ch.MAMH, ch.NOIDUNG, ch.A, ch.B, ch.C, ch.D, ch.DAPAN));
	}

	if (ch.ID < node->data.ID)
		node->pleft = insert(node->pleft, ch, dsmh);
	else if (ch.ID > node->data.ID)
		node->pright = insert(node->pright, ch, dsmh);
	else // Equal keys are not allowed in BST  
		return node;

	/* 2. Update height of this ancestor node */
	node->bf = 1 + Max(height(node->pleft), height(node->pright));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getbf(node);

	// If this node becomes unbalanced, then  
	// there are 4 cases  

	// Left Left Case  
	if (balance > 1 && ch.ID < node->pleft->data.ID)
		return rightRotate(node);

	// Right Right Case  
	if (balance < -1 && ch.ID > node->pright->data.ID)
		return leftRotate(node);

	// Left Right Case  
	if (balance > 1 && ch.ID > node->pleft->data.ID)
	{
		node->pleft = leftRotate(node->pleft);
		return rightRotate(node);
	}

	// Right Left Case  
	if (balance < -1 && ch.ID < node->pright->data.ID)
	{
		node->pright = rightRotate(node->pright);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

void DocFileCH(DSCH& dsch, int arr[], DSMH& dsmh) {
	ifstream FileIn;
	string mamh;
	FileIn.open("data\\cauhoithi.txt", ios::in);
	FileIn >> dsch.n;
	for (int i = 0; i < dsch.n; i++) {
		cauhoi ch;
		FileIn.ignore();
		getline(FileIn, mamh);
		ch.ID = mamh.substr(8, mamh.find(','));
		ch.MAMH = mamh.substr(0, mamh.find(','));
		getline(FileIn, ch.NOIDUNG);
		getline(FileIn, ch.A);
		getline(FileIn, ch.B);
		getline(FileIn, ch.C);
		getline(FileIn, ch.D);
		FileIn >> ch.DAPAN;
		dsch.root = insert(dsch.root, ch, dsmh);
	}
	FileIn.close();
}

void ThemCauHoiThi(nodetree& root, DSMH& dsmh, int arr[]) {
	int pointer1 = 12, pointer2 = 105;
	cauhoi ch;

	GiaoDienNhapCauHoi(75, 8);
	ShowCur(1);
	while (true)
	{
		if (pointer1 == 12)
		{
			gotoXY(101 + ch.MAMH.length(), pointer1);
			XuLyNhapMaMonHoc(ch.MAMH, 101, pointer1);
			if (pointer1 < 12)
			{
				pointer1 = 33;
			}
		}
		else if (pointer1 == 15)
		{
			gotoXY(101 + ch.NOIDUNG.length(), pointer1);
			XuLyNhap_Chu(ch.NOIDUNG, 101, pointer1, 47);
		}
		else if (pointer1 == 18)
		{
			gotoXY(101 + ch.A.length(), pointer1);
			XuLyNhap_Chu(ch.A, 101, pointer1, 47);
		}
		else if (pointer1 == 21)
		{
			gotoXY(101 + ch.B.length(), pointer1);
			XuLyNhap_Chu(ch.B, 101, pointer1, 47);
		}
		else if (pointer1 == 24)
		{
			gotoXY(101 + ch.C.length(), pointer1);
			XuLyNhap_Chu(ch.C, 101, pointer1, 47);
		}
		else if (pointer1 == 27)
		{
			gotoXY(101 + ch.D.length(), pointer1);
			XuLyNhap_Chu(ch.D, 101, pointer1, 47);
		}
		else if (pointer1 == 30)
		{
			ChonDapAn(105, 30, ch.DAPAN, pointer1);
		}
		else if (pointer1 == 33)
		{
			ShowCur(0);
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						if (pointer2 == 105)
						{
							ch.ID = to_string(arr[soluongsongaunhien]);
							soluongsongaunhien--;
							root = insert(root, ch, dsmh);
							XoaManHinhTuyChon(52, 6, 126, 31);
							Success("Them cau hoi thi thanh cong");
							return;
						}
						else if (pointer2 == 135)
						{
							XoaManHinhTuyChon(52, 6, 126, 31);
							return;
						}
						else
						{
							gotoXY(0, 29);
							cout << "                                               ";
							gotoXY(0, 29);
							cout << CanDeuChuoi("Vui Long Nhap Day Du Thong Tin", 176);
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							textcolor(7);
							gotoXY(135, 33);
							cout << "Thoat";
							gotoXY(105, 33);
							cout << "Them";
							pointer1 = pointer1 - 3;
							ShowCur(1);
							break;
						}
						else if (c == 80)
						{
							textcolor(7);
							gotoXY(135, 33);
							cout << "Thoat";
							gotoXY(105, 33);
							cout << "Them";
							ShowCur(1);
							pointer1 = 12;
							break;
						}
						else if (c == 75)
						{
							if (pointer2 == 105)
							{
								pointer2 = 135;
							}
							else
								pointer2 = 105;
						}
						else if (c == 77)
						{
							if (pointer2 == 105)
							{
								pointer2 = 135;
							}
							else
								pointer2 = 105;
						}
						gotoXY(pointer2, 33);
					}
				}
				textcolor(125);
				gotoXY(pointer2, 33);
				if (pointer2 == 105)
				{
					cout << "Them";
					textcolor(7);
					gotoXY(135, 33);
					cout << "Thoat";
				}
				else
				{
					cout << "Thoat";
					textcolor(7);
					gotoXY(105, 33);
					cout << "Them";
				}
			}
		}
	}
}

void DuyetTree(nodetree root, ofstream& FileOut) {
	if (root == NULL) return;

	DuyetTree(root->pleft, FileOut);
	FileOut << root->data.MAMH << ',';
	FileOut << root->data.ID << endl;
	FileOut << root->data.NOIDUNG << endl;
	FileOut << root->data.A << endl;
	FileOut << root->data.B << endl;
	FileOut << root->data.C << endl;
	FileOut << root->data.D << endl;
	FileOut << root->data.DAPAN << endl;
	DuyetTree(root->pright, FileOut);
}

void TestDuyetTree(nodetree root) {
	if (root == NULL) return;

	TestDuyetTree(root->pleft);
	cout << "ID: " << root->data.ID << endl;
	cout << "MAMH: " << root->data.MAMH << endl;
	cout << "NOIDUNG: " << root->data.NOIDUNG << endl;
	cout << "A: " << root->data.A << endl;
	cout << "B: " << root->data.B << endl;
	cout << "C: " << root->data.C << endl;
	cout << "D: " << root->data.D << endl;
	cout << "DAPAN: " << root->data.DAPAN << endl;
	TestDuyetTree(root->pright);
}

bool NopBai()
{
	GiaoDienNopBai();

	char c;
	int pointer1 = 55;
	while (true)
	{
		if (kbhit())
		{
			c = getch();
			if (c == -32)
			{
				c = getch();
				if (c == 75)
				{
					if (pointer1 == 45)
					{
						pointer1 = 55;
					}
					else
						pointer1 = 45;
					GiaoDienNopBai();
				}
				else if (c == 77)
				{
					if (pointer1 == 55)
					{
						pointer1 = 45;
					}
					else
						pointer1 = 55;
					GiaoDienNopBai();
				}
			}
			else if (c == 13)
			{
				textcolor(7);
				if (pointer1 == 45)
				{
					stop = 0;
					return true;
				}
				else if (pointer1 == 55)
				{
					return false;
				}
			}
		}

		textcolor(192);
		gotoXY(toadoXBox + pointer1, toadoYBox + 12);
		if (pointer1 == 45)
		{
			cout << "Yes";
		}
		else
			cout << "No";
		textcolor(240);
	}
}
bool KTSinhVienDaThiChua(DSLOP L, string MaSV, string MaMH)
{
	if (MaSV.empty())
	{
		return false;
	}
	for (int i = 0; i < L.n; i++)
	{
		for (SV* k = L.nodes[i]->ptrDSSV.phead; k != NULL; k = k->pnext)
		{
			if (k->MASV == MaSV)
			{
				for (DT* h = k->ptrDSDT.phead; h != NULL; h = h->pnext)
				{
					if (MaMH == h->MAMH)
					{
						return true;
					}
				}
				return false;
			}
		}
	}
	return false;
}
SV* LayThongTinSinhVien(DSLOP& L, string MaSV)
{
	for (int i = 0; i < L.n; i++)
	{
		for (SV* k = L.nodes[i]->ptrDSSV.phead; k != NULL; k = k->pnext)
		{
			if (k->MASV == MaSV)
			{
				return k;
			}
		}
	}
}
int LaySoCauHoi1Mon(DSMH dsmh, string MaMonHoc)
{
	for (int i = 0; i < dsmh.n; i++) {
		if (dsmh.mh[i]->MAMH == MaMonHoc) {
			return dsmh.mh[i]->soluongcauhoi;
		}
	}
}
void DanhDauDaCoSVThi(DSMH& dsmh, string MaMonHoc)
{
	for (int i = 0; i < dsmh.n; i++) {
		if (dsmh.mh[i]->MAMH == MaMonHoc) {
			dsmh.mh[i]->kiemtraxoa = true;
			return;
		}
	}
}
void DuyetCauHoi(nodetree root, string mamh, cauhoi ch1mon[], int& n) {
	if (root == NULL) return;

	DuyetCauHoi(root->pleft, mamh, ch1mon, n);
	if (mamh == root->data.MAMH) {
		cauhoi ch_temp;
		ch_temp.ID = root->data.ID;
		ch_temp.MAMH = root->data.MAMH;
		ch_temp.NOIDUNG = root->data.NOIDUNG;
		ch_temp.A = root->data.A;
		ch_temp.B = root->data.B;
		ch_temp.C = root->data.C;
		ch_temp.D = root->data.D;
		ch_temp.DAPAN = root->data.DAPAN;
		ch1mon[n++] = ch_temp;
	}
	DuyetCauHoi(root->pright, mamh, ch1mon, n);
}
void RandomCauHoi(DSCH ch, cauhoi CauHoiThi[], int SoCauHoi, string MaMonHoc)
{
	int h = 0;
	cauhoi CH1Mon[2000];
	// Lay Cau Hoi 1 Mon
	DuyetCauHoi(ch.root, MaMonHoc, CH1Mon, h);

	//Random Cau Hoi
	bool* KT = new bool[h] { false };
	int a = 0;
	int j = 0;

	srand(time(NULL));
	while (j < SoCauHoi)
	{
		a = rand() % +h;
		if (!KT[a])
		{
			CauHoiThi[j++] = CH1Mon[a];
			KT[a] = true;
		}
	}
}
void XuatCauHoi(cauhoi CauHoiThi[], char KetQua[], int tam, int tam1, int toadoX, int toadoY)
{
	int j = 0;
	for (int i = tam; i < tam1; i++)
	{
		gotoXY(toadoX - 28, toadoY - 8 + j + 0);
		cout << i + 1 << ".";
		gotoXY(toadoX - 25, toadoY - 8 + j + 0);
		cout << CauHoiThi[i].NOIDUNG;
		gotoXY(toadoX - 10, toadoY - 8 + j + 1);
		cout << CauHoiThi[i].A;
		gotoXY(toadoX - 10, toadoY - 8 + j + 2);
		cout << CauHoiThi[i].B;
		gotoXY(toadoX - 10, toadoY - 8 + j + 3);
		cout << CauHoiThi[i].C;
		gotoXY(toadoX - 10, toadoY - 8 + j + 4);
		cout << CauHoiThi[i].D;

		if (KetQua[i] == '1')
		{
			gotoXY(toadoX - 20, toadoY - 8 + j + 1);
			cout << "X";
		}
		else if (KetQua[i] == '2')
		{
			gotoXY(toadoX - 20, toadoY - 8 + j + 2);
			cout << "X";
		}
		else if (KetQua[i] == '3')
		{
			gotoXY(toadoX - 20, toadoY - 8 + j + 3);
			cout << "X";
		}
		else if (KetQua[i] == '4')
		{
			gotoXY(toadoX - 20, toadoY - 8 + j + 4);
			cout << "X";
		}
		j = j + 6;
	}
}
void XuatCauHoiTheoPage(cauhoi CauHoiThi[], char LuuDapAnChon[], int SoLgCauHoi, int toadoX, int toadoY)
{
	int pos = 0;// vi tri cua cau dang dc tro

	int page = 1;
	int tam = 0;
	int tam1 = 4;
	if (tam1 > SoLgCauHoi)
	{
		tam1 = SoLgCauHoi;
	}
	DeMuc("CAU HOI");
	XuatCauHoi(CauHoiThi, LuuDapAnChon, tam, tam1, toadoX, toadoY);
	XuatPage(page);

	char c;
	int pointer1 = toadoY - 7;
	int tampointer1 = pointer1;

	SetColor(4);
	gotoXY(toadoX - 10, pointer1);
	cout << CauHoiThi[tam].A;
	SetColor(7);

	while (true)
	{
		if (kbhit())
		{
			c = getch();
			if (c == -32)
			{
				c = getch();
				if (c == 75)
				{
					if (tam != 0)
					{
						tam = tam - 4;
						if (tam < 0)
						{
							tam = 0;
						}
						tam1 = tam + 4;
						if (tam1 > SoLgCauHoi)
						{
							tam1 = SoLgCauHoi;
						}
						pos = tam;
						page--;
						XoaManHinhTuyChon(toadoX - 28, toadoY - 8, 101, 25);
						pointer1 = toadoY - 7;
						XuatCauHoi(CauHoiThi, LuuDapAnChon, tam, tam1, toadoX, toadoY);
						XuatPage(page);

						SetColor(4);
						gotoXY(toadoX - 10, pointer1);
						cout << CauHoiThi[tam].A;
						SetColor(7);
					}
				}
				else if (c == 77)
				{
					if (tam1 < SoLgCauHoi)
					{
						tam = tam + 4;
						tam1 = tam1 + 4;
						if (tam1 > SoLgCauHoi)
						{
							tam1 = SoLgCauHoi;
						}
						pos = tam;
						page++;
						XoaManHinhTuyChon(toadoX - 28, toadoY - 8, 101, 25);
						pointer1 = toadoY - 7;
						XuatCauHoi(CauHoiThi, LuuDapAnChon, tam, tam1, toadoX, toadoY);
						XuatPage(page);

						SetColor(4);
						gotoXY(toadoX - 10, pointer1);
						cout << CauHoiThi[tam].A;
						SetColor(7);
					}
				}
				else if (c == 72)
				{
					if (pointer1 == toadoY - 7)
					{
						pos = tam1 - 1;
						pointer1 = toadoY - 8 + (tam1 - tam) * 6 - 2;
					}
					else
					{
						if (pointer1 == toadoY - 1 || pointer1 == toadoY + 5 || pointer1 == toadoY + 11)
						{
							pos = pos - 1;
							pointer1 = pointer1 - 3;
						}
						else
						{
							pointer1 = pointer1 - 1;
						}
					}

					SetColor(4);
					gotoXY(toadoX - 10, pointer1);
					if (pointer1 == toadoY - 7 || pointer1 == toadoY - 1 || pointer1 == toadoY + 5 || pointer1 == toadoY + 11)
					{
						cout << CauHoiThi[pos].A;
						SetColor(7);
						gotoXY(toadoX - 10, tampointer1);
						cout << CauHoiThi[pos].B;
					}
					else if (pointer1 == toadoY - 6 || pointer1 == toadoY || pointer1 == toadoY + 6 || pointer1 == toadoY + 12)
					{
						cout << CauHoiThi[pos].B;
						SetColor(7);
						gotoXY(toadoX - 10, tampointer1);
						cout << CauHoiThi[pos].C;
					}
					else if (pointer1 == toadoY - 5 || pointer1 == toadoY + 1 || pointer1 == toadoY + 7 || pointer1 == toadoY + 13)
					{
						cout << CauHoiThi[pos].C;
						SetColor(7);
						gotoXY(toadoX - 10, tampointer1);
						cout << CauHoiThi[pos].D;
					}
					else if (tampointer1 == toadoY - 7)
					{
						cout << CauHoiThi[tam1 - 1].D;
						SetColor(7);
						gotoXY(toadoX - 10, tampointer1);
						cout << CauHoiThi[tam].A;
					}
					else
					{
						cout << CauHoiThi[pos].D;
						SetColor(7);
						gotoXY(toadoX - 10, tampointer1);
						cout << CauHoiThi[pos + 1].A;
					}

					SetColor(7);
				}
				else if (c == 80)
				{
					if (pointer1 == toadoY - 8 + (tam1 - tam) * 6 - 2)
					{
						pos = tam;
						pointer1 = toadoY - 7;
					}
					else
					{
						if (pointer1 == toadoY - 4 || pointer1 == toadoY + 2 || pointer1 == toadoY + 8)
						{
							pos = pos + 1;
							pointer1 = pointer1 + 3;
						}
						else
						{
							pointer1 = pointer1 + 1;
						}
					}

					SetColor(4);
					gotoXY(toadoX - 10, pointer1);
					if (pointer1 == toadoY - 1 || pointer1 == toadoY + 5 || pointer1 == toadoY + 11)
					{
						cout << CauHoiThi[pos].A;
						SetColor(7);
						gotoXY(toadoX - 10, tampointer1);
						cout << CauHoiThi[pos - 1].D;
					}
					else if (pointer1 == toadoY - 6 || pointer1 == toadoY || pointer1 == toadoY + 6 || pointer1 == toadoY + 12)
					{
						cout << CauHoiThi[pos].B;
						SetColor(7);
						gotoXY(toadoX - 10, tampointer1);
						cout << CauHoiThi[pos].A;
					}
					else if (pointer1 == toadoY - 5 || pointer1 == toadoY + 1 || pointer1 == toadoY + 7 || pointer1 == toadoY + 13)
					{
						cout << CauHoiThi[pos].C;
						SetColor(7);
						gotoXY(toadoX - 10, tampointer1);
						cout << CauHoiThi[pos].B;
					}
					else if (tampointer1 == toadoY - 8 + (tam1 - tam) * 6 - 2)
					{
						cout << CauHoiThi[tam].A;
						SetColor(7);
						gotoXY(toadoX - 10, toadoY - 8 + (tam1 - tam) * 6 - 2);
						cout << CauHoiThi[tam1 - 1].D;
					}
					else
					{
						cout << CauHoiThi[pos].D;
						SetColor(7);
						gotoXY(toadoX - 10, tampointer1);
						cout << CauHoiThi[pos].C;
					}
					SetColor(7);
				}

			}
			else if (c == 27)
			{
				if (NopBai())
				{
					return;
				}

				XoaManHinhTuyChon(toadoX - 28, toadoY - 8, 101, 25);
				XuatCauHoi(CauHoiThi, LuuDapAnChon, tam, tam1, toadoX, toadoY);
				XuatPage(page);
				SetColor(4);
				gotoXY(toadoX - 10, pointer1);
				if (pointer1 == toadoY - 7 || pointer1 == toadoY - 1 || pointer1 == toadoY + 5 || pointer1 == toadoY + 11)
				{
					cout << CauHoiThi[pos].A;
				}
				else if (pointer1 == toadoY - 6 || pointer1 == toadoY || pointer1 == toadoY + 6 || pointer1 == toadoY + 12)
				{
					cout << CauHoiThi[pos].B;
				}
				else if (pointer1 == toadoY - 5 || pointer1 == toadoY + 1 || pointer1 == toadoY + 7 || pointer1 == toadoY + 13)
				{
					cout << CauHoiThi[pos].C;
				}
				else
				{
					cout << CauHoiThi[pos].D;
				}
				SetColor(7);

			}
			else if (c == 13)
			{
				if (LuuDapAnChon[pos] == '0')
				{
					gotoXY(toadoX - 20, pointer1);
					cout << "X";

					if (pointer1 == toadoY - 7 || pointer1 == toadoY - 1 || pointer1 == toadoY + 5 || pointer1 == toadoY + 11)
					{
						LuuDapAnChon[pos] = '1';
					}
					else if (pointer1 == toadoY - 6 || pointer1 == toadoY || pointer1 == toadoY + 6 || pointer1 == toadoY + 12)
					{
						LuuDapAnChon[pos] = '2';
					}
					else if (pointer1 == toadoY - 5 || pointer1 == toadoY + 1 || pointer1 == toadoY + 7 || pointer1 == toadoY + 13)
					{
						LuuDapAnChon[pos] = '3';
					}
					else
					{
						LuuDapAnChon[pos] = '4';
					}

				}
				else
				{
					if (LuuDapAnChon[pos] == '1')
					{
						if (pointer1 == toadoY - 7 || pointer1 == toadoY - 1 || pointer1 == toadoY + 5 || pointer1 == toadoY + 11)
						{
							gotoXY(toadoX - 20, pointer1);
							cout << " ";
							LuuDapAnChon[pos] = '0';
						}
						else
						{
							gotoXY(toadoX - 20, pointer1);
							cout << "X";
							//2
							if (pointer1 == toadoY - 6 || pointer1 == toadoY || pointer1 == toadoY + 6 || pointer1 == toadoY + 12)
							{
								LuuDapAnChon[pos] = '2';

								gotoXY(toadoX - 20, pointer1 - 1);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 + 1);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 + 2);
								cout << " ";
							}
							//3
							else if (pointer1 == toadoY - 5 || pointer1 == toadoY + 1 || pointer1 == toadoY + 7 || pointer1 == toadoY + 13)
							{
								LuuDapAnChon[pos] = '3';

								gotoXY(toadoX - 20, pointer1 - 2);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 - 1);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 + 1);
								cout << " ";
							}
							//4
							else
							{
								LuuDapAnChon[pos] = '4';

								gotoXY(toadoX - 20, pointer1 - 3);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 - 2);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 - 1);
								cout << " ";
							}
						}
					}
					else if (LuuDapAnChon[pos] == '2')
					{
						if (pointer1 == toadoY - 6 || pointer1 == toadoY || pointer1 == toadoY + 6 || pointer1 == toadoY + 12)
						{
							gotoXY(toadoX - 20, pointer1);
							cout << " ";
							LuuDapAnChon[pos] = '0';
						}
						else
						{
							gotoXY(toadoX - 20, pointer1);
							cout << "X";

							if (pointer1 == toadoY - 7 || pointer1 == toadoY - 1 || pointer1 == toadoY + 5 || pointer1 == toadoY + 11)
							{
								LuuDapAnChon[pos] = '1';

								gotoXY(toadoX - 20, pointer1 + 1);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 + 2);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 + 3);
								cout << " ";
							}
							else if (pointer1 == toadoY - 5 || pointer1 == toadoY + 1 || pointer1 == toadoY + 7 || pointer1 == toadoY + 13)
							{
								LuuDapAnChon[pos] = '3';

								gotoXY(toadoX - 20, pointer1 - 2);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 - 1);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 + 1);
								cout << " ";
							}
							else
							{
								LuuDapAnChon[pos] = '4';

								gotoXY(toadoX - 20, pointer1 - 3);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 - 2);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 - 1);
								cout << " ";
							}
						}
					}
					else if (LuuDapAnChon[pos] == '3')
					{
						if (pointer1 == toadoY - 5 || pointer1 == toadoY + 1 || pointer1 == toadoY + 7 || pointer1 == toadoY + 13)
						{
							gotoXY(toadoX - 20, pointer1);
							cout << " ";
							LuuDapAnChon[pos] = '0';
						}
						else
						{
							gotoXY(toadoX - 20, pointer1);
							cout << "X";

							//1
							if (pointer1 == toadoY - 7 || pointer1 == toadoY - 1 || pointer1 == toadoY + 5 || pointer1 == toadoY + 11)
							{
								LuuDapAnChon[pos] = '1';

								gotoXY(toadoX - 20, pointer1 + 1);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 + 2);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 + 3);
								cout << " ";
							}
							//2
							else if (pointer1 == toadoY - 6 || pointer1 == toadoY || pointer1 == toadoY + 6 || pointer1 == toadoY + 12)
							{
								LuuDapAnChon[pos] = '2';

								gotoXY(toadoX - 20, pointer1 - 1);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 + 1);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 + 2);
								cout << " ";
							}
							//4
							else
							{
								LuuDapAnChon[pos] = '4';

								gotoXY(toadoX - 20, pointer1 - 3);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 - 2);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 - 1);
								cout << " ";
							}
						}
					}
					else
					{
						if (pointer1 == toadoY - 4 || pointer1 == toadoY + 2 || pointer1 == toadoY + 8 || pointer1 == toadoY + 14)
						{
							gotoXY(toadoX - 20, pointer1);
							cout << " ";

							LuuDapAnChon[pos] = '0';
						}
						else
						{
							gotoXY(toadoX - 20, pointer1);
							cout << "X";

							//1
							if (pointer1 == toadoY - 7 || pointer1 == toadoY - 1 || pointer1 == toadoY + 5 || pointer1 == toadoY + 11)
							{
								LuuDapAnChon[pos] = '1';

								gotoXY(toadoX - 20, pointer1 + 1);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 + 2);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 + 3);
								cout << " ";
							}
							//2
							else if (pointer1 == toadoY - 6 || pointer1 == toadoY || pointer1 == toadoY + 6 || pointer1 == toadoY + 12)
							{
								LuuDapAnChon[pos] = '2';

								gotoXY(toadoX - 20, pointer1 - 1);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 + 1);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 + 2);
								cout << " ";
							}
							//3
							else
							{
								LuuDapAnChon[pos] = '3';

								gotoXY(toadoX - 20, pointer1 - 2);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 - 1);
								cout << " ";
								gotoXY(toadoX - 20, pointer1 + 1);
								cout << " ";
							}
						}
					}
				}
			}
		}

		if (stop == 0)
		{
			return;
		}

		tampointer1 = pointer1;
	}
}
void XemCauHoiDaThi(cauhoi CauHoiThi[], char LuuDapAnChon[], int SoLgCauHoi, int toadoX, int toadoY)
{
	int pos = 0;// vi tri cua cau dang dc tro

	int page = 1;
	int tam = 0;
	int tam1 = 4;
	if (tam1 > SoLgCauHoi)
	{
		tam1 = SoLgCauHoi;
	}
	DeMuc("CAU HOI");
	XuatCauHoi(CauHoiThi, LuuDapAnChon, tam, tam1, toadoX, toadoY);
	XuatPage(page);

	char c;
	int pointer1 = toadoY - 7;
	int tampointer1 = pointer1;

	while (true)
	{
		if (kbhit())
		{
			c = getch();
			if (c == -32)
			{
				c = getch();
				if (c == 75)
				{
					if (tam != 0)
					{
						tam = tam - 4;
						if (tam < 0)
						{
							tam = 0;
						}
						tam1 = tam + 4;
						if (tam1 > SoLgCauHoi)
						{
							tam1 = SoLgCauHoi;
						}
						pos = tam;
						page--;
						XoaManHinhTuyChon(toadoX - 28, toadoY - 8, 101, 25);
						pointer1 = toadoY - 7;
						XuatCauHoi(CauHoiThi, LuuDapAnChon, tam, tam1, toadoX, toadoY);
						XuatPage(page);
					}
				}
				else if (c == 77)
				{
					if (tam1 < SoLgCauHoi)
					{
						tam = tam + 4;
						tam1 = tam1 + 4;
						if (tam1 > SoLgCauHoi)
						{
							tam1 = SoLgCauHoi;
						}
						pos = tam;
						page++;
						XoaManHinhTuyChon(toadoX - 28, toadoY - 8, 101, 25);
						pointer1 = toadoY - 7;
						XuatCauHoi(CauHoiThi, LuuDapAnChon, tam, tam1, toadoX, toadoY);
						XuatPage(page);

					}
				}
			}
			else if (c == 27)
			{
				return;
			}
		}
		tampointer1 = pointer1;
	}
}
bool KTMonHoc(DSMH dsmh, string mamh, string& tenmh) {
	for (int i = 0; i < dsmh.n; i++) {
		if (dsmh.mh[i]->MAMH == mamh) {
			tenmh = dsmh.mh[i]->TENMH;
			return true;
		}

	}
	return false;
}
bool NhapThongTin(DSLOP L, DSMH t, int toadoX, int toadoY, int& SoCauHoi, int& SoPhut, string& MaMonHoc, string& TenMonHoc, string MaSV)
{
	GiaoDienNhapThiTracNghiem(toadoX, toadoY);
	int pointer1 = toadoY;

	while (true)
	{
		if (pointer1 == toadoY)
		{
			ShowCur(1);
			gotoXY(toadoX + 7 + MaMonHoc.length(), pointer1 + 1);
			XuLyNhapMaMonHoc(MaMonHoc, toadoX + 7, pointer1);
			if (pointer1 < toadoY)
			{
				pointer1 = toadoY + 9;
			}
		}
		else if (pointer1 == toadoY + 3)
		{
			ShowCur(1);
			gotoXY(toadoX + 7 + DemChuSo(SoCauHoi), pointer1 + 1);
			XuLyNhap_So(SoCauHoi, toadoX + 7, pointer1);
		}
		else if (pointer1 == toadoY + 6)
		{
			ShowCur(1);
			gotoXY(toadoX + 7 + DemChuSo(SoPhut), pointer1 + 1);
			XuLyNhap_So(SoPhut, toadoX + 7, pointer1);
		}
		else if (pointer1 == toadoY + 9) // save hoac huy
		{
			ShowCur(0);
			int pointer2 = toadoX + 15;
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						if (pointer2 == toadoX + 15
							&& SoPhut > 0
							&& SoCauHoi > 0
							&& !MaMonHoc.empty() && KTMonHoc(t, MaMonHoc, TenMonHoc)
							&& !KTSinhVienDaThiChua(L, MaSV, MaMonHoc)
							&& SoCauHoi <= LaySoCauHoi1Mon(t, MaMonHoc))
						{
							DanhDauDaCoSVThi(t, MaMonHoc);
							stop = 1;
							return true;
						}
						else if (pointer2 == toadoX + 30)
						{
							XoaManHinhTuyChon(52, 6, 126, 30);
							return false;
						}
						else if (!KTMonHoc(t, MaMonHoc, TenMonHoc))
						{
							textcolor(7);
							gotoXY(107, 30);
							cout << "Ma Mon Hoc Khong Ton Tai";
						}
						else if (SoCauHoi > LaySoCauHoi1Mon(t, MaMonHoc))
						{
							textcolor(7);
							gotoXY(107, 30);
							cout << "So Cau Hoi Trong Ngan Hang Khong Du";
						}
						else if (KTSinhVienDaThiChua(L, MaSV, MaMonHoc))
						{
							textcolor(7);
							gotoXY(107, 30);
							cout << "Sinh Vien Da Thi Mon Nay Roi";
						}
						else
						{
							textcolor(7);
							gotoXY(107, 30);
							cout << "Vui Long Dien Day Du Thong Tin";
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							textcolor(7);
							gotoXY(toadoX + 30, toadoY + 10);
							cout << "Cancel";
							gotoXY(toadoX + 15, toadoY + 10);
							cout << "Xac Nhan";
							pointer1 = pointer1 - 3;
							break;
						}
						else if (c == 80)
						{
							textcolor(7);
							gotoXY(toadoX + 30, toadoY + 10);
							cout << "Cancel";
							gotoXY(toadoX + 15, toadoY + 10);
							cout << "Xac Nhan";
							ShowCur(1);
							pointer1 = toadoY;
							break;
						}
						else if (c == 75)
						{
							if (pointer2 == toadoX + 30)
							{
								pointer2 = toadoX + 15;
							}
							else
								pointer2 = toadoX + 30;
						}
						else if (c == 77)
						{
							if (pointer2 == toadoX + 15)
							{
								pointer2 = toadoX + 30;
							}
							else
								pointer2 = toadoX + 15;
						}
						gotoXY(pointer2, toadoY + 10);
					}
				}

				SetColor(5);
				gotoXY(pointer2, toadoY + 10);
				if (pointer2 == toadoX + 15)
				{
					cout << "Xac Nhan";
					textcolor(7);
					gotoXY(toadoX + 30, toadoY + 10);
					cout << "Cancel";
				}
				else if (pointer2 == toadoX + 30)
				{
					cout << "Cancel";
					textcolor(7);
					gotoXY(toadoX + 15, toadoY + 10);
					cout << "Xac Nhan";
				}

				Sleep(100);
			}
		}
	}
}
void ThiTracNghiem(DSLOP& L, DSCH ch, DSMH t, string MaSV, int toadoX, int toadoY)
{
	string MaMonHoc;
	string TenMonHoc;
	int SoCauHoi = 0;
	int SoPhut = 0;
	if (!NhapThongTin(L, t, toadoX, toadoY, SoCauHoi, SoPhut, MaMonHoc, TenMonHoc, MaSV))
	{
		return;
	}

	cauhoi* CauHoiThi = new cauhoi[SoCauHoi];
	char* LuuDapAnChon = new char[SoCauHoi] {0};
	RandomCauHoi(ch, CauHoiThi, SoCauHoi, MaMonHoc);

	GiaoDienThiTracNghiem();
	if (SoCauHoi % 4 == 0)
	{
		gotoXY(19, 33);
		cout << SoCauHoi / 4 << " trang";
	}
	else
	{
		gotoXY(19, 33);
		cout << (SoCauHoi / 4) + 1 << " trang";
	}

	if (SoPhut > 60)
	{
		ThoiGian.hour = SoPhut / 60;
		ThoiGian.minute = SoPhut % 60;
	}
	else
	{
		ThoiGian.minute = SoPhut;
	}
	gotoXY(16, 30);
	cout << SoPhut << " Phut";
	gotoXY(16, 31);
	cout << SoCauHoi;
	gotoXY(16, 28);
	cout << TenMonHoc;
	gotoXY(16, 29);
	cout << MaMonHoc;

	SV* SV = NULL;
	if (!MaSV.empty())
	{
		SV = LayThongTinSinhVien(L, MaSV);
		gotoXY(16, 26);
		cout << SV->HO + " " + SV->TEN;
		gotoXY(16, 27);
		cout << MaSV;
	}

	//CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&ThreadProc, NULL, 0, NULL);
	XuatCauHoiTheoPage(CauHoiThi, LuuDapAnChon, SoCauHoi, toadoX, toadoY);

	//Cham Diem
	int SoCauDung = 0;
	for (int i = 0;i < SoCauHoi;i++)
	{
		if (LuuDapAnChon[i] == CauHoiThi[i].DAPAN)
		{
			SoCauDung++;
		}
	}
	float Diem = 0;
	Diem = (float)((10 / SoCauHoi) * SoCauDung);
	GiaoDienDiem(SoCauDung, SoCauHoi, toadoX, toadoY - 5);

	if (!MaSV.empty())
	{
		SV->slmondathi++;

		DT* p = new DT;
		p->DIEM = Diem;
		p->MAMH = MaMonHoc;

		p->cauhoidathi.slcauhoi = SoCauHoi;
		p->cauhoidathi.data = new cauhoi[SoCauHoi];
		p->cauhoidathi.DapAnDaChon = new char[SoCauHoi];

		for (int i = 0; i < SoCauHoi; i++)
		{
			p->cauhoidathi.data[i] = CauHoiThi[i];
			p->cauhoidathi.DapAnDaChon[i] = LuuDapAnChon[i];
		}
		p->pnext = NULL;

		if (SV->ptrDSDT.phead == NULL)
		{
			SV->ptrDSDT.phead = p;
			SV->ptrDSDT.phead->pnext = NULL;
		}
		else
		{
			DT* temp = SV->ptrDSDT.phead;
			while (true)
			{
				if (temp->pnext == NULL) {
					temp->pnext = p;
					break;
				}
				temp = temp->pnext;
			}
		}
	}
	delete[]LuuDapAnChon;
	delete[]CauHoiThi;
}
void DSCauHoiThi1MonCua1SinhVien(DSMH t, DSLOP L, int toadoX, int toadoY)
{
	string MaSinhVien;
	string MaMonHoc;
	string TenMonHoc;
	int pointer1 = toadoY;
	GiaoDienCauHoiDaThi(toadoX, toadoY);
	while (true)
	{
		if (pointer1 == toadoY)
		{
			ShowCur(1);
			gotoXY(toadoX + 2 + MaSinhVien.length(), pointer1 + 1);
			XuLyNhapTK(MaSinhVien, toadoX + 2, pointer1);
			if (pointer1 < toadoY)
			{
				pointer1 = toadoY + 6;
			}
		}
		else if (pointer1 == toadoY + 3)
		{
			ShowCur(1);
			gotoXY(toadoX + 2 + MaMonHoc.length(), pointer1 + 1);
			XuLyNhapMaMonHoc(MaMonHoc, toadoX + 2, pointer1);
		}
		else if (pointer1 == toadoY + 6) // save hoac huy
		{
			ShowCur(0);
			int pointer2 = toadoX + 15;
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						if (!MaSinhVien.empty() && !MaMonHoc.empty() && KTMonHoc(t, MaMonHoc, TenMonHoc)
							&& pointer2 == toadoX + 15)
						{
							SV* sv = LayThongTinSinhVien(L, MaSinhVien);
							for (DT* h = sv->ptrDSDT.phead; h != NULL; h = h->pnext)
							{
								if (h->MAMH == MaMonHoc)
								{
									XoaManHinhChinh();
									DeMuc("Cau Hoi Da Thi Cua Sinh Vien " + sv->MASV + " Mon " + h->MAMH);
									XemCauHoiDaThi(h->cauhoidathi.data, h->cauhoidathi.DapAnDaChon, h->cauhoidathi.slcauhoi, toadoX, toadoY);
									break;
								}
							}
							return;
						}
						else if (pointer2 == toadoX + 30)
						{
							return;
						}
						/*else if (!KTMaSinhVien(L, MaSinhVien))
						{
							textcolor(7);
							gotoXY(107, 30);
							cout << "Ma Sinh Vien Khong Ton Tai";
						}*/
						else if (!KTMonHoc(t, MaMonHoc, TenMonHoc))
						{
							textcolor(7);
							gotoXY(107, 30);
							cout << "Ma Mon Hoc Khong Ton Tai";
						}
						else
						{
							textcolor(7);
							gotoXY(107, 30);
							cout << "Vui Long Dien Day Du Thong Tin";
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							textcolor(7);
							gotoXY(toadoX + 30, toadoY + 10);
							cout << "Cancel";
							gotoXY(toadoX + 15, toadoY + 10);
							cout << "Xac Nhan";
							pointer1 = pointer1 - 3;
							break;
						}
						else if (c == 80)
						{
							textcolor(7);
							gotoXY(toadoX + 30, toadoY + 10);
							cout << "Cancel";
							gotoXY(toadoX + 15, toadoY + 10);
							cout << "Xac Nhan";
							ShowCur(1);
							pointer1 = toadoY;
							break;
						}
						else if (c == 75)
						{
							if (pointer2 == toadoX + 30)
							{
								pointer2 = toadoX + 15;
							}
							else
								pointer2 = toadoX + 30;
						}
						else if (c == 77)
						{
							if (pointer2 == toadoX + 15)
							{
								pointer2 = toadoX + 30;
							}
							else
								pointer2 = toadoX + 15;
						}
						gotoXY(pointer2, toadoY + 10);
					}
				}

				SetColor(5);
				gotoXY(pointer2, toadoY + 10);
				if (pointer2 == toadoX + 15)
				{
					cout << "Xac Nhan";
					textcolor(7);
					gotoXY(toadoX + 30, toadoY + 10);
					cout << "Cancel";
				}
				else if (pointer2 == toadoX + 30)
				{
					cout << "Cancel";
					textcolor(7);
					gotoXY(toadoX + 15, toadoY + 10);
					cout << "Xac Nhan";
				}
				Sleep(100);
			}
		}
	}
}
bool CheckXemCauHoiThi1SV(DSLOP dslop, DSMH dsmh) {
	int pointer1 = 18;
	int pointer2 = 105;
	string masv;
	string mamh;
	int solanthi{};

	GiaoDienNhapMMHandMSV();
	ShowCur(1);
	while (true)
	{
		if (pointer1 == 18)
		{
			gotoXY(101 + masv.length(), pointer1);
			XuLyNhapMaMonHoc(masv, 101, pointer1);
			if (pointer1 < 18)
			{
				pointer1 = 27;
			}
		}
		else if (pointer1 == 21)
		{
			gotoXY(101 + mamh.length(), pointer1);
			XuLyNhapMaMonHoc(mamh, 101, pointer1);
		}
		else if (pointer1 == 24)
		{
			gotoXY(101 + DemChuSo(solanthi), pointer1);
			XuLyNhap_So(solanthi, 101, pointer1);
		}
		else if (pointer1 == 27)
		{
			ShowCur(0);
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						if (pointer2 == 105)
						{
							bool ktsv = false, ktmh = false;
							for (int i = 0; i < dslop.n; i++) {
								for (SV* check = dslop.nodes[i]->ptrDSSV.phead; check != NULL; check = check->pnext) {
									if (masv == check->MASV) {
										ktsv = true;
										break;
									}
								}
							}
							for (int i = 0; i < dsmh.n; i++) {
								if (mamh == dsmh.mh[i]->MAMH) {
									ktmh = true;
									break;
								}
							}
							if (ktsv && ktmh) {
								return TRUE;
							}
							else if (!ktsv && ktmh) {
								gotoXY(101, 32);
								cout << CanDeuChuoi("Ma sinh vien khong ton tai !!!", 50);
								pointer1 = 18;
								textcolor(7);
								gotoXY(pointer2, 27);
								cout << "Xac Nhan";
								ShowCur(1);
								break;
							}
							else if (ktsv && !ktmh) {
								gotoXY(101, 32);
								cout << CanDeuChuoi("Ma mon hoc khong ton tai !!!", 50);
								pointer1 = 18;
								textcolor(7);
								gotoXY(pointer2, 27);
								cout << "Xac Nhan";
								ShowCur(1);
								break;
							}
							else if (!ktsv && !ktmh) {
								gotoXY(101, 32);
								cout << CanDeuChuoi("Ma mon hoc va ma sinh vien khong ton tai !!!", 50);
								pointer1 = 18;
								textcolor(7);
								gotoXY(pointer2, 27);
								cout << "Xac Nhan";
								ShowCur(1);
								break;
							}

						}
						else if (pointer2 == 120)
						{
							return FALSE;
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							textcolor(7);
							gotoXY(120, 27);
							cout << "Thoat";
							gotoXY(105, 27);
							cout << "Xac Nhan";
							pointer1 = pointer1 - 3;
							ShowCur(1);
							break;
						}
						else if (c == 80)
						{
							textcolor(7);
							gotoXY(120, 27);
							cout << "Thoat";
							gotoXY(105, 27);
							cout << "Xac Nhan";
							ShowCur(1);
							pointer1 = 18;
							break;
						}
						else if (c == 75)
						{
							if (pointer2 == 105)
							{
								pointer2 = 120;
							}
							else
								pointer2 = 105;
						}
						else if (c == 77)
						{
							if (pointer2 == 105)
							{
								pointer2 = 120;
							}
							else
								pointer2 = 105;
						}
						gotoXY(pointer2, 27);
					}
				}
				textcolor(125);
				gotoXY(pointer2, 27);
				if (pointer2 == 105)
				{
					cout << "Xac Nhan";
					textcolor(7);
					gotoXY(120, 27);
					cout << "Thoat";
				}
				else
				{
					cout << "Thoat";
					textcolor(7);
					gotoXY(105, 27);
					cout << "Xac Nhan";
				}
			}
		}
	}
}
bool CheckXemBangDiem1Lop(DSLOP dslop, DSMH dsmh, string &malop, string &mamh) {
	int pointer1 = 18;
	int pointer2 = 105;

	GiaoDienNhapMLandMMH();
	ShowCur(1);
	while (true)
	{
		if (pointer1 == 18)
		{
			gotoXY(101 + malop.length(), pointer1);
			XuLyNhapMaMonHoc(malop, 101, pointer1);
			if (pointer1 < 18)
			{
				pointer1 = 24;
			}
		}
		else if (pointer1 == 21)
		{
			gotoXY(101 + mamh.length(), pointer1);
			XuLyNhapMaMonHoc(mamh, 101, pointer1);
		}
		else if (pointer1 == 24)
		{
			ShowCur(0);
			while (true)
			{
				if (kbhit())
				{
					char c = getch();
					if (c == 13)
					{
						if (pointer2 == 105)
						{
							bool ktlop = false, ktmh = false;
							for (int i = 0; i < dslop.n; i++) {
								if (malop == dslop.nodes[i]->MALOP) {
									ktlop = true;
									break;
								}
							}
							for (int i = 0; i < dsmh.n; i++) {
								if (mamh == dsmh.mh[i]->MAMH) {
									ktmh = true;
									break;
								}
							}
							if (ktlop && ktmh) {
								return TRUE;
							}
							else if (!ktlop && ktmh) {
								gotoXY(101, 32);
								cout << CanDeuChuoi("Ma lop khong ton tai !!!", 50);
								pointer1 = 18;
								textcolor(7);
								gotoXY(pointer2, 27);
								cout << "Xac Nhan";
								ShowCur(1);
								break;
							}
							else if (ktlop && !ktmh) {
								gotoXY(101, 32);
								cout << CanDeuChuoi("Ma mon hoc khong ton tai !!!", 50);
								pointer1 = 18;
								textcolor(7);
								gotoXY(pointer2, 27);
								cout << "Xac Nhan";
								ShowCur(1);
								break;
							}
							else if (!ktlop && !ktmh) {
								gotoXY(101, 32);
								cout << CanDeuChuoi("Ma mon hoc va ma sinh vien khong ton tai !!!", 50);
								pointer1 = 18;
								textcolor(7);
								gotoXY(pointer2, 27);
								cout << "Xac Nhan";
								ShowCur(1);
								break;
							}

						}
						else if (pointer2 == 120)
						{
							return FALSE;
						}
					}
					else if (c == -32)
					{
						c = getch();
						if (c == 72)
						{
							textcolor(7);
							gotoXY(120, 27);
							cout << "Thoat";
							gotoXY(105, 27);
							cout << "Xac Nhan";
							pointer1 = pointer1 - 3;
							ShowCur(1);
							break;
						}
						else if (c == 80)
						{
							textcolor(7);
							gotoXY(120, 27);
							cout << "Thoat";
							gotoXY(105, 27);
							cout << "Xac Nhan";
							ShowCur(1);
							pointer1 = 18;
							break;
						}
						else if (c == 75)
						{
							if (pointer2 == 105)
							{
								pointer2 = 120;
							}
							else
								pointer2 = 105;
						}
						else if (c == 77)
						{
							if (pointer2 == 105)
							{
								pointer2 = 120;
							}
							else
								pointer2 = 105;
						}
						gotoXY(pointer2, 27);
					}
				}
				textcolor(125);
				gotoXY(pointer2, 27);
				if (pointer2 == 105)
				{
					cout << "Xac Nhan";
					textcolor(7);
					gotoXY(120, 27);
					cout << "Thoat";
				}
				else
				{
					cout << "Thoat";
					textcolor(7);
					gotoXY(105, 27);
					cout << "Xac Nhan";
				}
			}
		}
	}
}
void XuatBangDiem(DSLOP dslop, DSMH dsmh, string malop, string mamh) {
	for (int i = 0; i < dslop.n; i++) {
		if (malop == dslop.nodes[i]->MALOP) {
			int j = 0;
			for (SV* checksv = dslop.nodes[i]->ptrDSSV.phead; checksv != NULL; checksv = checksv->pnext) {
				bool ktdiem = true;
				for (DT* checkdiem = checksv->ptrDSDT.phead; checkdiem != NULL; checkdiem = checkdiem->pnext) {
					if (mamh == checkdiem->MAMH) {
						ktdiem = false;
						gotoXY(66, 10 + j);
						cout << CanDeuChuoi(checksv->MASV, 29);
						gotoXY(96, 10 + j);
						cout << CanDeuChuoi(checksv->HO + " " + checksv->TEN, 49);
						gotoXY(146, 10 + j);
						cout << CanDeuChuoi(to_string(checkdiem->DIEM), 19);
						j += 2;
					}
				}
				if (ktdiem) {
					gotoXY(66, 10 + j);
					cout << CanDeuChuoi(checksv->MASV, 29);
					gotoXY(96, 10 + j);
					cout << CanDeuChuoi(checksv->HO + " " + checksv->TEN, 49);
					gotoXY(146, 10 + j);
					cout << CanDeuChuoi("Chua Thi", 19);
					j += 2;
				}
			}
		}
	}
}

void XoaDauListSV(DSSV& l)
{
	if (l.phead == NULL)
	{
		return;
	}
	SV* t = l.phead;
	l.phead = l.phead->pnext;
	delete t;
}
void XoaDauListDiem(DSDT& l)
{
	if (l.phead == NULL)
	{
		return;
	}
	DT* t = l.phead;
	l.phead = l.phead->pnext;
	delete t;
}

void DeleteLop(DSLOP& L)
{
	for (int i = 0; i < L.n; i++)
	{
		while (L.nodes[i]->ptrDSSV.phead != NULL)
		{
			while (L.nodes[i]->ptrDSSV.phead->ptrDSDT.phead != NULL)
			{
				delete[] L.nodes[i]->ptrDSSV.phead->ptrDSDT.phead->cauhoidathi.data;
				delete[] L.nodes[i]->ptrDSSV.phead->ptrDSDT.phead->cauhoidathi.DapAnDaChon;
				XoaDauListDiem(L.nodes[i]->ptrDSSV.phead->ptrDSDT);
			}
			XoaDauListSV(L.nodes[i]->ptrDSSV);
		}
		delete L.nodes[i];
	}
}
void DeleteCauHoi(nodetree& ch)
{
	if (ch == NULL) return;

	DeleteCauHoi(ch->pleft);
	DeleteCauHoi(ch->pright);
	delete ch;
}
void DeleteMonHoc(DSMH& mh)
{
	for (int i = 0; i < mh.n; i++)
	{
		delete mh.mh[i];
	}
}
void DeleteMemory(DSMH& t, DSLOP& L, nodetree& CH)
{
	DeleteLop(L);
	DeleteCauHoi(CH);
	DeleteMonHoc(t);
}

void Save(DSLOP &dslop, DSCH &dsch) {
	ofstream FileOut;
	ofstream FileOut_CHDT;

	FileOut.open("data\\dslop.txt", ios::out);
	FileOut_CHDT.open("data\\cauhoidathi.txt", ios::out);
	FileOut << dslop.n << endl;
	for (int i = 0; i < dslop.n; i++) {
		FileOut << dslop.nodes[i]->MALOP << ",";
		FileOut << dslop.nodes[i]->TENLOP << endl;

		ofstream FileOut_SV;

		FileOut_SV.open("data\\" + dslop.nodes[i]->MALOP + ".txt", ios::out);
		FileOut_SV << dslop.nodes[i]->ptrDSSV.n << endl;
		for (SV* sv = dslop.nodes[i]->ptrDSSV.phead; sv != NULL; sv = sv->pnext) {
			FileOut_SV << sv->MASV << ",";
			FileOut_SV << sv->HO << ",";
			FileOut_SV << sv->TEN << ",";
			FileOut_SV << sv->PHAI << ",";
			FileOut_SV << MaHoaMK(sv->PASSWORD) << ",";
			FileOut_SV << sv->slmondathi << endl;

			for (DT* dt = sv->ptrDSDT.phead;dt != NULL;dt=dt->pnext) {
				FileOut_SV << dt->MAMH << ',';
				FileOut_SV << dt->DIEM << ',';
				FileOut_SV << dt->cauhoidathi.slcauhoi << endl;

				//cout << dt->cauhoidathi.slcauhoi << endl;
				for (int i = 0; i < dt->cauhoidathi.slcauhoi; i++) {

					FileOut_CHDT << dt->cauhoidathi.data[i].ID << endl;
					FileOut_CHDT << dt->cauhoidathi.data[i].NOIDUNG << endl;
					FileOut_CHDT << dt->cauhoidathi.data[i].A << endl;
					FileOut_CHDT << dt->cauhoidathi.data[i].B << endl;
					FileOut_CHDT << dt->cauhoidathi.data[i].C << endl;
					FileOut_CHDT << dt->cauhoidathi.data[i].D << endl;
					FileOut_CHDT << dt->cauhoidathi.data[i].DAPAN << endl;
					
					FileOut_CHDT << dt->cauhoidathi.DapAnDaChon[i] << endl;

					/*cout << dt->cauhoidathi.data[i].ID << endl;
					cout << dt->cauhoidathi.data[i].NOIDUNG << endl;
					cout << dt->cauhoidathi.data[i].A << endl;
					cout << dt->cauhoidathi.data[i].B << endl;
					cout << dt->cauhoidathi.data[i].C << endl;
					cout << dt->cauhoidathi.data[i].D << endl;
					cout << dt->cauhoidathi.data[i].DAPAN << endl;
					cout << dt->cauhoidathi.DapAnDaChon[i] << endl;*/

				}
			}
		}
		FileOut_SV.close();
	}
	FileOut.close();
	FileOut_CHDT.close();
}