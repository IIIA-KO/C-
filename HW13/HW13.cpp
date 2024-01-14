#include <iostream>
using namespace std;

int main()
{
	{
		//Завдання 1

		int count = 0;
		for (int i = 100; i < 1000; i++) {
			int a = (i / 100) % 10;
			int b = (i / 10) % 10;
			int c = (i % 100) % 10;
			if (a == b || b == c || a == c) {
				++count;
			}
		}
		cout << "+---------------------------------------------------------------------------------------+" << endl;
		cout << "Program calculates all integer numbers beetwen 100 and 999, that have two equal digits" << endl;
		cout << "Result: " << count << endl;
		cout << "+---------------------------------------------------------------------------------------+" << endl << endl << endl;


	}

	{
		//Завдання 2

		int count = 0;
		for (int i = 100; i < 1000; i++) {
			int a = (i / 100) % 10;
			int b = (i / 10) % 10;
			int c = (i % 100) % 10;
			if (a != b && b != c && a != c) {
				count++;
			}
		}
		cout << "+---------------------------------------------------------------------------------------+" << endl;
		cout << "Program calculates all integer numbers beetwen 100 and 999, that have different digits" << endl;
		cout << "Result: " << count << endl;
		cout << "+---------------------------------------------------------------------------------------+" << endl << endl << endl;
	}

	{
		//Завдання 3

		int number;
		cout << "+---------------------------------------------------------------------------------------+" << endl;
		cout << "Program deletes the '3' and '6' from entered inegteger number" << endl;
		cout << "Enter the integer number: "; cin >> number;

		int without = 0;
		int x = 1;
		while (number != 0) {
			if (number % 10 != 3 && number % 10 != 6) {
				without += (number % 10) * x;
				x *= 10;
			}
			number /= 10;
		}
		cout << "Result: " << without << endl;
		cout << "+---------------------------------------------------------------------------------------+" << endl << endl << endl;
	}

	{
		//Завдання 4
		cout << "+-----------------------------------------------------------------------------------------------------------+" << endl;
		cout << "The program calculates the number B for which the entered number A is divisible without a remainder by B*B." << endl << "And is not divisible without a remainder by B*B*B" << endl;
		int num;
		cout << "Enter integer number 'A': "; cin >> num;
		if (num == 0) {
			cout << "Result: No result" << endl;
		}
		else if (num > 0) {
			for (long long i = 1; i <= num; i++) {
				if ((num % (i * i)) == 0 && (num % (i * i * i)) != 0) {
					cout << "Result 'B': " << i << endl;
				}
			}
		}
		cout << "+-----------------------------------------------------------------------------------------------------------+" << endl << endl << endl;
	}

	{
		//Завдання 5
		cout << "+---------------------------------------------------------------------------------------+" << endl;
		cout << "The program calculates the sum of the digits of the positive entered number." << endl << "If sum eqauls the square of this entered number, program will return the result of it" << endl;
		int sum = 0, num;
		cout << "Enter the integer number 'A': "; cin >> num;
		cout << "A  = " << num << endl;

		while (num) {
			if (num > 0) {
				sum += num % 10;
				num /= 10;
			}
			else {
				num = abs(num);
				sum += num % 10;
				num /= 10;
			}

		}
		cout << "Sum  = " << sum << endl;
		if (num * num == sum * sum * sum) {
			cout << "Yes 'A'^2 equals sum of the digits ^3" << endl;
		}
		else {
			cout << "No 'A'^2 not equals sum of the digits ^3" << endl;
		}
		cout << "+-----------------------------------------------------------------------------------------------------------+" << endl << endl << endl;

	}

	{
		//Завдання 6
		cout << "+---------------------------------------------------------------------------------------------+" << endl;
		cout << "The program calculates all integers by which a given number is divisible without a remainder" << endl;
		int n;
		cout << "Enter integer number: "; cin >> n;
		if (n == 0) {
			cout << "Result: No result" << endl;
		}
		for (int i = 1; i <= n; i++) {
			if (n % i == 0) {
				cout << "Result: " << i << endl;
			}
		}
		cout << "+---------------------------------------------------------------------------------------------+" << endl << endl << endl;
	}

	{
		//Завдання 7

		cout << "+---------------------------------------------------------------------------------------------+" << endl;
		cout << "The program calculates all integers by which a two given number is divisible without a remainder" << endl;
		int a, b;
		cout << "Enter integer number 'A': "; cin >> a;
		cout << "Enter integer number 'B': "; cin >> b;
		if (a < b) {
			for (int i = 1; i <= a; i++) {
				if (a % i == 0 && b % i == 0) {
					cout << "Result: " << i << endl;

				}
			}
		}
		else if (a > b) {
			for (int j = 1; j <= b; j++) {
				if (b % j == 0 && a % j == 0) {
					cout << "Result: " << j << endl;
				}
			}
		}
		else {
			for (int i = 1; i <= a; i++) {
				if (a % i == 0 && b % i == 0) {
					cout << "Result: " << i << endl;

				}
			}
		}
		cout << "+---------------------------------------------------------------------------------------------+" << endl << endl << endl;

	}
	return 0;
}