#pragma warning(disable:4996)
#pragma one

#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

#define TRUE 1
#define FALSE 0
const int DSMH_MAX = 100;
const int DSLOP_MAX = 100;
int soluongsongaunhien;
string malop_xuatbangdiem1lop;
string mamh_xuatbangdiem1lop;

int pointer = 19;
int toadoXBox = 65;
int toadoYBox = 9;

struct Hour {
	int hour;
	int minute;
	int second;
};

//==================== danh sach mon hoc =================
struct monhoc {
	string MAMH;
	string TENMH;
	bool kiemtraxoa = false;
	int soluongcauhoi = 0;
};
typedef struct monhoc MonHoc;

struct danhsachmonhoc {
	int n;
	MonHoc* mh[DSMH_MAX];
};
typedef struct danhsachmonhoc DSMH;

//==================== danh sach cau hoi =================
struct cauhoi {
	string ID;
	string MAMH;
	string NOIDUNG;
	string A;
	string B;
	string C;
	string D;
	char DAPAN;
};
struct nodeTree {
	cauhoi data;

	int bf; //chi so can bang

	nodeTree* pleft;
	nodeTree* pright;
};
typedef struct nodeTree* nodetree;

struct danhsachcauhoi {
	int n;
	nodetree root = NULL;
};
typedef struct danhsachcauhoi DSCH;

struct CauHoiDaThi {
	int slcauhoi;
	char* DapAnDaChon;
	cauhoi* data;
};

//==================== danh sach diem thi =================
struct diemthi {
	string MAMH;
	float DIEM;
	CauHoiDaThi cauhoidathi;
	diemthi* pnext;
};
typedef struct diemthi DT;

struct danhsachdiemthi {
	int n;
	DT* phead;
};
typedef struct danhsachdiemthi DSDT;

//==================== danh sach sinh vien =================
struct sinhvien {
	string MASV;
	string HO;
	string TEN;
	string PHAI;
	string PASSWORD;
	int slmondathi = 0;
	//*diem;
	DSDT ptrDSDT;

	sinhvien* pnext;
};
typedef struct sinhvien SV;

struct danhsachsinhvien {
	int n = 0;
	SV* phead = NULL;
};
typedef struct danhsachsinhvien DSSV;

//==================== danh sach lop =================
struct lop {
	string MALOP;
	string TENLOP;
	//*dssv
	DSSV ptrDSSV;
};
typedef struct lop LOP;

struct danhsachlop {
	int n;
	LOP* nodes[DSLOP_MAX];
};
typedef struct danhsachlop DSLOP;

