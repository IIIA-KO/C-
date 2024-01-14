#include <iostream>
#include <iomanip>
#include<conio.h>
#include <Windows.h>
using namespace std;
#define BACKGROUND 0
#define FOREGROUNG 2
#define SELECTITEMMENU 15
#define LEFTMENU 85
#define TOPMENU 18

void SetColor(unsigned short backColor, unsigned short foreColor) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD color = ((backColor & 0x0F) << 4) + (foreColor & 0x0F);
	SetConsoleTextAttribute(h, color);
}
void SetСursor(unsigned short row, unsigned short col) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord{ col, row };
	SetConsoleCursorPosition(h, coord);
}
void paintMenu(const char** textMenu, size_t sizeMenu, size_t select = 0) {
	system("cls");
	SetСursor(TOPMENU, LEFTMENU);
	cout << "...............MENU..............." << endl;
	for (size_t i = 0; i < sizeMenu; i++)
	{
		SetСursor(TOPMENU + i + 1, LEFTMENU);
		if (i == select) {
			SetColor(BACKGROUND, SELECTITEMMENU);
			cout << "=> " << textMenu[i] << endl;
		}
		else {
			cout << "  " << textMenu[i] << endl;
		}
		SetColor(BACKGROUND, FOREGROUNG);
	}
}
size_t Menu(const char** textMenu, size_t sizeMenu, size_t select = 0) {
	unsigned char c = 80;
	while (true)
	{
		if (c == 72 || c == 80)
			paintMenu(textMenu, sizeMenu, select);
		c = _getch();
		switch (c) {
		case 13:
			return select;
		case 72:
			if (select == 0) select = sizeMenu;
			select--;
			break;
		case 80:
			select++;
			if (select == sizeMenu) select = 0;
			break;
		}
	}
	return 0;
}

struct Date {
	int day, month, year;
};
struct Good {
	char name[40];
	char department[40];
	double price;
	int code;
	Date realese_date;
	Date shelf_life;
};
struct Shop {
	char name[30];
	int count_of_goods;
	Good* goods;
};

void Save_Shop(const char* fname, const Shop& shop) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "wt");
	if (nError) {
		cout << "Error write file: " << fname << "\tError: " << nError << endl;
	}
	fwrite(shop.name, sizeof(shop.name), 1, fs);
	fwrite(shop.goods, sizeof(Good), shop.count_of_goods, fs);
	fclose(fs);
}
void Output_good(Good& good) {
	printf("|%*s|%20s|%10.2lf|%4d|%2d. %2d. %5d|%2d. %2d. %5d|\n",
		20, good.name, good.department, good.price, good.code, good.realese_date.day, good.realese_date.month, good.realese_date.year, good.shelf_life.day, good.shelf_life.month, good.shelf_life.year);
}
void Output_shop(Shop& shop) {
	printf("Shop Name: %s\n", shop.name);
	printf("|%20s|%20s|%10s|%4s|%13s|%13s|\n", "Name", "Department", "Price", "Code", "Realese Date", "Shelf Life");
	for (int i = 0; i < shop.count_of_goods; i++) Output_good(shop.goods[i]);
}

double Discount(double total_price) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char* discount[]{
		"1) Yes",
		"2) No"
	};
	size_t sizeMenu = sizeof(discount) / sizeof(*discount);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");
	size_t select = 0;
	cout << "Does customer have discount card ? " << endl;
	while (true) {
		select = Menu(discount, sizeMenu, 0);
		system("cls");
		switch (select) {
		case 0:
			total_price *= 0.92;
			cout << "Customer got a discount 8%" << endl;
			return total_price;
			break;
		case 1:
			return total_price;
		}
	}
}
int Goods_Menu(Shop& shop) {
	int choice;
	cout << "|" << setw(23) << "Name" << "|" << setw(10) << "Price" << "|" << endl;
	for (int i = 0; i < shop.count_of_goods; i++) {
		cout << "|" << setw(3) << i + 1 << " " << setw(10) << shop.goods[i].name << setw(10) << "|" << setw(10) << shop.goods[i].price << "|" << endl;
	}
	cout << "Enter number of product customer wants to buy: "; cin >> choice;
	if (choice < 1 || choice >(shop.count_of_goods + 1)) {
		cout << "Error: Wrong entered number" << endl;
		return 1;
	}
	choice -= 1;
	return choice;
}
void Serve_Customer(Shop& shop) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char* textMenu[]{
		"1) Add product",
		"2) Exit"
	};
	size_t sizeMenu = sizeof(textMenu) / sizeof(*textMenu);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");
	size_t select = 0;

	double total_price = 0;
	int weight = 0, choice = 0;

	while (true)
	{
		total_price += (shop.goods[choice].price / 100) * weight;
		select = Menu(textMenu, sizeMenu, 0);
		system("cls");
		switch (select)
		{
		case 0:
			weight = 0;
			choice = Goods_Menu(shop);
			cout << "You choosed " << shop.goods[choice].name << endl;
			cout << "Enter weight of " << shop.goods[choice].name << " in grams: "; cin >> weight;
			break;

		case 1:
			total_price = Discount(total_price);
			cout << "Total Bill: " << total_price << endl;
			return;
		}
		cout << "=======DONE=======\n";
		_getch();
	}
}

void Sort(const char* fname, Shop& shop, int size) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char* sort_menu[]{
		"1) Sort by Name",
		"2) Sort by Department",
		"3) Sort by Price",
		"4) Sort by Identification code",
		"5) Sort by Realese date",
		"6) Sort by Shelf Life date",
		"7) Exit"
	};
	size_t sizeMenu = sizeof(sort_menu) / sizeof(*sort_menu);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");
	size_t select = 0;
	while (true) {
		select = Menu(sort_menu, sizeMenu, 0);
		system("cls");
		switch (select)
		{
		case 0:
			for (int i = 0; i < size - 1; i++)
				for (int j = i + 1; j < size; j++)
					if (strcmp(shop.goods[i].name, shop.goods[j].name) == 1) {
						Good tmp = shop.goods[i];
						shop.goods[i] = shop.goods[j];
						shop.goods[j] = tmp;
						Save_Shop(fname, shop);
					}
			Output_shop(shop);
			break;
		case 1:
			for (int i = 0; i < size - 1; i++)
				for (int j = i + 1; j < size; j++)
					if (strcmp(shop.goods[i].department, shop.goods[j].department) == 1) {
						Good tmp = shop.goods[i];
						shop.goods[i] = shop.goods[j];
						shop.goods[j] = tmp;
						Save_Shop(fname, shop);
					}
			Output_shop(shop);
			break;
		case 2:
			for (int i = 0; i < size - 1; i++)
				for (int j = i + 1; j < size; j++)
					if (shop.goods[i].price > shop.goods[j].price) {
						Good tmp = shop.goods[i];
						shop.goods[i] = shop.goods[j];
						shop.goods[j] = tmp;
						Save_Shop(fname, shop);
					}
			Output_shop(shop);
			break;
		case 3:
			for (int i = 0; i < size - 1; i++)
				for (int j = i + 1; j < size; j++)
					if (shop.goods[i].code > shop.goods[j].code) {
						Good tmp = shop.goods[i];
						shop.goods[i] = shop.goods[j];
						shop.goods[j] = tmp;
						Save_Shop(fname, shop);
					}
			Output_shop(shop);
			break;
		case 4:
			for (int i = 0; i < size - 1; i++)
				for (int j = i + 1; j < size; j++)
					if (shop.goods[i].realese_date.year > shop.goods[j].realese_date.year ||
						shop.goods[i].realese_date.year == shop.goods[j].realese_date.year &&
						shop.goods[i].realese_date.month > shop.goods[j].realese_date.month ||
						shop.goods[i].realese_date.year == shop.goods[j].realese_date.year &&
						shop.goods[i].realese_date.month == shop.goods[j].realese_date.month &&
						shop.goods[i].realese_date.day > shop.goods[j].realese_date.day) {
						Good tmp = shop.goods[i];
						shop.goods[i] = shop.goods[j];
						shop.goods[j] = tmp;
						Save_Shop(fname, shop);
					}
			Output_shop(shop);
			break;
		case 5:
			for (int i = 0; i < size - 1; i++)
				for (int j = i + 1; j < size; j++)
					if (shop.goods[i].shelf_life.year > shop.goods[j].shelf_life.year ||
						shop.goods[i].shelf_life.year == shop.goods[j].shelf_life.year &&
						shop.goods[i].shelf_life.month > shop.goods[j].shelf_life.month ||
						shop.goods[i].shelf_life.year == shop.goods[j].shelf_life.year &&
						shop.goods[i].shelf_life.month == shop.goods[j].shelf_life.month &&
						shop.goods[i].shelf_life.day > shop.goods[j].shelf_life.day) {
						Good tmp = shop.goods[i];
						shop.goods[i] = shop.goods[j];
						shop.goods[j] = tmp;
						Save_Shop(fname, shop);
					}
			Output_shop(shop);
			break;
		case 6:
			return;
		}
		SetСursor(28, 102);
		cout << "=======DONE=======\n";
		_getch();
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char* textMenu[]{
		"1) Serve the customer",
		"2) Save information about store",
		"3) Output information about store",
		"4) Sort goods by...",
		"5) Exit"
	};
	size_t sizeMenu = sizeof(textMenu) / sizeof(*textMenu);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");
	size_t select = 0;
	int count = 10;
	Good* goods_list = new Good[count]{
		{"Milk", "Dairy", 4.99, 101, {10, 3, 2021}, {10, 4, 2021}},
		{"Cheese", "Dairy", 3.25, 102, {2, 3, 2021}, {20, 3, 2021}},
		{"Eggs", "Dairy", 1.50, 103, {1, 3, 2021}, {20, 4, 2021}},
		{"Bread", "Baking", 2.50, 201, {5, 3, 2021}, {4, 4, 2021}},
		{"Bun", "Baking", 3.00, 202, {2, 3, 2021}, {10, 3, 2021}},
		{"Pizza", "Baking", 10.90, 203, {12, 3, 2021}, {28, 3, 2021}},
		{"Banana", "Fruits & Vegetables", 3.50, 301, {11, 3, 2021},	{1, 4, 2021}},
		{"Carrot", "Fruits & Vegetables", 2.99, 302,{10, 3, 2021}, {25, 4, 2021}},
		{"Cabbage", "Fruits & Vegetables", 4.00, 303, {9, 3, 2021}, {15, 4, 2021}},
		{"Orange", "Fruits & Vegetables", 3.50, 304, {1, 3, 2021}, {10, 4, 2021}},
	};

	Shop Grocery_Store{ "Grocery Store", count, goods_list };
	const char* fname = "shop.bin";

	while (true)
	{
		select = Menu(textMenu, sizeMenu, 0);
		system("cls");
		switch (select)
		{
		case 0:
			Serve_Customer(Grocery_Store);
			break;

		case 1:
			SetСursor(24, 100);
			cout << "You can check the file !" << endl;
			Save_Shop(fname, Grocery_Store);
			break;

		case 2:
			Output_shop(Grocery_Store);
			break;

		case 3:
			Sort(fname, Grocery_Store, count);
			break;

		case 4:
			Save_Shop(fname, Grocery_Store);
			return 0;

		default:
			break;
		}
		SetСursor(28, 102);
		cout << "=======DONE=======\n";
		_getch();
	}


	return 0;
}