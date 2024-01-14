#include <iostream>
#include <string>
using namespace std;

int mystrlen(const char* text);
char* mystrrev(char* str);

int mystrlen(const char* text) {
	int i = 0;
	for (; text[i]; i++);
	return i;
}
char* mystrcpy(char* str1, const  char* str2) {
	int str2sz = mystrlen(str2);
	for (int i = 0; i <= str2sz; i++)
		str1[i] = str2[i];
	return str1;
}
char* mystrcat(char* str1, const char* str2) {
	int len = strlen(str1) + strlen(str2) + 2;
	char* str = new char[len];
	for (int i = 0; i < strlen(str1); i++) str[i] = str1[i];
	for (int i = strlen(str1), j = 0; i < len; i++, j++)
		str[i] = str2[j];
	return str;
}
char* mystrchr(char* str, char s, int i = 0) {
	while (str[i] && str[i] != s) ++i;
	return s == str[i] ? str + i : 0;
}
char* mystrstr(char* str1, char* str2) {
	char* cp = str1;
	char* s1, * s2;
	if (!*str2) return str1;
	while (*cp) {
		s1 = cp;
		s2 = (char*)str2;
		while (*s1 && *s2 && !(*s1 - *s2)) s1++, s2++;
		if (!*s2) return cp;
		cp++;
	}
	return(NULL);
}
int mystrcmp(const char* str1, const char* str2) {
	if (mystrlen(str1) > mystrlen(str2)) return 1;
	else if (mystrlen(str1) < mystrlen(str2)) return -1;
	else return 0;
}
int StringToNumber(char* str) {
	unsigned int strLen = 0;
	unsigned int i = 0;
	while (str[i] != '\0') {
		strLen += 1;
		i++;
	}
	int num = 0;
	int ten;
	bool signFlag = true;
	for (i = 0; i < strLen; i++) {
		if (str[i] < '0' || str[i] > '9') {
			if (i == 0 && str[i] == '-') {
				signFlag = false;
				continue;
			}
			if (i == 0 && str[i] == '+') {
				signFlag = true;
				continue;
			}
			return NULL;
		}
		ten = 1;
		for (unsigned int j = 0; j < strLen - 1 - i; j++) {
			ten *= 10;
		}
		num += ten * (str[i] - '0');
	}
	if (signFlag) return num;
	else return -num;
}
char* NumberToString(int number) {
	char* s = new char[100];
	int i = 0, sign;
	if ((sign = number) < 0) number = -number;
	do {
		s[i++] = number % 10 + '0';
	} while ((number /= 10) > 0);
	if (sign < 0) s[i++] = '-';
	s[i] = '\0';
	return mystrrev(s);
}
char* Uppercase(char* str) {
	for (char* i = str; *i != '\0'; ++i)
		if (*i >= 'a' && *i <= 'z') *i -= 'a' - 'A';
	return str;
}
char* Lowercase(char* str) {
	for (int i = 0; i < mystrlen(str); i++)
		if (str[i] > 'A' && str[i] < 'Z') str[i] += 'z' - 'Z';
	return str;
}
char* mystrrev(char* str)
{
	char* p1, * p2;
	if (!str) return 0;
	for (p1 = str, p2 = str + mystrlen(str) - 1; p2 > p1; ++p1, --p2) {
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
	return str;
}
int main()
{
	const char str[] = "Test string";
	{
		cout << "+===========================================+" << endl;
		cout << "#1" << endl;
		cout << "Text: " << str << endl;
		cout << "Len: " << mystrlen(str) << endl;
		cout << "+===========================================+" << endl << endl << endl;
	}
	{
		cout << "+===========================================+" << endl;
		cout << "#2" << endl;
		char* str2 = new char[100];
		cout << "Text: " << str << endl;
		cout << "Result: " << mystrcpy(str2, str) << endl;
		cout << "+===========================================+" << endl << endl << endl;
	}
	{
		cout << "+===========================================+" << endl;
		cout << "#3" << endl;
		char cat[] = "Cat-";
		char* str3 = mystrcat(cat, str);
		cout << "Str 1: " << cat << endl;
		cout << "Str 2: " << str << endl;
		cout << "Result: " << str3 << endl;
		cout << "+===========================================+" << endl << endl << endl;
	}
	{
		cout << "+===========================================+" << endl;
		cout << "#4" << endl;
		char str[] = "Hello";
		char s = 'l';
		char* p = mystrchr(str, s);
		cout << "Str: " << str << endl;
		cout << "s: " << s << endl;
		if (p == 0) cout << "There is no such symbol: " << 0 << endl;
		else cout << "Index: " << mystrchr(str, s) - str << endl;
		cout << "+===========================================+" << endl << endl << endl;
	}
	{
		cout << "+===========================================+" << endl;
		cout << "#5" << endl;
		char str1[] = "Hello to everyone";
		char str2[] = "to";
		char* p = mystrstr(str1, str2);
		cout << "Str1: " << str1 << endl;
		cout << "Str2: " << str2 << endl;
		if (p != 0) cout << "Index: " << mystrstr(str1, str2) - str1 << endl;
		else cout << "There is no such string: " << 0 << endl;
		cout << "+===========================================+" << endl << endl << endl;
	}
	{
		cout << "+===========================================+" << endl;
		cout << "#6" << endl;
		const char str1[] = "First string:";
		const char str2[] = "Second string:";
		cout << "Str1: " << str1 << endl;
		cout << "Str2: " << str2 << endl;
		cout << "Result: " << mystrcmp(str1, str2) << endl;
		cout << "+===========================================+" << endl << endl << endl;
	}
	{
		cout << "+===========================================+" << endl;
		cout << "#7" << endl;
		char str[] = "-1234";
		int integer = StringToNumber(str);
		cout << "Str: " << str << endl;
		cout << "Result: " << integer << endl;
		cout << "+===========================================+" << endl << endl << endl;
	}
	{
		cout << "+===========================================+" << endl;
		cout << "#8" << endl;
		int i = 1234;
		char* str = new char[i];
		str = NumberToString(i);
		cout << "Int: " << i << endl;
		cout << "Str: " << str << endl;
		cout << "+===========================================+" << endl << endl << endl;
	}
	{
		cout << "+===========================================+" << endl;
		cout << "#9" << endl;
		char str[] = "string";
		cout << str << endl;
		Uppercase(str);
		cout << str << endl;
		cout << "+===========================================+" << endl << endl << endl;
	}
	{
		cout << "+===========================================+" << endl;
		cout << "#10" << endl;
		char str[] = "STRING";
		cout << str << endl;
		Lowercase(str);
		cout << str << endl;
		cout << "+===========================================+" << endl << endl << endl;
	}
	{
		cout << "+===========================================+" << endl;
		cout << "#11" << endl;
		char str[] = "String";
		cout << str << endl;
		mystrrev(str);
		cout << str << endl;
		cout << "+===========================================+" << endl << endl << endl;
	}
	return 0;
}