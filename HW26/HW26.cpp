#include <iostream>
#include <iomanip>
using namespace std;

void StaticArrTest();
template<class T>
T** CreateArr2D(size_t r, size_t c) {
	T** arr = new T * [r];
	for (size_t i = 0; i < r; i++)
		arr[i] = new T[c]{ 0 };
	return arr;
}

template<class T>
void PrintArr(T** arr, size_t r, size_t c) {
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
			cout << setw(12) << arr[i][j];
		cout << "\n";
	}
	cout << "\n";
}

template<class T>
void SetRandomArr(T** arr, size_t r, size_t c, T a, T b) {
	for (size_t i = 0; i < r; i++)
		for (size_t j = 0; j < c; j++) {
			double k = rand() / (double)RAND_MAX;//[0...1]
			arr[i][j] = a + (b - a) * k;
		}
}
template<class T>
void Delete2D(T**& arr, size_t r)
{
	for (size_t i = 0; i < r; i++)
		delete[] arr[i];
	delete[] arr;
	arr = nullptr;
}

template<class T>
void AddElementPosition(T*& arr, size_t& n, size_t pos, T val)
{
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

template<class T>
void AddRowPosition(T**& arr, size_t& r, size_t c, size_t pos)
{
	if (!arr || pos > r)
	{
		cout << "Error\n";
		return;
	}
	T** temp = new T * [r + 1];
	for (size_t i = 0; i < pos; i++)
		temp[i] = arr[i];
	temp[pos] = new T[c]{ 0 };
	for (size_t i = pos; i < r; i++)
		temp[i + 1] = arr[i];
	delete[] arr;
	arr = temp;
	r++;
}
void Task3() {
	size_t r = 4, c = 5, pos;
	int** mas = CreateArr2D<int>(r, c);
	cout << "Position: "; cin >> pos;

	SetRandomArr(mas, r, c, -10, 10);
	PrintArr(mas, r, c);
	AddRowPosition<int>(mas, r, c, pos);
	PrintArr(mas, r, c);
	Delete2D(mas, r);
}

template<class T>
void AddRowBack(T**& arr, size_t& r, size_t c)
{
	AddRowPosition(arr, r, c, r);
}
void Task1() {
	size_t r = 4, c = 5;
	int** mas = CreateArr2D<int>(r, c);
	SetRandomArr(mas, r, c, -10, 10);
	PrintArr(mas, r, c);
	AddRowBack<int>(mas, r, c);
	PrintArr(mas, r, c);
	Delete2D(mas, r);
}

template<class T>
void AddRowFront(T**& arr, size_t& r, size_t c)
{
	AddRowPosition(arr, r, c, 0);
}
void Task2() {
	size_t r = 4, c = 5;
	int** mas = CreateArr2D<int>(r, c);
	SetRandomArr(mas, r, c, -10, 10);
	PrintArr(mas, r, c);
	AddRowFront<int>(mas, r, c);
	PrintArr(mas, r, c);
	Delete2D(mas, r);
}

template<class T>
void DeleteRowPosition(int**& mas, int& r, int c, int pos) {
	if (!mas || pos < 0 || r < 1 || pos >= r)
	{
		cout << "Error" << endl;
		return;
	}

	T** arr = new T * [r - 1];
	for (size_t i = 0; i < pos; i++)


		arr[i] = mas[i];

	for (size_t i = pos + 1; i < r; i++)
		arr[i - 1] = mas[i];

	delete[] mas;
	mas = arr;
	r--;
}
void Task4() {
	int r = 4, c = 5, pos;
	int** mas = CreateArr2D<int>(r, c);
	cout << "Pos: "; cin >> pos;
	SetRandomArr(mas, r, c, -10, 10);
	PrintArr(mas, r, c);
	DeleteRowPosition<int>(mas, r, c, pos);
	PrintArr(mas, r, c);
	Delete2D(mas, r);
}

template<class T>
void AddColumnPosition(T**& arr, size_t r, size_t& c, size_t pos)
{
	if (!arr || pos > c)
	{
		cout << "Error\n";
		return;
	}
	for (size_t i = 0; i < r; i++) {
		size_t t = c;
		AddElementPosition(arr[i], t, pos, 0);
	}
	c++;
}
void Task5()
{
	size_t r = 4, c = 5;
	int pos;
	cout << "Position: "; cin >> pos;
	int** mas = CreateArr2D<int>(r, c);
	SetRandomArr(mas, r, c, -10, 10);
	PrintArr(mas, r, c);
	AddColumnPosition(mas, r, c, pos);
	PrintArr(mas, r, c);
	Delete2D(mas, r);
}

template<class T>
void DeleteElementPosition(T*& mas, size_t& n, size_t pos) {
	if (!mas || n < 1 || pos >= n)
	{
		cout << "Error delete element" << endl;
		return;
	}
	int* temp = new int[n - 1];
	for (size_t i = 0; i < pos; i++)
		temp[i] = mas[i];

	for (size_t i = pos + 1; i < n; i++)
		temp[i - 1] = mas[i];

	n--;
	delete[] mas;
	mas = temp;
}
template<class T>
void DeleteColumnPosition(int**& mas, int r, int& c, int pos) {
	if (!mas || pos > c)
	{
		cout << "Error\n";
		return;
	}
	for (size_t i = 0; i < r; i++) {
		size_t t = c;
		DeleteElementPosition(mas[i], t, pos);
	}
	c--;
}
void Task6() {
	int r = 4, c = 5, pos;
	int** mas = CreateArr2D<int>(r, c);
	cout << "Pos: "; cin >> pos;
	SetRandomArr(mas, r, c, -10, 10);
	PrintArr(mas, r, c);
	DeleteColumnPosition<int>(mas, r, c, pos);
	PrintArr(mas, r, c);
	Delete2D(mas, r);
}

int main()
{
	{
		//Завдання 1
		cout << "+===========================================================+" << endl;
		cout << "Inserting row the end of matrix: " << endl;
		Task1();
		cout << "+===========================================================+" << endl << endl;
	}
	{
		//Завдання 2
		cout << "+===========================================================+" << endl;
		cout << "Inserting row the front of matrix: " << endl;
		Task2();
		cout << "+===========================================================+" << endl << endl;
	}
	{
		//Завдання 3
		cout << "+===========================================================+" << endl;
		cout << "Inserting row the entered position of matrix: " << endl;
		Task3();
		cout << "+===========================================================+" << endl << endl;
	}
	{
		//Завдання 4
		cout << "+===========================================================+" << endl;
		cout << "Deleting row the entered position of matrix: " << endl;
		Task4();
		cout << "+===========================================================+" << endl << endl;
	}
	{
		//Завдання 5
		cout << "+===========================================================+" << endl;
		cout << "Inserting column the entered position of matrix: " << endl;
		Task5();
		cout << "+===========================================================+" << endl << endl;
	}
	{
		//Завдання 6
		cout << "+===========================================================+" << endl;
		cout << "Deleting column the entered position of matrix: " << endl;
		Task6();
		cout << "+===========================================================+" << endl << endl;
	}
}
