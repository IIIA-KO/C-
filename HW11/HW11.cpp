#include <iostream>
using namespace std;

int main()
{
	cout << "Program calculating the count of negative and positive entered numbers while they are not equal zero" << endl;

	double i; int negative_count, positive_count;
	positive_count = 0;
	negative_count = 0;

	cout << "Enter number: "; cin >> i;

	while (i != 0) {
		if (i > 0) {
			positive_count++;
		}
		else {
			negative_count++;
		}
		cout << "Enter number: "; cin >> i;
	}
	cout << "Count of positive numbers: " << positive_count << endl;
	cout << "Count of negative numbers: " << negative_count << endl;

	return 0;
}
