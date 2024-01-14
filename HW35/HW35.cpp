#include <iostream>
#include <iomanip>
#include<conio.h>
#include <Windows.h>
#define BACKGROUND 1
#define FOREGROUNG 15
#define SELECTITEMMENU 15
#define LEFTMENU 80
#define TOPMENU 15
using namespace std;

void SetColor(unsigned short backColor, unsigned short foreColor) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD color = ((backColor & 0x0F) << 4) + (foreColor & 0x0F);//15;
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


struct Book {
	int ordinal_number;
	char name[100];
	char author[100];
	char publishing_house[100];
	char genre[100];
};

void Input(Book& bk) {
	cout << "+===============================================+" << endl;
	cin.get();
	cout << "Name: "; cin.getline(bk.name, 50);
	cin.get();
	cout << "Author: "; cin.getline(bk.author, 50);
	cin.get();
	cout << "Publishing house: "; cin.getline(bk.publishing_house, 50);
	cin.get();
	cout << "Genge: "; cin.getline(bk.genre, 50);
	cout << "+===============================================+" << endl;
}
void EditBook(Book* bk, const int n) {
	size_t number;
	cout << "Enter book's number: "; cin >> number;
	if (number < 1 || number > 10) {
		cout << "Error: wrongly entered number" << endl;
		return;
	}
	Input(bk[number - 1]);
}
void PrintBk(const Book& bk) {
	cout << "|" << setw(40) << bk.ordinal_number;
	cout << "|" << setw(40) << bk.name;
	cout << "|" << setw(40) << bk.author;
	cout << "|" << setw(40) << bk.publishing_house;
	cout << "|" << setw(40) << bk.genre;
	cout << "|" << endl;
}
void PrintBooks(Book* bk, const int n) {
	for (int i = 0; i < n; i++) PrintBk(bk[i]);
}
void SearchByAuthor(Book* bk, const int n) {
	char* author = new char[100];
	cout << "Enter Name of the Author you want to search: "; cin.getline(author, 100);
	for (int i = 0; i < n; i++)
		if (!strcmp(author, bk[i].author)) {
			PrintBk(bk[i]);
		}
	delete[] author;
}
void SearchByName(Book* bk, const int n) {
	char* name = new char[100];
	cout << "Enter Name of the book you want to search: "; cin.getline(name, 100);
	for (int i = 0; i < n; i++)
		if (!strcmp(name, bk[i].name)) {
			PrintBk(bk[i]);
		}
	delete[] name;
}
void SortByName(Book st[], const int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (strcmp(st[i].name, st[j].name) == 1) {
				Book temp = st[i];
				st[i] = st[j];
				st[j] = temp;
			}
}
void SortByAuthor(Book st[], const int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (strcmp(st[i].author, st[j].author) == 1) {
				Book temp = st[i];
				st[i] = st[j];
				st[j] = temp;
			}
}
void SortByPublisher(Book st[], const int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (strcmp(st[i].publishing_house, st[j].publishing_house) == 1) {
				Book temp = st[i];
				st[i] = st[j];
				st[j] = temp;
			}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char* textMenu[]{
		"1) Edit Book",
		"2) Output all books",
		"3) Search by author",
		"4) Search by name",
		"5) Sort by name",
		"6) Sort by author",
		"7) Sort by publishing house",
		"8) Exit"
	};
	size_t sizeMenu = sizeof(textMenu) / sizeof(*textMenu);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");
	size_t select = 0;
	int n;
	int* arr = new int[] {0};

	const int N = 10;
	Book book[N]{
		{1, "Harry Potter and the Philosopher's Stone", "J. K. Rowling", "Bloomsbury", "Children's Fiction"},
		{2, "Da Vinci Code", "Brown, Dan", "Transworld", "Crime, Thriller & Adventure"},
		{3, "Short History of Nearly Everything", "Bryson, Bill", "Transworld", "Popular Science"},
		{4, "Harry Potter and the Chamber of Secrets", "J. K. Rowling", "Bloomsbury", "Children's Fiction"},
		{5, "Jamie's Italy", "Oliver, Jamie", "Penguin", "National & Regional Cuisine"},
		{6, "Small Island", "Levy, Andrea", "Headline", "General & Literary Fiction"},
		{7, "Harry Potter and the Prisoner of Azkaban", "J. K. Rowling", "Bloomsbury", "Children's Fiction"},
		{8, "Hunger Games,The:Hunger Games Trilogy", "Collins, Suzanne", "Scholastic Ltd.", "Young Adult Fiction"},
		{9, "Book Thief", "Zusak, Markus", "Transworld", "General & Literary Fiction"},
		{10, "1984", "George Orwell", "Houghton Mifflin Harcourt", "Dystopia"},
	};

	while (true)
	{
		select = Menu(textMenu, sizeMenu, 0);
		system("cls");
		switch (select)
		{
		case 7:
			return select;

		case 0:
			EditBook(book, N);
			break;

		case 1:
			cout << "|" << setw(40) << "Ordinal Number";
			cout << "|" << setw(40) << "Name";
			cout << "|" << setw(40) << "Author";
			cout << "|" << setw(40) << "Publishing House";
			cout << "|" << setw(40) << "Genre" << "|";
			cout << endl << endl;
			PrintBooks(book, N);
			break;

		case 2:
			SearchByAuthor(book, N);
			break;

		case 3:
			SearchByName(book, N);
			break;

		case 4:
			SortByName(book, N);
			PrintBooks(book, N);
			break;

		case 5:
			SortByAuthor(book, N);
			PrintBooks(book, N);
			break;

		case 6:
			SortByPublisher(book, N);
			PrintBooks(book, N);
			break;

		default:
			break;
		}
		cout << "---DONE---\n";
		_getch();
	}
	return 0;
}
