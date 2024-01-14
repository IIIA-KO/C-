#include <iostream>
#include <string.h>
#include <Windows.h>
using namespace std;

void Tabs(char* text) {
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] == ' ')
			text[i] = '	';
	}
}
int WordQuantity(char* text) {
	int words = 0;
	for (int i = 0; i < strlen(text); i++) {
		if (text[i] == ' ')
			words++;
	}
	return words + 1;
}
bool IsPalindrome(char* text) {
	int len = strlen(text);
	for (int i = 0; i < len / 2; i++)
	{
		if (text[i] != text[len - i - 1])
		{
			return false;
		}
	}
	return true;
}
int Count_digits(char* text) {
	int count = 0;
	for (int i = 0; text[i] != 0; i++)
		if (text[i] >= '0' && text[i] <= '9')
			count++;
	return count;
}
int Count_letters(char* text) {
	int count = 0;
	for (int i = 0; text[i] != 0; i++)
		if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
			count++;
	return count;
}
int Count_голосні(char* text) {
	int count = 0;
	for (int i = 0; text[i] != 0; i++)
		if (text[i] == 'а' || text[i] == 'о' || text[i] == 'у' || text[i] == 'и' || text[i] == 'і' || text[i] == 'е')
			count++;
	return count;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	{
		//Завдання 1
		cout << "+=========================================================+" << endl;
		char symbols[]{ "Hello Nick & Mike" };
		cout << "Text: " << endl;
		cout << symbols << endl;
		Tabs(symbols);
		cout << symbols << endl;
		cout << "+=========================================================+" << endl << endl << endl;
	}
	{
		//Завдання 2
		cout << "+=========================================================+" << endl;
		char symbols[]{ "a=1k.n34mm3,3:gh2/*-+" };
		cout << "Text: " << endl;
		cout << symbols << endl;
		cout << "Count of digits: " << Count_digits(symbols) << endl;
		cout << "Count of letters: " << Count_letters(symbols) << endl;
		cout << "Count of symbols: " << strlen(symbols) - (Count_letters(symbols) + Count_digits(symbols)) << endl;
		cout << symbols << endl;
		cout << "+=========================================================+" << endl << endl << endl;
	}
	{
		//Завдання 3
		cout << "+=========================================================+" << endl;
		char words[]{ "Word1, Word2, Word3, Word4" };
		cout << "Text: " << endl;
		cout << words << endl;
		cout << "Words count: " << WordQuantity(words) << endl;
		cout << "+=========================================================+" << endl << endl << endl;
	}
	{
		//Завдання 4
		cout << "+=========================================================+" << endl;
		char ukr[1000];
		cout << "Введіть текст укаїнcькою: ";
		cin.getline(ukr, 200);
		cout << "Ваш введений текст: " << endl << ukr << endl;
		cout << "+=========================================================+" << endl << endl << endl;

	}
	{
		//Завдання 5
		cout << "+=========================================================+" << endl;
		char ukr[1000];
		cout << "Введіть текст укаїнькою: ";
		cin.getline(ukr, 200);
		cout << "Кількість голосних літер: " << Count_голосні(ukr) << endl;
		cout << "+=========================================================+" << endl << endl << endl;
	}
	{
		//Завдання 6
		cout << "+=========================================================+" << endl;
		char string[]{ "Some String" };
		char str[]{ "deed" };
		cout << "Text 1: " << endl;
		cout << string << endl;
		cout << "Text 2: " << endl;
		cout << str << endl << endl;

		if (IsPalindrome(string))
			cout << "Text 1 is palindrome" << endl;
		else
			cout << "Text 1 is not palindrome" << endl;

		if (IsPalindrome(str))
			cout << "Text 2 is palindrome" << endl;
		else
			cout << "Text 2 is not palindrome" << endl;
		cout << "+=========================================================+";
	}
	return 0;
}
