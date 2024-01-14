#pragma once
struct Date {
	int day;
	int month;
	int year;
};
struct Worker {
	char name[50];
	char surname[50];
	char patronymic[50];
	Date birth;
	char gender[2];
	Date hire_date;
	char subsection[30];
	char position[30];
	char phone_num[14];
};
struct Zodiac {
	Date d1;
	Date d2;
	int s;
};

void Print_Worker_Card(Worker& wr, int choice);

void Print_Worker(Worker& wr);

void Print_Workers_Group(Worker* wr, size_t size, int choice);

void Save_Worker(const char* fname, Worker wr, int choice);

void Save_Worker_Bin(const char* fname, Worker wr, int choice);

void Save_Workers_Arr(const char* fname, Worker* wr, int n, int choice);

Worker Load_Worker(const char* fname, int choice);

Worker* Load_Workers_Arr(const char* fname, int size, int choice);

void Delete_Worker(const char* fname, Worker*& workers, int& size, int choice, int del_pos);

Worker Input_Worker(Worker& wr, int choice);

void Input_Workers_Group(Worker* wr, size_t size, int choice);

void Add_Worker(Worker*& workers, Worker elem, int& size, int choice);

void Edit(Worker* workers, int size, int choice);

void Sort(const char* fname, Worker* workers, size_t size, int choice);

void Find(Worker* workers, size_t size, int choice);

void Select(Worker* workers, size_t size, int choice);

void Create_Arr(const char* wr_file, Worker*& workers, int& size, int choice);

void Hire_Back(const char* fname, const char* fired_file, Worker*& workers, int& size, int choice);

void Additional_Functions(const char* wr_file, const char* fire_file, Worker*& workers, int& size, int choice);