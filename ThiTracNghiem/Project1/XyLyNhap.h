//Xu ly nhap
void XuLyNhapTK(string& InPut, int toadoX, int& toadoY)
{
	int toadoXtam;
	char c;
	while (true)
	{
		c = getch();
		if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90)) && InPut.length() < 20)
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                         ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if ((c >= 97 && c <= 122) && InPut.length() < 20)
		{
			c = c - 32;
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                         ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 8 && whereX() > toadoX)
		{
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                         ";
			gotoXY(toadoX, whereY());
			cout << InPut;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 13 && InPut.length() > 0)// n?u là phím enter
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}
void XuLyNhapMK(string& InPut, int toadoX, int& toadoY)
{
	int toadoXtam;
	char c;
	while (true)
	{
		c = getch();
		if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) && InPut.length() < 20)
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                         ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << "*";
		}
		else if (c == 8 && whereX() > toadoX)
		{
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                         ";
			gotoXY(toadoX, whereY());
			for (int i = 0; i < InPut.length(); i++)
			{
				cout << "*";
			}
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 13 && InPut.length() > 0)// n?u là phím enter
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}
void XuLyNhapMaMonHoc(string& InPut, int toadoX, int& toadoY)
{
	int toadoXtam;
	char c;
	while (true)
	{
		c = getch();
		if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90)) && InPut.length() < 15)
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                         ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if ((c >= 97 && c <= 122) && InPut.length() < 15)
		{
			c = c - 32;
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                         ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 8 && whereX() > toadoX)
		{
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                         ";
			gotoXY(toadoX, whereY());
			cout << InPut;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 13 && InPut.length() > 0)// n?u là phím enter
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}
void XuLyNhapMaLop(string& InPut, int toadoX, int toadoY)
{
	int toadoXtam;
	char c;
	while (true)
	{
		c = getch();
		if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90)) && InPut.length() < 15)
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                         ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if ((c >= 97 && c <= 122) && InPut.length() < 15)
		{
			c = c - 32;
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                         ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 8 && whereX() > toadoX)
		{
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                         ";
			gotoXY(toadoX, whereY());
			cout << InPut;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 13 && InPut.length() > 0)// n?u là phím enter
		{
			break;
		}
	}
}
void XuLyNhap_Chu(string& InPut, int toadoX, int& toadoY, int LenghtMax)
{
	int toadoXtam;
	char c;
	while (true)
	{
		char c = _getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) && InPut.length() < LenghtMax)
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 8 && whereX() > toadoX)
		{
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                                               ";
			gotoXY(toadoX, whereY());
			cout << InPut;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 32 && InPut.length() < LenghtMax && InPut.length() != 0 && InPut[whereX() - toadoX - 1] != ' ')
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), ' ');
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 13 && InPut.length() > 0)// n?u là phím enter
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}
void XuLyNhap_So(int& n, int toadoX, int& toadoY)
{
	int toadoXtam;
	string x;
	//x = ChuyenSoSangString(n);
	char c;
	while (true)
	{
		c = getch();
		if ((c >= 48 && c <= 57) && whereX() < toadoX + 47)// n?u là s? thì
		{
			x.insert(x.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < x.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << x;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 8 && whereX() > toadoX)
		{
			x.erase(x.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                                               ";
			gotoXY(toadoX, whereY());
			cout << x;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 13 && x.length() > 0)// n?u là phím enter
		{
			toadoY = toadoY + 3;
			n = atoi(x.c_str());
			break;
		}
		else if (c == -32)
		{
			c = getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + x.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				if (x.empty())
				{
					n = 0;
				}
				else
				{
					n = atoi(x.c_str());
				}
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				if (x.empty())
				{
					n = 0;
				}
				else
				{
					n = atoi(x.c_str());
				}
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}
void ChonPhai(int toadoX, int toadoY, string& Phai, int& pointer2)
{
	ShowCur(0);
	int pointer1 = toadoX;
	gotoXY(toadoX, toadoY);
	cout << "Nam";
	gotoXY(toadoX + 15, toadoY);
	cout << "Nu";
	while (true)
	{
		if (kbhit())
		{
			char c = getch();
			if (c == -32)
			{
				c = getch();
				if (c == 75)
				{
					if (pointer1 == toadoX)
						pointer1 = toadoX + 15;
					else
						pointer1 = toadoX;

					gotoXY(toadoX, toadoY);
					cout << "Nam";
					gotoXY(toadoX + 15, toadoY);
					cout << "Nu";
				}
				else if (c == 77)
				{
					if (pointer1 == toadoX + 15)
						pointer1 = toadoX;
					else
						pointer1 = toadoX + 15;

					gotoXY(toadoX, toadoY);
					cout << "Nam";
					gotoXY(toadoX + 15, toadoY);
					cout << "Nu";
				}
				else if (c == 72)
				{
					ShowCur(1);
					pointer2 = pointer2 - 3;
					gotoXY(toadoX, toadoY);
					cout << "Nam";
					gotoXY(toadoX + 15, toadoY);
					cout << "Nu";
					break;
				}
				else if (c == 80)
				{
					pointer2 = pointer2 + 3;
					gotoXY(toadoX, toadoY);
					cout << "Nam";
					gotoXY(toadoX + 15, toadoY);
					cout << "Nu";
					break;
				}
			}
			if (c == 13)
			{
				gotoXY(135, 24);
				cout << "   ";
				gotoXY(pointer1, toadoY);
				SetColor(4);
				if (pointer1 == toadoX)
				{
					//					cout << "Nam";
					gotoXY(135, 24);
					cout << "Nam";
					Phai = "Nam";
				}
				else if (pointer1 == toadoX + 15)
				{
					cout << "Nu";
					gotoXY(135, 24);
					cout << "Nu";
					Phai = "Nu";
				}
				textcolor(7);
				gotoXY(toadoX, toadoY);
				cout << "Nam";
				gotoXY(toadoX + 15, toadoY);
				cout << "Nu";
				pointer2 = pointer2 + 3;
				break;
			}
		}

		gotoXY(pointer1, toadoY);
		SetColor(4);
		if (pointer1 == toadoX)
		{
			cout << "Nam";
		}
		else if (pointer1 == toadoX + 15)
		{
			cout << "Nu";
		}
		textcolor(7);
		Sleep(100);
	}
}
void ChonDapAn(int toadoX, int toadoY, char& DapAn, int& pointer2)
{
	ShowCur(0);
	int pointer1 = toadoX;
	char c;
	gotoXY(toadoX, toadoY);
	cout << "A";
	gotoXY(toadoX + 5, toadoY);
	cout << "B";
	gotoXY(toadoX + 10, toadoY);
	cout << "C";
	gotoXY(toadoX + 15, toadoY);
	cout << "D";
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
					if (pointer1 == toadoX)
						pointer1 = toadoX + 15;
					else
						pointer1 = pointer1 - 5;

					gotoXY(toadoX, toadoY);
					cout << "A";
					gotoXY(toadoX + 5, toadoY);
					cout << "B";
					gotoXY(toadoX + 10, toadoY);
					cout << "C";
					gotoXY(toadoX + 15, toadoY);
					cout << "D";
				}
				else if (c == 77)
				{
					if (pointer1 == toadoX + 15)
						pointer1 = toadoX;
					else
						pointer1 = pointer1 + 5;

					gotoXY(toadoX, toadoY);
					cout << "A";
					gotoXY(toadoX + 5, toadoY);
					cout << "B";
					gotoXY(toadoX + 10, toadoY);
					cout << "C";
					gotoXY(toadoX + 15, toadoY);
					cout << "D";
				}
				else if (c == 72)
				{
					ShowCur(1);
					pointer2 = pointer2 - 3;

					gotoXY(toadoX, toadoY);
					cout << "A";
					gotoXY(toadoX + 5, toadoY);
					cout << "B";
					gotoXY(toadoX + 10, toadoY);
					cout << "C";
					gotoXY(toadoX + 15, toadoY);
					cout << "D";
					break;
				}
				else if (c == 80)
				{
					pointer2 = pointer2 + 3;
					gotoXY(toadoX, toadoY);
					cout << "A";
					gotoXY(toadoX + 5, toadoY);
					cout << "B";
					gotoXY(toadoX + 10, toadoY);
					cout << "C";
					gotoXY(toadoX + 15, toadoY);
					cout << "D";
					break;
				}
			}
			if (c == 13)
			{
				gotoXY(135, toadoY);
				cout << "   ";
				gotoXY(pointer1, toadoY);
				SetColor(4);
				if (pointer1 == toadoX)
				{
					cout << "A";
					gotoXY(135, toadoY);
					cout << "A";
					DapAn = 1;
				}
				else if (pointer1 == toadoX + 5)
				{
					cout << "B";
					gotoXY(135, toadoY);
					cout << "B";
					DapAn = 2;
				}
				else if (pointer1 == toadoX + 10)
				{
					cout << "C";
					gotoXY(135, toadoY);
					cout << "C";
					DapAn = 3;
				}
				else if (pointer1 == toadoX + 15)
				{
					cout << "D";
					gotoXY(135, toadoY);
					cout << "D";
					DapAn = 4;
				}
				textcolor(7);
				gotoXY(toadoX, toadoY);
				cout << "A";
				gotoXY(toadoX + 5, toadoY);
				cout << "B";
				gotoXY(toadoX + 10, toadoY);
				cout << "C";
				gotoXY(toadoX + 15, toadoY);
				cout << "D";
				pointer2 = pointer2 + 3;
				break;
			}
		}

		gotoXY(pointer1, toadoY);
		SetColor(4);
		if (pointer1 == toadoX)
		{
			cout << "A";
		}
		else if (pointer1 == toadoX + 5)
		{
			cout << "B";
		}
		else if (pointer1 == toadoX + 10)
		{
			cout << "C";
		}
		else if (pointer1 == toadoX + 15)
		{
			cout << "D";
		}
		textcolor(7);
		Sleep(100);
	}
}

string XuatMaDocGia(string a[], string str[], int n, string MaTam, int toadoX, int toadoY, int pointer1, int& SoMa, int& pos, bool TrangThaiTruoc)
{
	string MaHienTai;
	int j = toadoY;
	int vitri = 0;
	int tam = pos;

	if (n == 0)
	{
		gotoXY(toadoX, toadoY + 5);
		cout << "Khong Co Mon Hoc Nao !!!";
		return 0;
	}
	else if (MaTam > a[n - 1])
	{
		gotoXY(toadoX, toadoY + 5);
		cout << "Ma Khong Ton Tai";
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		if (a[i] >= MaTam)
		{
			vitri = i;
			break;
		}
	}
	if (!MaTam.empty() && TrangThaiTruoc == false)
	{
		pos = 0;
		tam = 0;
	}
	while (tam > 0 && vitri < n)
	{
		vitri++;
		tam--;
	}
	while (true)
	{
		if (j == pointer1)
		{
			textcolor(192);
			gotoXY(toadoX, j++);
			MaHienTai = a[vitri];
			cout << left;
			cout << setw(10) << a[vitri] << setw(20) << str[vitri];
			vitri++;
			textcolor(7);
		}
		else
		{
			gotoXY(toadoX, j++);
			cout << a[vitri++];
		}
		SoMa++;
		if (vitri == n)
		{
			break;
		}
		if (j == toadoY + 11)
		{
			break;
		}
	}
	return MaHienTai;
}
//void XuLyNhapMaDocGia(string& MaMonHoc, int toadoX, int toadoY, int KT, int& pointer1, int& pos)
//{
//	string* a = new string[0];
//	int n = 0;
//	string* str = new string[0];
//
//	if (KT == 1) // lay het
//	{
////		LayMaMonHoc(str, a, n);
//	}
//	else if (KT == 2) // lay de xoa
//	{
////		LayMaMonHocDeXoa(t, str, a, n);
//	}
//
//	string x;
//	int SoMa = 0;
//	char c;
//	string MaTam ;
//	bool TrangThaiTruoc = false;
//	GiaoDienNhapMocHocCanSua(toadoXBox + 25, toadoYBox + 4);
//	gotoXY(toadoXBox + 27, toadoYBox + 5);
//
//	MaMonHoc = XuatMaDocGia(a, str, n, MaTam, toadoX + 2, toadoY + 3, pointer1, SoMa, pos, TrangThaiTruoc);
//	gotoXY(toadoX + 2, toadoY);
//	ShowCur(1);
//	while (true)
//	{
//		if (kbhit())
//		{
//			ShowCur(0);
//			c = getch();
//			if ((c >= 48 && c <= 57) && x.length() < 5) // n?u là s? thì
//			{
//				x.insert(x.begin() + x.length(), c);
//				cout << c;
//				MaTam = atoi(x.c_str());
//				pointer1 = toadoY + 3;
//				XoaManHinhTuyChon(toadoX + 2, toadoY + 2, 48, 12);
//			}
//			else if (c == 8 && x.length() > 0)
//			{
//				x.erase(x.begin() + x.length() - 1);
//				cout << "\b";
//				cout << " ";
//				cout << "\b";
//				MaTam = atoi(x.c_str());
//				pointer1 = toadoY + 3;
//				XoaManHinhTuyChon(toadoX + 2, toadoY + 2, 48, 12);
//			}
//			else if (c == 13)// n?u là phím enter
//			{
//				XoaManHinhTuyChon(toadoX, toadoY - 5, 60, 25);
//				break;
//			}
//			else if (c == 27)
//			{
//				MaMonHoc.clear() ;
//				break;
//			}
//			else if (c == -32)
//			{
//				c = getch();
//				if (c == 72)
//				{
//					if (pointer1 == toadoY + 3)
//					{
//						if (MaMonHoc != a[0])
//						{
//							pos--;
//						}
//					}
//					else
//					{
//						pointer1--;
//					}
//					XoaManHinhTuyChon(toadoX + 2, toadoY + 2, 48, 12);
//				}
//				else if (c == 80)
//				{
//					if (pointer1 == toadoY + 3 + SoMa - 1)
//					{
//						if (MaMonHoc != a[n - 1])
//						{
//							pos++;
//						}
//					}
//					else
//					{
//						pointer1++;
//					}
//					XoaManHinhTuyChon(toadoX + 2, toadoY + 2, 48, 12);
//				}
//			}
//
//			SoMa = 0;
//			MaMonHoc = XuatMaDocGia(a, str, n, MaTam, toadoX + 2, toadoY + 3, pointer1, SoMa, pos, TrangThaiTruoc);
//			gotoXY(toadoX + 2 + x.length(), toadoY);
//			ShowCur(1);
//			if (x.empty())
//			{
//				TrangThaiTruoc = false;
//			}
//			else
//				TrangThaiTruoc = true;
//		}
//	}
//	delete[]a;
//	delete[]str;
//}
