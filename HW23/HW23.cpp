#include <iostream>
using namespace std;

template<typename R>
void SetRandom(R arr[], int n, R a, R b) {
	for (int i = 0; i < n; i++) {
		arr[i] = a + (double)(b - a) * rand() / RAND_MAX;
	}
}

template<class T>
void Print(T* a, size_t n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t" << " | ";
	}
}

void Char_Enter(char* arr, size_t size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter [" << i << "] element of char array: "; cin >> arr[i];
	}
}

template <typename T>
void Swap_variables(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename G>
void Insert_sort(G* arr, size_t size, int a = 0) {
	cout << "Your generated array: " << endl;
	Print(arr, size);
	cout << endl;
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
			G tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
		}
	}
}

template <typename R>
void Choice_sort(R* arr, size_t size, int a = 0) {
	cout << "Your generated array: " << endl;
	Print(arr, size);
	cout << endl;
	for (int j = 0; j < size - 1; j++) {
		int min = j;
		for (int i = j + 1; i < size; i++) {
			if (arr[i] < arr[min]) {
				min = i;
			}
		}
		R temp = arr[min];
		arr[min] = arr[j];
		arr[j] = temp;
	}
}

template<typename B>
void Bubble_sort(B* arr, size_t size, int a = 0) {
	cout << "Your generated array: " << endl;
	Print(arr, size);
	cout << endl;
	bool isSorted = true;
	int i = 0;
	do
	{
		isSorted = true;
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				B temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				isSorted = false;
			}
		}
		i++;
	} while (!isSorted);
}

int pos = 0;
template<typename F>
void Find(F* arr, size_t size, F elem) {
	bool found = false;
	for (int i = 0; i < size; i++) {
		if (arr[i] == elem) {
			cout << "Element found the " << i << " index" << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "There is no element that you are looking for" << endl;
	}
}

template <typename BF>
void BinSearch(BF* arr, int size, BF elem) {
	int l = 0, r = size;
	while (r >= l)
	{
		int m = (l + r) / 2;
		if (arr[m] == elem)
		{
			cout << "Index: " << m << endl;
			break;
		}
		else if (arr[m] < elem)
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
}

template<typename C>
void Change(C* arr, C elem, size_t ind) {
	arr[ind] = elem;
}

template <typename R>
void Reverse(R* arr, size_t size) {
	int j = size - 1;
	R temp;
	for (int i = 0; i < size / 2; i++) {
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		j--;
	}
}

int main()
{
	srand(time(0));
	{
		//Завдання 1
		cout << "+==============================================================================+" << endl;
		cout << "Swap 2 variables" << endl;
		int a, b; double c, d; char f, g; const char* x = "Anna"; const char* y = "Bob";

		cout << "Enter int variable a: "; cin >> a;
		cout << "Enter int variable b: "; cin >> b;
		Swap_variables(a, b);
		cout << "Variable a: " << a << endl;
		cout << "Variable b: " << b << endl << endl;

		cout << "Enter double variable c: "; cin >> c;
		cout << "Enter double variable d: "; cin >> d;
		Swap_variables(c, d);
		cout << "Variable double c: " << c << endl;
		cout << "Variable double d: " << d << endl << endl;

		cout << "Enter char variable f: "; cin >> f;
		cout << "Enter char variable g: "; cin >> g;
		Swap_variables(f, g);
		cout << "Variable f: " << f << endl;
		cout << "Variable g: " << g << endl << endl;

		cout << "x variable = Anna" << endl;
		cout << "y variable = Bob" << endl;
		Swap_variables(x, y);
		cout << "Variable x: " << x << endl;
		cout << "Variable y: " << y << endl;
		cout << "+==============================================================================+" << endl << endl << endl;
	}

	{
		//Завдання 2
		cout << "+==============================================================================+" << endl;
		cout << "Insert sort: " << endl;
		const int size = 5;
		int arr[size];
		double array[size];
		char mas[size];
		const char* ar[size]{ "Mary", "Sam", "John", "Jack", "Bob" };

		SetRandom(arr, size, -10, 10);
		Insert_sort(arr, size, 0);
		cout << "Sort by inserts (int): " << endl;
		Print(arr, size);
		cout << endl << endl;

		SetRandom(array, size, -10.0, 10.0);
		Insert_sort(array, size, 0);
		cout << "Sort by inserts (double): " << endl;
		Print(array, size);
		cout << endl << endl;

		Char_Enter(mas, size);
		Insert_sort(mas, size, 0);
		cout << "Sort by inserts (char): " << endl;
		Print(mas, size);
		cout << endl << endl;

		Insert_sort(ar, size);
		cout << "Sort by inserts (char*): " << endl;
		Print(ar, size);
		cout << endl;
		cout << "+==============================================================================+" << endl << endl << endl;

	}

	{
		//Завдання 3
		cout << "+==============================================================================+" << endl;
		cout << "Sort by choice: " << endl;
		const int size = 5;
		int arr[size];
		double array[size];
		char mas[size];
		const char* ar[size]{ "Mary", "Sam", "John", "Jack", "Bob" };

		SetRandom(arr, size, -10, 10);
		Choice_sort(arr, size, 0);
		cout << "Sort by choice (int): " << endl;
		Print(arr, size);
		cout << endl << endl;

		SetRandom(array, size, -10.0, 10.0);
		Choice_sort(array, size, 0);
		cout << "Sort by choice (double): " << endl;
		Print(array, size);
		cout << endl << endl;

		Char_Enter(mas, size);
		Choice_sort(mas, size, 0);
		cout << "Sort by choice (char): " << endl;
		Print(mas, size);
		cout << endl << endl;

		Choice_sort(ar, size);
		cout << "Sort by choice (char*): " << endl;
		Print(ar, size);
		cout << endl;
		cout << "+==============================================================================+" << endl << endl << endl;
	}

	{
		//Завдання 4
		cout << "+==============================================================================+" << endl;
		cout << "Buuble sort: " << endl;
		const int size = 5;
		int arr[size];
		double array[size];
		char mas[size];
		const char* ar[size]{ "Mary", "Sam", "John", "Jack", "Bob" };

		SetRandom(arr, size, -10, 10);
		Bubble_sort(arr, size, 0);
		cout << "Bubble sort (int): " << endl;
		Print(arr, size);
		cout << endl << endl;

		SetRandom(array, size, -10.0, 10.0);
		Bubble_sort(array, size, 0);
		cout << "Bubble sort  (double): " << endl;
		Print(array, size);
		cout << endl << endl;

		Char_Enter(mas, size);
		Bubble_sort(mas, size, 0);
		cout << "Bubble sort  (char): " << endl;
		Print(mas, size);
		cout << endl << endl;

		Bubble_sort(ar, size);
		cout << "Bubble sort  (char*): " << endl;
		Print(ar, size);
		cout << endl;
		cout << "+==============================================================================+" << endl << endl << endl;
	}

	{
		//Завдання 5
		cout << "+==============================================================================+" << endl;
		cout << "Finding element in array" << endl;
		const int size = 5;
		int arr[size];
		double array[size];
		char mas[size];
		const char* ar[size]{ "Mary", "Sam", "John", "Jack", "Bob" };
		int elem;
		double lm;
		char elm;
		int lem;

		SetRandom(arr, size, -10, 10);
		cout << "Your generated int array: " << endl;
		Print(arr, size);
		cout << endl;
		cout << "Enter which element you want to find in int array: "; cin >> elem;
		Find(arr, size, elem);
		cout << endl << endl;

		SetRandom(array, size, -10.0, 10.0);
		cout << "Your generated double array: " << endl;
		Print(array, size);
		cout << endl;
		cout << "Enter which element you want to find in double array: "; cin >> lm;
		Find(array, size, lm);
		cout << endl << endl;

		Char_Enter(mas, size);
		cout << "Your char array: " << endl;
		Print(mas, size);
		cout << endl;
		cout << "Enter which element you want to find in char array: "; cin >> elm;
		Find(mas, size, elm);
		cout << endl << endl;

		cout << "Your char* array: " << endl;
		Print(ar, size);
		cout << endl;
		cout << "Element in char* will be chosen randomly" << endl;
		lem = rand() % (5);
		cout << "Random choice: " << lem << endl;
		cout << "Element found the " << lem << " index." << " It's " << ar[lem] << endl;
		cout << "+==============================================================================+" << endl << endl << endl;
	}


	{
		//Завдання 6
		cout << "+==============================================================================+" << endl;
		cout << "Finding element in sorted array" << endl;
		const int size = 5;
		int arr[size];
		double array[size];
		char mas[size];
		const char* ar[size]{ "Mary", "Sam", "John", "Jack", "Bob" };
		int elem;
		double ele;
		char el;
		int e;

		SetRandom(arr, size, -10, 10);
		Insert_sort(arr, size);
		cout << "Sorted: " << endl;
		Print(arr, size);
		cout << endl;
		cout << "Enter which element you want to find in int array: "; cin >> elem;
		BinSearch(arr, size, elem);
		cout << endl << endl;

		SetRandom(array, size, -10.0, 10.0);
		Insert_sort(array, size);
		cout << "Sorted: " << endl;
		Print(array, size);
		cout << endl;
		cout << "Enter which element you want to find in double array: "; cin >> ele;
		BinSearch(array, size, ele);
		cout << endl << endl;

		Char_Enter(mas, size);
		Insert_sort(mas, size);
		cout << "Sorted: " << endl;
		Print(mas, size);
		cout << endl;
		cout << "Enter which element you want to find in char array: "; cin >> el;
		BinSearch(mas, size, el);
		cout << endl << endl;

		cout << "Your char* array: " << endl;
		Print(ar, size);
		cout << endl;
		cout << "Element in char* will be chosen randomly" << endl;
		e = rand() % (5);
		cout << "Random choice: " << e << endl;
		cout << "Element found the " << e << " index." << " It's " << ar[e] << endl;
		cout << "+==============================================================================+" << endl << endl << endl;
	}

	{
		//Завдання 7
		cout << "+==============================================================================+" << endl;
		cout << "Exchange array element" << endl;
		const int size = 5;
		int arr[size];
		double array[size];
		char mas[size];
		const char* ar[size]{ "Mary", "Sam", "John", "Jack", "Bob" };

		int int_ind, int_s_ind, d_ind, d_s_ind, c_ind, c_s_ind, cx_ind, cx_s_ind;

		SetRandom(arr, size, -10, 10);
		cout << "Your random generated int array: " << endl;
		Print(arr, size);
		cout << endl;

		cout << "Choose index of element of int array you want to change: "; cin >> int_ind;
		cout << "Choose index of second element of int array you want to change: "; cin >> int_s_ind;
		Swap_variables(arr[int_ind], arr[int_s_ind]);
		
		cout << "Changed: " << endl;
		Print(arr, size);
		cout << endl << endl;

		SetRandom(array, size, -10.0, 10.0);
		cout << "Your random generated double array: " << endl;
		Print(array, size);
		cout << endl;

		cout << "Choose index of element of double array you want to change: "; cin >> d_ind;
		cout << "Choose index of second element of double array you want to change: "; cin >> d_s_ind;
		Swap_variables(array[d_ind], array[d_s_ind]);

		cout << "Changed: " << endl;
		Print(array, size);
		cout << endl << endl;

		Char_Enter(mas, size);
		cout << "Your generated char array: " << endl;
		Print(mas, size);
		cout << endl;

		cout << "Choose index of element of char array you want to change: "; cin >> c_ind;
		cout << "Choose index of second element of char array you want to change: "; cin >> c_s_ind;
		Swap_variables(mas[c_ind], mas[c_s_ind]);
		
		cout << "Changed: " << endl;
		Print(mas, size);
		cout << endl << endl;

		cout << "Your char* array: " << endl;
		Print(ar, size);
		cout << endl;

		cout << "Choose index of element of int array you want to change: "; cin >> cx_ind;
		cout << "Choose index of second element of int array you want to change: "; cin >> cx_s_ind;
		Swap_variables(ar[cx_ind], ar[cx_s_ind]);

		cout << "Changed: " << endl;
		Print(ar, size);
		cout << endl;
		cout << "+==============================================================================+" << endl << endl << endl;
	}

	{
		//Завдання 8
		cout << "+==============================================================================+" << endl;
		cout << "Array reverse: " << endl;
		const int size = 5;
		int arr[size];
		double array[size];
		char mas[size];
		const char* ar[size]{ "Mary", "Sam", "John", "Jack", "Bob" };

		SetRandom(arr, size, -10, 10);
		cout << "Your random generated int array: " << endl;
		Print(arr, size);
		cout << endl;
		Reverse(arr, size);
		cout << "Reversed: " << endl;
		Print(arr, size);
		cout << endl << endl;

		SetRandom(array, size, -10.0, 10.0);
		cout << "Your random generated double array: " << endl;
		Print(array, size);
		cout << endl;
		Reverse(array, size);
		cout << "Reversed: " << endl;
		Print(array, size);
		cout << endl << endl;

		Char_Enter(mas, size);
		cout << "Your generated char array: " << endl;
		Print(mas, size);
		cout << endl;
		Reverse(mas, size);
		cout << "Reversed: " << endl;
		Print(mas, size);
		cout << endl << endl;

		cout << "Your char* array: " << endl;
		Print(ar, size);
		cout << endl;
		Reverse(ar, size);
		cout << "Reversed: " << endl;
		Print(ar, size);
		cout << endl;
		cout << "+==============================================================================+" << endl << endl << endl;
	}
	return 0;
}