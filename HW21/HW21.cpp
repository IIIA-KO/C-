#include <iostream>
using namespace std;

void Generate_Array(int* arr, int size, int a = -10, int b = 10) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = a + rand() % (b - a + 1);
	}
}

void Print_Array(int* arr, int size) {
	cout << "Your array: " << endl;
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

float Arithmetic(int arr[], int size) {
	float avg = 0, count = 0, sum = 0;

	for (int i = 0; i < size; i++) {
		count++;
		sum += arr[i];
	}
	avg = sum / count;
	return avg;
}

void Pos_Neg_Zero(int* arr, int size, int& pos_count, int& neg_count, int& zero_count) {
	for (int i = 0; i < size; i++) {
		if (arr[i] > 0) {
			pos_count++;
		}
		else if (arr[i] < 0) {
			neg_count++;
		}
		else {
			zero_count++;
		}
	}
}

bool Leap(int year) {
	bool leap = false;

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		leap = true;
	}
	else {
		leap = false;
	}
	return leap;
}

int Day_quantity(int year, int month, int day) {
	int days = day;

	switch (month - 1) {
	case 12:
		days += 31;
	case 11:
		days += 30;
	case 10:
		days += 31;
	case 9:
		days += 30;
	case 8:
		days += 31;
	case 7:
		days += 31;
	case 6:
		days += 30;
	case 5:
		days += 31;
	case 4:
		days += 30;
	case 3:
		days += 31;
	case 2:
		if (Leap(year)) {
			days += 29;
		}
		else {
			days += 28;
		}
	case 1:
		days += 31;
	}
	days += (year - 1) * 365 + ((year - 1) / 4);

	return days;
}

int main()
{

	{
		//Завдання 1
		cout << "+=========================================================================================+" << endl;
		cout << "The program takes two dates and determines the difference between them in days" << endl;
		int year1, month1, day1, year2, month2, day2, difference = 0;
		cout << "Enter the year of first date: "; cin >> year1;
		cout << "Enter the month of first date: "; cin >> month1;
		cout << "Enter the day of first date: "; cin >> day1;

		cout << "Enter the year of second date: "; cin >> year2;
		cout << "Enter the month of second date: "; cin >> month2;
		cout << "Enter the day of second date: "; cin >> day2;

		if (year1 < 0 || year2 < 0 || month1 < 0 || month1 > 12 || month2 < 0 || month2 > 12 || day1 < 0 || day1 > 31 || day2 < 0 || day2 > 31) {
			cout << "Error: wrongly entered date" << endl;
			return 1;
			cout << "+=========================================================================================+" << endl << endl << endl;
		}

		(Day_quantity(year1, month1, day1) > Day_quantity(year2, month2, day2)) ? difference = Day_quantity(year1, month1, day1) - Day_quantity(year2, month2, day2) : difference = Day_quantity(year2, month2, day2) - Day_quantity(year1, month1, day1);
		cout << "Difference: " << difference << endl;
		cout << "+=========================================================================================+" << endl << endl << endl;

	}

	{
		//Завданя 2
		cout << "+=========================================================================================+" << endl;
		cout << "Program finds arithmetic mean of random generated value" << endl;
		const int size = 10;
		int arr[size];

		Generate_Array(arr, size, -10, 10);
		Print_Array(arr, size);

		cout << "Arithmetic mean of your array: " << Arithmetic(arr, size) << endl;
		cout << "+=========================================================================================+" << endl << endl << endl;
	}

	{
		//Завдання 3
		cout << "+=========================================================================================+" << endl;
		cout << "Program finds quantity of positive, nagative and zero elements in randon generated array" << endl;

		const int size = 10;
		int arr[size];

		Generate_Array(arr, size, -10, 10);
		Print_Array(arr, size);

		int pos_count = 0, neg_count = 0, zero_count = 0;

		Pos_Neg_Zero(arr, size, pos_count, neg_count, zero_count);

		cout << "Quantity of positive, nagative and zero elements in your array: " << endl;
		cout << "Quantity of positive elements: " << pos_count << endl;
		cout << "Quantity of negative elements: " << neg_count << endl;
		cout << "Quantity of zero elements: " << zero_count << endl;
		cout << "+=========================================================================================+" << endl << endl << endl;
	}
	return 0;
}
