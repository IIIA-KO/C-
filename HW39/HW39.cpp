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
	WORD color = ((backColor & 0x0F) << 4) + (foreColor & 0x0F);//15;
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

void SetRandom(int arr[], int& size, int a, int b) {
	srand(time(0));
	int c = 1, d = 100;
	size = c + rand() % (d - c + 1);
	for (int i = 0; i < size; i++)
		arr[i] = a + (int)(b - a) * rand() / RAND_MAX;
}
void SaveArr(const char* fname, int* arr, int n) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "wt");
	if (nError) {
		cout << "Error write file: " << fname << "\tError:" << nError << endl;
		return;
	}
	fprintf(fs, "%d\n", n);
	for (int i = 0; i < n; i++)
		fprintf(fs, "%d ", arr[i]);
	fclose(fs);
}
int ArrSum(int* arr, int n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += arr[i];
	}
	return s;
}
double Avg(int* arr, int sum, int count) {
	return double(sum) / count;
}
void Clear(const char* fname) {
	FILE* fs;
	int nError = fopen_s(&fs, fname, "wt");
	if (nError) {
		cout << "Error clear file: " << fname << "\tError:" << nError << endl;
		exit(3);
	}
	fclose(fs);
}
void SortArr(int* arr, size_t size) {
	for (int j = 0; j < size - 1; j++) {
		int min = j;
		for (int i = j + 1; i < size; i++)
			if (arr[i] < arr[min])
				min = i;
		swap(arr[j], arr[min]);
	}
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
		"5) Sort",
		"6) Exit"
	};
	size_t sizeMenu = sizeof(textMenu) / sizeof(*textMenu);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");
	size_t select = 0;
	int n;
	int* arr = new int[] {0};

	const char* filename = "Array.txt";
	int N = 1;
	int* mas = new int[N];
	while (true)
	{
		select = Menu(textMenu, sizeMenu, 0);
		system("cls");
		switch (select)
		{
		case 5:
			return select;

		case 0:
			SetRandom(mas, N, -100, 100);
			SaveArr(filename, mas, N);
			break;

		case 1:
			cout << "Count of numbers = " << N << endl;
			break;

		case 2:
			cout << "Sum of numbers = " << ArrSum(mas, N) << endl;
			break;

		case 3:
			cout << "Average = " << Avg(mas, ArrSum(mas, N), N) << endl;
			break;

		case 4: {
			Clear(filename);
			SortArr(mas, N);
			SaveArr(filename, mas, N);
		}
			  break;

		default:
			break;
		}
		cout << "---DONE---\n";
		_getch();
	}
	return 0;
}
