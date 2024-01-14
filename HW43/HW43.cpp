 #include "menu.h"
#include "exam.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char* language[]{
		"English",
		"Українська"
	};

	size_t sizeMenu = sizeof(language) / sizeof(*language);
	SetColor(BACKGROUND, FOREGROUNG);
	system("cls");

	const char* wr_file = "all_workers_array.txt";
	const char* fired_file = "fired_workers_array.bin";

	int choice = Menu(language, sizeMenu, 0);
	switch (choice)
	{
	case 0:
	{
		int choice = 0;
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		const char* textMenu[]{
			"1) Create workers array",
			"2) Add new worker",
			"3) Edit",
			"4) Delete worker",
			"5) Print all workers",
			"6) Print worker card",
			"7) Sort",
			"8) Find",
			"9) Select",
			"10) Save",
			"11) Additional functions",
			"12) Exit"
		};
		size_t sizeMenu = sizeof(textMenu) / sizeof(*textMenu);
		SetColor(BACKGROUND, FOREGROUNG);
		system("cls");

		size_t select = 0;
		int size = 3;
		Worker* workers = new Worker[size];

		int worker_card, del_pos, fire_pos;
		while (true)
		{
			select = Menu(textMenu, sizeMenu, 0);
			system("cls");
			switch (select)
			{
			case 11:
				return 0;
			case 0:
				Create_Arr(wr_file, workers, size, choice);
				break;
			case 1: {
				Worker elem{ 0 };
				Input_Worker(elem, choice);
				Add_Worker(workers, elem, size, choice);
				Save_Workers_Arr(wr_file, workers, size, choice);
			}
				  break;
			case 2:
				Edit(workers, size, choice);
				Save_Workers_Arr(wr_file, workers, size, choice);
				break;
			case 3: {
				Print_Workers_Group(workers, size, choice);
				int del_pos;
				cout << "Enter number of worker you want to delete: "; cin >> del_pos;
				Delete_Worker(wr_file, workers, size, choice, del_pos);
			}
				  break;
			case 4:
				Print_Workers_Group(workers, size, choice);
				break;
			case 5:
				Print_Workers_Group(workers, size, choice);
				cout << "Enter number of worker: "; cin >> worker_card;
				if (worker_card < 0 || worker_card > size) cout << "Error: Wrongly entered number" << endl;
				Print_Worker_Card(workers[worker_card], choice);
				break;
			case 6:
				Sort(wr_file, workers, size, choice);
				break;
			case 7:
				Find(workers, size, choice);
				break;
			case 8:
				Select(workers, size, choice);
				break;
			case 9:
				Save_Workers_Arr(wr_file, workers, size, choice);
				break;
			case 10:
				Additional_Functions(wr_file, fired_file, workers, size, choice);
				Save_Workers_Arr(wr_file, workers, size, choice);
				break;
			}
			cout << "=========DONE=========\n";
			_getch();
		}
		delete[] workers;
		break;
	}
	case 1: {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		const char* textMenu[]{
			"1) Створити список робітників",
			"2) Додати нового робітника",
			"3) Редагувати",
			"4) Видалити робітника",
			"5) Друк усіх робітників",
			"6) Друк картки робітника",
			"7) Сортування",
			"8) Пошук",
			"9) Вибірка",
			"10) Зберегти",
			"11) Додаткові функції",
			"12) Вихід"
		};
		size_t sizeMenu = sizeof(textMenu) / sizeof(*textMenu);
		SetColor(BACKGROUND, FOREGROUNG);
		system("cls");

		size_t select = 0;

		int size = 3;
		Worker* workers = new Worker[size];

		int worker_card, del_pos, fire_pos;
		while (true)
		{
			select = Menu(textMenu, sizeMenu, 0);
			system("cls");
			switch (select)
			{
			case 11:
				return 0;
			case 0:
				Create_Arr(wr_file, workers, size, choice);
				break;
			case 1: {
				Worker elem{ 0 };
				Input_Worker(elem, choice);
				Add_Worker(workers, elem, size, choice);
				Save_Workers_Arr(wr_file, workers, size, choice);
			}
				  break;
			case 2:
				Edit(workers, size, choice);
				Save_Workers_Arr(wr_file, workers, size, choice);
				break;
			case 3: {
				Print_Workers_Group(workers, size, choice);
				int del_pos;
				cout << "Введіть номер робітника, якого ви хочете видалити: " << endl; cin >> del_pos;
				Delete_Worker(wr_file, workers, size, choice, del_pos);
			}
				  break;
			case 4:
				Print_Workers_Group(workers, size, choice);
				break;
			case 5:
				Print_Workers_Group(workers, size, choice);
				cout << "Введіть номер робітника: "; cin >> worker_card;
				if (worker_card < 0 || worker_card > size) cout << "Помилка: неправильно введений номер" << endl;
				Print_Worker_Card(workers[worker_card], choice);
				break;
			case 6:
				Sort(wr_file, workers, size, choice);
				break;
			case 7:
				Find(workers, size, choice);
				break;
			case 8:
				Select(workers, size, choice);
				break;
			case 9:
				Save_Workers_Arr(wr_file, workers, size, choice);
				break;
			case 10:
				Additional_Functions(wr_file, fired_file, workers, size, choice);
				Save_Workers_Arr(wr_file, workers, size, choice);
				break;
			}
			cout << "=========ЗРОБЛЕНО=========\n";
			_getch();
		}
		delete[] workers;
	}
		  break;
	}
	return 0;
}
