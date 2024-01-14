#include <iostream>
#define n 10
using namespace std;

template<class R>
void SetRand(R* arr, size_t size, R a = -10, R b = 10) {
	for (int i = 0; i < size; i++) {
		arr[i] = a + rand() % (b - a + 1);
	}
}

template<class P>
void Print(P* arr, size_t size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

double Minn(int* arr, int size) {
	int min = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}
double Maxx(int* arr, int size) {
	int max = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
double Avgg(int* arr, int size) {
	double avg = 0;
	int count = 0, sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
		count++;
	}
	avg = double(sum) / count;
	return avg;
}

//typedef int (*Test)(int* arr, int size);
void Action(int* a, int size, double(*Test)(int*, int)) {
	cout << Test(a, size) << endl;
}

int main()
{
	cout << "Min Max Avg functions: " << endl;
	int* a = new int[n] {};
	int* b = new int[n] {};

	size_t choose_arr;
	size_t choose_act;
	SetRand(a, n);
	SetRand(b, n);

	cout << "Random generated array A: " << endl;
	Print(a, n);
	cout << "Random generated array B: " << endl;
	Print(b, n);

	cout << "Enter in which array you want to actions (A - 0, B - 1): "; cin >> choose_arr;
	cout << "Enter in which action you want to do (Find Min - 0, Find Max - 1, Find Avg - 2): "; cin >> choose_act;

	switch (choose_arr) {
	case 0:
		switch (choose_act)
		{
		case 0:
			cout << "Min in A: " << endl;
			Action(a, n, Minn);
			break;

		case 1:
			cout << "Max in A: " << endl;
			Action(a, n, Maxx);
			break;

		case 2:
			cout << "Avg in A: " << endl;
			Action(a, n, Avgg);
			break;

		default:
			cout << "Error: Wrongly entered action" << endl;
			break;

		}
		break;

	case 1:
		switch (choose_act)
		{
		case 0:
			cout << "Min in B: " << endl;
			Action(b, n, Minn);
			break;

		case 1:
			cout << "Max in B: " << endl;
			Action(b, n, Maxx);
			break;

		case 2:
			cout << "Avg in B: " << endl;
			Action(b, n, Avgg);
			break;

		default:
			cout << "Error: Wrongly entered action" << endl;
			break;

		}
		break;

	default:
		cout << "Error: Wrongly entered array" << endl;
		break;

	}
	return 0;
}