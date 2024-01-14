#include "function.h"

#define Min(a, b) (a) < (b) ? a : b
#define Max(a, b) (a) > (b) ? a : b
#define pow2(a) (a)*(a)
#define mypow(x, y) (exp((y)*log(x))) 
#define even(a) ((a) % 2 == 0)
#define odd(a) ((a) % 2 != 0)

#define SIZE 10
#define INTEGER
//#define DOUBLE
//#define CHAR

struct Capital {
	char name[20];
	int population;
	int age;
	char sightseeing[50];
	double area;
};
struct Country {
	char name[30];
	char partoftheworld[10];
	int population;
	long long GDP;
	double area;
	Capital capital;
};

void PrintCapital(Capital capital) {
	cout << "---CAPITAL---" << endl;
	cout << "Name of the capital: "  << capital.name << endl;
	cout << "Population: " << capital.population << endl;
	cout << "Area of city: " << capital.area <<  " square kilometers" << endl;
	cout << "Age of city: " << capital.age << endl;
	cout << "Popular sightseeing: " << capital.sightseeing << endl;
	cout << endl;
}
void PrintCountry(Country country, Capital capital) {
	cout << "---COUNTRY---" << endl;
	cout << "Name: " << country.name << endl;
	cout << "Part of of the world: " << country.partoftheworld << endl;
	cout << "Population: " << country.population << endl;
	cout << "GDP: " << country.GDP << "$" << endl;
	cout << "Area of country: " << country.area <<  " square kilometers" << endl;
	cout << "Capital: " << country.capital.name << endl;
}

int main()
{
	{
		//Завдання 1
		int a, b, c, min, max;
		cout << "Enter a: "; cin >> a;
		cout << "Enter b: "; cin >> b;
		cout << "Enter c: "; cin >> c;
		min = Min(a, b);
		max = Max(b, c);
		cout << "Min(a, b) = " << min << endl;
		cout << "Max(c, b) = " << max << endl;
		cout << "a to second power = " << pow2(a) << endl;
		cout << "b to a power = " << mypow(b, a) << endl;
		cout << "Is a even: " << even(a) << endl;
		cout << "Is c odd: " << odd(c) << endl;
	}

	{
		cout << "+=================================================================+" << endl;
		//Завдання 2
#ifdef INTEGER
		cout << "-------Integer-------" << endl;
		int arr[SIZE];
		setrand(arr, SIZE, -10, 10);
		cout << "Generated array: " << endl;
		printarr(arr, SIZE);
		cout << endl;
		cout << "Minimal value: " << minarr(arr, SIZE) << endl;
		cout << "Maximal value: " << maxarr(arr, SIZE) << endl;
		cout << "Sorted: " << endl;
		sortarr(arr, SIZE);
		printarr(arr, SIZE);
		cout << endl;

		int ind, elem;
		cout << "Enter index of element you want to edit: "; cin >> ind;
		if (ind < 0 || ind > SIZE) {
			cout << "Wrong entered index" << endl;
			return 1;
		}
		cout << "Enter new element: "; cin >> elem;
		editelem(arr, elem, ind);
		printarr(arr, SIZE);
		cout << endl;

#endif

#ifdef DOUBLE
		cout << "-------Double-------" << endl;
		double array[SIZE];
		setrand(array, SIZE, -10, 10);
		cout << "Generated array: " << endl;
		printarr(array, SIZE);
		cout << endl;
		cout << "Minimal value: " << minarr(array, SIZE); cout << endl;
		cout << "Maximal value: " << maxarr(array, SIZE); cout << endl;
		cout << "Sorted: " << endl;
		sortarr(array, SIZE);
		printarr(array, SIZE);
		cout << endl;

		int index;
		double element;
		cout << "Enter index of element you want to edit: "; cin >> index;
		if (index < 0 || index > SIZE) {
			cout << "Wrong entered index" << endl;
			return 1;
		}
		cout << "Enter new element: "; cin >> element;
		editelem(array, element, index);
		printarr(array, SIZE);
		cout << endl;
#endif

#ifdef CHAR
		cout << "-------Char-------" << endl;
		char mas[SIZE];
		setrand(mas, SIZE);
		cout << "Generated array: " << endl;
		printarr(mas, SIZE);
		cout << endl;
		cout << "Minimal value: " << minarr(mas, SIZE) << endl;
		cout << "Maximal value: " << maxarr(mas, SIZE) << endl;
		cout << "Sorted: " << endl;
		sortarr(mas, SIZE);
		printarr(mas, SIZE);
		cout << endl;

		int pos;
		char sym;
		cout << "Enter index of element you want to edit: "; cin >> pos;
		if (pos < 0 || pos > SIZE) {
			cout << "Wrong entered index" << endl;
			return 1;
		}
		cout << "Enter new element: "; cin >> sym;
		editelem(mas, sym, pos);
		printarr(mas, SIZE);
		cout << endl;
#endif
		cout << "+=================================================================+" << endl;
	}

	{
		//Завдання 3

#define USA 0
#define Italy 1
#define Austalia 2
#define COUNTRY Italy
#define CAPITAL

		Capital capitals[3]{
			{"Washington", 7615000, 220, "United States Capitol and Capitol Hill", 177}, 
			{"Rome", 2873000, 2800, "The Colosseum and the Arch of Constantine", 1285}, 
			{"Canberra", 395790, 108, "Australian War Memorial", 814.2}
		};
		Country countries[3]{
			{"United States of America", "America", 328200000, 2143000000000, 9834000, capitals[0]}, 
			{"Italy", "Europe", 60360000, 2004000000, 301340, capitals[1]}, 
			{"Australia", "Australia", 25360000, 1397000000, 7692000, capitals[2]}
		};

#if COUNTRY == USA
		PrintCountry(countries[0], capitals[0]);
#ifdef CAPITAL
		PrintCapital(capitals[0]);
#endif

#elif COUNTRY == Italy
		PrintCountry(countries[1], capitals[1]);
#ifdef CAPITAL
		PrintCapital(capitals[1]);
#endif

#elif COUNTRY == Australia
		PrintCountry(countries[2], capitals[2]);
#ifdef CAPITAL
		PrintCapital(capitals[2]);
#endif

#endif
	}
	return 0;
}