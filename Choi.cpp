#include <fstream>
#include <iostream>
#include <conio.h>
#include "Header.h"
#include "DoHoa.h"
#include "XuLy.h"
#include "XuLyPhu.h"

// Xử lý play
void XuLy::Choi(){
	SetConsoleTitle(TEXT("2048"));
	resizeBuffer(79, 22);
	Nocursortype();
	score = 0;
	SetBGColor(1);
	Setcolor(15);
	clear();
	DoHoa::VeLogo();
	clear();
	DoHoa::TaoKhung();
	DoHoa::HuongDan();

	// Lấy mức điểm mà người chơi cần phải đạt được
	ifstream inScore("Score.in");
	inScore >> highScore;
	inScore.close();

	// Khởi tạo các ô ban đầu = 0
	for (int i = 0; i < CANH - 1; i++)
	for (int j = 0; j < CANH - 1; j++)
	{
		Matrix[i][j] = 0;
	}

	bool KiTuKep = false; // Kiểm tra kí tự kép
	char move;

	ThemSo(Matrix);

	do{
		DoHoa::InBang(Diem, Matrix, highScore, score);

		// Đọc một kí tự từ bàn phím
		move = _getch();
		int x = (int)move;

		themSo = false;
		
		// Kiểm tra thắng
		if (score > highScore)
		{
			ofstream outScore("Score.in");
			outScore << score;
			outScore.close();
			gotoxy(17, 19);
			cout << "CONGRATULATION ! YOU BEAT THE HIGH SCORE !";
			_getch();
			if (x == 13)
			{
				score = 0;
				for (int i = 0; i < CANH - 1; i++)
				for (int j = 0; j < CANH - 1; j++)
				{
					Matrix[i][j] = 0;
				}
				Choi();
			}
		}
			switch (x){
			case 80: Xuong(themSo, Matrix, Diem, delay, score);		break;
			case 72: Len(themSo, Matrix, Diem, delay, score);		break;
			case 77: Phai(themSo, Matrix, Diem, delay, score);	    break;
			case 75: Trai(themSo, Matrix, Diem, delay, score);		break;
			default: KiTuKep = true;	break;
			}
			if (themSo) ThemSo(Matrix);
			// Nếu có kí tự kép thì bỏ qua việc thêm số
			if (KiTuKep){
				KiTuKep = false;
				continue;
			}
		} while (!ThuaCuoc(Matrix));

	// Xử lý thua
	if (ThuaCuoc(Matrix))
	{
		gotoxy(27, 19);
		SetBGColor(1);
		Setcolor(14);
		cout << "YOU LOSE ! GAME OVER !";	
		move = _getch();
		for (int i = 0; i < CANH - 1; i++)
		for (int j = 0; j < CANH - 1; j++)
		{
			Matrix[i][j] = 0;
		}
		Choi();
	}
}