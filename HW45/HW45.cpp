#include <iostream>
using namespace std;

bool IsPrime(unsigned long long n) {
	if (n % 10 == 0) return false;
	if (n > 0) {
		for (unsigned long long i = 2; i <= n / 2; i++)
			if (n % i == 0) return false;
		return true;
	}
	else return false;
}
bool IsPalindrome(unsigned long long num)
{
	unsigned long long temp = num;
	unsigned long long div = temp % 10;
	while (temp /= 10)
		div = div * 10 + temp % 10;
	return (div == num);
}
int main() {
	const int max = 99999;
	int count = 0;
	long long int mas[max]{ 0 };
	for (int i = sqrt(max); i < max; i++) {
		if (IsPrime(i)) {
			mas[count] = i;
			count++;
		}
	}
	long long int n;
	long long int max_num = 0;
	int first_num = 0, second_num = 0;
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count; j++) {
			n = mas[i] * mas[j];
			if (IsPalindrome(n)) {
				if (n > max_num) {
					max_num = n;
					first_num = i;
					second_num = j;
				}
			}
		}
	cout << "Result: " << endl; cout << "First number:" << mas[first_num] << endl; cout << "Second number: " << mas[second_num] << endl;
	cout << mas[first_num] << " * " << mas[second_num] << " = " << max_num << endl;
	return 0;
}