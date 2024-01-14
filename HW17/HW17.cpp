#include <iostream>
using namespace std;
int main()
{
	srand(time(0));
	{
		//Завддання 1
		cout << "+-----------------------------------------------------------------------------------------+" << endl;
		cout << "Task 1" << endl;
		cout << "Program sorts odd index numbers in random generated array" << endl;
		const int size = 101;
		int array[size], a = -100, number = 0, b = 100;

		cout << "Enter how many numbers you want to see: "; cin >> number;

		if (number < 1 || number > size) {
			cout << "Size error: too many numbers. Donate pls to use more" << endl;
			cout << endl << "+-----------------------------------------------------------------------------------------+" << endl << endl << endl;
			return 1;
		}

		for (int i = 0; i <= number; i++) {
			array[i] = a + rand() % (b - a + 1);
		}

		cout << "Your array: " << endl;
		for (int j = 0; j < number; j++) {
			cout << array[j] << "\t";
		}

		for (int j = 0; j < number - 1; j++) {
			int min = j;
			for (int i = j + 1; i < number; i++) {
				if (array[i] < array[min]) {
					min = i;
				}
			}
			int temp = array[min];
			array[min] = array[j];
			array[j] = temp;
		}
		cout << endl << endl;

		cout << endl << "Sorted: " << endl;
		for (int j = 0; j < number; j++) {
			cout << array[j] << "\t";
		}
		cout << endl << endl;

		cout << "Odd index sort: " << endl;
		for (int j = 0; j < number; j += 2) {
			cout << array[j] << "\t";
		}
		cout << endl << "+-----------------------------------------------------------------------------------------+" << endl << endl << endl;
	}

	{
		//Завдання 2
		cout << "+-----------------------------------------------------------------------------------------+" << endl;

		cout << "Task 2" << endl;
		cout << "Program sort elements in random generated array in descending order from 'k' untill the end" << endl;

		const int size = 101;
		int array[size], a = 1, number = 0, b = 100;

		cout << "Enter how many numbers you want to see: "; cin >> number;
		if (number < 1 || number > size) {
			cout << "Size error: too many numbers. Donate pls to use more" << endl;
			cout << endl << "+-----------------------------------------------------------------------------------------+" << endl << endl << endl;
			return 1;
		}
		for (int i = 0; i <= number; i++) {
			array[i] = a + rand() % (b - a + 1);
		}
		cout << "Your array: " << endl;
		for (int j = 0; j < number; j++) {
			cout << array[j] << "\t";
		}
		cout << endl << endl;

		int k = 0;
		cout << "Enter 'k': "; cin >> k;
		if (k < 1 || k > 10) {
			cout << "Anvailable value 'k'" << endl;
			cout << endl << "+-----------------------------------------------------------------------------------------+" << endl << endl << endl;
			return 1;
		}

		for (int i = k - 1; i < number - 1; i++) {
			for (int j = k - 1; j < number - 1; j++) {
				if (array[j] < array[j + 1]) {
					int tmp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = tmp;
				}
			}

		}
		cout << endl << "Sorted: " << endl;
		for (int j = k - 1; j < number; j++) {
			cout << array[j] << "\t";
		}
		cout << endl << "+-----------------------------------------------------------------------------------------+" << endl << endl << endl;
	}

	{
		//Завдання 3
		cout << "+-----------------------------------------------------------------------------------------+" << endl;
		cout << "Task 3" << endl;
		cout << "The program determines whether a entered sequence of numbers is increasing" << endl;
		const int size = 101;
		int a = -100, number = 0, b = 100;

		cout << "Enter how many numbers you want to enter: "; cin >> number;

		if (number < 1 || number > size) {
			cout << "Size error: too many numbers. Donate pls to use more" << endl;
			cout << endl << "+-----------------------------------------------------------------------------------------+" << endl << endl << endl;
			return 1;
		}

		bool isIncreasing = true;
		int num = 0, num1 = 0;
		cout << "Enter number: "; cin >> num;
		for (int i = 0; i < number - 1; i++) {
			cout << "Enter number: "; cin >> num1;
			if (num < num1) {
				num = num1;
			}
			else {
				isIncreasing = false;
			}
		}

		cout << endl << endl;

		if (isIncreasing == true) {
			cout << "Secuense is increasig" << endl;
		}
		else if (isIncreasing == false) {
			cout << "Secuense is not increasig" << endl;
		}
		cout << endl << "+-----------------------------------------------------------------------------------------+" << endl << endl << endl;
	}

	{
		//Завдання 4
		cout << "+-----------------------------------------------------------------------------------------+" << endl;
		cout << "Task 4" << endl;

		cout << "Program outputs sequence with zero in descending untill the zero" << endl;
		const int size = 101;
		int array[size], a = -100, number = 0, b = 100;

		cout << "Enter how many numbers you want to enter: "; cin >> number;

		if (number < 1 || number > size) {
			cout << "Size error: too many numbers. Donate pls to use more" << endl;
			cout << endl << "+-----------------------------------------------------------------------------------------+" << endl << endl << endl;
			return 1;
		}

		for (int i = 0; i < number; i++) {
			cout << "Enter number: "; cin >> array[i];
		}

		bool isIn = false;
		int zero_indx = 0;
		for (int j = 0; j < number; j++) {
			if (array[j] == 0) {
				zero_indx = j;
				isIn = true;
				break;
			}
		}

		switch (isIn)
		{
		case true:
			cout << "Your array: " << endl;
			for (int i = 0; i < number; i++) {
				cout << array[i] << "\t";
			}
			cout << endl;

			if (array[0] == 0) {
				cout << "There are no numbers in your sequense before 0" << endl;
				cout << endl << "+-----------------------------------------------------------------------------------------+" << endl << endl << endl;
				return 1;
			}

			cout << "Your sorted sequence in descending untill the zero: " << endl;
			for (int i = zero_indx - 1; i >= 0; i--) {
				for (int j = zero_indx - 1; j >= 0; j--) {
					if (array[j] < array[j - 1]) {
						int temp = array[j];
						array[j] = array[j - 1];
						array[j - 1] = temp;
					}
				}
			}
			for (int i = zero_indx - 1; i >= 0; i--) {
				cout << array[i] << "\t";
			}
			cout << endl;
			break;

		case false:
			cout << "Error: There is no 0 in your sequense" << endl;
			cout << endl << "+-----------------------------------------------------------------------------------------+" << endl << endl << endl;
			return 1;
			break;
		}
		cout << endl << "+-----------------------------------------------------------------------------------------+" << endl << endl << endl;
	}
	return 0;
}
