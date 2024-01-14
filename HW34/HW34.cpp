#include <iostream>
using namespace std;

struct Complex {
	double R, I;
};

Complex Plus(Complex a, Complex b) {
	Complex c;
	c.R = a.R + b.R;
	c.I = a.I + b.I;
	return c;
}

Complex Minus(Complex a, Complex b) {
	Complex c;
	c.R = a.R - b.R;
	c.I = a.I - b.I;
	return c;
}

Complex Multiply(Complex a, Complex b) {
	Complex c;
	c.R = ((a.R * b.R) - (a.I * b.I));
	c.I = ((a.R * b.I) + (b.R * a.I));
	return c;
}

Complex Divide(Complex a, Complex b) {
	Complex c;
	c.R = (a.R * b.R + a.I * b.I) / (b.R * b.R + b.I * b.I);
	c.I = (a.I * b.R - b.I * a.R) / (b.R * b.R + b.I * b.I);
	return c;
}

void ShowComplex(Complex a) {
	cout << "Realparty: " << a.R << endl;
	cout << "Imaginarypart: " << a.I << "*i" << endl << endl;
}
Complex EnterComplex() {	
	Complex tmp;
	cout << "Enter Realparty: "; cin >> tmp.R; cout << endl;
	cout << "Enter Imaginarypart: "; cin >> tmp.I; cout << endl << endl;
	return tmp;
}

int main()
{
	cout << "+=========================================+" << endl;
	Complex a, b;
	cout << "Enter Compex Number A: " << endl;
	a = EnterComplex();

	cout << "Enter Compex Number B: " << endl;
	b = EnterComplex();

	cout << "Complex Number A: "; cout << endl;
	ShowComplex(a);

	cout << "Complex Number B: "; cout << endl;
	ShowComplex(b);
	cout << "+=========================================+" << endl << endl << endl;

	{
		cout << "+=========================================+" << endl;
		cout << "Plus Complex Numbers: " << endl;
		Complex c = Plus(a, b);
		ShowComplex(c);
		cout << "+=========================================+" << endl << endl << endl;
	}
	{
		cout << "+=========================================+" << endl;
		cout << "Minus Complex Numbers: " << endl;
		Complex c = Minus(a, b);
		ShowComplex(c);

		cout << "+=========================================+" << endl << endl << endl;
	}
	{
		cout << "+=========================================+" << endl;
		cout << "Multiply Complex Numbers: " << endl;
		Complex c = Multiply(a, b);
		ShowComplex(c);
		cout << "+=========================================+" << endl << endl << endl;
	}
	{
		cout << "+=========================================+" << endl;
		cout << "Divide Complex Numbers: " << endl;
		Complex c = Divide(a, b);
		ShowComplex(c);
		cout << "+=========================================+" << endl << endl << endl;
	}
	return 0;
}