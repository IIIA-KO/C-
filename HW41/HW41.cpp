#include <iostream>
#include <iomanip>
#include<conio.h>
#include <Windows.h>
#define BACKGROUND 1
#define FOREGROUNG 15
#define SELECTITEMMENU 15
#define LEFTMENU 80
#define TOPMENU 15
using namespace std;

void SetColor(unsigned short backColor, unsigned short foreColor) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD color = ((backColor & 0x0F) << 4) + (foreColor & 0x0F);
	SetConsoleTextAttribute(h, color);
}
void SetСursor(unsigned short row, unsigned short col) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord{ col, row };
	SetConsoleCursorPosition(h, coord);
}
void paintMenu(const char** textMenu, size_t sizeMenu, size_t select = 0) {
	system("cls");
	SetСursor(TOPMENU, LEFTMENU);
	cout << "...............MENU..............." << endl;
	for (size_t i = 0; i < sizeMenu; i++)
	{
		SetСursor(TOPMENU + i + 1, LEFTMENU);
		if (i == select) {
			SetColor(BACKGROUND, SELECTITEMMENU);
			cout << "=> " << textMenu[i] << endl;
		}
		else {
			cout << "  " << textMenu[i] << endl;
		}
		SetColor(BACKGROUND, FOREGROUNG);
	}
}
size_t Menu(const char** textMenu, size_t sizeMenu, size_t select = 0) {
	unsigned char c = 80;
	while (true)
	{
		if (c == 72 || c == 80)
			paintMenu(textMenu, sizeMenu, select);
		c = _getch();
		switch (c) {
		case 13:
			return select;
		case 72:
			if (select == 0) select = sizeMenu;
			select--;
			break;
		case 80:
			select++;
			if (select == sizeMenu) select = 0;
			break;
		}
	}
	return 0;
}

void SetRandomToFile(const char* fname) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "wb");
	if (nError) {
		cout << "Error write file: " << fname << "\tError:" << nError << endl;
		return;
	}

	srand(time(0));
	int a = -100, b = 100, c = 1, size;
	size = c + rand() % (b - c + 1);
	int buf;
	for (int i = 0; i < size; i++) {
		buf = a + (int)(b - a) * rand() / RAND_MAX;
		fwrite(&buf, sizeof(buf), 1, fs);
	}
	fclose(fs);
}
int Count_Nums(const char* fname) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "rb");
	if (nError) {
		cout << "Error read file: " << fname << "\tError:" << nError << endl;
		exit(3);
	}
	fseek(fs, 0, SEEK_END);
	int count = ftell(fs) / sizeof(count);
	fseek(fs, 0, SEEK_SET);
	fclose(fs);
	return count;
}
int Sum(const char* fname) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "rb");
	if (nError) {
		cout << "Error file: " << fname << "\tError:" << nError << endl;
		exit(3);
	}
	int sum = 0, num;
	for (int i = 0; i < Count_Nums(fname); i++) {
		fread(&num, sizeof(num), 1, fs);
		sum += num;
	}
	fclose(fs);
	return sum;
}
double Avg(const char* fname) {
	double avg = 0;
	avg = double(Sum(fname)) / Count_Nums(fname);
	return avg;
}
void OutPutAvg(const char* fname) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "rb");
	if (nError) {
		cout << "Error read file: " << fname << "\tError:" << nError << endl;
		exit(3);
	}
	int buf, avg = Avg(fname);
	for (int i = 0; i < Count_Nums(fname); i++) {
		fread(&buf, sizeof(buf), 1, fs);
		if (buf > avg)
			cout << buf << " ";
	}
	printf("\n");
	fclose(fs);
}
void Sort(const char* fname) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "r+b");
	if (nError) {
		cout << "Error sort file: " << fname << "\tError:" << nError << endl;
		exit(3);
	}
	int x, y;

	fseek(fs, 0, SEEK_END);
	int size = ftell(fs) / sizeof(size);
	fseek(fs, 0, SEEK_SET);

	for (int i = 0; i < size; i++) {
		fread(&x, sizeof(x), 1, fs);
		fread(&y, sizeof(y), 1, fs);
		for (int j = 0; j < size - 1; j++) {
			if (x > y) {
				fseek(fs, -8, SEEK_CUR);
				fwrite(&y, sizeof(y), 1, fs);
				fseek(fs, 4, SEEK_CUR);
				fwrite(&x, sizeof(x), 1, fs);
			}
			fseek(fs, -4, SEEK_CUR);
		}
		fseek(fs, 0, SEEK_SET);
	}
	fclose(fs);
}
void Print(const char* fname) {
	FILE* fs = 0;
	int nError = fopen_s(&fs, fname, "rb");
	if (nError) {
		cout << "Error sort file: " << fname << "\tError:" << nError << endl;
		exit(3);
	}
	int buf;
	for (int i = 0; i < Count_Nums(fname); i++) {
		fread(&buf, sizeof(buf), 1, fs);
		cout << buf << " ";
	}
	cout << endl;
	fclose(fs);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char* textMenu[]{
		"1) Create Array",
		"2) Count numbers",
		"3) Count sum",
		"4) Count average",
		"5) Output numbers bigger than avarage",
		"6) Sort",
		"7) Exit"
	};
	size_t sizeMenu = sizeof(textMenu) / sizeof(*textMenu);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");
	size_t select = 0;

	const char* fname = "array.bin";

	while (true)
	{
		select = Menu(textMenu, sizeMenu, 0);
		system("cls");
		switch (select)
		{
		case 6:
			return select;

		case 0:
			SetRandomToFile(fname);
			Print(fname);
			break;

		case 1:
			cout << "Count of numbers: " << Count_Nums(fname) << endl;
			break;

		case 2:
			cout << "Sum of elements: " << Sum(fname) << endl;
			break;

		case 3:
			cout << "Avarage of all numbers: " << Avg(fname) << endl;
			break;

		case 4:
			cout << "Numbers bigger than avarage: "; OutPutAvg(fname);
			break;

		case 5:
			Sort(fname);
			Print(fname);
			break;

		default:
			break;
		}
		cout << "---DONE---\n";
		_getch();
	}
	return 0;
}