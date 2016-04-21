#define CANH 4
#include <iostream>
#include <conio.h>
#include "XuLyPhu.h"
#include "XuLy.h"

// Phương thức private:
// Tạo số
int XuLy::TaoSo()
{
	int a = rand() % 20;
	if (!a) return 2;	// Điền giá trị 4 với xác xuất thấp
	else return 1;		// Điền giá trị 2 với xác xuất cao
}

// Kiểm tra còn ô trống
bool XuLy::ConOTrong(int Matrix[CANH][CANH])
{
	bool kq = false;
	for (int i = 0; i<CANH; i++){
		for (int j = 0; j<CANH; j++){
			if (!Matrix[i][j]){
				kq = true;
			}
		}
	}
	return kq;
}

// Đổi chỗ các dòng
void XuLy::DoiChoDong(int &i, int &vt1, int &vt2, int Matrix[CANH][CANH]){
	int temp = Matrix[i][vt1];
	Matrix[i][vt1] = Matrix[i][vt2];
	Matrix[i][vt2] = temp;
}

// Đổi chỗ các cột
void XuLy::DoiChoCot(int &j, int &vt1, int &vt2, int Matrix[CANH][CANH]){
	int temp = Matrix[vt1][j];
	Matrix[vt1][j] = Matrix[vt2][j];
	Matrix[vt2][j] = temp;
}

// Gom xuống
void XuLy::GomXuong(int &j, int &i, int &vt1, int &vt2, bool &themSo, int Matrix[CANH][CANH], string Diem[14], int delay){
	for (j = CANH - 1; j>0; j--){
		if (!Matrix[i][j]){
			vt1 = vt2 = j; // Đánh dấu vị trí ô trống bằng vt1 và vt2

			// Dùng vị trí vt2 để tìm ra ô có giá trị
			do{
				vt2--;
				if (vt2 == 0)
					break;
			} while (!Matrix[i][vt2]);

			// Nếu tại vị trí vt2 có giá trị
			if (vt2 || (!vt2 && Matrix[i][vt2])){
				// Dùng vòng lặp chạy từ vị trí vt2 đến vị trí vt1 để xử lý việc in ra màn hình
				for (int k = vt2 * 2 + 3 + 1; k < vt1 * 2 + 3 + 1; k++){
					// In ra khoảng trắng khi giá trị đang bị dời đi
					gotoxy(i * 5 + 1 + 27, vt2 * 2 + 3);
					SetBGColor(7);
					Setcolor(1);
					cout << " ";
					
					// In giá trị cho các vị trí
					gotoxy(i * 5 + 1 + 27, k); cout << Diem[Matrix[i][vt2]];

					// Delay khi di chuyển
					sleep(delay);
				}

				// Đổi chỗ ô trống với ô có giá trị
				DoiChoDong(i, vt1, vt2, Matrix);
				themSo = true;
			}
		}
	}
}

// Gom lên
void XuLy::GomLen(int &j, int &i, int &vt1, int &vt2, bool &themSo, int Matrix[CANH][CANH], string Diem[14], int delay){
	for (j = 0; j < CANH - 1; j++){
		if (!Matrix[i][j]){
			vt1 = vt2 = j; // Đánh dấu vị trí ô trống bằng vt1 và vt2

			// Dùng vị trí vt2 để tìm ra ô có giá trị
			do{
				vt2++;
				if (vt2 == CANH - 1)
					break;
			} while (!Matrix[i][vt2]);

			// Nếu tại vị trí vt2 có giá trị
			if (vt2!=CANH - 1 || (vt2==CANH - 1 && Matrix[i][vt2])){
				// Dùng vòng lặp chạy từ vị trí vt2 đến vị trí vt1 để xử lý việc in ra màn hình
				for (int k = vt2 * 2 + 3 + 1; k > vt1 * 2 + 3 + 1; k--){
					// In ra khoảng trắng khi giá trị đang bị dời đi
					gotoxy(i * 5 + 1 + 27, vt2 * 2 + 3);
					SetBGColor(7);
					Setcolor(1);
					cout << " ";

					// In giá trị cho các vị trí
					gotoxy(i * 5 + 1 + 27, k); cout << Diem[Matrix[i][vt2]];

					// Delay khi di chuyển
					sleep(delay);
				}

				// Đổi chỗ ô trống với ô có giá trị
				DoiChoDong(i, vt1, vt2, Matrix);
				themSo = true;
			}
		}
	}
}

// Gom phải
void XuLy::GomPhai(int &j, int &i, int &vt1, int &vt2, bool &themSo, int Matrix[CANH][CANH], string Diem[14], int delay){
	for (i = CANH - 1; i>0; i--){
		if (!Matrix[i][j]){
			vt1 = vt2 = i; // Đánh dấu vị trí ô trống bằng vt1 và vt2

			// Dùng vị trí vt2 để tìm ra ô có giá trị
			do{ 
				vt2--; 
				if (vt2 == 0) 
					break; 
			} while (!Matrix[vt2][j]);

			// Nếu tại vị trí vt2 có giá trị
			if (vt2 || (!vt2 && Matrix[vt2][j])){
				// Dùng vòng lặp chạy từ vị trí vt2 đến vị trí vt1 để xử lý việc in ra màn hình
				for (int k = vt2 * 5 + 1 + 1 + 27; k<vt1 * 5 + 1 + 1 + 27; k++){
					// In ra khoảng trắng khi giá trị đang bị dời đi
					gotoxy(vt2 * 5 + 1 + 27, j * 3 + 2);
					SetBGColor(7);
					Setcolor(1);
					cout << " ";

					// In giá trị cho các vị trí
					gotoxy(k, j * 3 + 2); cout << Diem[Matrix[vt2][j]];

					// Delay khi di chuyển
					sleep(delay);
				}
				
				// Đổi chỗ ô trống với ô có giá trị
				DoiChoCot(j, vt1, vt2, Matrix);
				themSo = true;
			}
		}
	}
}

// Gom trái
void XuLy::GomTrai(int &j, int &i, int &vt1, int &vt2, bool &themSo, int Matrix[CANH][CANH], string Diem[14], int delay){
	for (i = 0; i < CANH - 1; i++){
		if (!Matrix[i][j]){
			vt1 = vt2 = i; // Đánh dấu vị trí ô trống bằng vt1 và vt2

			// Dùng vị trí vt2 để tìm ra ô có giá trị
			do{
				vt2++;
				if (vt2 == CANH - 1)
					break;
			} while (!Matrix[vt2][j]);

			// Nếu tại vị trí vt2 có giá trị
			if (vt2!=CANH - 1 || (vt2==CANH - 1 && Matrix[vt2][j])){
				// Dùng vòng lặp chạy từ vị trí vt2 đến vị trí vt1 để xử lý việc in ra màn hình
				for (int k = vt2 * 5 + 1 + 1 + 27; k > vt1 * 5 + 1 + 1 + 27; k--){
					// In ra khoảng trắng khi giá trị đang bị dời đi
					gotoxy(vt2 * 5 + 1 + 27, j * 3 + 2);
					SetBGColor(7);
					Setcolor(1);
					cout << " ";

					// In giá trị cho các vị trí
					gotoxy(k, j * 3 + 2); cout << Diem[Matrix[vt2][j]];

					// Delay khi di chuyển
					sleep(delay);
				}

				// Đổi chỗ ô trống với ô có giá trị
				DoiChoCot(j, vt1, vt2, Matrix);
				themSo = true;
			}
		}
	}
}

// Cộng dồn xuống
void XuLy::CongXuong(int &j, int &i, bool &themSo, int &score, int Matrix[CANH][CANH]){
	for (j = CANH - 1; j > 0; j--){
		if (Matrix[i][j] != 0 && Matrix[i][j] == Matrix[i][j - 1]){
			Matrix[i][j]++;
			TinhScore(score, j, i, Matrix);
			Matrix[i][j - 1] = 0;
			themSo = true;
		}
	}
}

// Cộng dồn lên
void XuLy::CongLen(int &j, int &i, bool &themSo, int &score, int Matrix[CANH][CANH]){
	for (j = 0; j < CANH - 1; j++){
		if (Matrix[i][j] != 0 && Matrix[i][j] == Matrix[i][j + 1]){
			Matrix[i][j]++;
			TinhScore(score, j, i, Matrix);
			Matrix[i][j + 1] = 0;
			themSo = true;
		}
	}
}

// Cộng dồn phải
void XuLy::CongPhai(int &j, int &i, bool &themSo, int &score, int Matrix[CANH][CANH]){
	for (i = CANH - 1; i > 0; i--){
		if (Matrix[i][j] != 0 && Matrix[i][j] == Matrix[i - 1][j]){
			Matrix[i][j]++;
			TinhScore(score, j, i, Matrix);
			Matrix[i - 1][j] = 0;
			themSo = true;
		}
	}
}

// Cộng dồn trái
void XuLy::CongTrai(int &j, int &i, bool &themSo, int &score, int Matrix[CANH][CANH]){
	for (i = 0; i < CANH - 1; i++){
		if (Matrix[i][j] != 0 && Matrix[i][j] == Matrix[i + 1][j]){
			Matrix[i][j]++;
			TinhScore(score, j, i, Matrix);
			Matrix[i + 1][j] = 0;
			themSo = true;
		}
	}
}

// Tính score
void XuLy::TinhScore(int &score, int &j, int &i, int Matrix[CANH][CANH]){
	// Cách tính score = score + 2^i (1 <= i <= 13)
	score += (int)pow(2, Matrix[i][j]);
}

// Phương thức public:
// Thêm số
void XuLy::ThemSo(int Matrix[CANH][CANH])
{
	int i, j;
	// Kiểm tra còn chỗ trống không
	bool ConCho = false;
	for (int i = 0; i<CANH; i++){
		for (int j = 0; j<CANH; j++){
			if (!Matrix[i][j]){
				ConCho = true;
				break;
			}
		}
	}

	// Nếu còn chỗ trống thì chọn chỗ trống ngẫu nhiên để tạo giá trị
	if (ConCho){
		do{
			i = rand() % CANH;
			j = rand() % CANH;
		} while (Matrix[i][j]);
		Matrix[i][j] = TaoSo();
	}
}

// Kiểm tra thua cuộc
bool XuLy::ThuaCuoc(int Matrix[CANH][CANH])
{
	// Còn ô trống
	bool kq1, kq2;
	if (ConOTrong(Matrix)) {
		kq1 = true;
	}

	// Còn 2 ô cạnh nhau có cùng giá trị
	for (int i = 0; i<CANH - 1; i++){
		for (int j = 0; j<CANH - 1; j++){
			if (Matrix[i][j] == Matrix[i][j + 1] || Matrix[i][j] == Matrix[i + 1][j]){
				kq2 = true;
			}
		}
	}

	// Nếu không thỏa 2 điều kiện trên thì thua
	if ((!kq1) && (!kq2)) return true;
	else return false;
}

// Xử lý xuống
void XuLy::Xuong(bool &themSo, int Matrix[CANH][CANH], string Diem[14], int delay, int &score)
{
	int i, j, vt1, vt2;

	// Dùng vòng lặp để xử lý cho 4 cột
	for (i = 0; i < CANH; i++){
		// Gom xuống
		GomXuong(j, i, vt1, vt2, themSo, Matrix, Diem, delay);

		// Cộng dồn xuống 2 ô có cùng giá trị
		CongXuong(j, i, themSo, score, Matrix);
		
		// Gom xuống một lần nữa
		GomXuong(j, i, vt1, vt2, themSo, Matrix, Diem, delay);
	}
}

// Xử lý lên
void XuLy::Len(bool &themSo, int Matrix[CANH][CANH], string Diem[14], int delay, int &score)
{
	int i, j, vt1, vt2;

	// Dùng vòng lặp để xử lý cho 4 cột
	for (i = 0; i < CANH; i++){
		// Gom lên
		GomLen(j, i, vt1, vt2, themSo, Matrix, Diem, delay);

		// Cộng dồn lên 2 ô có cùng giá trị
		CongLen(j, i, themSo, score, Matrix);

		// Gom lên một lần nữa
		GomLen(j, i, vt1, vt2, themSo, Matrix, Diem, delay);
	}
}

// Xử lý phải
void XuLy::Phai(bool &themSo, int Matrix[CANH][CANH], string Diem[14], int delay, int &score)
{
	int i, j, vt1, vt2;

	// Dùng vòng lặp để xử lý cho 4 dòng
	for (j = 0; j < CANH; j++){
		// Gom phải
		GomPhai(j, i, vt1, vt2, themSo, Matrix, Diem, delay);

		// Cộng dồn phải 2 ô có cùng giá trị
		CongPhai(j, i, themSo, score, Matrix);

		// Gom phải một lần nữa
		GomPhai(j, i, vt1, vt2, themSo, Matrix, Diem, delay);
	}
}

// Xử lý trái
void XuLy::Trai(bool &themSo, int Matrix[CANH][CANH], string Diem[14], int delay, int &score)
{
	int i, j, vt1, vt2;

	// Dùng vòng lặp để xử lý cho 4 dòng
	for (j = 0; j < CANH; j++){
		// Gom trái
		GomTrai(j, i, vt1, vt2, themSo, Matrix, Diem, delay);

		// Cộng dồn trái 2 ô có cùng giá trị
		CongTrai(j, i, themSo, score, Matrix);

		// Gom trái một lần nữa
		GomTrai(j, i, vt1, vt2, themSo, Matrix, Diem, delay);
	}
}

