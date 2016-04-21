#pragma once
#include <Windows.h>
void gotoxy(int cot, int dong);
void clear();
void pause();
void sleep(int thoigian);
void resizeBuffer(int width, int height);
void Nocursortype();
void Setcolor(WORD color);
void SetBGColor(WORD color);