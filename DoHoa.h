#pragma once
#include <string>
using namespace std;
#define CANH 4

// Lớp đồ họa
class DoHoa
{
private:
	static int SoDong;
	static int SoCot;
	static int ToaDo[21][13]; // Ma trận tọa độ các kí tự
public:
	static void TaoKhung();
	static void VeKhung();
	static void HuongDan();
	static void VeLogo();
	static void InBang(string Diem[14], int Matrix[CANH][CANH], int highScore, int &score);
};

