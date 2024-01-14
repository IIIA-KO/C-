#include "function.h"

//функції для int:
void SetRandomInt(int arr[], size_t size, int a, int b) {
	for (int i = 0; i < size; i++)
		arr[i] = a + rand() % (b - a + 1);
}

void PrintInt(int* a, size_t size) {
	for (int i = 0; i < size; i++)
		cout << a[i] << " " << " | ";
}

int MinInt(int* arr, size_t size) {
	int min = arr[0];
	for (int i = 1; i < size; i++)
		if (min > arr[i])
			min = arr[i];
	return min;
}

int MaxInt(int* arr, size_t size) {
	int max = arr[0];
	for (int i = 1; i < size; i++)
		if (max < arr[i])
			max = arr[i];
	return max;
}

void SortInt(int* arr, size_t size) {
	for (int i = 1; i < size; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
			swap(arr[j - 1], arr[j]);
}

void EditInt(int* arr, int elem, size_t ind) {
	arr[ind] = elem;
}

//функції для double:
void SetRandomDouble(double arr[], size_t size, double a, double b) {
	for (int i = 0; i < size; i++)
		arr[i] = a + (double)(b - a) * rand() / RAND_MAX;
}

void PrintDouble(double* a, size_t size) {
	for (int i = 0; i < size; i++)
		cout << a[i] << " " << " | ";
}

double MinDouble(double* arr, size_t size) {
	double min = arr[0];
	for (int i = 1; i < size; i++)
		if (min > arr[i])
			min = arr[i];
	return min;
}

double MaxDouble(double* arr, size_t size) {
	double max = arr[0];
	for (int i = 1; i < size; i++)
		if (max < arr[i])
			max = arr[i];
	return max;
}

void SortDouble(double* arr, size_t size) {
	for (int i = 1; i < size; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
			swap(arr[j - 1], arr[j]);
}

void EditDouble(double* arr, double elem, size_t ind) {
	arr[ind] = elem;
}

//функції для char:
void SetRandomChar(char* arr, size_t size) {
	//double a = 0, b = 255;
	char a = 'a', z = 'z';
	for (int i = 0; i < size; i++)
		arr[i] = a + (double)(z - a) * rand() / RAND_MAX;
}

void PrintChar(char* a, size_t size) {
	for (int i = 0; i < size; i++)
		cout << a[i] << " " << " | ";
}

char MinChar(char* arr, size_t size) {
	char min = arr[0];
	for (int i = 1; i < size; i++)
		if (min > arr[i])
			min = arr[i];
	return min;
}

char MaxChar(char* arr, size_t size) {
	char max = arr[0];
	for (int i = 1; i < size; i++)
		if (max < arr[i])
			max = arr[i];
	return max;
}

void SortChar(char* arr, size_t size) {
	for (int i = 1; i < size; i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
			swap(arr[j - 1], arr[j]);
}

void EditChar(char* arr, char elem, size_t ind) {
	arr[ind] = elem;
}