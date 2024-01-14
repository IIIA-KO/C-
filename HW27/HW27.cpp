#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

template<class T>
T** CreateArr2D(size_t r, size_t c) {
	T** arr = new T * [r];
	for (size_t i = 0; i < r; i++)
		arr[i] = new T[c]{ 0 };
	return arr;
}

template<class T>
void PrintArr(T** arr, size_t r, size_t c) {
	for (size_t i = 0; i < r; i++)
	{
		for (size_t j = 0; j < c; j++)
			cout << setw(12) << arr[i][j];
		cout << "\n";
	}
	cout << "\n";
}

template<class T>
void SetRandomArr(T** arr, size_t r, size_t c, T a, T b) {
	for (size_t i = 0; i < r; i++)
		for (size_t j = 0; j < c; j++) {
			double k = rand() / (double)RAND_MAX;
			arr[i][j] = a + (b - a) * k;
		}
}
template<class T>
void Delete2D(T**& arr, size_t r)
{
	for (size_t i = 0; i < r; i++)
		delete[] arr[i];
	delete[] arr;
	arr = nullptr;
}

template<class T>
T** Transport_Matrix(T** arr, size_t r, size_t c) {
	size_t rt = c, ct = r;
	T** arrt = CreateArr2D<int>(rt, ct);
	for (int i = 0; i < rt; i++)
		for (int j = 0; j < ct; j++)
			arrt[i][j] = arr[j][i];
	return arrt;
}

template<class T>
void Print(T* arr, size_t size) {
	for (size_t j = 0; j < size; j++)
		cout << setw(12) << arr[j];
	cout << "\n";
}

void Delete(int*& mas, int& n, size_t pos) {
	int* temp = new int[n - 1];
	memcpy(temp, mas, pos * sizeof(*mas));
	memcpy(temp + pos, mas + pos + 1, (n - pos - 1) * sizeof(*mas));
	n--;
	delete[] mas;
	mas = temp;
}

template<class T>
void Unique(T*& arr, size_t& size) {
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (arr[i] == arr[j]) {
				for (int k = j; k < size - 1; k++)
					arr[k] = arr[k + 1];
				size--;
				if (arr[i] == arr[j])
					j--;
			}
}

int main()
{
	{
		//Завдання 1
		cout << "+==========================================================================================================================================================================+" << endl;
		cout << "Transporting Matrix: " << endl;
		size_t r = 5, c = 7;
		size_t rt = c, ct = r;

		int** arr = CreateArr2D<int>(r, c);
		SetRandomArr(arr, r, c, -10, 10);

		int** arrt = Transport_Matrix(arr, r, c);
		cout << "Your array: " << endl;
		PrintArr(arr, r, c);

		cout << "Transported array: " << endl;
		PrintArr(arrt, rt, ct);
		Delete2D(arr, r);
		Delete2D(arrt, rt);
		cout << "+==========================================================================================================================================================================+" << endl << endl << endl;
	}

	{
		//Завдання 2
		cout << "+==========================================================================================================================================================================+" << endl;
		size_t ra, ca, rb, cb, rc, cc;
		cout << "Enter rows for A matrix (1 <= row <= 20): "; cin >> ra;
		cout << "Enter columns for A matrix (1 <= column <= 20): "; cin >> ca; cout << endl;
		cout << "Enter rows for B matrix (1 <= row <= 20): "; cin >> rb;
		cout << "Enter columns for B matrix (1 <= column <= 20): "; cin >> cb; cout << endl;
		cout << "Enter rows for C matrix (1 <= row <= 20): "; cin >> rc;
		cout << "Enter columns for C matrix (1 <= column <= 20): "; cin >> cc; cout << endl;

		if (ra < 1 || ca < 1 || rb < 1 || cb < 1 || rc < 1 || cc < 1 || ra > 20 || ca > 20 || rb > 20 || cb > 20 || rc > 20 || cc > 20) {
			cout << "Error: wrongly entered row or column" << endl;
			cout << "+==========================================================================================================================================================================+" << endl << endl << endl;
			return 1;
		}

		int** mata = CreateArr2D<int>(ra, ca);
		cout << "Matrix A: " << endl;
		SetRandomArr(mata, ra, ca, -10, 10);
		PrintArr(mata, ra, ca);
		cout << endl;

		int** matb = CreateArr2D<int>(rb, cb);
		cout << "Matrix B: " << endl;
		SetRandomArr(matb, rb, cb, -10, 10);
		PrintArr(matb, rb, cb);
		cout << endl;

		int** matc = CreateArr2D<int>(rc, cc);
		cout << "Matrix C: " << endl;
		SetRandomArr(matc, rc, cc, -10, 10);
		PrintArr(matc, rc, cc);
		cout << endl;
	

		{
			//2.1
			cout << "+==========================================================================================================================================================================+" << endl;
			int* mat = new int[(((ra * ca) * (rb * cb) * (rc * cc)) * 2)]{};
			size_t count = 0;

			for (int i = 0; i < ra; i++) {
				for (int j = 0; j < ca; j++)
					for (int u = 0; u < rb; u++)
						for (int o = 0; o < cb; o++)
							if (mata[i][j] == matb[u][o])
								for (int k = 0; k < rc; k++) {
									for (int l = 0; l < cc; l++) {
										if (mata[i][j] == matc[k][l]) {
											mat[count++] = mata[i][j];
										}
									}
								}
			}

			Unique(mat, count);
			cout << "Same elements of A, B & C: " << endl;
			Print(mat, count);
			delete[] mat;
			cout << "+==========================================================================================================================================================================+" << endl << endl << endl;
		}

		{
			//2.2
			cout << "+==========================================================================================================================================================================+" << endl;
			cout << "Unique elements of A, B & C: " << endl;
			int* mat = new int[(((ra * ca) * (rb * cb) * (rc * cc)) * 2)]{};
			size_t count = 0;
			for (int i = 0; i < ra; i++) {
				for (int j = 0; j < ca; j++) {
					mat[count++] = mata[i][j];
				}
			}
			for (int i = 0; i < rb; i++) {
				for (int j = 0; j < cb; j++) {
					mat[count++] = matb[i][j];
				}
			}
			for (int i = 0; i < rc; i++) {
				for (int j = 0; j < cc; j++) {
					mat[count++] = matc[i][j];
				}
			}
			Unique(mat, count);
			Print(mat, count);
			delete[] mat;
			cout << "+==========================================================================================================================================================================+" << endl << endl << endl;
		}

		{
			//2.3
			cout << "+==========================================================================================================================================================================+" << endl;
			size_t count = 0;
			int* mat = new int[(((ra * ca) * (rb * cb) * (rc * cc)) * 2)];

			for (int i = 0; i < ra; i++)
				for (int j = 0; j < ca; j++)
					for (int k = 0; k < rc; k++)
						for (int l = 0; l < cc; l++)
							if (mata[i][j] == matc[k][l])
								mat[count++] = mata[i][j];
			cout << "Same elements of A & C: " << endl;
			Unique(mat, count);
			Print(mat, count);
			delete[] mat;
			cout << "+==========================================================================================================================================================================+" << endl << endl << endl;
		}

		{
			//2.4
			cout << "+==========================================================================================================================================================================+" << endl;
			int* mat = new int[(((ra * ca) * (rb * cb) * (rc * cc)) * 2)];
			size_t count = 0;

			for (int i = 0; i < ra; i++) {
				for (int j = 0; j < ca; j++) {
					if (mata[i][j] < 0) {
						mat[count++] = mata[i][j];
					}
				}
			}

			for (int i = 0; i < rb; i++) {
				for (int j = 0; j < cb; j++) {
					if (matb[i][j] < 0) {
						mat[count++] = matb[i][j];
					}
				}
			}

			for (int i = 0; i < rc; i++) {
				for (int j = 0; j < cc; j++) {
					if (matc[i][j] < 0) {
						mat[count++] = matc[i][j];
					}
				}
			}
			cout << "Elements less than 0 of A, B & C: " << endl;
			Unique(mat, count);
			Print(mat, count);
			delete[] mat;
		}
		cout << "+==========================================================================================================================================================================+" << endl << endl << endl;
	}
	return 0;
}