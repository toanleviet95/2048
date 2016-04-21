#pragma once
#include <string>
using namespace std;
#define CANH 4

// Lớp xử lý
class XuLy
{
private:
	static int TaoSo();
	static bool ConOTrong(int Matrix[CANH][CANH]);
	static void DoiChoDong(int &i, int &vt1, int &vt2, int Matrix[CANH][CANH]);
	static void DoiChoCot(int &j, int &vt1, int &vt2, int Matrix[CANH][CANH]);
	static void GomXuong(int &j, int &i, int &vt1, int &vt2, bool &themSo, int Matrix[CANH][CANH], string Diem[14], int delay);
	static void GomLen(int &j, int &i, int &vt1, int &vt2, bool &themSo, int Matrix[CANH][CANH], string Diem[14], int delay);
	static void GomPhai(int &j, int &i, int &vt1, int &vt2, bool &themSo, int Matrix[CANH][CANH], string Diem[14], int delay);
	static void GomTrai(int &j, int &i, int &vt1, int &vt2, bool &themSo, int Matrix[CANH][CANH], string Diem[14], int delay);
	static void CongXuong(int &j, int &i, bool &themSo, int &score, int Matrix[CANH][CANH]);
	static void CongLen(int &j, int &i, bool &themSo, int &score, int Matrix[CANH][CANH]);
	static void CongPhai(int &j, int &i, bool &themSo, int &score, int Matrix[CANH][CANH]);
	static void CongTrai(int &j, int &i, bool &themSo, int &score, int Matrix[CANH][CANH]);
	static void TinhScore(int &score, int &j, int &i, int Matrix[CANH][CANH]);
public:
	static void ThemSo(int Matrix[CANH][CANH]);
	static bool ThuaCuoc(int Matrix[CANH][CANH]);
	static void Xuong(bool &themSo, int Matrix[CANH][CANH], string Diem[14], int delay, int &score);
	static void Len(bool &themSo, int Matrix[CANH][CANH], string Diem[14], int delay, int &score);
	static void Phai(bool &themSo, int Matrix[CANH][CANH], string Diem[14], int delay, int &score);
	static void Trai(bool &themSo, int Matrix[CANH][CANH], string Diem[14], int delay, int &score);
	static void Choi();
};

