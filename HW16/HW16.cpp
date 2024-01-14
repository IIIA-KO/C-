#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	cout << "+--------------------------------------------------------------------------------+" << endl;
	cout << "Program Guide" << endl;
	cout << "You can see sorted list of: " << endl;
	cout << "1) ICQ numbers;" << endl << "2) Phone numbers;" << endl << "3) List of users" << endl << "And exit of guide" << endl;
	cout << "You have list of 10 users, so you also have list of their phone and ICQ numbers " << endl << endl;

	const int size = 10;

	string name[size]{ "Sam", "Mike", "Dan", "John", "Dean", "Nina", "Kyle", "Lily", "Elen", "Bob" };

	int icq[size];
	int phone_num[size];

	cout << "List of names: " << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ")" << name[i] << "\t";
	}
	cout << endl << endl;

	cout << "You should enter phone numbers without symbols, onle numbers" << endl;
	for (int i = 0; i < size; i++) {
		cout << "Enter the phone mumber of " << name[i] << " "; cin >> phone_num[i];
	}
	cout << endl << endl;

	cout << "ICQ numbers: " << endl;
	for (int i = 0; i < size; i++) {
		cout << "Enter the ICQ mumber of " << name[i] << " "; cin >> icq[i];
	}
	cout << endl << endl;

	cout << "--------------------------------------------------------" << endl;
	cout << "Whole information table: " << endl;
	for (int i = 0; i < size; i++) {
		cout  << i+1 << ") Name: " << name[i] << "; ICQ: " << icq[i] << "; Phone number: " << phone_num[i] << endl;
	}
	cout << "--------------------------------------------------------" << endl << endl << endl;

	int acticion = 0, d = size / 2;
	cout << "Functions: " << endl;
	cout << "1) See sorted ICQ numbers list " << endl;
	cout << "2) See sorted phone numbers list " << endl;
	cout << "3) See users list " << endl;
	cout << "4) Exit " << endl;

	while (1) {
		cout << "Enter action you want to do: "; cin >> acticion;
		switch (acticion) {
		case 1:
			for (int i = 1; i < size; i++)
			{
				int j = i;
				while (j > 0 && icq[j - 1] > icq[j])
				{
					int temp = icq[j - 1];
					icq[j - 1] = icq[j];
					icq[j] = temp;

					string tempp = " ";
					tempp = name[j - 1];
					name[j - 1] = name[j];
					name[j] = tempp;
					j -= 1;
				}
			}

			cout << "Sorted ICQ numbers: " << endl;
			for (int i = 0; i < size; i++) {
				cout << i + 1 << ") Name: " << name[i] << "; ICQ: " << icq[i] << endl;
			}
			break;

		case 2:
			for (int i = 1; i < size; ++i)
			{
				int k = i;
				while (k > 0 && phone_num[k - 1] > phone_num[k])
				{
					int temp = phone_num[k - 1];
					phone_num[k - 1] = phone_num[k];
					phone_num[k] = temp;

					string ttemp = " ";
					ttemp = name[k - 1];
					name[k - 1] = name[k];
					name[k] = ttemp;
					k -= 1;
				}
			}

			cout << "Sorted phone numbers: " << endl;
			for (int i = 0; i < size; i++) {
				cout << i + 1 << ") Name: " << name[i] << "; Phone number: " << phone_num[i] << endl;
			}
			break;

		case 3:
			cout << "List of names: " << endl;
			for (int i = 0; i < size; i++) {
				cout << i + 1 << ")" << name[i] << "\t";
			}
			cout << endl;
			break;

		case 4:
			return 0;

		default:
			cout << "Error: unavailable value" << endl;
			break;
		}
	}
	cout << "+--------------------------------------------------------------------------------+" << endl;
	return 0;
}
