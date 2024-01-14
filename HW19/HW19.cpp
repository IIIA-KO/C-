#include <iostream>
using namespace std;

int main()
{
	int size, number;
	cout << "+====================================================================================================+" << endl;

	const int Size = 100;
	int arr[Size][Size];
	string mass[Size][Size];

	while (1) {
		cout << "Program shows different figures made by matrix" << endl << "Enter size of figures (max size - 25): "; cin >> size;

		if (size > 25 || size < 1) {
			cout << "Error: Unavailable value for size" << endl;
			return 1;
			cout << "+====================================================================================================+" << endl;
		}

		cout << "Enter number of figure you want to see: "; cin >> number; cout << endl;

		switch (number) {
		case 1:
			for (int i = 0; i < size; i++) {
				for (int l = size; l >= 0; l--) {
					arr[i][l] = 0;
				}
				for (int j = size; j >= i; j--) {
					arr[i][j] = 1;
				}
			}
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
			break;

		case 2:
			for (int i = 0; i < size; i++) {
				for (int l = size; l >= 0; l--) {
					arr[i][l] = 1;
				}
				for (int j = size; j >= i; j--) {
					arr[i][j] = 0;
				}
			}

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
			break;

		case 3:
			for (int i = 0; i < size / 2; i++) {
				for (int j = 0; j < size; j++) {
					((i >= j && i <= size - 1 - j) || (i <= j && i >= size - 1 - j) ? arr[i][j] = 0 : arr[i][j] = 1);
				}
			}
			for (int i = size / 2; i < size; i++) {
				for (int j = 0; j < size; j++) {
					arr[i][j] = 0;
				}
			}
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
			break;

		case 4:
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					((i >= j && i <= size - 1 - j) || (i <= j && i >= size - 1 - j) ? arr[i][j] = 0 : arr[i][j] = 1);
				}
			}

			for (int i = 0; i < size / 2; i++) {
				for (int j = 0; j < size; j++) {
					arr[i][j] = 0;
				}
			}

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
			break;

		case 5:
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					((i >= j && i <= size - 1 - j) || (i <= j && i >= size - 1 - j) ? arr[i][j] = 0 : arr[i][j] = 1);
				}
			}
			arr[size / 2][size / 2] = 1;

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
			break;

		case 6:
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					((i >= j && i <= size - 1 - j) || (i <= j && i >= size - 1 - j) ? arr[i][j] = 1 : arr[i][j] = 0);
				}
			}

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
			break;

		case 7:
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					((i >= j && i <= size - 1 - j) ? arr[i][j] = 1 : arr[i][j] = 0);
				}
			}

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
			break;

		case 8:
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					((i <= j && i >= size - 1 - j) ? arr[i][j] = 1 : arr[i][j] = 0);
				}
			}

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
			break;

		case 9:
			for (int i = 0; i < size; i++) {
				for (int j = size; j >= 0; j--) {
					arr[i][j] = 0;
				}
			}

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size - i; j++) {
					arr[i][j] = 1;
				}
			}

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
			break;

		case 10: 
			for (int i = 0; i < size; i++) {
				for (int j = size; j >= 0; j--) {
					arr[i][j] = 1;
				}
			}

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size - i; j++) {
					arr[i][j] = 0;
				}
			}

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
			break;

		default:
			cout << "Error: Unavailable value for number" << endl;
			break;
		}
	}

	return 0;
}