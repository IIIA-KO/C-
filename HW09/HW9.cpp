#include <iostream>
using namespace std;

int main()
{
	{
		//Завдання 1

		int a, sum;
		cout << "Program calculates the sum of all integer values from 'A' to 500" << endl << "Enter 'A': "; cin >> a; cout << endl;

		if (a <= 500) {
			sum = 0;
			for (int i = a; a <= 500; i++, a++) {
				sum += a;
			}
			cout << "The sum of all integer values from 'A' to 500 is " << sum << endl << endl;
		}
		else {
			cout << "Error: maybe 'A' more than 500" << endl << endl;
		}
		
	}

	{
		//Завдання 2
		double x, y, xx, yy;
		double result;
		cout << "Program calculates entered value 'X' in to the power of 'Y' " << endl;
		cout << "Enter integer number 'X': "; cin >> x;
		cout << "Enter integer number 'Y': "; cin >> y;

		result = 0;
		xx = x;

		if (y == 0) {
			result = 1;
			cout << "Result: " << result << endl << endl;
		}
		else if (y == 1) {
			result = x;
			cout << "Result: " << result << endl << endl;
		}
		else if (y == -1) {
			result = 1 / x;
			cout << "Result: " << result << endl << endl;
		}
		else if (x == -1 && y == -1) {
			result = -1;
			cout << "Result: " << result << endl << endl;
		}
		else if (y > 0){
			for (int i = 1; i < y; i++) {
				x *= xx;
				result = x;
			}
			cout << "Result: " << result << endl << endl;
		}
		else if (y < 0) {
			y = abs(y);
			for (int i = 1; i < y; i++) {
				x *= xx;
				result = x;
			}
			cout << "Result: " << 1/result << endl << endl;
		}
	}

	{
		//Завдання 3
		float sum = 0; float avg;
		cout << "Program finds arithmetic average from 1 to 1,000" << endl;

		for (int i = 1; i <= 1000; i++) {
			sum += i;
			avg = sum/1000;
		}
		cout << "Result: " << avg << endl << endl;
	}

	{
		//Завданн 4

		int a, res; long long multiply;
		cout << "Program calculates the multiplying of all integer values from 'A' to 20 (1 <= A <= 20)" << endl << "Enter 'A': "; cin >> a; cout << endl;
		if (a < 1 || a > 20) {
			cout << "Error: 'A' has value less than 1 or more than 20" << endl << endl;
		}else {
			multiply = 1;
			for (int i = a; i <= 20;i++) {
				multiply *= i;
			}
		}
		cout << "Result: " << multiply << endl << endl;
	}
	
	{
		//Завдання 5

		double k;
		cout << "Program calculates multiplication table by entered number 'K' " << endl; cout << "Enter 'K': "; cin >> k;

		for (int i = 1; i <= 10; i++) {
			cout << k << " * " << i << " = " << i * k << endl;
		}
	}
	return 0;
}
