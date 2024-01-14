#include <iostream>
using namespace std;
int main()
{	
	{
		//Завдання 1
		int start_number;

		cout << "Cheking your number - lucky or not" << endl;
		cout << "If sum of first 3 digits equal sum of last 3 digigts - number is lucky" << endl;
		cout << "Enter the integer number that has value from 100,000 to 999,999: "; cin >> start_number; cout << endl;
		if (start_number < 100000 or start_number > 999999) {
			cout << "Error: Entered the number that has value more than 100,000 or less than 999,999 !" << endl;
		}

		if ((((start_number / 1000) / 100) + (((start_number / 1000) % 100) / 10) + ((start_number / 1000) % 10)) == (((start_number % 1000) / 100) + ((((start_number % 1000) % 1000) % 100) / 10) + ((start_number % 1000) % 10))) {
			cout << "Number is lucky" << endl << endl;
		}
		else {
			cout << "Number is not lucky" << endl << endl;
		}

	}
		
	{
		//Завдання 2
		int four_digit_number;

		cout << "Replacing the digits of 4-digit number (program replaces the first and second digits, third and fourth)" << endl;
		cout << "Enter the integer number that has value more than 1,000 or less than 9,999: "; cin >> four_digit_number;
		if (four_digit_number < 1000 or four_digit_number > 9999) {
			cout << "Error: Entered number has value less than 1,000 or more than 9,999 !" << endl;
		}
		cout << "Your number: " << four_digit_number << endl;
		cout << "Replaced variant: " << (four_digit_number / 100) % 10 << (four_digit_number / 100) / 10 << (four_digit_number % 100) % 10 << (four_digit_number % 100) / 10 << endl << endl;
			 
	}

	{
		//Завдання 3
		cout << "Calculating the maximal of seven entered numbers" << endl;
		int first; int second; int third; int fourth; int fifth; int sixth; int seventh; int max;

		cout << "Enter the first integer number: "; cin >> first;
		cout << "Enter the second integer number: "; cin >> second;
		cout << "Enter the third integer number: "; cin >> third;
		cout << "Enter the fourth integer number: "; cin >> fourth;	
		cout << "Enter the fifth integer number: "; cin >> fifth;
		cout << "Enter the sixth integer number: "; cin >> sixth;
		cout << "Enter the seventh integer number: "; cin >> seventh;

		max = first;
		if (second > max) {
			max = second;
		}
		if (third > max) {
			max = third;
		}
		if (fourth > max) {
			max = fourth;
		}
		if (fifth > max) {
			max = fifth;
		}
		if (sixth > max) {
			max = sixth;
		}
		if (seventh > max) {
			max = seventh;
		}
		cout << "Max: " << max << endl << endl;
	}

	{
		//Завдання 4
		float distance_AB; float distance_BC; float cargo; float one_km_consumption; float consumption_AB; float consumption_BC; float consumption_AC;
		int  max_capacity; int rest; int refuel;

		cout << "Plane have to replace some cargo from point 'A' to point 'C' (before 'C' plain flies to point 'B')" << endl;
		cout << "If the aircraft is flying with a payload of up to 500 kg, it spends 1 liter per kilometer" << endl;
		cout << "If the aircraft is flying with a payload of up to 1000 kg, it spends 4 liter per kilometer" << endl;
		cout << "If the aircraft is flying with a payload of up to 1500 kg, it spends 7 liter per kilometer" << endl;
		cout << "If the aircraft is flying with a payload of up to 2000 kg, it spends 9 liter per kilometer" << endl;
		cout << "The maximal capacity of plane tank if 300 liters" << endl;
		cout << "If plane do not have cargo, it cannot fly" << endl;
		cout << "If the plane flies with a payload more than 2000 kg, it connot fly" << endl;

		cout << "Enter the distance between point 'A' and point 'B' in kilometers: "; cin >> distance_AB; cout << endl;
		cout << "Enter the distance between point 'B' and point 'C' in kilometers: "; cin >> distance_BC; cout << endl;
		cout << "Enter the weight of cargo that plain have to replace from point 'A'and 'C' in kilograms: "; cin >> cargo; cout << endl;

		if (cargo <= 0) {
			cout << "Warning: Plane don't have cargo!" << endl;
		}
		else if (cargo >= 1 and cargo <= 499){
			one_km_consumption = 1;
		}
		else if (cargo >= 500 and cargo <= 999) {
			one_km_consumption = 4;
		}
		else if (cargo >= 1000 and cargo <= 1499) {
			one_km_consumption = 7;
		}
		else if (cargo >= 1500 and cargo <= 2000) {
			one_km_consumption = 9;
		}
		else if (cargo > 2000) {
			cout << "Warning: Plane cannot fly !" << endl;
		}

		consumption_AB = one_km_consumption * distance_AB;
		consumption_BC = one_km_consumption * distance_BC;
		consumption_AC = consumption_AB + consumption_BC;
		max_capacity = 300;
		rest = max_capacity - consumption_AB;
		refuel = consumption_BC - rest;

		if (consumption_AC <= max_capacity) {
			cout << "Plane can fly to point 'C' without refueling" << endl;
		}
		else if (consumption_AB > max_capacity) {
			cout << "Plane cannot fly from point 'A' to point 'B' !" << endl;
		}
		else if (consumption_BC > max_capacity) {
			cout << "Plane cannot fly from point 'B' to point 'C' !" << endl;
		}
		else if (consumption_BC > rest) {
			cout << "You need to refuel " << refuel << " liters of gas" << endl;
		}
		else if (consumption_AB == max_capacity or consumption_BC == max_capacity) {
			cout << "Plane need to refuel all the tank" << endl;
		}
	}
	return 0;	
}