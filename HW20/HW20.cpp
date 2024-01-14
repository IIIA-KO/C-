#include <iostream>
using namespace std;

int Degree(double x, double y) {
	double result;
	double xx;

	xx = x;
	result = 0;

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
	else if (y > 0) {
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
		cout << "Result: " << 1 / result << endl << endl;
	}
	return result;
}

int Loop_Sum(int x, int y) {
	int sum = 0;
	if (x < y) {
		for (int i = x; i <= y; i++) {
			sum += i;
		}
		cout << "Result: " << sum << endl;
	}
	else if (y < x) {
		for (int i = y; i <= x; i++) {
			sum += i;
		}
		cout << "Result: " << sum << endl;
	}
	else {
		cout << "No elements between 'X' and 'Y' " << endl;
	}
	return sum;
}

bool Perfect(int n) {
	bool perf = true;
	int sum = 0;

	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}
	if (sum == n) {
		cout << "Number is perfect (True)" << endl;
	}
	else {
		cout << "Number is not perfect (False)" << endl;

	}
	cout << "Sum: " << sum << endl;

	return n;
}

bool Prime(int x) {
	bool prime = true;
	for (int i = 2; i < x / 2; i++) {
		if (x % i == 0) {
			prime = false;
			cout << "Number is not prime (False)" << endl;
			break;
		}
		else {
			prime = true;
		}
	}

	if (prime == true) {
		cout << "Number is prime (True)" << endl;
	}
	return x;
}

int main()
{
	{
		//Degree
		cout << "+==================================================================================+" << endl;
		double x, y;
		cout << "Program calculates entered value 'X' in to the power of 'Y' " << endl;
		cout << "Enter integer number 'X': "; cin >> x;
		cout << "Enter integer number 'Y': "; cin >> y;

		Degree(x, y);
		cout << "+==================================================================================+" << endl << endl << endl;
	}

	{
		//Loop Sum
		cout << "+==================================================================================+" << endl;
		int x, y;
		cout << "Program calculates the sum of all integer numbers between entered 'X' and 'Y' " << endl << "If 'X' > 'Y' program'll find the sum of all integer elements between 'Y' and 'X' " << endl;
		cout << "Enter the value of 'X': "; cin >> x;
		cout << "Enter the value of 'Y': "; cin >> y;

		Loop_Sum(x, y);
		cout << "+==================================================================================+" << endl << endl << endl;
	}

	{
		//Perfect
		cout << "+==================================================================================+" << endl;
		int n;
		cout << "Program returns True if intered integer number is perfect, False - if not" << endl;
		cout << "A number is called perfect if the sum of all its divisors is equal to itself" << endl;
		cout << "Enter number: "; cin >> n;

		Perfect(n);
		cout << "+==================================================================================+" << endl << endl << endl;
	}

	{
		//Prime
		cout << "+==================================================================================+" << endl;
		int n;
		cout << "Program returns True if intered integer number is prime, False - if not" << endl;
		cout << "Enter number: "; cin >> n;

		Prime(n);
		cout << "+==================================================================================+" << endl << endl << endl;
	}


	return 0;
}
