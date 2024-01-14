#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	srand(time(0));
	{
		//Завдання 1
		cout << "+=============================================================================================+" << endl;
		cout << "Task 1" << endl;
		cout << "Program makes matrix where each element equals multiplying by two by prewious element" << endl;

		const int row = 5, col = 5;
		int n = 0, r = 0, c = 0;
		int arr[row][col];

		cout << "Enter value of first element: "; cin >> n;
		cout << "Enter how many rows you want to see (max value for rows is 5): "; cin >> r;
		cout << "Enter how many columns you want to see (max value for columns is 5): "; cin >> c;

		if (r > 5 || r < 1 || c > 5 || c < 1) {
			cout << "Error: Unavailable value for rows or columns" << endl;
			cout << "+=============================================================================================+" << endl << endl << endl;
			return 1;
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				arr[i][j] = n;
				n *= 2;
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "+=============================================================================================+" << endl << endl << endl;
	}

	{
		//Завдання 2
		cout << "+=============================================================================================+" << endl;
		cout << "Task 2" << endl;
		cout << "Program makes matrix where each element equals adding 1 to prewious element" << endl;

		const int row = 100, col = 100;
		int n = 0, r = 0, c = 0;
		int arr[row][col];

		cout << "Enter value of first element: "; cin >> n;
		cout << "Enter how many rows you want to see: "; cin >> r;
		cout << "Enter how many columns you want to see: "; cin >> c;

		if (r > 100 || r < 1 || c > 100 || c < 1) {
			cout << "Error: Unavailable value for rows or columns" << endl;
			cout << "+=============================================================================================+" << endl << endl << endl;
			return 1;
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				arr[i][j] = n;
				n++;
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "+=============================================================================================+" << endl << endl << endl;
	}

	{
		//Завдання 3
		cout << "+=============================================================================================+" << endl;
		cout << "Task 3" << endl;
		cout << "Program makes random created matrix. You can select the number of shifts and their direction" << endl;

		const int row = 100, col = 100;
		int r = 0, c = 0, a = -10, b = 10, direction = 0, move = 0;
		int arr[row][col];

		cout << "Enter how many rows you want to see: "; cin >> r;
		cout << "Enter how many columns you want to see: "; cin >> c;

		if (r > 100 || r < 1 || c > 100 || c < 1) {
			cout << "Error: Unavailable value for rows or columns" << endl;
			cout << "+=============================================================================================+" << endl << endl << endl;
			return 1;
		}

		for (int i = 0; i < r; i++) {
			for (int k = 0; k < c; k++) {
				arr[i][k] = a + rand() % (b - a + 1);
			}
		}

		cout << "Your matrix: " << endl;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}

		cout << "Enter how many moves you want to do (move can be only positive): "; cin >> move;
		cout << "Enter in which direction you want to move (1 - left, 2 - right, 3 - up, 4 - down): "; cin >> direction; cout << endl;

		if (move > c) {
			move %= c;
		}
		if (move < 0) {
			move *= -1;
		}

		switch (direction) {
		case 1:

			move = c - move;
			for (int i = 0; i < move; i++) {
				for (int j = 0; j < r; j++) {
					int temp = arr[j][c - 1];
					int k;
					for (k = c - 1; k > 0; k--) {
						arr[j][k] = arr[j][k - 1];
					}
					arr[j][k] = temp;
				}
			}

			cout << "Your shifted matrix: " << endl;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					cout << arr[i][j] << "\t";
				}
				cout << endl;
			}
			break;

		case 2:

			for (int i = 0; i < move; i++) {
				for (int j = 0; j < r; j++) {
					int temp = arr[j][c - 1];
					int k;
					for (k = c - 1; k > 0; k--) {
						arr[j][k] = arr[j][k - 1];
					}
					arr[j][k] = temp;
				}
			}

			cout << "Your shifted matrix: " << endl;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					cout << arr[i][j] << "\t";
				}
				cout << endl;
			}
			break;

		case 3:
			move = c - move;
			if (move > r) {
				move %= r;
			}

			for (int i = 0; i < move; i++) {
				for (int j = 0; j < c; j++) {
					int temp = arr[r - 1][j];
					int k;
					for (k = r - 1; k > 0; k--) {
						arr[k][j] = arr[k - 1][j];
					}
					arr[k][j] = temp;
				}
			}
			cout << "Your shifted matrix: " << endl;
			for (int i = 0; i < c; i++) {
				for (int j = 0; j < r; j++) {
					cout << arr[i][j] << "\t";
				}
				cout << endl;
			}
			break;

		case 4:
			if (move > r) {
				move %= r;
			}

			for (int i = 0; i < move; i++) {
				for (int j = 0; j < c; j++) {
					int temp = arr[r - 1][j];
					int k;
					for (k = r - 1; k > 0; k--) {
						arr[k][j] = arr[k - 1][j];
					}
					arr[k][j] = temp;
				}
			}

			cout << "Your shifted matrix: " << endl;
			for (int i = 0; i < c; i++) {
				for (int j = 0; j < r; j++) {
					cout << arr[i][j] << "\t";
				}
				cout << endl;
			}
			break;

		default:
			cout << "Error: unavailable value" << endl;
			cout << "+=============================================================================================+" << endl << endl << endl;
			return 1;
		}

		cout << "+=============================================================================================+" << endl << endl << endl;

	}
	return 0;
}
