#include <fstream>
#include <iostream>
#include "DoHoa.h"
#include "XuLyPhu.h"
int DoHoa::SoCot = 21;
int DoHoa::SoDong = 13;
int DoHoa::ToaDo[21][13];

// Tạo khung
void DoHoa::TaoKhung()
{
	int temp;
	ifstream in("Data.in");
	for (int j = 0; j<SoDong; j++){
		for (int i = 0; i<SoCot; i++){
			in >> temp;
			ToaDo[i][j] = temp;
		}
	}
}

// Vẽ khung
void DoHoa::VeKhung()
{
	for (int j = 0; j < SoDong; j++){
		for (int i = 0; i < SoCot; i++){
			gotoxy(27 + i, j);
			cout << (char)ToaDo[i][j];
		}
		cout << endl;
	}
}

// Vẽ logo
void DoHoa::VeLogo()
{
	char c = 0;
	int i = 1;
	gotoxy(17, i);
	ifstream in("Logo.in");
	do{
		in >> c;
		cout << c;
		if (c == ')'){
			i++;
			gotoxy(17, i);
		}
		sleep(1);
	} while (c != ']');
	cout << endl << endl;
	gotoxy(27, 15);
	Setcolor(14);
	pause();
}

// In bảng
void DoHoa::InBang(string Diem[14], int Matrix[CANH][CANH], int highScore, int &score){
	int max = 0;
	// Vẽ khung rồi điền giá trị
	SetBGColor(7);
	Setcolor(1);
	VeKhung();
	for (int i = 0; i < CANH; i++){
		for (int j = 0; j < CANH; j++){
			gotoxy(1 + i * 5 + 27, 2 + j * 3);
			cout << Diem[Matrix[i][j]];
		}
	}
	// In điểm người chơi
	gotoxy(30, 15);
	SetBGColor(1);
	Setcolor(15);
	cout << "SCORE TO WIN: ";
	Setcolor(14);
	cout << highScore;
	gotoxy(32, 17);
	Setcolor(15);
	cout << "YOUR SCORE: ";
	Setcolor(14);
	cout << score;
}

// Hướng dẫn di chuyển
void DoHoa::HuongDan(){
	gotoxy(21, 21);
	Setcolor(15);
	cout << "*PRESS KEYBOARD BUTTONS: " << (char)24 << " " << (char)25 << " " << (char)27 << " " << (char)26;
}


