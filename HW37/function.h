#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

#define INTEGER
//#define DOUBLE
//#define CHAR

void SetRandomInt(int arr[], size_t size, int a, int b);
void PrintInt(int* a, size_t size);
int MinInt(int* arr, size_t size);
int MaxInt(int* arr, size_t size);
void SortInt(int* arr, size_t size);
void EditInt(int* arr, int elem, size_t ind);

void SetRandomDouble(double arr[], size_t size, double a, double b);
void PrintDouble(double* a, size_t size);
double MinDouble(double* arr, size_t size);
double MaxDouble(double* arr, size_t size);
void SortDouble(double* arr, size_t size);
void EditDouble(double* arr, double elem, size_t ind);

void SetRandomChar(char* arr, size_t size);
void PrintChar(char* a, size_t size);
char MinChar(char* arr, size_t size);
char MaxChar(char* arr, size_t size);
void SortChar(char* arr, size_t size);
void EditChar(char* arr, char elem, size_t ind);

#ifdef INTEGER
#define setrand SetRandomInt
#define printarr PrintInt
#define minarr MinInt
#define maxarr MaxInt
#define sortarr SortInt
#define editelem EditInt
#endif

#ifdef DOUBLE
#define setrand SetRandomDouble
#define printarr PrintDouble
#define minarr MinDouble
#define maxarr MaxDouble
#define sortarr SortDouble
#define editelem EditDouble
#endif

#ifdef CHAR
#define setrand SetRandomChar
#define printarr PrintChar
#define minarr MinChar
#define maxarr MaxChar
#define sortarr SortChar
#define editelem EditChar
#endif 

