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

struct Worker {
	char Surname[50];
	int Age;
	float salary;
	char position[50];
};
void CreateFile(const char* fname) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "wt");
	if (nError) {
		cout << "Error write file: " << fname << "\tError: " << nError << endl;
	}
	fclose(fs);
}
/*void Save_Worker(const char* fname, Worker wr) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "wt");
	if (nError) {
		cout << "Error write file: " << fname << "\tError: " << nError << endl;
	}
	fprintf(fs, "%s\t", wr.Surname);
	fprintf(fs, "%d\t", wr.Age);
	fprintf(fs, "%d\t", wr.salary);
	fprintf(fs, "%s\n", wr.position);
	fclose(fs);
}*/
void Save_Workers_Arr(const char* fname, Worker* wr, int n) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "wt");
	if (nError) {
		cout << "Error write file: " << fname << "\tError:" << nError << endl;
		exit(3);
	}
	fprintf(fs, "%d\n", n);
	for (int i = 0; i < n; i++) {
		fprintf(fs, "%20s\t", wr[i].Surname);
		fprintf(fs, "%20d\t", wr[i].Age);
		fprintf(fs, "%20fl\t", wr[i].salary);
		fprintf(fs, "%20s\n", wr[i].position);
	}
	fclose(fs);
}
void Print_Worker(Worker& wr) {
	cout << "Surname: " << wr.Surname << endl;
	cout << "Age: " << wr.Age << endl;
	cout << "Salary: " << wr.salary << endl;
	cout << "Position: " << wr.position << endl;
}
void Input_Worker(Worker& wr) {
	cout << "Enter Surname: "; cin >> wr.Surname;
	cout << "Enter age: "; cin >> wr.Age;
	cout << "Enter salary: "; cin >> wr.salary;
	cout << "Enter position of worker: "; cin >> wr.position;
}
void Input_Workers_Arr(Worker* workers, int n) {
	for (int i = 0; i < n; i++) {
		cout << i << " Worker: " << endl;
		Input_Worker(workers[i]);
		cout << endl;
	}
}
void Edit(Worker* workers, int n) {
	const char* Menu_for_edit[]{
		"Edit Surname",
		"Edit Age",
		"Edit Salary",
		"Edit position",
		"Exit"
	};
	for (int i = 0; i < n; i++) {
		cout << i << ") ";
		Print_Worker(workers[i]);
	}
	int pos;
	cout << "Enter number of worker you want to edit: "; cin >> pos;
	if (pos >= 0 && pos <= n) {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		size_t sizeMenu = sizeof(Menu_for_edit) / sizeof(*Menu_for_edit);
		SetColor(BACKGROUND, FOREGROUNG);
		system("cls");
		size_t select = 0;

		select = Menu(Menu_for_edit, sizeMenu, 0);
		system("cls");
		switch (select)
		{
		case 4:
			return;

		case 0:
			cout << "Enter surname of the worker: "; cin >> workers[pos].Surname;
			break;

		case 1:
			cout << "Enter age of the worker: "; cin >> workers[pos].Age;
			break;

		case 2:
			cout << "Enter salary of the worker: "; cin >> workers[pos].salary;
			break;

		case 3:
			cout << "Enter Position of the worker: "; cin >> workers[pos].position;
			break;

		default:
			break;
		}
	}
	else cout << "Error: Wrong enetered number" << endl;
}
void Delete_Worker(const char* all, Worker* workers, int& n) {
	for (int i = 0; i < n; i++) {
		cout << i << ") " << endl;
		Print_Worker(workers[i]);
	}
	int pos;
	cout << "Enter number of worker you want to edit: "; cin >> pos;

	if (pos < 0 || pos > n)
		cout << "Error: Wrong enetered number" << endl;

	Worker* tmpwr = new Worker[n - 1];
	for (int i = 0; i < pos; i++)
		tmpwr[i] = workers[i];
	for (int i = pos + 1; i < n; i++)
		tmpwr[i - 1] = workers[i];
	delete[] workers;
	workers = tmpwr;
	n--;
	Save_Workers_Arr(all, workers, n);
}
void SearchBySurname(const char* fname, Worker* wr, size_t size) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "wt");
	if (nError) {
		cout << "Error write file: " << fname << "\tError:" << nError << endl;
		exit(3);
	}
	char* surname = new char[50];
	cout << "Enter surname of worker you want to search: "; cin >> surname;
	for (int i = 0; i < size; i++)
		if (strcmp(wr[i].Surname, surname) == 0) {
			Print_Worker(wr[i]);
			fprintf(fs, "%s\t", wr[i].Surname);
			fprintf(fs, "%d\t", wr[i].Age);
			fprintf(fs, "%lf\t", wr[i].salary);
			fprintf(fs, "%s\n", wr[i].position);
		}
	fclose(fs);
}
void OutPut_ByAge(const char* fname, Worker* wr, size_t size) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "wt");
	if (nError) {
		cout << "Error write file: " << fname << "\tError:" << nError << endl;
		exit(3);
	}
	int age;
	cout << "Enter age of worker you want to output: "; cin >> age;
	for (int i = 0; i < size; i++)
		if (wr[i].Age == age) {
			Print_Worker(wr[i]);
			fprintf(fs, "%s\t", wr[i].Surname);
			fprintf(fs, "%d\t", wr[i].Age);
			fprintf(fs, "%lf\t", wr[i].salary);
			fprintf(fs, "%s\n", wr[i].position);
		}
	fclose(fs);
}
void OutPut_ByFLofSurname(const char* fname, Worker* wr, size_t size) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "wt");
	if (nError) {
		cout << "Error write file: " << fname << "\tError:" << nError << endl;
		exit(3);
	}
	char l;
	cout << "Enter first letter of surname of the worker you want to output: "; cin >> l;
	for (int i = 0; i < size; i++)
		if (wr[i].Surname[0] == l) {
			Print_Worker(wr[i]);
			fprintf(fs, "%s\t", wr[i].Surname);
			fprintf(fs, "%d\t", wr[i].Age);
			fprintf(fs, "%lf\t", wr[i].salary);
			fprintf(fs, "%s\n", wr[i].position);
		}
	fclose(fs);
}
Worker* Load_Worker(const char* fname, size_t size) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "rt");
	if (nError) {
		cout << "Error write file: " << fname << "\tError:" << nError << endl;
		exit(3);
	}
	Worker* wr = new Worker[size]{ 0 };
	for (int i = 0; i < size; i++) {
		fscanf(fs, "%s", &wr[i].Surname);
		fscanf(fs, "%d", &wr[i].Age);
		fscanf(fs, "%f", &wr[i].salary);
		fscanf(fs, "%s", &wr[i].position);
	}
	fclose(fs);
	return wr;
}

int main()
{
	const char* allworkers = "workers.txt";
	const char* surname = "search_by_surname_workers.txt";
	const char* age = "output_by_age_workers.txt";
	const char* fl = "first_letter_of_surname_workers.txt";

	CreateFile(surname);
	CreateFile(age);
	CreateFile(fl);

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char* filemenu[]{
		"1) Use default workers array",
		"2) Input new array"
	};

	size_t sizeMenu = sizeof(filemenu) / sizeof(*filemenu);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");


	int choice = Menu(filemenu, sizeMenu, 0);
	switch (choice)
	{
	case 0: {
		const char* textMenu[]{
		"1) Edit Worker",
		"2) Delete Worker",
		"3) Search by Surname",
		"4) Output by Age",
		"5) Output by first letter of surname",
		"6) Save",
		"7) Exit"
		};
		size_t sizeMenu = sizeof(textMenu) / sizeof(*textMenu);
		SetColor(BACKGROUND, FOREGROUNG);
		system("cls");
		size_t select = 0;
		int n;
		int* arr = new int[] {0};

		int size = 3;
		Worker* workers = Load_Worker("default.txt", size);

		while (true)
		{
			select = Menu(textMenu, sizeMenu, 0);
			system("cls");
			switch (select)
			{

			case 0:
				Edit(workers, size);
				Save_Workers_Arr(allworkers, workers, size);
				break;

			case 1:
				Delete_Worker(allworkers, workers, size);
				break;

			case 2:
				SearchBySurname(surname, workers, size);
				break;

			case 3:
				OutPut_ByAge(age, workers, size);
				break;

			case 4:
				OutPut_ByFLofSurname(fl, workers, size);
				break;

			case 5:
				Save_Workers_Arr(allworkers, workers, size);
				break;

			case 6:
				Save_Workers_Arr(allworkers, workers, size);
				return select;
			}
			cout << "---DONE---\n";
			_getch();
		}
		delete[] workers;
		break;
	}

	case 1: {
		const char* textMenu[]{
		"1) Input",
		"2) Edit Worker",
		"3) Delete Worker",
		"4) Search by Surname",
		"5) Output by Age",
		"6) Output by first letter of surname",
		"7) Save",
		"8) Exit"
		};
		size_t sizeMenu = sizeof(textMenu) / sizeof(*textMenu);
		SetColor(BACKGROUND, FOREGROUNG);
		system("cls");
		size_t select = 0;
		int n;
		int* arr = new int[] {0};

		int size = 3;
		cout << "Enter how many workers you want to input: "; cin >> size;
		Worker* workers = new Worker[size];

		while (true)
		{
			select = Menu(textMenu, sizeMenu, 0);
			system("cls");
			switch (select)
			{

			case 0:
				Input_Workers_Arr(workers, size);
				Save_Workers_Arr(allworkers, workers, size);
				break;

			case 1:
				Edit(workers, size);
				Save_Workers_Arr(allworkers, workers, size);
				break;

			case 2:
				Delete_Worker(allworkers, workers, size);
				break;

			case 3:
				SearchBySurname(surname, workers, size);
				break;

			case 4:
				OutPut_ByAge(age, workers, size);
				break;

			case 5:
				OutPut_ByFLofSurname(fl, workers, size);
				break;

			case 6:
				Save_Workers_Arr(allworkers, workers, size);
				break;

			case 7:
				Save_Workers_Arr(allworkers, workers, size);
				return select;
			}
			cout << "---DONE---\n";
			_getch();
		}
		delete[] workers;
		break;
	}

	default:
		cout << "Error: You enetered wrong number" << endl;
		break;
	}
	return 0;
}