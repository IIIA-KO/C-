#include <iostream>
using namespace std;
#include <time.h>

int main()
{
	{
		//Завдання 1
		srand(time(0));
		cout << "+---------------------------------------------------------------------------------+" << endl;
		cout << "Program divides random generated array with 10 values to 2 smaller ones with 5 values" << endl;

		const int size = 10;
		int array[size], a = -10, b = 10;

		for (int i = 0; i < size; i++) {
			array[i] = a + rand() % (b - a + 1);
		}

		cout << "All array: " << endl;
		for (int j = 0; j < size; j++) {
			cout << array[j] << endl;
		}
		cout << endl;


		cout << "First small array: " << endl;
		for (int k = 0; k < size / 2; k++) {
			cout << array[k] << endl;
		}
		cout << endl;

		cout << "Second small array: " << endl;
		for (int l = 5; l < size; l++) {
			cout << array[l] << endl;
		}
		cout << "+---------------------------------------------------------------------------------+" << endl << endl << endl;
	}

	{
		//Завдання 2
		cout << "+----------------------------------------------------------------------------------------------------------+" << endl;
		cout << "Program has two random regenerated arrays. It will create third with sum of each element of two previous." << endl;

		const int size = 10;
		int arr[size];
		int mass[size];
		int sumarr[size];
		int a = -10, b = 10;

		for (int i = 0; i < size; i++) {
			arr[i] = a + rand() % (b - a + 1);
		}

		for (int i = 0; i < size; i++) {
			mass[i] = a + rand() % (b - a + 1);
		}

		for (int i = 0; i < size; i++) {
			sumarr[i] = arr[i] + mass[i];
		}

		cout << "First array: " << endl;
		for (int j = 0; j < size; j++) {
			cout << arr[j] << endl;
		}
		cout << endl;

		cout << "Second array: " << endl;
		for (int j = 0; j < size; j++) {
			cout << mass[j] << endl;
		}
		cout << endl;

		cout << "Third array: " << endl;
		for (int j = 0; j < size; j++) {
			cout << sumarr[j] << endl;
		}

		cout << "+----------------------------------------------------------------------------------------------------------+" << endl << endl << endl;

	}
	return 0;
}
