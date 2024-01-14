#include <iostream>
#include <string>
using namespace std;

char* Delete(const char* text, size_t indx) {
	size_t len = strlen(text);
	char* copy = new char[len - 1];
	if (!text || indx < 0 || indx >= len) {
		cout << "Error: delete error" << endl;
	}
	for (int i = 0; i <= indx; i++)
		copy[i] = text[i];
	for (int i = indx + 1; i <= len; i++)
		copy[i - 1] = text[i];
	return copy;
}
char* Enter(const char* text, size_t indx, char sym) {
	size_t len = strlen(text);
	char* copy = new char[len + 1];
	if (!text || indx < 0 || indx >= len) {
		cout << "Error: delete error" << endl;
	}
	for (int i = 0; i < indx; i++)
		copy[i] = text[i];
	copy[indx] = sym;
	for (int i = indx; i <= len; i++)
		copy[i + 1] = text[i];
	return copy;
}
char* letdel(char* text, char sym) {
	size_t len = strlen(text);
	int i = 0, j = i;
	while (text[i])
	{
		if (text[i] != sym)
			text[j++] = text[i];
		i++;
	}
	text[j] = 0;
	return text;	
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
int sym_count(char* text, char sym) {
	int count = 0;
	for (int i = 0; text[i] != 0; i++)
		if (text[i] == sym)
			count++;
	return count;
}
char* replace(char* text) {
	int len = strlen(text);
	char* new_text = new char[len + 1];
	for (int i = 0; i < len; i++) {
		new_text[i] = text[i];
	}
	for (int i = 0; i < len; i++) {
		if (new_text[i] == '.')
			new_text[i] = '!';
	}
	new_text[len] = 0;
	return new_text;
}

void Task1() {
	cout << "+===========================================+" << endl;
	cout << "#Task 1" << endl;
	cout << "Text: " << endl;
	const char text[]{ "Some string, idk)" };
	cout << text << endl;
	size_t indx = -1;
	cout << "Enter index you want to delete: "; cin >> indx;
	cout << Delete(text, indx) << endl;
	cout << "+===========================================+" << endl << endl << endl;
}
void Task2() {
	cout << "+===========================================+" << endl;
	cout << "#Task 2" << endl;
	cout << "Text: " << endl;
	char text[]{ "Sooomeee sstrrinnggg, iddkkk)" };
	cout << text << endl;
	char sym;
	cout << "Enter letter you want to delete: "; cin >> sym;
	cout << letdel(text, sym) << endl;
	cout << "+===========================================+" << endl << endl << endl;
}
void Task3() {
	cout << "+===========================================+" << endl;
	cout << "#Task 3" << endl;
	cout << "Text: " << endl;
	const char text[]{ "Some string, idk)" };
	char sym;
	size_t indx = -1;
	cout << text << endl;
	cout << "Enter symbol: "; cin >> sym;
	cout << "Enter index you want to enter: "; cin >> indx;
	cout << Enter(text, indx, sym) << endl;
	cout << "+===========================================+" << endl << endl << endl;
}
void Task4() {
	cout << "+===========================================+" << endl;
	cout << "#Task 4" << endl;
	char text[200];
	cout << "Enter text: ";
	cin.getline(text, 200);
	cout << "Changed: " << endl;
	cout << replace(text) << endl;
	cout << "+===========================================+" << endl << endl << endl;
}
void Task5() {
	cout << "+===========================================+" << endl;
	cout << "#Task 5" << endl;
	char text[1000];
	char sym;
	cout << "Enter text: ";
	cin.getline(text, 1000);
	cout << "Entered text: " << text << endl;
	text[strlen(text)] = 0;
	cout << "Enter symbol: ";
	cin >> sym;
	cin.get();
	cout << "Count: " << sym_count(text, sym) << endl;
	cout << "+===========================================+" << endl << endl << endl;
}
void Task6() {
	cout << "+===========================================+" << endl;
	cout << "#Task 6" << endl;
	char symbols[1000];
	cout << "Enter text: ";
	cin.getline(symbols, 1000);
	cout << "Count of digits: " << Count_digits(symbols) << endl;
	cout << "Count of letters: " << Count_letters(symbols) << endl;
	cout << "Count of symbols: " << strlen(symbols) - (Count_letters(symbols) + Count_digits(symbols)) << endl;
	cout << "+===========================================+" << endl << endl << endl;
}

void main()
{
	Task1();
	Task2();
	getchar();
	Task3();
	getchar();
	Task4();
	Task5();
	Task6();
}
