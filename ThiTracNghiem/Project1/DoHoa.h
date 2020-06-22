//Ham Do Hoa

void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
//Ve HCN
void HCNTextDong(int toadoX, int toadoY, int chieudai, int chieucao)
{
	for (int i = toadoX; i < toadoX + chieudai; i++)
	{
		gotoXY(i, toadoY);
		textcolor(1926);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
	for (int i = toadoY; i < toadoY + chieucao; i++)
	{
		gotoXY(toadoX + chieudai - 1, i);
		textcolor(1926);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
	for (int i = toadoX + chieudai - 1; i >= toadoX; i--)
	{
		gotoXY(i, toadoY + chieucao - 1);
		textcolor(1926);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
	for (int i = toadoY + chieucao - 1; i >= toadoY; i--)
	{
		gotoXY(toadoX, i);
		textcolor(1926);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
}
void HCNText(int toadoX, int toadoY, int chieudai, int chieucao)
{
	for (int i = toadoX; i < toadoX + chieudai; i++)
	{
		gotoXY(i, toadoY);
		textcolor(1926);
		cout << " ";
		textcolor(7);
	}
	for (int i = toadoY; i < toadoY + chieucao; i++)
	{
		gotoXY(toadoX + chieudai - 1, i);
		textcolor(1926);
		cout << " ";
		textcolor(7);
	}
	for (int i = toadoX + chieudai - 1; i >= toadoX; i--)
	{
		gotoXY(i, toadoY + chieucao - 1);
		textcolor(1926);
		cout << " ";
		textcolor(7);
	}
	for (int i = toadoY + chieucao - 1; i >= toadoY; i--)
	{
		gotoXY(toadoX, i);
		textcolor(1926);
		cout << " ";
		textcolor(7);
	}
}
void VeHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mauSet)
{
	SetColor(mauSet);
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}
	SetColor(7);
}
void ToMauHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mauText)
{
	textcolor(mauText);
	for (int i = toadoY + 1; i < toadoY + chieucao; i++)
	{
		for (int j = toadoX + 1; j < chieudai + toadoX; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
	textcolor(7);
}
void XoaHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mau)
{
	textcolor(mau);
	for (int j = toadoY + 1; j < toadoY + chieucao; j++)
	{
		for (int i = toadoX + 1; i < toadoX + chieudai; i++)
		{
			gotoXY(i, j);
			cout << " ";
		}
	}
}
//Logo
void Logo1(int toadoX, int toadoY)
{
	string str;
	ifstream FileIn;
	FileIn.open("text_login.txt", ios::in);
	int h = toadoY;
	int mamau;
	while (true)
	{
		getline(FileIn, str);
		mamau = 10 + rand() % 6;
		SetColor(mamau);
		gotoXY(toadoX, h++);
		cout << str << endl;
		if (FileIn.eof())
		{
			break;
		}
	}
	textcolor(7);
	FileIn.close();
}

//Huong Dan
int MauNenHuongDan = 7;
void XoaHuongDan()
{
	textcolor(MauNenHuongDan);
	for (int i = 4; i < 11; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
	textcolor(7);
}
void HuongDanMenuMain()
{
	textcolor(MauNenHuongDan);
	cout << left;
	gotoXY(1, 4);
	cout << setw(22) << "Nut Mui Ten Len Xuong :" << "De Dieu Khien Thanh Sang";
	gotoXY(1, 5);
	cout << setw(22) << "Nut Enter" << ":De Chon";
	gotoXY(1, 6);
	cout << setw(22) << "Nut Esc" << ":De Thoat";
	textcolor(7);
}void HuongDanThi()
{
	textcolor(MauNenHuongDan);
	cout << left;
	gotoXY(1, 4);
	cout << setw(22) << "Nut Mui Ten Len Xuong :" << "De Dieu Khien Thanh Sang";
	gotoXY(1, 5);
	cout << setw(22) << "Nut Mui Ten Qua Ve" << ":De Chuyen Trang";
	gotoXY(1, 6);
	cout << setw(22) << "Nut Enter" << ":De Chon Va Bo Chon Dap An";
	gotoXY(1, 7);
	cout << setw(22) << "Nut Esc" << ":De Nop Bai";
	textcolor(7);
}
//Xoa Man Hinh
void XoaManHinhChinh()
{
	textcolor(7);
	for (int i = 6; i < 36; i++)
	{
		for (int j = 51; j < 176; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
}
void XoaManHinhTuyChon(int toadoX, int toadoY, int chieudai, int chieucao)
{
	textcolor(7);
	for (int i = toadoY; i < chieucao + toadoY; i++)
	{
		for (int j = toadoX; j < toadoX + chieudai; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
}
//
void DeMuc(string x)
{
	SetColor(14);
	gotoXY(51, 7);
	cout << CanDeuChuoi(x, 126);
	textcolor(7);
}
void XuatPage(int page)
{
	gotoXY(111, 34);
	cout << char(174);
	gotoXY(115, 34);
	cout << char(175);
	gotoXY(113, 34);
	cout << page;
}
void Success(string title) {
	VeHCN(90, 31, 50, 2, 15);
	textcolor(10);
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
	cout << CanDeuChuoi(title, 50);
}
void Error(string title) {
	VeHCN(90, 17, 50, 2, 15);
	textcolor(4);
	for (int i = 0; i < 48; i++) {
		gotoXY(91 + i, 18);
		cout << ".";
		Sleep(10);
	}
	for (int i = 0; i < 48; i++) {
		gotoXY(91 + i, 18);
		cout << " ";
	}
	gotoXY(91, 18);
	cout << CanDeuChuoi(title, 50);
}
void ClearText(int toadoX, int toadoY, int chieudai) {
	for (int i = toadoX; i < toadoX + chieudai + 1; i++) {
		gotoXY(i, toadoY);
		cout << " ";
	}
}
//GiaoDien
void GiaoDienMain()
{
	ShowCur(0);
	HCNText(4, 13, 42, 22);

	textcolor(112);
	// duong to mau gach xuong
	for (int i = 0; i < 36; i++)
	{
		gotoXY(50, i);
		cout << " ";
	}
	// duong to mau tren Menu
	for (int i = 0; i < 50; i++)
	{
		gotoXY(i, 11);
		cout << " ";
	}
	// duong to mau duoi cuoi
	for (int i = 0; i < 176; i++)
	{
		gotoXY(i, 36);
		cout << " ";
	}
	textcolor(7);
	// duong gach ngang duoi welcome
	for (int i = 51; i < 176; i++)
	{
		gotoXY(i, 5);
		cout << (char)205;
	}

	ToMauHCN(-1, -1, 51, 4, 176);
	gotoXY(20, 1);
	textcolor(188);
	cout << "Huong Dan";
	textcolor(7);
	//ToMauHCN(-1,2 , 51, 9, 240);
	HuongDanMenuMain();
	gotoXY(105, 2);
	cout << "WELCOME TO THE PROGRAM";
	gotoXY(23, 15);
	SetColor(9);
	cout << "MENU";
	textcolor(7);
}
void GiaoDienDangNhap()
{
	//	chu kieu
	Logo1(50, 0);
	//	cai khung
	VeHCN(61, 12, 48, 16, 7);
	//	thanh ngang
	for (int i = 62; i <= 48 + 61 - 1; i++)
	{
		gotoXY(i, 14);
		cout << (char)196;
	}
	SetColor(4);
	gotoXY(62, 13);
	cout << CanDeuChuoi("DANG NHAP", 46);
	SetColor(7);
	gotoXY(65, 18);
	cout << "Tai Khoan";
	VeHCN(75, 17, 30, 2, 7);
	gotoXY(65, 21);
	cout << "Mat Khau";
	VeHCN(75, 20, 30, 2, 7);

	gotoXY(75, 25);
	cout << "Xac Nhan";
	gotoXY(95, 25);
	cout << "Exit";
}
void GiaoDienNhapLop()
{
	DeMuc("DANG KI LOP");
	gotoXY(75, 18);
	cout << "Nhap Ma Lop:";
	gotoXY(75, 21);
	cout << "Nhap Ten Lop:";
	VeHCN(90, 17, 50, 2, 15);
	VeHCN(90, 17 + 3, 50, 2, 15);
	gotoXY(105, 27);
	cout << "Them";
	gotoXY(120, 27);
	cout << "Thoat";
}
void GiaoDienNhapMaLop()
{
	DeMuc("Dang Ki Sinh Vien");
	gotoXY(75, 18);
	cout << "Nhap Ma Lop:";
	VeHCN(90, 17, 50, 2, 7);
}
void GiaoDienXuatDanhSachLop(int toadoX, int toadoY, int n)
{
	int chieucao = 3 + 2 * n;
	int chieudai = 100;

	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}

	// gach xuong
	for (int i = toadoX + 1; i < chieudai + toadoX; i++)
	{
		if (i == toadoX + 30)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j == toadoY)
					cout << char(194);
				else if (j == chieucao + toadoY)
					cout << char(193);
				else
					cout << (char)179;
			}
		}
	}

	// gach ngang
	for (int j = 3; j < chieucao; j = j + 2)
	{
		for (int i = toadoX; i <= chieudai + toadoX; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX)
				cout << (char)195;
			else if (i == chieudai + toadoX)
				cout << (char)180;
			else if (i == toadoX + 30)
				cout << (char)197;
			else
				cout << (char)196;
		}
	}

	gotoXY(toadoX + 1, toadoY + 1);
	cout << CanDeuChuoi("Ma Lop", 29);
	gotoXY(toadoX + 31, toadoY + 1);
	cout << CanDeuChuoi("Ten Lop", 69);
}
void GiaoDienNhapSinhVien()
{
	DeMuc("Dang Ki Sinh Vien");
	gotoXY(75, 12);
	cout << "Nhap Password:";
	VeHCN(105, 11, 50, 2, 7);
	gotoXY(75, 15);
	cout << "Nhap Ma Sinh Vien:";
	VeHCN(105, 14, 50, 2, 7);

	gotoXY(75, 18);
	cout << "Nhap Ho va Ten Lot:";
	gotoXY(75, 21);
	cout << "Nhap Ten:";
	gotoXY(75, 24);
	cout << "Chon Phai:";
	VeHCN(130, 23, 15, 2, 4);

	VeHCN(105, 17, 50, 2, 15);
	VeHCN(105, 20, 50, 2, 15);
	gotoXY(110, 24);
	cout << "Nam";
	gotoXY(125, 24);
	cout << "Nu";
	gotoXY(120, 27);
	cout << "Them";
	gotoXY(135, 27);
	cout << "Thoat";
}
void GiaoDienDKMonHoc()
{
	DeMuc("DANG KI MOM HOC");
	gotoXY(75, 18);
	cout << "Nhap Ma Mon Hoc:";
	gotoXY(75, 21);
	cout << "Nhap Ten Mon Hoc:";
	VeHCN(95, 17, 50, 2, 15);
	VeHCN(95, 20, 50, 2, 15);
	gotoXY(110, 24);
	cout << "Dang Ki";
	gotoXY(125, 24);
	cout << "Thoat";
}
void GiaoDienSuaMonHoc()
{
	DeMuc("SUA MOM HOC");
	gotoXY(75, 18);
	cout << "Nhap Ma Mon Hoc:";
	gotoXY(75, 21);
	cout << "Nhap Ten Mon Hoc:";
	VeHCN(95, 17, 50, 2, 15);
	VeHCN(95, 20, 50, 2, 15);
	gotoXY(110, 24);
	cout << "Cap nhat";
	gotoXY(125, 24);
	cout << "Thoat";
}
void GiaoDienNhapThiTracNghiem(int toadoX, int toadoY)
{
	DeMuc("THI TRAC NGHIEM");
	gotoXY(75, 18);
	cout << "Nhap Ma Mon:";
	gotoXY(75, 21);
	cout << "Nhap So Luong Cau Hoi:";
	gotoXY(75, 24);
	cout << "Nhap Thoi Gian(Phut):";

	VeHCN(toadoX + 5, toadoY, 50, 2, 15);
	VeHCN(toadoX + 5, toadoY + 3, 50, 2, 15);
	VeHCN(toadoX + 5, toadoY + 6, 50, 2, 15);
	gotoXY(toadoX + 15, toadoY + 10);
	cout << "Xac Nhan";
	gotoXY(toadoX + 30, toadoY + 10);
	cout << "Cancel";
}
void GiaoDienThiTracNghiem()
{
	system("cls");
	ShowCur(0);
	//	Logo2(80, 0);
	textcolor(112);
	// duong to mau gach xuong
	for (int i = 0; i < 36; i++)
	{
		gotoXY(50, i);
		cout << " ";
	}

	// duong to mau duoi cuoi
	for (int i = 0; i < 176; i++)
	{
		gotoXY(i, 36);
		cout << " ";
	}
	textcolor(7);

	for (int i = 51; i < 176; i++)
	{
		gotoXY(i, 5);
		cout << (char)205;
	}

	ToMauHCN(-1, -1, 51, 4, 176);
	ToMauHCN(-1, 10, 51, 4, 176);
	ToMauHCN(-1, 20, 51, 4, 176);

	HuongDanThi();
	gotoXY(20, 1);
	textcolor(188);
	cout << "Huong Dan";
	gotoXY(0, 12);
	cout << CanDeuChuoi("Thoi Gian Thi Con Lai", 49);
	gotoXY(0, 22);
	cout << CanDeuChuoi("Thong Tin", 49);
	textcolor(7);

	gotoXY(1, 26);
	cout << "Ten Sinh Vien:";
	gotoXY(1, 27);
	cout << "Ma Sinh Vien :";
	gotoXY(1, 28);
	cout << "Ten Mon      :";
	gotoXY(1, 29);
	cout << "Ma Mon       :";
	gotoXY(1, 30);
	cout << "Thoi Gian Thi:";
	gotoXY(1, 31);
	cout << "So Cau Hoi   :";
	gotoXY(5, 33);
	cout << "De Thi Gom Co ";
}
void GiaoDienSinhVienDangNhap()
{
	ShowCur(0);
	HCNText(4, 13, 42, 22);

	textcolor(112);
	// duong to mau gach xuong
	for (int i = 0; i < 36; i++)
	{
		gotoXY(50, i);
		cout << " ";
	}
	// duong to mau tren Menu
	for (int i = 0; i < 50; i++)
	{
		gotoXY(i, 11);
		cout << " ";
	}
	// duong to mau duoi cuoi
	for (int i = 0; i < 176; i++)
	{
		gotoXY(i, 36);
		cout << " ";
	}
	textcolor(7);
	// duong gach ngang duoi welcome
	for (int i = 51; i < 176; i++)
	{
		gotoXY(i, 5);
		cout << (char)205;
	}

	ToMauHCN(-1, -1, 51, 4, 176);
	gotoXY(20, 1);
	textcolor(188);
	cout << "Huong Dan";
	textcolor(7);
	gotoXY(105, 2);
	cout << "WELCOME TO THE PROGRAM";
	gotoXY(5, 15);
	SetColor(9);
	cout << CanDeuChuoi("NOI QUI THI", 41);
	textcolor(7);
}
void GiaoDienNhapCauHoi(int toadoX, int toadoY)
{
	DeMuc("THEM CAU HOI");
	//VeHCN(toadoX + 25, toadoY, 70, 2, 15);
	VeHCN(toadoX + 25, toadoY + 3, 70, 2, 15);
	VeHCN(toadoX + 25, toadoY + 6, 70, 2, 15);
	VeHCN(toadoX + 25, toadoY + 9, 70, 2, 15);
	VeHCN(toadoX + 25, toadoY + 12, 70, 2, 15);
	VeHCN(toadoX + 25, toadoY + 15, 70, 2, 15);
	VeHCN(toadoX + 25, toadoY + 18, 70, 2, 15);
	VeHCN(130, toadoY + 21, 15, 2, 4);

	/*gotoXY(toadoX, toadoY + 1);
	cout << "ID:";*/
	gotoXY(toadoX, toadoY + 4);
	cout << "Nhap Ma Mon Hoc:";
	gotoXY(toadoX, toadoY + 7);
	cout << "Nhap Noi Dung Cau Hoi:";
	gotoXY(toadoX, toadoY + 10);
	cout << "Nhap Dap An A:";
	gotoXY(toadoX, toadoY + 13);
	cout << "Nhap Dap An B";
	gotoXY(toadoX, toadoY + 16);
	cout << "Nhap Dap An C:";
	gotoXY(toadoX, toadoY + 19);
	cout << "Nhap Dap An D:";
	gotoXY(toadoX, toadoY + 22);
	cout << "Nhap Dap An Dung:";
	gotoXY(toadoX + 30, toadoY + 25);
	cout << "Them";
	gotoXY(toadoX + 60, toadoY + 25);
	cout << "Thoat";

	gotoXY(toadoX + 30, toadoY + 22);
	cout << "A";
	gotoXY(toadoX + 35, toadoY + 22);
	cout << "B";
	gotoXY(toadoX + 40, toadoY + 22);
	cout << "C";
	gotoXY(toadoX + 45, toadoY + 22);
	cout << "D";
}
void GiaoDienBangDiem(int toadoX, int toadoY)
{
	DeMuc("BANG DIEM");
	gotoXY(75, 18);
	cout << "Nhap Ma Lop:";
	gotoXY(75, 21);
	cout << "Nhap Ma Mon Hoc:";
	VeHCN(toadoX, toadoY, 50, 2, 15);
	VeHCN(toadoX, toadoY + 3, 50, 2, 15);
	gotoXY(toadoX + 15, toadoY + 10);
	cout << "Xac Nhan";
	gotoXY(toadoX + 30, toadoY + 10);
	cout << "Cancel";
}
void GiaoDienXuatBangDiem1Lop(int toadoX, int toadoY, int n)
{
	int chieucao = 3 + 2 * n;
	int chieudai = 100;

	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}


	// gach xuong
	for (int i = toadoX + 1; i < chieudai + toadoX; i++)
	{
		if (i == toadoX || i == toadoX + 30 || i == toadoX + 80)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j == toadoY)
					cout << char(194);
				else if (j == chieucao + toadoY)
					cout << char(193);
				else
					cout << (char)179;
			}
		}
	}


	// gach ngang
	for (int j = 3; j < chieucao; j = j + 2)
	{
		for (int i = toadoX; i <= chieudai + toadoX; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX || i == toadoX + 30 || i == toadoX + 80)
				cout << (char)195;
			else if (i == chieudai + toadoX)
				cout << (char)180;
			else if (i == toadoX + 30)
				cout << (char)197;
			else
				cout << (char)196;
		}
	}

	gotoXY(toadoX + 1, toadoY + 1);
	cout << CanDeuChuoi("Ma Sinh Vien", 29);
	gotoXY(toadoX + 31, toadoY + 1);
	cout << CanDeuChuoi("Ten Sinh Vien", 49);
	gotoXY(toadoX + 81, toadoY + 1);
	cout << CanDeuChuoi("Diem", 19);
}
void GiaoDienDiem(int SoCauDung, int TongSoCau, int toadoX, int toadoY)
{
	ToMauHCN(90, 17, 50, 10, 95);
	textcolor(95);
	gotoXY(91, 20);
	cout << CanDeuChuoi("Ban Da Dung " + ChuyenSoSangString(SoCauDung) + " / " + ChuyenSoSangString(TongSoCau) + " Cau", 49);
	gotoXY(91, 21);
	cout << CanDeuChuoi("Diem Cua Ban La: " + ChuyenSoSangString((float)((10 / TongSoCau) * SoCauDung)), 49);
	gotoXY(103, 23);
	system("pause");
	textcolor(7);
}
void GiaoDienNopBai()
{
	XoaHuongDan();
	ToMauHCN(toadoXBox + 46 - 15, toadoYBox + 10 - 5, 40, 10, 240);
	textcolor(240);
	gotoXY(toadoXBox + 38, toadoYBox + 8);
	cout << "Ban Co Chac Chan Muon Nop Bai";
	gotoXY(toadoXBox + 40, toadoYBox + 9);
	cout << "(Thoi Gian Van Dang Chay)";
	gotoXY(toadoXBox + 45, toadoYBox + 12);
	cout << "Yes";
	gotoXY(toadoXBox + 55, toadoYBox + 12);
	cout << "No";
}
void GiaoDienCauHoiDaThi(int toadoX, int toadoY)
{
	DeMuc("DANH SACH CAU HOI DA THI");
	gotoXY(75, 18);
	cout << "Nhap Ma Sinh Vien:";
	gotoXY(75, 21);
	cout << "Nhap Ma Mon Hoc:";
	VeHCN(toadoX, toadoY, 50, 2, 15);
	VeHCN(toadoX, toadoY + 3, 50, 2, 15);
	gotoXY(toadoX + 15, toadoY + 10);
	cout << "Xac Nhan";
	gotoXY(toadoX + 30, toadoY + 10);
	cout << "Cancel";
}
void GiaoDienNhapMocHocCanSua(int toadoX, int toadoY)
{
	DeMuc("SUA MOM HOC");
	gotoXY(toadoX, 11);
	cout << CanDeuChuoi("Chon mon hoc can sua", 50);
	VeHCN(toadoX, toadoY, 60, 18, 7);
	for (int i = toadoX + 1; i < toadoX + 60; i++)
	{
		gotoXY(i, toadoY + 2);
		cout << "_";
	}
	for (int i = toadoX + 1; i < toadoX + 60; i++)
	{
		gotoXY(i, toadoY + 15);
		cout << "_";
	}
	for (int i = toadoY + 1; i < toadoY + 16; i++) {
		gotoXY(toadoX + 11, i);
		cout << char(179);
		gotoXY(toadoX + 49, i);
		cout << char(179);
		gotoXY(toadoX + 1, toadoY + 1);
		cout << CanDeuChuoi("Ma mon hoc", 10);
		gotoXY(toadoX + 12, toadoY + 1);
		cout << CanDeuChuoi("Ten mon hoc", 37);
		gotoXY(toadoX + 50, toadoY + 1);
		cout << CanDeuChuoi("So cau hoi", 10);
	}
	gotoXY(toadoX + 13, toadoY + 17);
	SetColor(9);
	cout << "Danh Sach Cac Mon Hoc";
	textcolor(7);
}
void GiaoDienChonMocHocCanXoa(int toadoX, int toadoY)
{
	DeMuc("XOA MOM HOC");
	gotoXY(toadoX, 11);
	cout << CanDeuChuoi("Chon mon hoc can xoa", 50);
	VeHCN(toadoX, toadoY, 60, 18, 7);
	for (int i = toadoX + 1; i < toadoX + 60; i++)
	{
		gotoXY(i, toadoY + 2);
		cout << "_";
	}
	for (int i = toadoX + 1; i < toadoX + 60; i++)
	{
		gotoXY(i, toadoY + 15);
		cout << "_";
	}
	for (int i = toadoY + 1; i < toadoY + 16; i++) {
		gotoXY(toadoX + 11, i);
		cout << char(179);
		gotoXY(toadoX + 49, i);
		cout << char(179);
		gotoXY(toadoX + 1, toadoY + 1);
		cout << CanDeuChuoi("Ma mon hoc", 10);
		gotoXY(toadoX + 12, toadoY + 1);
		cout << CanDeuChuoi("Ten mon hoc", 37);
		gotoXY(toadoX + 50, toadoY + 1);
		cout << CanDeuChuoi("So cau hoi", 10);
	}
	gotoXY(toadoX + 13, toadoY + 17);
	SetColor(9);
	cout << "Danh Sach Cac Mon Hoc";
	textcolor(7);
}
void GiaoDienKTCauHoi(int toadoX, int toadoY, int n, char DapAn[])
{
	int chieucao = 3 + 2 * n;
	int chieudai = 100;
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}

	// gach xuong
	int h = 0;
	for (int i = toadoX; i < chieudai + toadoX; i++)
	{
		if (h % 4 == 0)
		{
			for (int j = toadoY; j < chieucao + toadoY + 1; j++)
			{
				gotoXY(i, j);
				if (j == toadoY)
					cout << char(194);
				else if (j == chieucao + toadoY)
					cout << char(193);
				else
					cout << (char)179;
			}
		}
		h++;
	}

	//gach ngang
	for (int j = 2; j < chieucao; j = j + 2)
	{
		int k = 0;
		for (int i = toadoX; i <= chieudai + toadoX; i++)
		{
			gotoXY(i, toadoY + j);
			if (i == toadoX)
				cout << (char)195;
			else if (i == chieudai + toadoX)
				cout << (char)180;
			else if (k % 4 == 0)
				cout << (char)197;
			else
				cout << (char)196;
			k++;
		}
	}
}
void GiaoDienNhapMLandMMH()
{
	DeMuc("XEM BANG DIEM THI TRAC NGHIEM CUA 1 LOP");
	gotoXY(75, 18);
	cout << "Nhap Ma Lop:";
	gotoXY(75, 21);
	cout << "Nhap Ma Mon Hoc:";
	VeHCN(100, 17, 50, 2, 15);
	VeHCN(100, 17 + 3, 50, 2, 15);
	gotoXY(105, 27);
	cout << "Xac Nhan";
	gotoXY(120, 27);
	cout << "Thoat";
}
void GiaoDienNhapMMHandMSV()
{
	DeMuc("XEM BAI THI CUA 1 SINH VIEN");
	gotoXY(75, 18);
	cout << "Nhap Ma Sinh Vien:";
	gotoXY(75, 21);
	cout << "Nhap Ma Mon Hoc:";
	gotoXY(75, 24);
	cout << "Nhap So Lan Thi:";
	VeHCN(100, 17, 50, 2, 15);
	VeHCN(100, 17 + 3, 50, 2, 15);
	VeHCN(100, 17 + 6, 50, 2, 15);
	gotoXY(105, 27);
	cout << "Xac Nhan";
	gotoXY(120, 27);
	cout << "Thoat";
}