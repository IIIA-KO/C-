#include "menu.h"
#include "exam.h"

void Print_Worker_Card(Worker& wr, int choice) {
	if (choice == 0) cout << "|" << setw(13) << "Name |" << setw(13) << " Surname |" << setw(13) << " Patronymic |" << setw(13) << "Bith day |" << setw(11) << " Gender |" << setw(13) << " Hire Date |" << setw(13) << "Subsection |" << setw(13) << "Position |" << setw(16) << " Phone number |" << endl;
	else cout << "|" << setw(13) << "Ім'я |" << setw(13) << " Прізвище |" << setw(13) << "По батькові |" << setw(13) << "День нар. |" << setw(11) << " Стать |" << setw(13) << "День прийнят|" << setw(13) << "Підрозділ |" << setw(13) << "Посада |" << setw(16) << "Номер телефону |" << endl;
	cout << "|" << setw(12) << wr.name;
	cout << "|" << setw(12) << wr.surname;
	cout << "|" << setw(12) << wr.patronymic;
	cout << "|" << wr.birth.day << ". " << wr.birth.month << ". " << wr.birth.year << "  ";
	cout << "|" << setw(10) << wr.gender;
	cout << "|" << wr.hire_date.day << ". " << wr.hire_date.month << ". " << wr.hire_date.year << "  ";
	cout << "|" << setw(12) << wr.subsection;
	cout << "|" << setw(12) << wr.position;
	cout << "|" << setw(15) << wr.phone_num;
	cout << "|" << endl;
}
void Print_Worker(Worker& wr) {
	cout << "|" << setw(12) << wr.surname;
	cout << "|" << setw(5) << wr.name[0] << ". " << wr.patronymic[0] << ". ";
	cout << "|" << setw(12) << wr.subsection;
	cout << "|" << setw(12) << wr.position;
	cout << "|" << setw(15) << wr.phone_num;
	cout << "|" << endl;
}
void Print_Workers_Group(Worker* wr, size_t size, int choice) {
	if (choice == 0)cout << "|" << setw(13) << "Surname |" << setw(10) << "Initials |" << setw(14) << "Subsection |" << setw(13) << "Position |" << setw(16) << "Phone number |" << endl;
	else cout << "|" << setw(13) << "Прізвище |" << setw(10) << " Ініціали |" << setw(13) << " Підрозділ |" << setw(13) << "Посада |" << setw(15) << "Номер телефону |" << endl;
	for (int i = 0; i < size; i++) {
		cout << i << ")" << endl;
		Print_Worker(wr[i]);
	}
	cout << endl;
}
void Save_Worker(const char* fname, Worker wr, int choice) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "wt");
	if (nError) {
		if (choice == 0) cout << "Error write file: " << fname << "\tError: " << nError << endl;
		else cout << "Помилка запису файлу: " << fname << "\tПомилка:" << nError << endl;
		exit(3);
	}
	fprintf(fs, "%20s\t", wr.name);
	fprintf(fs, "%20s\t", wr.surname);
	fprintf(fs, "%20s\t", wr.patronymic);
	fprintf(fs, "%2d\t", wr.birth.day);
	fprintf(fs, "%2d\t", wr.birth.month);
	fprintf(fs, "%2d\t", wr.birth.year);
	fprintf(fs, "%2s\t", wr.gender);
	fprintf(fs, "%2d\t", wr.hire_date.day);
	fprintf(fs, "%2d\t", wr.hire_date.month);
	fprintf(fs, "%2d\t", wr.hire_date.year);
	fprintf(fs, "%15s\t", wr.subsection);
	fprintf(fs, "%15s\t", wr.position);
	fprintf(fs, "%15s\n", wr.phone_num);
	fclose(fs);
}
void Save_Worker_Bin(const char* fname, Worker wr, int choice) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "wt");
	if (nError) {
		if (choice == 0) cout << "Error write file: " << fname << "\tError: " << nError << endl;
		else cout << "Помилка запису файлу: " << fname << "\tПомилка:" << nError << endl;
		exit(3);
	}
	fwrite(&wr.name, sizeof(wr.name), 1, fs);
	fwrite(&wr.surname, sizeof(wr.surname), 1, fs);
	fwrite(&wr.patronymic, sizeof(wr.patronymic), 1, fs);
	fwrite(&wr.birth.day, sizeof(wr.birth.day), 1, fs);
	fwrite(&wr.birth.month, sizeof(wr.birth.month), 1, fs);
	fwrite(&wr.gender, sizeof(wr.gender), 1, fs);
	fwrite(&wr.hire_date.day, sizeof(wr.hire_date.day), 1, fs);
	fwrite(&wr.hire_date.month, sizeof(wr.hire_date.month), 1, fs);
	fwrite(&wr.hire_date.year, sizeof(wr.hire_date.year), 1, fs);
	fwrite(&wr.subsection, sizeof(wr.subsection), 1, fs);
	fwrite(&wr.position, sizeof(wr.position), 1, fs);
	fwrite(&wr.phone_num, sizeof(wr.phone_num), 1, fs);
	fclose(fs);
}
void Save_Workers_Arr(const char* fname, Worker* wr, int n, int choice) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "wt");
	if (nError) {
		if (choice == 0) cout << "Error write file: " << fname << "\tError: " << nError << endl;
		else cout << "Помилка запису файлу: " << fname << "\tПомилка:" << nError << endl;
		exit(3);
	}
	fprintf(fs, "%d\n", n);
	for (int i = 0; i < n; i++) {
		fprintf(fs, "%20s\t", wr[i].name);
		fprintf(fs, "%20s\t", wr[i].surname);
		fprintf(fs, "%20s\t", wr[i].patronymic);
		fprintf(fs, "%2d\t", wr[i].birth.day);
		fprintf(fs, "%2d\t", wr[i].birth.month);
		fprintf(fs, "%2d\t", wr[i].birth.year);
		fprintf(fs, "%2s\t", wr[i].gender);
		fprintf(fs, "%2d\t", wr[i].hire_date.day);
		fprintf(fs, "%2d\t", wr[i].hire_date.month);
		fprintf(fs, "%2d\t", wr[i].hire_date.year);
		fprintf(fs, "%15s\t", wr[i].subsection);
		fprintf(fs, "%15s\t", wr[i].position);
		fprintf(fs, "%15s\n", wr[i].phone_num);
	}
	fclose(fs);
}
Worker Load_Worker(const char* fname, int choice) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "rt");
	if (nError) {
		if (choice == 0) cout << "Error read file: " << fname << "\tError: " << nError << endl;
		else cout << "Помилка читання файлу: " << fname << "\tПомилка:" << nError << endl;
		exit(3);
	}
	Worker wr;
	fscanf(fs, "%s", wr.name);
	fscanf(fs, "%s", wr.surname);
	fscanf(fs, "%s", wr.patronymic);
	fscanf(fs, "%d", &wr.birth.day);
	fscanf(fs, "%d", &wr.birth.month);
	fscanf(fs, "%d", &wr.birth.year);
	fscanf(fs, "%s", wr.gender);
	fscanf(fs, "%d", &wr.hire_date.day);
	fscanf(fs, "%d", &wr.hire_date.month);
	fscanf(fs, "%d", &wr.hire_date.year);
	fscanf(fs, "%s", wr.subsection);
	fscanf(fs, "%s", wr.position);
	fscanf(fs, "%s", wr.phone_num);
	fclose(fs);
	return wr;
}
Worker* Load_Workers_Arr(const char* fname, int size, int choice) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "rt");
	if (nError) {
		if (choice == 0) cout << "Error read file: " << fname << "\tError: " << nError << endl;
		else cout << "Помилка читання файлу: " << fname << "\tПомилка:" << nError << endl;
		exit(3);
	}
	Worker* wr = new Worker[size]{ 0 };
	fscanf(fs, "%d", &size);
	for (int i = 0; i < size; i++) {
		fscanf(fs, "%s", wr[i].name);
		fscanf(fs, "%s", wr[i].surname);
		fscanf(fs, "%s", wr[i].patronymic);
		fscanf(fs, "%d", &wr[i].birth.day);
		fscanf(fs, "%d", &wr[i].birth.month);
		fscanf(fs, "%d", &wr[i].birth.year);
		fscanf(fs, "%s", wr[i].gender);
		fscanf(fs, "%d", &wr[i].hire_date.day);
		fscanf(fs, "%d", &wr[i].hire_date.month);
		fscanf(fs, "%d", &wr[i].hire_date.year);
		fscanf(fs, "%s", wr[i].subsection);
		fscanf(fs, "%s", wr[i].position);
		fscanf(fs, "%s", wr[i].phone_num);
	}
	fclose(fs);
	return wr;
}
void Delete_Worker(const char* fname, Worker*& workers, int& size, int choice, int del_pos) {
	if (del_pos < 0 || del_pos > size) {
		if (choice == 0) cout << "Error: wrongly enter number of worker" << endl;
		else cout << "Помилка: неправильно введений номер" << endl;
	}
	Worker* tmpwr = new Worker[size - 1];
	for (int i = 0; i < del_pos; i++)
		tmpwr[i] = workers[i];
	for (int i = del_pos; i < size - 1; i++)
		tmpwr[i] = workers[i + 1];
	delete[] workers;
	workers = tmpwr;
	size--;
	Save_Workers_Arr(fname, workers, size, choice);
}
Worker Input_Worker(Worker& wr, int choice) {
	cin.get();
	if (choice == 0) {
		cout << "Enter worker's name: "; cin.getline(wr.name, 50); cout << endl;
		cout << "Enter worker's surname: "; cin.getline(wr.surname, 50); cout << endl;
		cout << "Enter worker's patronymic: "; cin.getline(wr.patronymic, 50); cout << endl;
		cout << "Enter day of worker's bitrh: "; cin >> wr.birth.day; cout << endl;
		cout << "Enter month of worker's bitrh: "; cin >> wr.birth.month; cout << endl;
		cout << "Enter year of worker's bitrh: "; cin >> wr.birth.year; cout << endl;
		if ((wr.birth.day < 1 || wr.birth.day > 31) || (wr.birth.month < 1 || wr.birth.month> 12) || (wr.birth.year < 1) || (wr.birth.day > 29 && wr.birth.month == 2)) {
			cout << "Error: wrongly entered number: " << endl;
			exit(1);
		}
		cin.get();
		cout << "Enter worker's gender (M or F): "; cin.getline(wr.gender, 3); cout << endl;
		cout << "Enter day of worker's hire date: "; cin >> wr.hire_date.day; cout << endl;
		cout << "Enter month of worker's hire date: "; cin >> wr.hire_date.month; cout << endl;
		cout << "Enter year of worker's hire date: "; cin >> wr.hire_date.year; cout << endl;
		if ((wr.hire_date.day < 1 || wr.hire_date.day > 31) || (wr.hire_date.month < 1 || wr.hire_date.month > 12) || (wr.hire_date.year < 1) || (wr.hire_date.day > 29 && wr.hire_date.month == 2)) {
			cout << "Error: wrongly entered number" << endl;
			exit(1);
		}
		cin.get();
		cout << "Enter worker's subsection: "; cin.getline(wr.subsection, 50); cout << endl;
		cout << "Enter worker's position: "; cin.getline(wr.position, 50); cout << endl;
		cout << "Enter worker's phone number: "; cin.getline(wr.phone_num, 14); cout << endl;
	}
	else {
		cout << "Введіть ім'я робітника: "; cin.getline(wr.name, 50); cout << endl;
		cout << "Введіть прізвище робітника: "; cin.getline(wr.surname, 50); cout << endl;
		cout << "Введіть по бітькові працівника: "; cin.getline(wr.patronymic, 50); cout << endl;
		cout << "Введіть день народження працівника: "; cin >> wr.birth.day; cout << endl;
		cout << "Введіть місяць народження працівника: "; cin >> wr.birth.month; cout << endl;
		cout << "Введіть рік народження працівника: "; cin >> wr.birth.year; cout << endl;
		if ((wr.birth.day < 1 || wr.birth.day > 31) || (wr.birth.month < 1 || wr.birth.month> 12) || (wr.birth.year < 1) || (wr.birth.day > 29 && wr.birth.month == 2)) {
			cout << "Помилка: неправильно введена дата" << endl;
			exit(1);
		}
		cin.get();
		cout << "Введіть стать працівника (літера Ч аба Ж): "; cin.getline(wr.gender, 3); cout << endl;
		cout << "Введіть день прийняття працівника на роботу: "; cin >> wr.hire_date.day; cout << endl;
		cout << "Введіть місяць прийняття працівника на роботу: "; cin >> wr.hire_date.month; cout << endl;
		cout << "Введіть рік прийняття працівника на роботу: "; cin >> wr.hire_date.year; cout << endl;
		if ((wr.hire_date.day < 1 || wr.hire_date.day > 31) || (wr.hire_date.month < 1 || wr.hire_date.month > 12) || (wr.hire_date.year < 1) || (wr.hire_date.day > 29 && wr.hire_date.month == 2)) {
			cout << "Помилка: неправильно введена дата" << endl;
			exit(1);
		}
		cin.get();
		cout << "Введіть підрозділ працівника: "; cin.getline(wr.subsection, 50); cout << endl;
		cout << "Введіть посаду працівника: "; cin.getline(wr.position, 50); cout << endl;
		cout << "Введіть номер телефону працівника: "; cin.getline(wr.phone_num, 14); cout << endl;
	}
}
void Input_Workers_Group(Worker* wr, size_t size, int choice) {
	for (int i = 0; i < size; i++) {
		if (choice == 0) cout << "Worker № " << i << " " << endl;
		else cout << "Робітник № " << i << " " << endl;
		Input_Worker(wr[i], choice);
	}
}
void Add_Worker(Worker*& workers, Worker elem, int& size, int choice) {
	Worker* temp = new Worker[size + 1]{};
	for (int i = 0; i < size; i++)
		temp[i] = workers[i];
	temp[size] = elem;
	size++;
	delete[] workers;
	workers = temp;
}
void Edit(Worker* workers, int size, int choice) {
	const char* Menu_for_edit[9];
	if (choice == 0) {
		Menu_for_edit[0] = "1) Edit name";
		Menu_for_edit[1] = "2) Edit surname";
		Menu_for_edit[2] = "3) Edit patronymic";
		Menu_for_edit[3] = "4) Edit birth date";
		Menu_for_edit[4] = "5) Edit gender";
		Menu_for_edit[5] = "6) Edit hire date";
		Menu_for_edit[6] = "7) Edit subsection";
		Menu_for_edit[7] = "8) Edit position";
		Menu_for_edit[8] = "9) Edit phone num";
	}
	else {
		Menu_for_edit[0] = "1) Редагувати ім'я";
		Menu_for_edit[1] = "2) Редагувати прізвище";
		Menu_for_edit[2] = "3) Редагувати по батькові";
		Menu_for_edit[3] = "4) Редагувати дату народження";
		Menu_for_edit[4] = "5) Редагувати стать";
		Menu_for_edit[5] = "6) Редагувати дату прийняття на роботу";
		Menu_for_edit[6] = "7) Редагувати підрозділ";
		Menu_for_edit[7] = "8) Редагувати посаду";
		Menu_for_edit[8] = "9) Редагувати номер телефону";
	}
	Print_Workers_Group(workers, size, choice);
	int pos;
	cout << "Enter number of worker you want to edit: "; cin >> pos;
	if (pos < 0 && pos > size) {
		cout << "Error: Wrongly entered number" << endl;
		return;
	}
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
	case 9:
		return;
	case 0:
		if (choice == 0) cout << "Enter worker's name: ";
		else cout << "Введіть ім'я робітника: ";
		cin >> workers[pos].name;
		break;
	case 1:
		if (choice == 0) cout << "Enter worker's surname: ";
		else cout << "Введіть прізвище робітника: ";
		cin >> workers[pos].surname;
		break;
	case 2:
		if (choice == 0) cout << "Enter worker's patronymic: ";
		else cout << "Введіть по бітькові працівника: ";
		cin >> workers[pos].patronymic;
		break;
	case 3:
		if (choice == 0) {
			cout << "Enter day of worker's bitrh: "; cin >> workers[pos].birth.day; cout << endl;
			cout << "Enter month of worker's bitrh: "; cin >> workers[pos].birth.month; cout << endl;
			cout << "Enter year of worker's bitrh: "; cin >> workers[pos].birth.year; cout << endl;
			if ((workers[pos].birth.day < 1 || workers[pos].birth.day > 31) || (workers[pos].birth.month < 1 || workers[pos].birth.month > 12) || (workers[pos].birth.year < 1) || (workers[pos].birth.day > 29 && workers[pos].birth.month == 2)) {
				cout << "Error: wrongly entered number" << endl;
				return;
			}
		}
		else {
			cout << "Введіть день народження працівника: "; cin >> workers[pos].birth.day; cout << endl;
			cout << "Введіть місяць народження працівника: "; cin >> workers[pos].birth.month; cout << endl;
			cout << "Введіть рік народження працівника: "; cin >> workers[pos].birth.year; cout << endl;
			if ((workers[pos].birth.day < 1 || workers[pos].birth.day > 31) || (workers[pos].birth.month < 1 || workers[pos].birth.month > 12) || (workers[pos].birth.year < 1) || (workers[pos].birth.day > 29 && workers[pos].birth.month == 2)) {
				cout << "Помилка: неправильно введена дата" << endl;
				return;
			}
		}
		break;
	case 4:
		if (choice == 0)cout << "Enter worker's gender (M or F): ";
		else cout << "Введіть стать працівника (літера Ч аба Ж): ";
		cin >> workers[pos].gender;
		break;
	case 5:
		if (choice == 0) {
			cout << "Enter day of worker's hire date: "; cin >> workers[pos].hire_date.day; cout << endl;
			cout << "Enter month of worker's hire date: "; cin >> workers[pos].hire_date.month; cout << endl;
			cout << "Enter year of worker's hire date: "; cin >> workers[pos].hire_date.year; cout << endl;
			if ((workers[pos].hire_date.day < 1 || workers[pos].hire_date.day > 31) || (workers[pos].hire_date.month < 1 || workers[pos].hire_date.month > 12) || (workers[pos].hire_date.year < 1) || (workers[pos].hire_date.day > 29 && workers[pos].hire_date.month == 2)) {
				cout << "Error: wrongly entered number" << endl;
				return;
			}
		}
		else {
			cout << "Введіть день прийняття працівника на роботу: "; cin >> workers[pos].hire_date.day; cout << endl;
			cout << "Введіть місяць прийняття працівника на роботу: "; cin >> workers[pos].hire_date.month; cout << endl;
			cout << "Введіть рік прийняття працівника на роботу: "; cin >> workers[pos].hire_date.year; cout << endl;
			if ((workers[pos].hire_date.day < 1 || workers[pos].hire_date.day > 31) || (workers[pos].hire_date.month < 1 || workers[pos].hire_date.month > 12) || (workers[pos].hire_date.year < 1) || (workers[pos].hire_date.day > 29 && workers[pos].hire_date.month == 2)) {
				cout << "Помилка: неправильно введена дата" << endl;
				return;
			}
		}
		break;
	case 6:
		if (choice == 0) cout << "Enter worker's subsection: ";
		else cout << "Введіть підрозділ працівника: ";
		cin >> workers[pos].subsection;
		break;
	case 7:
		if (choice == 0) cout << "Enter worker's position: ";
		else cout << "Введіть посаду працівника: ";
		cin >> workers[pos].position;
		break;
	case 8:
		if (choice == 0) cout << "Enter worker's phone number: ";
		else cout << "Введіть номер телефону працівника: ";
		cin >> workers[pos].position;
		break;
	}
}
void Sort(const char* fname, Worker* workers, size_t size, int choice) {
	setlocale(0, "");
	const char* Menu_for_sort[3];
	if (choice == 0) {
		Menu_for_sort[0] = "1) Sort by SNP";
		Menu_for_sort[1] = "2) Sort by date of birth";
		Menu_for_sort[2] = "3) Sort by subsection and position";
	}
	else {
		Menu_for_sort[0] = "1) Сортувати за ПІБ";
		Menu_for_sort[1] = "2) Сортувати за датою народження";
		Menu_for_sort[2] = "3) Сортувати за підрозділом і посадою";
	}
	Print_Workers_Group(workers, size, choice);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	size_t sizeMenu = sizeof(Menu_for_sort) / sizeof(*Menu_for_sort);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");
	size_t select = 0;
	select = Menu(Menu_for_sort, sizeMenu, 0);
	system("cls");
	switch (select)
	{
	case 3:
		return;
	case 0:
		for (int i = 0; i < size - 1; i++)
			for (int j = i + 1; j < size; j++)
				if (strcoll(workers[i].surname, workers[j].surname) == 1 ||
					strcoll(workers[i].surname, workers[j].surname) == 0 &&
					strcoll(workers[i].name, workers[j].name) == 1 ||
					strcoll(workers[i].surname, workers[j].surname) == 0 &&
					strcoll(workers[i].name, workers[j].name) == 0 &&
					strcoll(workers[i].patronymic, workers[j].patronymic) == 1) {
					Worker tmp = workers[i];
					workers[i] = workers[j];
					workers[j] = tmp;
					Save_Workers_Arr(fname, workers, size, choice);
				}
		Print_Workers_Group(workers, size, choice);
		break;
	case 1:
		for (int i = 0; i < size - 1; i++)
			for (int j = i + 1; j < size; j++)
				if (workers[i].birth.year > workers[j].birth.year ||
					workers[i].birth.year == workers[j].birth.year &&
					workers[i].birth.month > workers[j].birth.month ||
					workers[i].birth.year == workers[j].birth.year &&
					workers[i].birth.month == workers[j].birth.month &&
					workers[i].birth.day > workers[j].birth.day) {
					Worker tmp = workers[i];
					workers[i] = workers[j];
					workers[j] = tmp;
					Save_Workers_Arr(fname, workers, size, choice);
				}
		Print_Workers_Group(workers, size, choice);
		break;
	case 2:
		for (int i = 0; i < size - 1; i++)
			for (int j = i + 1; j < size; j++)
				if (strcmp(workers[i].subsection, workers[j].subsection) == 1 ||
					strcmp(workers[i].subsection, workers[j].subsection) == 0 &&
					strcmp(workers[i].position, workers[j].position) == 1) {
					Worker tmp = workers[i];
					workers[i] = workers[j];
					workers[j] = tmp;
					Save_Workers_Arr(fname, workers, size, choice);
				}
		Print_Workers_Group(workers, size, choice);
		break;
	}
}
void Find(Worker* workers, size_t size, int choice) {
	const char* Menu_for_find[3]{
		"1) Find by SNP",
		"2) Find by name",
		"3) Find by phone number"
	};
	if (choice == 0) {
		Menu_for_find[0] = "1) Find by SNP";
		Menu_for_find[1] = "2) Find by name";
		Menu_for_find[2] = "3) Find by phone number";
	}
	else {
		Menu_for_find[0] = "1) Шукати за ПІБ";
		Menu_for_find[1] = "2) Шукати за ім'ям";
		Menu_for_find[2] = "3) Шукати за номером телефону";
	}
	Print_Workers_Group(workers, size, choice);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	size_t sizeMenu = sizeof(Menu_for_find) / sizeof(*Menu_for_find);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");
	size_t select = 0;
	select = Menu(Menu_for_find, sizeMenu, 0);
	system("cls");
	char name[50];
	char surname[50];
	char patronymic[50];
	char phone_num[15];
	switch (select)
	{
	case 3:
		return;
	case 0:
		cin.get();
		if (choice == 0) {
			cout << "Enter worker's surname: "; cin.getline(surname, 50);
			cout << "Enter worker's name: "; cin.getline(name, 50);
			cout << "Enter worker's patronymic: "; cin.getline(patronymic, 50);
			for (int i = 0; i < size; i++)
				if (!strcmp(surname, workers[i].surname) && !strcmp(name, workers[i].name) && !strcmp(patronymic, workers[i].patronymic))
					Print_Worker(workers[i]);
		}
		else {
			cout << "Введіть прізвище робітника: "; cin.getline(surname, 50);
			cout << "Введіть ім'я робітника: "; cin.getline(name, 50);
			cout << "Введіть по батькові робітника: "; cin.getline(patronymic, 50);
			for (int i = 0; i < size; i++)
				if (!strcmp(surname, workers[i].surname) && !strcmp(name, workers[i].name) && !strcmp(patronymic, workers[i].patronymic))
					Print_Worker(workers[i]);
		}
		break;
	case 1:
		if (choice == 0) cout << "Enter worker's name: ";
		else cout << "Введіть ім'я робітника: ";
		cin.getline(name, 50);
		for (int i = 0; i < size; i++)
			if (!strcmp(name, workers[i].name))
				Print_Worker(workers[i]);
		break;
	case 2:
		if (choice == 0) cout << "Enter worker's phone number: ";
		else cout << "Введіть номер телефону працівника: ";
		cin.getline(phone_num, 15);
		for (int i = 0; i < size; i++)
			if (!strcmp(phone_num, workers[i].phone_num))
				Print_Worker(workers[i]);
		break;
	}
}
void Select(Worker* workers, size_t size, int choice) {
	const char* Menu_for_output[5];
	if (choice == 0) {
		Menu_for_output[0] = "1) Output the worker whose last name begins with the entered letter";
		Menu_for_output[1] = "2) Output the worker by subsection";
		Menu_for_output[2] = "3) Output the worker-birthdayers of month";
		Menu_for_output[3] = "4) Output the worker by zodiac sign";
		Menu_for_output[4] = "5) Output the retired worker(women older than 55, men older than 60)";
	}
	else {
		Menu_for_output[0] = "1) Вибірка працівника, прізвище якого починається на задану літеру";
		Menu_for_output[1] = "2) Вибірка працівників за підрозділом";
		Menu_for_output[2] = "3) Вибірка іменинників місяця";
		Menu_for_output[3] = "4) Вибірка за знаком зодіака";
		Menu_for_output[4] = "5) Вибірка пенсіорнерів(жінки старші 55 років, чоловіки старші 60 років)";
	}
	Print_Workers_Group(workers, size, choice);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	size_t sizeMenu = sizeof(Menu_for_output) / sizeof(*Menu_for_output);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");
	size_t select = 0;
	select = Menu(Menu_for_output, sizeMenu, 0);
	system("cls");
	char surname_letter;
	char subsection[50];
	switch (select)
	{
	case 5:
		return;
	case 0:
		if (choice == 0) cout << "Enter first letter of surname: ";
		else cout << "Введіть першу літеру прізвища: ";
		cin >> surname_letter;
		for (int i = 0; i < size; i++) {
			if (workers[i].surname[0] == surname_letter) {
				Print_Worker(workers[i]);
			}
		}
		break;
	case 1:
		if (choice == 0)cout << "Enter subsection: ";
		else cout << "Введіть назву підрозділу: ";
		cin >> subsection;
		for (int i = 0; i < size; i++) {
			if (!strcmp(workers[i].subsection, subsection)) {
				Print_Worker(workers[i]);
			}
		}
		break;
	case 2:
		if (choice == 0) {
			const char* month_menu[]{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			size_t sizeMenu = sizeof(month_menu) / sizeof(*month_menu);
			SetColor(BACKGROUND, FOREGROUNG);
			system("cls");
			size_t select = 0;
			select = Menu(month_menu, sizeMenu, 0);
			system("cls");
			for (int i = 0; i < size; i++)
				switch (select)
				{
				case 0: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 1: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 2: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 3: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 4: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 5: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 6: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 7: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 8: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 9: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 10: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 11: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				}
		}
		else {
			const char* month_menu[]{ "Січень", "Лютий", "Березень", "Квітень", "Травень", "Червень", "Липень", "Серпень", "Вересень","Жовтень", "Листопад", "Грудень" };
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			size_t sizeMenu = sizeof(month_menu) / sizeof(*month_menu);
			SetColor(BACKGROUND, FOREGROUNG);
			system("cls");
			size_t select = 0;
			select = Menu(month_menu, sizeMenu, 0);
			system("cls");
			for (int i = 0; i < size; i++)
				switch (select)
				{
				case 0: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 1: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 2: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 3: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 4: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 5: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 6: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 7: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 8: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 9: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 10: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				case 11: if (workers[i].birth.month == (select + 1)) Print_Worker(workers[i]);
					break;
				}
		}
		break;
	case 3:
		if (choice == 0) {
			const char* month_menu[]{ "Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius" };
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			size_t sizeMenu = sizeof(month_menu) / sizeof(*month_menu);
			SetColor(BACKGROUND, FOREGROUNG);
			system("cls");
			size_t select = 0;
			select = Menu(month_menu, sizeMenu, 0);
			system("cls");
			for (int i = 0; i < size; i++) {
				int zodiac = 100 * workers[i].birth.day + workers[i].birth.month;
				switch (select)
				{
				case 0:  if (zodiac >= 1222 || zodiac <= 120) Print_Worker(workers[i]);
					break;
				case 1: if (zodiac >= 121 && zodiac <= 219)
					Print_Worker(workers[i]);
					break;
				case 2: if (zodiac >= 220 && zodiac <= 320)
					Print_Worker(workers[i]);
					break;
				case 3: if (zodiac >= 321 && zodiac <= 420)
					Print_Worker(workers[i]);
					break;
				case 4: if (zodiac >= 421 && zodiac <= 521)
					break;
				case 5: if (zodiac >= 522 && zodiac <= 621)
					Print_Worker(workers[i]);
					break;
				case 6: if (zodiac >= 621 && zodiac <= 722)
					Print_Worker(workers[i]);
					break;
				case 7: if (zodiac >= 723 && zodiac <= 823)
					Print_Worker(workers[i]);
					break;
				case 8: if (zodiac >= 824 && zodiac <= 923)
					Print_Worker(workers[i]);
					break;
				case 9:  if (zodiac >= 924 && zodiac <= 1023)
					Print_Worker(workers[i]);
					break;
				case 10:  if (zodiac >= 1024 && zodiac <= 1122)
					Print_Worker(workers[i]);
					break;
				case 11: if (zodiac >= 1123 && zodiac <= 1221)
					Print_Worker(workers[i]);
					break;
				}
			}
		}
		else {
			const char* month_menu[]{ "Козоріг", "Водолій", "Риби", "Овен", "Телець", "Близнюки", "Рак", "Лев", "Діва", "Терези", "Скорпіон", "Стрілець" };
			SetConsoleCP(1251);
			SetConsoleOutputCP(1251);
			size_t sizeMenu = sizeof(month_menu) / sizeof(*month_menu);
			SetColor(BACKGROUND, FOREGROUNG);
			system("cls");
			size_t select = 0;
			select = Menu(month_menu, sizeMenu, 0);
			system("cls");
			for (int i = 0; i < size; i++) {
				int zodiac = 100 * workers[i].birth.day + workers[i].birth.month;
				switch (select)
				{
				case 0:  if (zodiac >= 1222 || zodiac <= 120) Print_Worker(workers[i]);
					break;
				case 1: if (zodiac >= 121 && zodiac <= 219)
					Print_Worker(workers[i]);
					break;
				case 2: if (zodiac >= 220 && zodiac <= 320)
					Print_Worker(workers[i]);
					break;
				case 3: if (zodiac >= 321 && zodiac <= 420)
					Print_Worker(workers[i]);
					break;
				case 4: if (zodiac >= 421 && zodiac <= 521)
					break;
				case 5: if (zodiac >= 522 && zodiac <= 621)
					Print_Worker(workers[i]);
					break;
				case 6: if (zodiac >= 621 && zodiac <= 722)
					Print_Worker(workers[i]);
					break;
				case 7: if (zodiac >= 723 && zodiac <= 823)
					Print_Worker(workers[i]);
					break;
				case 8: if (zodiac >= 824 && zodiac <= 923)
					Print_Worker(workers[i]);
					break;
				case 9:  if (zodiac >= 924 && zodiac <= 1023)
					Print_Worker(workers[i]);
					break;
				case 10:  if (zodiac >= 1024 && zodiac <= 1122)
					Print_Worker(workers[i]);
					break;
				case 11: if (zodiac >= 1123 && zodiac <= 1221)
					Print_Worker(workers[i]);
					break;
				}
			}
		}
		break;
	case 4:
		if (choice == 0) {
			for (int i = 0; i < size; i++) {
				if ((strcmp(workers[i].gender, "F") == 0 || strcmp(workers[i].gender, "f") == 0) && ((2021 - workers[i].birth.year) > 55)) {
					Print_Worker(workers[i]);
				}
				else if ((strcmp(workers[i].gender, "M") == 0 || strcmp(workers[i].gender, "m") == 0) && ((2021 - workers[i].birth.year) > 60)) {
					Print_Worker(workers[i]);
				}
			}
			//cout << "There are no pensioners on the list" << endl;
		}
		else {
			for (int i = 0; i < size; i++) {
				if ((strcmp(workers[i].gender, "Ж") == 0 || strcmp(workers[i].gender, "ж") == 0) && ((2021 - workers[i].birth.year) > 55)) {
					Print_Worker(workers[i]);
				}
				else if ((strcmp(workers[i].gender, "Ч") == 0 || strcmp(workers[i].gender, "ч") == 0) && ((2021 - workers[i].birth.year) > 60)) {
					Print_Worker(workers[i]);
				}
			}
			//cout << "В списку немає пенсіонерів" << endl;
		}
		break;
	}
}
void Create_Arr(const char* wr_file, Worker*& workers, int& size, int choice) {
	const char* menu[2];
	if (choice == 0) {
		menu[0] = "1) Enter info about worker";
		menu[1] = "2) Use default workers array";
	}
	else {
		menu[0] = "1) Ввести інформацію про робітників";
		menu[1] = "2) Використовувати стандартний список робітників";
	}
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	size_t sizeMenu = sizeof(menu) / sizeof(*menu);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");
	size_t select = 0;
	select = Menu(menu, sizeMenu, 0);
	system("cls");
	switch (select)
	{
	case 0:
		if (choice == 0) cout << "Enter how many workers you want to enter: ";
		else cout << "Введіть кількість робітників, інформацію про яких ви хочете ввести: ";
		cin >> size;
		Input_Workers_Group(workers, size, choice);
		Save_Workers_Arr(wr_file, workers, size, choice);
		break;

	case 1:
		if (choice == 0) workers = Load_Workers_Arr("default_e.txt", size, choice);
		else workers = Load_Workers_Arr("default_u.txt", size, choice);
		Save_Workers_Arr(wr_file, workers, size, choice);
		break;
	}
}
//void Hire_Back(const char* fname, const char* fired_file, Worker*& workers, int& size, int choice) {
//	FILE* fs = NULL;
//	int nError = fopen_s(&fs, fname, "rb");
//	if (nError) {
//		if (choice == 0) cout << "Error read file: " << fname << "\tError: " << nError << endl;
//		else cout << "Помилка читання файлу: " << fname << "\tПомилка:" << nError << endl;
//		exit(3);
//	}
//
//	fseek(fs, 0, SEEK_END);
//	int n = ftell(fs) / sizeof(Worker);
//	fseek(fs, 0, SEEK_SET);
//
//	if (n == 0) {
//		if (choice == 0) cout << "Error: List is empty" << endl;
//		else cout << "Помилка: Список пустий" << endl;
//		return;
//	}
//	Worker* fired_arr = new Worker[n];
//	fread(fired_arr, sizeof(Worker), n, fs);
//	fclose(fs);
//
//	Worker* tmp = new Worker[size + 1];
//	for (int i = 0; i < size; i++) {
//		tmp[i] = workers[i];
//	}
//	tmp[size] = fired_arr[0];
//
//	size++;
//	Delete_Worker(fired_file, fired_arr, n, choice, 0);
//	Save_Workers_Arr(fname, fired_arr, n, choice);
//	delete[] workers;
//	workers = tmp;
//}
void Additional_Functions(const char* wr_file, const char* fire_file, Worker*& workers, int& size, int choice) {
	const char* menu[2];
	if (choice == 0) {
		menu[0] = "1) Fire worker";
		menu[1] = "2) Hire fired workers back";
	}
	else {
		menu[0] = "1) Звільнити працівника";
		menu[1] = "2) Найняти звільнених працівників назад";
	}
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	size_t sizeMenu = sizeof(menu) / sizeof(*menu);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");
	size_t select = 0;
	select = Menu(menu, sizeMenu, 0);
	system("cls");

	int fire_pos;
	switch (select)
	{
	case 0:
		Print_Workers_Group(workers, size, choice);
		if (choice == 0) cout << "Enter number of worker you want to fire: ";
		else cout << "Введіть позицію робітника, якого ви хочете звільнити: ";
		cin >> fire_pos;
		if (fire_pos < 0 || fire_pos > size) {
			if (choice == 0) cout << "Error: wrongly enter number of worker" << endl;
			else cout << "Помилка: неправильно введений номер" << endl;
		}
		Save_Worker_Bin(fire_file, workers[fire_pos], choice);
		Delete_Worker(wr_file, workers, size, choice, fire_pos);
		break;

	case 1:
		if (choice == 0) cout << "The function does not work correctly" << endl;
		else cout << "Функція працює некоректно" << endl;
		//Hire_Back(wr_file, fire_file, workers, size, choice);
		break;
	}
}