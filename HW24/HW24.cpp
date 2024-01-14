#include <iostream>
#define n 5
using namespace std;

void Print(int* arr, size_t size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << "\t";
	cout << endl;
}

void Copy(int* arr1, int* mas1, int* end) {
	for (; arr1 != end; ++arr1, ++mas1)
		*mas1 = *arr1;
}

void Reverse(int* arr, int* end) {
	while (arr != end)
	{
		int temp = *arr;
		*arr = *end;
		*end = temp;
		arr++;
		end--;
	}
}

void Reverse_copy(int* arr1, int* mas1, int* end, size_t size) {
	for (int i = 0; i < size; i++) {
		*mas1 = *end;
		mas1++;
		end--;
	}
}

int main()
{
	{
		//Завдання 1
		cout << "+=========================================================================+" << endl;
		int arr[n]{ 0, 1, 2, 3, 4 };
		int mas[n]{ 0 };
		int* arr1 = arr;
		int* mas1 = mas;
		int* end = arr1 + n;

		cout << "First array: " << endl;
		Print(arr, n);
		cout << "Second array (it's actually empty now): " << endl;
		Print(mas, n);
		cout << "Copied: " << endl;
		Copy(arr1, mas1, end);
		Print(mas1, n);
		cout << "+=========================================================================+" << endl << endl << endl;
	}

	{
		//Завдання 2
		cout << "+=========================================================================+" << endl;
		int arr[n]{ 0, 1, 2, 3, 4 };
		cout << "Array: " << endl;
		Print(arr, n);

		int* arr1 = arr;
		int* end = &arr[n - 1];
		cout << "Reversed: " << endl;
		Reverse(arr1, end);
		Print(arr1, n);
		cout << "+=========================================================================+" << endl << endl << endl;
	}

	{
		//Завдання 3
		cout << "+=========================================================================+" << endl;
		int arr[n]{ 0, 1, 2, 3, 4 };
		int mas[n]{ 0 };
		int* arr1 = arr;
		int* mas1 = mas;
		int* end = arr1 + n - 1;

		cout << "First array: " << endl;
		Print(arr, n);
		cout << "Second array (it's actually empty now): " << endl;
		Print(mas, n);
		cout << "Reverse copied: " << endl;
		Reverse_copy(arr1, mas1, end, n);
		Print(mas1, n);
		cout << "+=========================================================================+" << endl << endl << endl;
	}
	return 0;
}
