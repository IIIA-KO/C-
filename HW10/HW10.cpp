#include <iostream>
using namespace std;

int main()
{
	cout << "Program calculates the minimal of antered numbers while they are not equal zero" << endl;

	double i, min;

	cout << "Enter number: "; cin >> i;
	min = i;

	if (min == 0) {
		cout << "No numbers" << endl;
	}

	while (i != 0) {
		cout << "Enter number: "; cin >> i;
		if (i == 0) {
			cout << "Minimal: " << min << endl;
		}
		else if (i < min) {
			min = i;
		}
	}

	return 0;
}
