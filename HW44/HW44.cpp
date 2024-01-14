#include <iostream>
using namespace std;

void Bin(unsigned int n, int w = 8) {
	if (n < 1 && w == 0) return;
	Bin(n / 2, --w);
	cout << n % 2;
}

struct RGB {
	unsigned int r, g, b;
};
unsigned int RgbToUInt(int r, int g, int b) {
	unsigned int color;
	color = (r << 16) + (g << 8) + (b << 0);
	return color;
}
RGB UIntToRgb(unsigned int x) {
	RGB res;
	res.r = x >> 16;
	res.g = x >> 8;
	res.g = res.g << 24 >> 24;
	res.b = x << 24 >> 24;
	return res;
}

int main()
{
	unsigned r, g, b;
	cout << "Enter argument R: "; cin >> r; cout << endl;
	cout << "Enter argument G: "; cin >> g; cout << endl;
	cout << "Enter argument B: "; cin >> b; cout << endl;
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
		cout << "Error: Wrong enterd number" << endl;
		return 1;
	}
	cout << "Bin A: "; Bin(r); cout << endl;
	cout << "Bin G: "; Bin(g); cout << endl;
	cout << "Bin B: "; Bin(b); cout << endl;

	unsigned int color = RgbToUInt(r, g, b);
	cout << "RGB to Number: ";  Bin(color, 32); cout << endl;

	RGB res = UIntToRgb(color);
	cout << "Number to RGB: " << endl;

	cout << "R: " << res.r; cout << endl;
	cout << "G: " << res.g; cout << endl;
	cout << "B: " << res.b; cout << endl;
	return 0;
}
