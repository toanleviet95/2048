#pragma once
#include <string>
using namespace std;
#define CANH 4

// Giá trị của các ô trong trò chơi
string Diem[14] = { "    ", "  2 ", "  4 ", "  8 ", " 16 ", " 32 ", " 64 ", " 128", " 256", " 512", "1024", "2048", "4096", "8192" };

// Ma trận vuông 4x4 lưu giá trị các ô trong bảng
int Matrix[CANH][CANH];

// Thời gian delay trong game
int delay = 5;

// Điểm số
int score, highScore;

// Kiểm tra thêm số
bool themSo;

