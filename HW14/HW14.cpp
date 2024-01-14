#include <iostream>
using namespace std;

int main() {
	{
		//Завдання 1
		cout << "+----------------------------------------------------------------------------+" << endl;
		cout << "Program finds the minimal value and maximal value in random generated array: " << endl;
		const int size = 11;
		int arr[size];
		srand(time(0));
		int a = -10, b = 10, c = 10;
		int min = 0, max = 0;

		for (int i = 0; i <= c; i++) {
			arr[i] = a + rand() % (b - a + 1);
		}

		cout << "All: " << endl;
		for (int j = 0; j <= c; j++) {
			cout << arr[j] << endl;
		}

		min = arr[0];
		max = arr[0];

		for (int j = 0; j <= c; j++) {
			if (max < arr[j]) {
				max = arr[j];
			}
			if (min > arr[j]) {
				min = arr[j];
			}
		}

		cout << "Min: " << min << endl;
		cout << "Max: " << max << endl;
		cout << "+----------------------------------------------------------------------------+" << endl << endl << endl;
	}

	{
		//Завдання 2
		const int year = 13;
		int arr[year];
		int income = 0, sum = 0;
		int start = 0, end = 0;
		int minimal = 0, maximal = 0, min_indx = 0, max_indx = 0;
		cout << "+-------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "The program calculates the month in which there was the maximum income and the month with the minimum income," << endl;
		cout << "taking into account the selected range.You need to enter the income for each month" << endl;
		for (int i = 1; i < year; i++) {
			cout << "Enter your incom for " << i << " month "; cin >> income;
			arr[i] = income;
		}
		cout << endl;

		for (int j = 1; j < year; j++) {
			sum += arr[j];
		}
		cout << "Your income for all year " << sum << endl;
		cout << "Enter the start number of month (start month must be less than than end month): "; cin >> start;
		cout << "Enter the end number of month (end month must be more than than start month): "; cin >> end;
		cout << endl;


		if (start > 0 && start < 13 && start < end && end > 0 && end < 13) {
			minimal = arr[end];
			maximal = arr[start];

			min_indx = arr[end];
			max_indx = arr[start];

			for (int k = start; k <= end; k++) {

				if (maximal < arr[k]) {
					maximal = arr[k];
				}

				if (minimal > arr[k]) {
					minimal = arr[k];
				}
			}
		}
		else {
			cout << "Error: Entered values are wrong" << endl;
		}
		cout << "Minimal income in entered range:" << minimal << endl;
		cout << "Maximal income in entered range:" << maximal << endl;
		cout << "+-------------------------------------------------------------------------------------------------------------+" << endl << endl << endl;

	}

	{
		//Завдання 3
		cout << "+----------------------------------------------------------------------------+" << endl;
		cout << "Program finds: " << endl;
		cout << "1) Sum of negative elements of random generated array;" << endl;
		cout << "2) Multiply of elements BEETWEN min and max;" << endl;
		cout << "3) Multiply of elements with even number;" << endl;
		cout << "4) Sum of elements of BEETWEN first and last negaive elements." << endl << endl;

		const int Size = 11;

		int mass[Size], c = 11, a = -10, b = 10;
		int min = 0, max = 0, minindx = 0, maxindx = 0;

		double negative_sum = 0; int even_index_multiply = 1, min_max_mult = 1;

		for (int i = 1; i < c; i++) {
			mass[i] = a + rand() % (b - a + 1);
		}

		cout << "All elements: " << endl;
		for (int j = 1; j < c; j++) {
			cout << mass[j] << endl;

			if (mass[j] < 0) {
				negative_sum += mass[j];
			}
			if (j % 2 == 0) {
				even_index_multiply *= mass[j];
			}
		}
		cout << endl;
		//-----------------------------------------------------------------------------

		for (int k = 1; k < c; k++) {
			if (max < mass[k]) {
				max = mass[k];
				maxindx = k;
			}
			if (min > mass[k]) {
				min = mass[k];
				minindx = k;
			}
		}
		if (minindx < maxindx) {
			for (int i = minindx + 1; i < maxindx; i++) {
				min_max_mult *= mass[i];
			}
		}
		else if (minindx > maxindx) {
			for (int j = maxindx + 1; j < minindx; j++) {
				min_max_mult *= mass[j];
			}
		}
		else if ((minindx + 1) == maxindx || (minindx - 1) == maxindx) {
			min_max_mult = 0;
		}

		//---------------------------------------------------------------------------
		int first_neg = 0, last_neg = 0, sum_neg = 0;
		for (int i = 1; i < c; i++) {
			if (mass[i] < 0) {
				first_neg = i;
				break;
			}
		}

		for (int j = 10; j > 1; j--) {
			if (mass[j] < 0) {
				last_neg = j;
				break;
			}
		}

		for (int l = first_neg + 1; l < last_neg; l++) {
			sum_neg += mass[l];
		}

		cout << "Min: " << min << endl << "Max: " << max << endl << endl;

		cout << "Sum of negative elements of array: " << negative_sum << endl;
		cout << "Multiply of elements BEETWEN min and max: " << min_max_mult << endl;
		cout << "Multiply of elements with even number: " << even_index_multiply << endl;
		cout << "Sum of elements of BEETWEN first and last negaive elements: " << sum_neg << endl;
		cout << "+----------------------------------------------------------------------------+" << endl << endl << endl;
	}
	return 0;
}
