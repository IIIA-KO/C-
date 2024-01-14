#include <iostream>
using namespace std;

void Print(int* arr, size_t size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << "\t" << " | ";
	cout << endl;
}

bool isPrime(int x)
{
	if (x > 1)
	{
		for (int i = 2; i < x; i++)
			if (x % i == 0)
				return false;
		return true;
	}
	else
		return false;
}

int* Del_Prime(int* arr, int size, int& n)
{
	int j = 0;
	for (int i = 0; i < size; ++i)
		if (!isPrime(arr[i]))
			n++;
	int* arr2 = new int[n];
	for (int i = 0; i < size; ++i)
		if (!isPrime(arr[i]))
			arr2[j++] = arr[i];
	return arr2;
}

void Pos_Neg_Zero(int* arr, size_t size, int* pos, int* neg, int* zero, int& p_c, int& n_c, int& z_s) {
	for (int i = 0; i < size; i++) {
		if (arr[i] > 0) {
			pos[p_c] = arr[i];
			p_c++;
		}
		else if (arr[i] < 0) {
			neg[n_c] = arr[i];
			n_c++;
		}
		else {
			zero[z_s] = arr[i];
			z_s++;
		}
	}
}

int main()
{
	{
		cout << "+===============================================================================+" << endl;
		//Завдання 1
		int size = 9;
		int n = 0;
		int* arr1 = new int[size] {1, 2, 5, 3, 7, 9, 11, 23, 12};

		cout << "Your array: " << endl;
		Print(arr1, size);
		cout << "Without Prime numbers: " << endl;

		int* arr2 = Del_Prime(arr1, size, n);
		Print(arr2, n);
		delete[] arr1;
		delete[] arr2;

		cout << "+===============================================================================+" << endl << endl << endl;
	}

	{
		//Завдання 2
		cout << "+===============================================================================+" << endl;
		int size = 9;
		int* arr = new int[size] {1, -1, 2, -2, 0, 32, -11, 0, 0};
		int* pos = new int[size] {0};
		int* neg = new int[size] {0};
		int* zero = new int[size] {0};
		int p_c = 0, n_c = 0, z_c = 0;

		cout << "Your array: " << endl;
		Print(arr, size);
		cout << endl;
		Pos_Neg_Zero(arr, size, pos, neg, zero, p_c, n_c, z_c);
		cout << "Pos: " << endl;
		Print(pos, p_c);
		cout << "Neg: " << endl;
		Print(neg, n_c);
		cout << "Zero: " << endl;
		Print(zero, z_c);
		delete[] arr;
		delete[] pos;
		delete[] neg;
		delete[] zero;
		cout << "+===============================================================================+" << endl << endl << endl;
	}
	return 0;
}