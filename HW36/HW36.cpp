#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::setw;
using std::endl;

struct Student {
	char surname[50];
	int group;
	int marks[5];
};

struct Man {
	char name[50];
	char surname[50];
	int age;
	int dr[3];
};

void ShowDoubletalker(Student* arr, size_t size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 5; j++)
			if (arr[i].marks[j] <= 3) count++;
		if (count >= 3) cout << arr[i].surname << endl;
		count = 0;
	}
}
void ShowExcellenters(Student* arr, size_t size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 5; j++)
			if (arr[i].marks[j] >= 10) count++;
		if (count >= 4) cout << arr[i].surname << endl;
		count = 0;
	}
}


void PrintSt(Student& bk) {
	cout << "|" << setw(20) << bk.surname;
	cout << "|" << setw(20) << bk.group;
	cout << "|" << setw(20);
	for (int i = 0; i < 5; i++)
		cout << setw(3) << bk.marks[i] << " ";
	cout << "|" << endl;
}
void PrintStudents(Student* bk, const int n) {
	for (int i = 0; i < n; i++) PrintSt(bk[i]);
	cout << endl;
}
void ShowStudents(Student arr[], size_t size) {
	cout << "Students array: " << endl;
	cout << "|" << setw(20) << "Surname" << "|" << setw(20) << "Group" << "|" << setw(20) << "Marks" << "|" << endl;
	PrintStudents(arr, size);
}
void PrintMan(Man& bk) {
	cout << "|" << setw(20) << bk.name;
	cout << "|" << setw(20) << bk.surname;
	cout << "|" << setw(20) << bk.age;
	cout << "|" << setw(13) << bk.dr[0] << " " << bk.dr[1] << " " << bk.dr[2];
	cout << "|" << endl;
}
void PrintHumans(Man* bk, const int n) {
	for (int i = 0; i < n; i++) PrintMan(bk[i]);
	cout << endl;
}
void ShowBirthers(Man* arr, size_t& size, int c_m) {
	for (int i = 0; i < size; i++) {
		if (arr[i].dr[1] == c_m)
			PrintMan(arr[i]);
	}
}
void ShowHumans(Man* arr, size_t size) {
	cout << "Humans array: " << endl;
	cout << "|" << setw(20) << "Name" << "|" << setw(20) << "Surname" << "|" << setw(20) << "Age" << "|" << setw(20) << "Birth Date" << "|" << endl;
	PrintHumans(arr, size);
}


void SortByName(Man st[], const int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (strcmp(st[i].name, st[j].name) == 1) std::swap(st[i], st[j]);
}
void SortBySurname(Man st[], const int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (strcmp(st[i].surname, st[j].surname) == 1) std::swap(st[i], st[j]);
}
void SearchByName(Man* bk, const int n) {
	char* name = new char[100];
	cout << "Enter Name you want to search: "; cin.getline(name, 100);
	for (int i = 0; i < n; i++)
		if (!strcmp(name, bk[i].name)) {
			PrintMan(bk[i]);
		}
	delete[] name;
}
void SearchBySurname(Man* bk, const int n) {
	char* name = new char[100];
	cout << "Enter Surname you want to search: "; cin.getline(name, 100);
	for (int i = 0; i < n; i++)
		if (!strcmp(name, bk[i].surname)) {
			PrintMan(bk[i]);
		}
	delete[] name;
}


Student* DeleteStudent(Student* arr, size_t& size, int del_pos) {
	Student* temp = new Student[size - 1];
	for (int i = 0; i < del_pos; i++)
		temp[i] = arr[i];
	for (int i = del_pos + 1; i < size; i++)
		temp[i - 1] = arr[i];
	size--;
	delete[] arr;
	return temp;
}
void AddStudent(Student*& arr, size_t& size, Student elem) {
	Student* temp = new Student[size + 1]{};
	for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
	}
	temp[size] = elem;
	size++;
	delete[] arr;
	arr = temp;
}
Man* DeleteMan(Man* arr, size_t& size, int del_pos) {
	if (del_pos > size || del_pos < 0)
		cout << "Delete error" << endl;
	Man* temp = new Man[size - 1];
	for (int i = 0; i < del_pos; i++)
		temp[i] = arr[i];
	for (int i = del_pos + 1; i < size; i++)
		temp[i - 1] = arr[i];
	size--;
	delete[] arr;
	return temp;
}
void AddMan(Man*& arr, size_t& size, Man elem) {
	Man* temp = new Man[size + 1]{};
	for (int i = 0; i < size; i++) temp[i] = arr[i];
	temp[size] = elem;
	size++;
	delete[] arr;
	arr = temp;
}

Student InputSt() {
	Student bk;
	cin.get();
	cout << "Surname: "; cin.getline(bk.surname, 30);
	cout << "Group: "; cin >> bk.group;
	for (int i = 0; i < 5; i++) {
		cout << "Mark " << i + 1 << "(1-12): "; cin >> bk.marks[i];
		if (bk.marks[i] > 12 || bk.marks[i] < 1) {
			cout << "Wrong mark" << endl;
			return bk;
		}
	}
	return bk;
}
Man InputMan() {
	Man bk;
	cin.get();
	cout << "Name: "; cin.getline(bk.name, 30);
	cout << "Surname: "; cin.getline(bk.surname, 30);
	cout << "Age: "; cin >> bk.age;
	cout << "Day of birth: "; cin >> bk.dr[0];
	if (bk.dr[0] < 0 || bk.dr[0] > 31) cout << "Wrong entered day of birth" << endl;
	cout << "Month of birth: "; cin >> bk.dr[1];
	if (bk.dr[1] < 0 || bk.dr[1] > 12) cout << "Wrong entered month of birth" << endl;
	cout << "Year of birth: "; cin >> bk.dr[2];
	if (bk.dr[0] < 0) cout << "Wrong entered year of birth" << endl;
	return bk;
}
void EditMan(Man*& arr, size_t size, int pos) {
	arr[pos] = InputMan();
}


int main()
{
	{
		//Завдання 1
		cout << "+===============================================================================================+" << endl;
		size_t size = 7;
		Student* arr = new Student[7]{
			{"Brown", 112, {10, 9, 10, 11, 10}},
			{"Green", 110, {8, 9, 10, 9, 12}},
			{"Blue", 611, {10, 9, 10, 11, 11}},
			{"Red", 109, {2, 6, 8 , 12, 11}},
			{"Pink", 310, {3, 5, 9, 8, 7}},
			{"Purple", 110, {8, 10, 3, 2, 2}},
			{"Yellow", 211, {2, 2, 3, 4, 6}}
		};
		ShowStudents(arr, size);

		cout << "+-----------------------------------------------------------------------------------------------+" << endl;
		cout << "1.1" << endl;
		cout << "-------Change array size-------" << endl << endl;
		cout << "Delete Student: " << endl;

		int del_pos;
		cout << "Enter position of student you want to delete: "; cin >> del_pos;
		if (del_pos > size || del_pos < 0) {
			cout << "Delete error" << endl;
			return 1;
		}
		arr = DeleteStudent(arr, size, del_pos);
		ShowStudents(arr, size);

		Student* temp = new Student[size + 1];
		cout << "Add Student: " << endl;
		cout << "Enter information about student: " << endl;

		Student a = InputSt();
		AddStudent(arr, size, a);
		ShowStudents(arr, size);
		cout << "+-----------------------------------------------------------------------------------------------+" << endl << endl;

		cout << "+-----------------------------------------------------------------------------------------------+" << endl;
		cout << "1.2" << endl;
		cout << "-------Excellenters-------" << endl;
		ShowExcellenters(arr, size);
		cout << "+-----------------------------------------------------------------------------------------------+" << endl;

		cout << "+-----------------------------------------------------------------------------------------------+" << endl << endl;
		cout << "1.3" << endl;
		cout << "-------Doubletalkers-------" << endl;
		ShowDoubletalker(arr, size);
		cout << "+-----------------------------------------------------------------------------------------------+" << endl;
		cout << "+===============================================================================================+" << endl << endl << endl;
	}

	{
		//Завдання 2
		cout << "+===============================================================================================+" << endl;
		size_t size = 7;
		Man* arr = new Man[7]{
			{"Kate", "Brown", 25, {1, 3, 1996}},
			{"Sam", "Green", 34, {14, 5, 1987}},
			{"Bob", "Blue", 18, {28, 4, 2003}},
			{"Roger", "Red", 23, {2, 8, 1998}},
			{"Lana", "Pink", 43, {31, 12, 1978}},
			{"Alan", "Purple", 25, {23, 3, 1996}},
			{"Jessica", "Yellow", 30, {15, 7, 1991}}
		};
		ShowHumans(arr, size);

		cout << "+-----------------------------------------------------------------------------------------------+" << endl;
		cout << "2.1" << endl;
		cout << "-------Sort by Name-------" << endl;
		SortByName(arr, size);
		ShowHumans(arr, size);

		cout << "-------Sort by Surname-------" << endl;
		SortBySurname(arr, size);
		ShowHumans(arr, size);
		cout << "+-----------------------------------------------------------------------------------------------+" << endl << endl;

		cout << "+-----------------------------------------------------------------------------------------------+" << endl;
		cout << "2.2" << endl;
		cout << "-------Birthday people-------" << endl;
		int current_month;
		cout << "Input current month (only number): "; cin >> current_month;
		ShowBirthers(arr, size, current_month);
		cout << "+-----------------------------------------------------------------------------------------------+" << endl << endl;

		cout << "+-----------------------------------------------------------------------------------------------+" << endl;
		cout << "2.3" << endl;
		cout << "-------Change array size-------" << endl << endl;
		cout << "Delete Human: " << endl;

		int del_pos;
		cout << "Enter position of student you want to delete: "; cin >> del_pos;
		arr = DeleteMan(arr, size, del_pos);
		ShowHumans(arr, size);

		cout << "Add human: " << endl;
		Man* temp = new Man[size + 1];
		cout << "Add Student: " << endl;
		cout << "Enter information about student: " << endl;

		Man elem = InputMan();
		AddMan(arr, size, elem);
		ShowHumans(arr, size);
		cout << "+-----------------------------------------------------------------------------------------------+" << endl << endl;

		cout << "+-----------------------------------------------------------------------------------------------+" << endl;
		cout << "2.4" << endl;
		cin.get();
		cout << "-------Search by Name-------" << endl;
		SearchByName(arr, size);
		cout << "-------Search by Surname-------" << endl;
		SearchBySurname(arr, size);
		cout << "+-----------------------------------------------------------------------------------------------+" << endl << endl;

		cout << "+-----------------------------------------------------------------------------------------------+" << endl;
		cout << "2.5" << endl;
		cout << "-------Edit-------" << endl;
		int edit_pos;
		cout << "Enter position of human you want to edit: "; cin >> edit_pos;
		EditMan(arr, size, edit_pos);
		ShowHumans(arr, size);
		cout << "+-----------------------------------------------------------------------------------------------+" << endl;
		cout << "+===============================================================================================+";
	}
	return 0;
}
