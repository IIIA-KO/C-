#include <iostream>
#include <string.h>
#include <Windows.h>
using namespace std;

int CountWord(char* s) {
	char delim[] = " ,.!?-*/-+_;&%:()[]{}'\"\t\n\b\r";
	char* buf = new char[strlen(s) + 1]{ 0 };
	strcpy(buf, s);
	int count = 0;
	char* str = strtok(buf, delim);
	while (str) {
		count++;
		str = strtok(NULL, delim);
	}
	delete[] buf;
	return count;
}
char* MaxWord(const char* s) {
	char delim[] = " ,.!?-*/-+_;&%:()[]{}'\"\t\n\b\r";
	char* buf = new char[strlen(s) + 1]{ 0 };
	strcpy(buf, s);

	char* str = strtok(buf, delim);
	int maxlen = strlen(str);
	char* max = new char[strlen(s) + 1];
	while (str) {
		if (maxlen < strlen(str)) {
			maxlen = strlen(str);
			delete[] max;
			strcpy(max, str);
		}
		str = strtok(NULL, delim);
	}
	delete[] buf;
	return max;
}
void strlensort(char* str) {
	char delim[] = " ,.!?-/*-+_;&%:()[]{}'\"\t\n\b\r\0";
	char* buf = new char[strlen(str) + 1]{ 0 };
	strcpy(buf, str);
	char* s = strtok(buf, delim);
	char* list[SHRT_MAX];
	int i = 0;
	while (s != NULL) {
		list[i++] = s;
		s = strtok(NULL, delim);
	}
	for (int i = 0; i < CountWord(str); i++) 
		for (int j = 0; j < CountWord(str) - 1; j++) 
			if (strlen(list[j]) > strlen(list[j+ 1])) swap(list[j], list[j + 1]);
	for (int i = 0; i < CountWord(str); i++) cout << list[i] << " ";
	cout << endl;
}
int main()
{
	cout << "+========================================================================================================+" << endl;
	char str[201];
	cout << "Enter string: "; cin.getline(str, 201);
	cout << "Your string: " << str << endl << endl;
	int r = CountWord(str);
	cout << "Sorted: " << endl;
	strlensort(str);
	cout << "+========================================================================================================+" << endl;
	return 0;
}