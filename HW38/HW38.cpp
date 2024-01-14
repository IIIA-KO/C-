#include <iostream>
using namespace std;

void Save(const char* fname, char* text) {
	FILE* fs = NULL;
	int nerror = fopen_s(&fs, fname, "wt");
	if (nerror) {
		cout << "Error write file: " << fname << " Error: " << nerror << endl;
		exit(3);
	}
	fprintf(fs, "%s", text);
	fclose(fs);
}
char* Scan(const char* fname) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "rt");
	if (nError) {
		cout << "Error read file: " << fname << "\tError:" << nError << endl;
		exit(3);
	}
	char* arr = new char[1000];
	while (!feof(fs)) fgets(arr, 100, fs);
	fclose(fs);
	return arr;
}

void CountFile(const char* fname) {
	FILE* fs = NULL;
	int nError = fopen_s(&fs, fname, "rt");
	if (nError) {
		cout << "Error read file: " << fname << "\tError:" << nError << endl;
		exit(3);
	}
	char vowel[] = "AEIOUYaeiouy";
	char consonant[] = "BCDFGJKLMNPQSTVXZHRWYbcdfgjklmnpqstvxzhrwy";
	int count_symbols = 0, count_str = 0, count_vowel = 0, count_consonant = 0, count_digit = 0;
	while (!feof(fs)) {
		char c = fgetc(fs);
		count_symbols++;
		if (c == '\n') count_str++;
		for (int i = 0; i < strlen(vowel); i++) {
			if (c == vowel[i]) count_vowel++;
		}
		for (int i = 0; i < strlen(consonant); i++)
			if (c == consonant[i]) count_consonant++;
		if (c >= '0' && c <= '9') count_digit++;
	}
	count_str++;

	const char* fn = "Stat.txt";
	FILE* f = NULL;
	int Error = fopen_s(&f, fn, "wt");
	fprintf(f, "Count of symbols = %d \n", count_symbols);
	fprintf(f, "Count of strings = %d \n", count_str);
	fprintf(f, "Count of vowel = %d \n", count_vowel);
	fprintf(f, "Count of consonant = %d \n", count_consonant);
	fprintf(f, "Count of digits = %d \n", count_digit);

	cout << "Count of symbols: " << count_symbols << endl;
	cout << "Count of strings: " << count_str << endl;
	cout << "Count of vowel: " << count_vowel << endl;
	cout << "Count of consonant: " << count_consonant << endl;
	cout << "Count of digits: " << count_digit << endl;
}
char* Uppercase(char* str) {
	for (char* i = str; *i != '\0'; ++i)
		if (*i >= 'a' && *i <= 'z') *i -= 'a' - 'A';
	return str;
}
char* caesar_cipher(const char* fname, char* txt, int key) {
	char alphabet[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	FILE* fs;
	int nError = fopen_s(&fs, fname, "rt");
	if (nError) {
		cout << "Error read file: " << fname << "\tError:" << nError << endl;
		exit(3);
	}
	int i = 0;
	char* begin = alphabet;
	char* end = alphabet + sizeof(alphabet);
	for (; txt[i]; i++) {
		char* ch = find(begin, end, txt[i]);
		if (ch != end) txt[i] = *(begin + (ch - begin + key) % sizeof(alphabet));
	}
	return txt;
}

void Task1() {
	char* text1 = new char[1000];
	char* text2 = new char[1000];
	const char* fn1 = "1.txt";
	const char* fn2 = "2.txt";
	cout << "Enter text for 1st file: "; cin.getline(text1, 1000);
	Save(fn1, text1);
	cout << "Enter text for 2nd file: "; cin.getline(text2, 1000);
	Save(fn2, text2);
	char* txt1 = Scan(fn1);
	char* txt2 = Scan(fn2);
	if (strcmp(txt1, txt2) != 0) {
		cout << "-------Texts in files are not equal-------" << endl;
		cout << "Text from 1st file: " << txt1 << endl;
		cout << "Text from 2nd file: " << txt2 << endl;
	}
	else {
		cout << "-------Texts in files are equal-------" << endl;
	}
	delete[] text1;
	delete[] text2;
	delete[] txt1;
	delete[] txt2;
}
void Task2() {
	const char* fn = "3.txt";
	char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.Praesent in dignissim lorem, non molestie tellus.Maecenas pulvinar lorem placerat, porttitor erat ac, euismod tortor.\nDuis facilisis augue augue, ac lacinia mi mollis vitae.Proin tempus sed turpis nec viverra.\nCras eget ex ullamcorper, fermentum erat eu, pellentesque quam.Nam quis scelerisque felis.Donec nec enim mi.Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae;\nCurabitur eu mi eleifend neque interdum tempor et nec libero.Ut lacinia augue augue, vitae fringilla ligula sollicitudin eu.Praesent a eros nulla.Vivamus et ligula diam.Morbi vehicula nec erat eu consectetur.\nNam ac fermentum purus.Curabitur pellentesque ornare erat sit amet posuere.Nulla ac enim lorem.\nEtiam molestie lacinia velit, suscipit malesuada velit.Fusce ex quam, posuere in vehicula eu, aliquam nec enim.Cras metus nisl, fermentum at augue id, suscipit porta nisi.\nProin pretium sapien vel lacus faucibus vehicula.Duis dictum leo ut nisi cursus viverra.Aenean feugiat mauris a tortor feugiat vestibulum.\nIn fringilla orci ut dolor fringilla, eget tristique urna congue.Mauris non rhoncus lorem.Morbi justo purus, porttitor sed mollis at, pretium ac justo.Pellentesque interdum semper nisl, ut ultricies orci pharetra ac.\nNunc hendrerit faucibus laoreet.Integer ac tellus in libero bibendum malesuada.In hac habitasse platea dictumst.Suspendisse in fringilla nisl, vel facilisis magna.Sed tincidunt dolor metus, non pellentesque risus porttitor viverra.\nIn hac habitasse platea dictumst.Etiam venenatis orci venenatis, lacinia sapien in, efficitur tellus.Aliquam nec posuere nisi.Sed commodo purus in augue bibendum iaculis.Morbi iaculis lacus ut justo fermentum fermentum.\nNullam id congue lorem.Vestibulum et blandit nisl, sed dapibus sem.Donec fermentum mattis auctor.Mauris venenatis dapibus porta.Curabitur eget libero luctus, faucibus risus eu, suscipit nibh.\nMaecenas eleifend tellus vitae nisl pulvinar porta.Sed sit amet ipsum odio.Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos.Ut faucibus nec urna a sagittis.\nQuisque ac est quis urna semper molestie vel efficitur ante.Aenean accumsan interdum mi sed elementum.Etiam lacus elit, sagittis eu eleifend eu, dignissim sed mauris.Nulla ut malesuada turpis.\nNullam interdum quam turpis, nec pretium mi dignissim ac.Donec aliquet justo a ipsum tincidunt, vitae pharetra diam tempor.Nulla pellentesque nisi vitae dui fringilla, vel venenatis massa congue.\nDuis bibendum justo libero, et luctus erat rutrum fermentum.Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.Cras placerat ullamcorper risus, id condimentum mi pharetra ut.\nSuspendisse sit amet lorem sagittis, bibendum mauris in, accumsan est.Donec id bibendum dui.Vivamus accumsan dolor nisi, et sollicitudin tellus vehicula non\nNam vehicula in diam vel efficitur.Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Suspendisse potenti.";
	Save(fn, text);
	cout << "Text From Source File: " << endl;
	cout << text << endl << endl;
	CountFile(fn);
}
void Task3() {
	char* txt = new char[1000];
	const char* fn = "4.txt";
	const char* file = "5.txt";
	cout << "Enter text: "; cin.getline(txt, 1000);
	Save(fn, txt);

	int key = 3;
	char* txt2 = Scan(fn);
	txt2 = Uppercase(txt2);
	txt2 = caesar_cipher(fn, txt2, key);
	Save(file, txt2);
	cout << "Changed with key = 3: " << endl;
	cout << txt2 << endl;
	delete[] txt;
	delete[] txt2;
}
int main()
{
	cout << "+=======================================================================================================================================================+" << endl;
	Task1();
	cout << "+=======================================================================================================================================================+" << endl << endl << endl;
	cout << "+=======================================================================================================================================================+" << endl;
	Task2();
	cout << "+=======================================================================================================================================================+" << endl << endl << endl;
	cout << "+=======================================================================================================================================================+" << endl;
	Task3();
	cout << "+=======================================================================================================================================================+" << endl;
	return 0;
}
