int intLength(int i) {
	int l = 0;
	for (;i;i /= 10) l++;
	return l == 0 ? 1 : l;
}
//Chuoi
int DemChuSo(int n)
{
	int dem = 0;
	while (n > 0)
	{
		n = n / 10;
		dem++;
	}
	return dem;
}
char Chuyen1SoSangKiTu(int n)
{
	switch (n)
	{
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 0:
		return '0';
	}
}
//De Nhap
string ChuyenSoSangString1(int n)
{
	string str;
	int a;
	while (n > 0)
	{
		a = n % 10;
		Chuyen1SoSangKiTu(a);
		str.insert(str.begin() + 0, Chuyen1SoSangKiTu(a));
		n = n / 10;
	}
	return str;
}
//De Xuat
string ChuyenSoSangString(int n)
{
	string str;
	int a;
	if (n == 0)
	{
		str = "0";
	}
	while (n > 0)
	{
		a = n % 10;
		Chuyen1SoSangKiTu(a);
		str.insert(str.begin() + 0, Chuyen1SoSangKiTu(a));
		n = n / 10;
	}
	return str;
}
void DinhDangChuoi(string& str)
{
	//Xoa khoang trong
	while (str[0] == ' ')
	{
		str.erase(str.begin() + 0);
	}
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + (str.length() - 1));
	}

	for (int i = 1; i < str.length() - 1; i++)
	{
		if (str[i + 1] == ' ' && str[i] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
	//Viet thuong all lai
	for (int i = 0; i < str.length(); i++)
	{
		if ((65 <= str[i] && str[i] <= 90) && str[i] != ' ')
		{
			str[i] = str[i] + 32;
		}
	}
	//Viet hoa
	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0 && (97 <= str[i] && str[i] <= 122))
		{
			str[0] = str[0] - 32;
		}
		if (str[i] == ' ' && (97 <= str[i + 1] && str[i + 1] <= 122))
		{
			str[i + 1] = str[i + 1] - 32;
		}
	}

}
string CanDeuChuoi(string str, int ChieuRong)
{
	if (str.empty())
	{
		return str;
	}
	else if (str.length() > ChieuRong)
	{
		return str;
	}
	return string((ChieuRong - str.length()) / 2, ' ') + str;
}
//
string MaHoaMK(string pass)
{
	for (int i = 0; i < pass.length(); i++)
	{
		pass[i] = pass[i] + 48 + 9 - 4;
	}
	return pass;
}
string GiaiMa(string pass)
{
	for (int i = 0; i < pass.length(); i++)
	{
		pass[i] = pass[i] - 48 - 9 + 4;
	}
	return pass;
}

//Da Luong
bool stop = 1;// Bien Khoi Tao Da Luong
Hour ThoiGian = { 0,0,0 }; //Thoi Gian Thi

void insertarray(char* h, Hour* j)
{
	int bait = 0;
	bait = j->second;
	h[7] = Chuyen1SoSangKiTu(bait % 10);
	h[6] = Chuyen1SoSangKiTu(bait /= 10);

	bait = j->minute;
	h[4] = Chuyen1SoSangKiTu(bait % 10);
	h[3] = Chuyen1SoSangKiTu(bait /= 10);

	bait = j->hour;
	h[1] = Chuyen1SoSangKiTu(bait % 10);
	h[0] = Chuyen1SoSangKiTu(bait /= 10);

}
bool changetime(Hour* h)
{
	if (h->second > 0)
		--h->second;
	else if (h->minute > 0)
	{
		h->second = 59;
		--h->minute;
	}
	else if (h->hour > 0)
	{
		--h->hour;
		h->minute = 59;
		h->second = 59;
	}
	else
		return 0;
	return 1;
}
//dung de in ra mot chuoi thay the ham cout
void WriteBlockChar(char* Arraych, int row, int col, int x, int y, int color)
{
	CHAR_INFO* charater = new CHAR_INFO[row * col];
	for (int i = 0; i < row * col; i++)
	{
		charater[i].Attributes = color;
		charater[i].Char.AsciiChar = Arraych[i];
	}
	COORD sizebuff = { col,row };
	COORD pos = { 0,0 };
	SMALL_RECT earea = { x,y,x + col - 1,y + row - 1 };
	WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), charater, sizebuff, pos, &earea);
	delete[] charater;
}
void printClock()
{
	char str[8] = { '0','0',':','0','0',':','0','0' };
	while (stop)
	{
		if (!changetime(&ThoiGian))
			stop = 0;
		insertarray(str, &ThoiGian);
		WriteBlockChar(str, 1, 8, 20, 17, 0x005 | 0x070);
		Sleep(1000);
	}
	return;
}
DWORD WINAPI ThreadProc(LPVOID param, int a, int b, int c)
{
	printClock();
	return 0;
}

void GhiFileSoNgauNhien(int arr[], int soluongsongaunhien) {
	ofstream FileOut;
	FileOut.open("data\\input.txt", ios::in);
	FileOut << soluongsongaunhien << endl;
	for (int i = 0; i < soluongsongaunhien; i++) {
		FileOut << arr[i] << " ";
	}
	FileOut.close();
}

void DocFileSoNgauNhien(int arr[]) {
	ifstream FileIn;
	FileIn.open("data\\input.txt", ios::in);
	FileIn >> soluongsongaunhien;
	FileIn.ignore();
	for (int i = 0; i < soluongsongaunhien; i++) {
		FileIn >> arr[i];
	}
	FileIn.close();
}

void DocFileLop(DSLOP& dslop) {
	ifstream FileIn;
	ifstream FileIn_CHDT;
	int n;

	FileIn.open("data\\dslop.txt", ios::in);
	FileIn_CHDT.open("data\\cauhoidathi.txt", ios::in);
	FileIn >> n;
	FileIn.ignore();
	for (int i = 0; i < n; i++) {
		dslop.nodes[i] = new LOP;
		getline(FileIn, dslop.nodes[i]->MALOP, ',');
		getline(FileIn, dslop.nodes[i]->TENLOP);
		dslop.nodes[i]->ptrDSSV.n = 0;
		dslop.nodes[i]->ptrDSSV.phead = NULL;
		dslop.n++;

		ifstream FileInSV;
		int slsv;
		string sv, pass;

		FileInSV.open("data\\" + dslop.nodes[i]->MALOP + ".txt", ios::in);
		FileInSV >> slsv;
		FileInSV.ignore();
		for (int j = 0; j < slsv; j++) {
			SV* sv = new SV;
			getline(FileInSV, sv->MASV, ',');
			getline(FileInSV, sv->HO, ',');
			getline(FileInSV, sv->TEN, ',');
			getline(FileInSV, sv->PHAI, ',');
			getline(FileInSV, sv->PASSWORD, ',');
			sv->PASSWORD = GiaiMa(sv->PASSWORD);
			FileInSV >> sv->slmondathi;
			FileInSV.ignore();
			sv->ptrDSDT.phead = NULL;

			for (int h = 0;h < sv->slmondathi;h++) {

				DT* dt = new DT();
				getline(FileInSV, dt->MAMH, ',');
				FileInSV >> dt->DIEM;
				FileInSV.ignore();
				FileInSV >> dt->cauhoidathi.slcauhoi;
				dt->cauhoidathi.data = new cauhoi[dt->cauhoidathi.slcauhoi];
				dt->cauhoidathi.DapAnDaChon = new char[dt->cauhoidathi.slcauhoi];
				FileInSV.ignore();

				if (sv->ptrDSDT.phead == NULL) {
					sv->ptrDSDT.phead = dt;
				}
				else {
					DT* dtTemp = sv->ptrDSDT.phead;
					while (true) {
						if (dtTemp->pnext == NULL) {
							dtTemp->pnext = dt;
							break;
						}
						dtTemp = dt->pnext;
					}
				}

				for (int i = 0; i < dt->cauhoidathi.slcauhoi; i++) {

					getline(FileIn_CHDT, dt->cauhoidathi.data[i].ID);
					getline(FileIn_CHDT, dt->cauhoidathi.data[i].NOIDUNG);
					getline(FileIn_CHDT, dt->cauhoidathi.data[i].A);
					getline(FileIn_CHDT, dt->cauhoidathi.data[i].B);
					getline(FileIn_CHDT, dt->cauhoidathi.data[i].C);
					getline(FileIn_CHDT, dt->cauhoidathi.data[i].D);
					FileIn_CHDT >> dt->cauhoidathi.data[i].DAPAN;
					//FileIn_CHDT.ignore();
					FileIn_CHDT >> dt->cauhoidathi.DapAnDaChon[i];

					/*cout << dt->cauhoidathi.data[i].ID << endl;
					cout << dt->cauhoidathi.data[i].NOIDUNG << endl;
					cout << dt->cauhoidathi.data[i].A << endl;
					cout << dt->cauhoidathi.data[i].B << endl;
					cout << dt->cauhoidathi.data[i].C << endl;
					cout << dt->cauhoidathi.data[i].D << endl;
					cout << dt->cauhoidathi.data[i].DAPAN << endl;
					cout << dt->cauhoidathi.DapAnDaChon[i] << endl;*/
					FileIn_CHDT.ignore();
				}
			}

			//	them dau
			if (dslop.nodes[i]->ptrDSSV.phead == NULL) {
				sv->pnext = NULL;
				dslop.nodes[i]->ptrDSSV.phead = sv;
				dslop.nodes[i]->ptrDSSV.n++;
			}
			else {
				sv->pnext = dslop.nodes[i]->ptrDSSV.phead;
				dslop.nodes[i]->ptrDSSV.phead = sv;
				dslop.nodes[i]->ptrDSSV.n++;
			}
		}	
		FileInSV.close();
	}
	FileIn_CHDT.close();
	FileIn.close();
}

void DocFileMH(DSMH& dsmh) {
	ifstream FileIn;
	int n;
	FileIn.open("data\\dsmh.txt", ios::in);
	FileIn >> n;
	FileIn.ignore();
	for (int i = 0; i < n; i++) {
		dsmh.mh[i] = new MonHoc;
		getline(FileIn, dsmh.mh[i]->MAMH, ',');
		getline(FileIn, dsmh.mh[i]->TENMH);
		//FileIn >> dsmh.mh[i]->soluongcauhoi;
		//FileIn.ignore();
		dsmh.n++;
	}
	FileIn.close();
}