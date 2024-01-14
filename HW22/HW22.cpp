#include <iostream>
#include <time.h>
using namespace std;

void Genereate_Array(int arr[][5], int size) {
	srand(1);
	int a = -10, b = 10;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = a + rand() % (b - a + 1);
		}
	}
}

void Output_Array(int arr[][5], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int Gcd(int a, int b) {
	if (a > b || a == b) {
		if (b == 0) {
			return a;
		}
		return Gcd(b, a % b);
	}
	else {
		if (b == 0) {
			return b;
		}
		return Gcd(a, b % a);
	}
}

int Bulls_Cows_Game(int* bot_arr, int* user_arr, int try_count = 1) {
	for (int i = 0; i < 4; i++) {
		cout << "Enter digit of your number (0-9): "; cin >> user_arr[i];
		if (user_arr[i] < 0 || user_arr[i] > 9) {
			cout << "Error: Wrongly entered number" << endl;
			cout << "+====================================================================================================================================================================+" << endl;
			return try_count;
		}
		else if (bot_arr[0] == user_arr[0] && bot_arr[1] == user_arr[1] && bot_arr[2] == user_arr[2] && bot_arr[3] == user_arr[3]) {
			cout << "You Won !" << endl;
			cout << "Number that Bot guessed in star of the game: " << endl;
			for (int i = 0; i < 4; i++) {
				cout << bot_arr[i];
			}
			cout << endl;
			cout << "Your try_count: " << try_count + 1 << endl;
			cout << "+====================================================================================================================================================================+" << endl;
			return try_count;
		}
	}

	cout << "Your number: ";
	for (int i = 0; i < 4; i++) {
		cout << user_arr[i];
	}
	cout << endl;

	int bulls = 0, cows = 0;
	for (int i = 0; i < 4; i++) {
		if (user_arr[i] == bot_arr[0] || user_arr[i] == bot_arr[1] || user_arr[i] == bot_arr[2] || user_arr[i] == bot_arr[3]) {
			bulls++;
		}
		if (user_arr[i] == bot_arr[i]) {
			cows++;
		}
	}
	cout << "Bulls: " << bulls << endl;
	cout << "Cows: " << cows << endl;
	Bulls_Cows_Game(bot_arr, user_arr, try_count + 1);
	return try_count;
}


int Matrix(int arr[][5], int size) {
	Genereate_Array(arr, size);
	int min = arr[0][0], max = arr[0][0];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (i == j) {
				if (arr[i][j] > max) {
					max = arr[i][j];
				}
				if (arr[i][j] < min) {
					min = arr[i][j];
				}
			}
	Output_Array(arr, size);
	cout << "Min on the main diagonal: " << min << endl << "Max on the main diagonal: " << max << endl;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - 1; j++)
			for (int k = 0; k < size - 1; k++)
				if (arr[i][k] > arr[i][k + 1]) {
					int temp = arr[i][k];
					arr[i][k] = arr[i][k + 1];
					arr[i][k + 1] = temp;
				}
	cout << "Sorted Matrix: " << endl;
	Output_Array(arr, size);
	cout << "+------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
	return 0;
}

double Matrix(double arr[][5], double size) {
	srand(2);
	int a = -10, b = 10;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arr[i][j] = a + rand() % (b - a + 1);

	int min = arr[0][0], max = arr[0][0];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (i == j) {
				if (arr[i][j] > max) {
					max = arr[i][j];
				}
				if (arr[i][j] < min) {
					min = arr[i][j];
				}
			}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
	cout << "Min on the main diagonal: " << min << endl << "Max on the main diagonal: " << max << endl;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - 1; j++)
			for (int k = 0; k < size - 1; k++)
				if (arr[i][k] > arr[i][k + 1]) {
					int temp = arr[i][k];
					arr[i][k] = arr[i][k + 1];
					arr[i][k + 1] = temp;
				}

	cout << "Sorted Matrix: " << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
	cout << "+------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
	return 0;
}

char Matrix(float arr[][5], int size) {
	srand(3);
	int a = -10, b = 10;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arr[i][j] = a + rand() % (b - a + 1);

	int min = arr[0][0], max = arr[0][0];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (i == j) {
				if (arr[i][j] > max) {
					max = arr[i][j];
				}
				if (arr[i][j] < min) {
					min = arr[i][j];
				}
			}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
	cout << "Min on the main diagonal: " << min << endl << "Max on the main diagonal: " << max << endl;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - 1; j++)
			for (int k = 0; k < size - 1; k++) {
				if (arr[i][k] > arr[i][k + 1]) {
					int temp = arr[i][k];
					arr[i][k] = arr[i][k + 1];
					arr[i][k + 1] = temp;
				}
			}
	cout << "Sorted Matrix: " << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
	return 0;
}

int main()
{
	srand(time(0));
	{
		//Завдання 1
		cout << "+====================================================================================================================================================================+" << endl;
		cout << "Overloaded functions" << endl;
		cout << "The square matrix will be initialized, output. The minimum and maximum elements on the matrix mian diagonal (from element 0-0 to element 5-5) will be determined." << endl << "Sorting in ascending order for each matrix row will be done" << endl;
		const int size = 5;
		int arr[size][size];
		double mass[size][size];
		float array[size][size];
		cout << "+------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "Integer function:" << endl;
		Matrix(arr, size);
		cout << "+------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "Double function:" << endl;
		Matrix(mass, size);
		cout << "Char function:" << endl;
		Matrix(array, size);

		cout << "+====================================================================================================================================================================+" << endl << endl << endl;
	}

	{
		//Завдання 2
		cout << "+====================================================================================================================================================================+" << endl;
		cout << "Program finds the greatest common divisor for two entered numbers" << endl;
		int a, b;
		cout << "Enter first number: "; cin >> a;
		cout << "Enter second number: "; cin >> b;
		cout << "Greatest common divisor: " << Gcd(a, b) << endl;
		cout << "+====================================================================================================================================================================+" << endl << endl << endl;

	}

	{
		//Завдання 3
		cout << "+====================================================================================================================================================================+" << endl;
		cout << "Game 'Bulls & Cows'" << endl << "Bot guesses a 4-digit number - You have to gues it" << endl;
		cout << "Hint: the bot can guess repetitive numbers" << endl;
		cout << "After the user enters a number, the program reports how many digits of the number are guessed (bulls) and how many digits are guessed and in the right place (cows)" << endl;
		int a = 1000, b = 9999, bot_num, bot_arr[4], user_arr[4];
		srand(time(0));
		bot_num = a + rand() % (b - a + 1);
		for (int i = 0; i < 4; i++) {
			bot_arr[i] = bot_num % 10;
			bot_num /= 10;
		}

		for (int i = 0; i < 4; i++) {
			cout << "Enter digit of your number (0-9): "; cin >> user_arr[i];
			if (user_arr[i] < 0 || user_arr[i] > 9) {
				cout << "Error: Wrongly entered number" << endl;
				return 1;
			}
		}

		int bools = 0, cows = 0;
		for (int i = 0; i < 4; i++) {
			if (user_arr[i] == bot_arr[0] || user_arr[i] == bot_arr[1] || user_arr[i] == bot_arr[2] || user_arr[i] == bot_arr[3]) {
				bools++;
			}
			if (user_arr[i] == bot_arr[i]) {
				cows++;
			}
		}
		cout << "Bulls: " << bools << endl;
		cout << "Cows: " << cows << endl;

		if (bot_arr[0] == user_arr[0] && bot_arr[1] == user_arr[1] && bot_arr[2] == user_arr[2] && bot_arr[3] == user_arr[3]) {
			cout << "You Won !" << endl;
			cout << "Your try_count: " << 1 << endl;
			cout << "+====================================================================================================================================================================+" << endl;
			return 0;
		}

		cout << "Your number: ";
		for (int i = 0; i < 4; i++) {
			cout << user_arr[i];
		}
		cout << endl;

		Bulls_Cows_Game(bot_arr, user_arr);
	}
	return 0;
}