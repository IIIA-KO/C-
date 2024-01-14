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

template<typename T>
T* createArr(int n) {
	return new T[n]{ 0 };
}
template<typename R>
void SetRandom(R arr[], int n, R a, R b) {
	for (int i = 0; i < n; i++) {
		arr[i] = a + (double)(b - a) * rand() / RAND_MAX;
	}
}
template<typename P>
void Print(P arr[], int n) {
	cout << "Array:" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
template<class T>
void AddPos(T*& arr, int& n, int pos, T val) {
	if (!arr || pos > n)
	{
		cout << "Error\n";
		return;
	}
	T* temp = new T[n + 1];
	for (size_t i = 0; i < pos; i++)
		temp[i] = arr[i];
	temp[pos] = val;
	for (size_t i = pos; i < n; i++)
		temp[i + 1] = arr[i];
	delete[] arr;
	arr = temp;
	n++;
}
void Delete(int*& mas, int& n, int pos) {
	if (!mas || n < 1 || pos >= n)
	{
		cout << "Error delete element" << endl;
		return;
	}
	int* temp = new int[n - 1];
	for (size_t i = 0; i < pos; i++)
	{
		temp[i] = mas[i];
	}
	for (size_t i = pos + 1; i < n; i++)
	{
		temp[i - 1] = mas[i];
	}
	--n;
	delete[] mas;
	mas = temp;
}
void Sort(int* array, int number) {
	for (int j = 0; j < number - 1; j++) {
		int min = j;
		for (int i = j + 1; i < number; i++)
			if (array[i] < array[min])
				min = i;

		int temp = array[min];
		array[min] = array[j];
		array[j] = temp;
	}
}
void Sortdes(int* array, int number) {
	for (int i = 0; i < number - 1; i++)
		for (int j = 0; j < number - 1; j++)
			if (array[j] < array[j + 1]) {
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
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

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char* textMenu[]{
		"1) Create Array",
		"2) Set array with random values",
		"3) Output array",
		"4) Add element to the start of array",
		"5) Add element to the entered position in array",
		"6) Add element to the end of array",
		"7) Delete element at the start of array",
		"8) Delete element at the entered position in array",
		"9) Delete element at the end of array",
		"10) Sort array by encreasing",
		"11) Sort array by in descending order",
		"12) Exit"
	};
	size_t sizeMenu = sizeof(textMenu) / sizeof(*textMenu);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");
	size_t select = 0;
	int n;
	int* arr = new int[] {0};

	while (true)
	{
		select = Menu(textMenu, sizeMenu, 0);
		system("cls");
		switch (select)
		{
		case 11:
			return select;

		case 0:
			cout << "Enter size of array: "; cin >> n;
			arr = createArr<int>(n);
			break;

		case 1:
			SetRandom<int>(arr, n, -10, 10);
			break;

		case 2:
			Print(arr, n);
			break;

		case 3:
			int ele;
			cout << "Enter element: "; cin >> ele;
			AddPos(arr, n, 0, ele);
			Print(arr, n);
			break;

		case 4:
			int pos, elem;
			cout << "Enter position: "; cin >> pos;
			cout << "Enter element: "; cin >> elem;
			AddPos(arr, n, pos, elem);
			Print(arr, n);
			break;

		case 5:
			int el;
			cout << "Enter element: "; cin >> el;
			AddPos(arr, n, n, el);
			cout << "Your array: " << endl;
			Print(arr, n);
			break;

		case 6:
			Delete(arr, n, 0);
			Print(arr, n);
			break;

		case 7:
			int indx;
			cout << "Enter position: "; cin >> indx;
			Delete(arr, n, indx);
			Print(arr, n);
			break;

		case 8:
			Delete(arr, n, n - 1);
			Print(arr, n);
			break;

		case 9:
			Sort(arr, n);
			Print(arr, n);
			break;

		case 10:
			Sortdes(arr, n);
			Print(arr, n);
			break;

		default:
			break;
		}
		cout << "---DONE---\n";
		_getch();
	}
	return 0;
}
