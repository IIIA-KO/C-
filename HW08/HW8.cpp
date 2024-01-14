#include <iostream>
using namespace std;
int main()
{
	{
		//Завдання 1
		int month_number;
		cout << "Enter the integer number that has value from 1 to 12 (Number will match every month of year): "; cin >> month_number;
		switch (month_number)
		{
		case 1:
			cout << "January" << endl; break;
		case 2:
			cout << "February" << endl; break;
		case 3:
			cout << "March" << endl; break;
		case 4:
			cout << "April" << endl; break;
		case 5:
			cout << "May" << endl; break;
		case 6:
			cout << "June" << endl; break;
		case 7:
			cout << "July" << endl; break;
		case 8:
			cout << "August" << endl; break;
		case 9:
			cout << "September" << endl; break;
		case 10:
			cout << "October" << endl; break;
		case 11:
			cout << "November" << endl; break;
		case 12:
			cout << "December" << endl; break;
		default:
			cout << "Error: Entered number has value less than 1 or more than 12" << endl; break;
		}
	}
	{
		//Завдання 2
		int number;
		cout << "Enter the integer number that has value from 1 to 9 (Number will match every number and word, for example 1 - 'one', 2 - 'two'...): "; cin >> number;
		switch (number)
		{
		case 1:
			cout << "One" << endl; break;
		case 2:
			cout << "Two" << endl; break;
		case 3:
			cout << "Three" << endl; break;
		case 4:
			cout << "Four" << endl; break;
		case 5:
			cout << "Five" << endl; break;
		case 6:
			cout << "Six" << endl; break;
		case 7:
			cout << "Seven" << endl; break;
		case 8:
			cout << "Eight" << endl; break;
		case 9:
			cout << "Nine" << endl; break;
		default:
			cout << "Error: Entered number has value less than 1 or more than 9" << endl;  break;
		}
	}

	{
		//Задання 3
		double x, y; int operation;
		cout << "Enter the number X: "; cin >> x;
		cout << "Enter the number Y: "; cin >> y;
		cout << "Enter which type of operation on numbers you want to do (1 - addition, 2 - subtraction, 3 - multiplication, 4 - dividing): "; cin >> operation;

		switch (operation)
		{
		case 1:
			cout << x << " + " << y << " = " << x + y << endl << y << " + " << x << " = " << y + x << endl; break;
		case 2:
			cout << x << " - " << y << " = " << x - y << endl << y << " - " << x << " = " << y - x << endl; break;
		case 3:
			cout << x << " * " << y << " = " << x * y << endl << y << " * " << x << " = " << y * x << endl; break;
		case 4:
			cout << x << " / " << y << " = " << x / y << endl << y << " / " << x << " = " << y / x << endl; break;
		default:
			cout << "Error: Entered number has value less than 1 or more than 4" << endl;  break;
		}
	}
	{
		//Завдання 4
		int holiday;
		cout << "Enter the integer number that has value from 1 to 12 (Number will match every month and holidays): "; cin >> holiday;
		switch (holiday)
		{
		case 1:
			cout << "January: " << endl;
			cout << "January 1 - New Year, January 6 - Christmas Eve, January 7 - Christmas" << endl;
			cout << "January 14 - Old New Year, January 19 - Baptism of the Lord (Epiphany)"<< endl;
			cout << "January 22 - Day of Unity and Freedom of Ukraine, January 25 - Student's Day (Tatiana's Day), January 27 - International Holocaust Remembrance Day" << endl;
			break;
		case 2:
			cout << "February: " << endl;
			cout << "February 4 - International Cancer Day, February 7 - Saint Mel's Day, February 11 - World Sick Day" << endl;
			cout << "February 14 - Valentine's Day, February 19 - World Whale Day, February 20 - Apple Day in USA" << endl;
			break;
		case 3:
			cout << "March: " << endl;
			cout << "March 3 - World Writers Day, March 8 - International Women's Day, March 14 - unofficial Pi Day" << endl;
			cout << "March 17 - St. Patrick's Day in Ireland, Northern Ireland and the Canadian province of Newfoundland and Labrador." << endl;
			break;
		case 4:
			cout << "April: " << endl;
			cout << "April 1 - April Fool's Day; International bird day, April 7 - Feast of the Annunciation of the Blessed Virgin Mary among Christians adhering to the 'old style'" << endl;
			cout << "April 12 - World Aviation and Astronautics Day, April 22 - Earth Day, April 23 - International Book Day" << endl;
			break;
		case 5:
			cout << "May: " << endl;
			cout << "May 8 - Victory Day in Europe, May 17 - International Telecommunication Day, May 18 - International Museum Day" << endl;
			cout << "May 21 - International Day of Space, May 26 - Kyiv City Day" << endl;
			break;
		case 6:
			cout << "June: " << endl;
			cout << "June 1 - International Children's Day (since 1949), June 5 - World Environment Day, June 8 -World Oceans Day(since 2009)" << endl;
			cout << "21st of June - International Skateboarding Day, June 27 - World Fishing Day" << endl;
			break;
		case 7:
			cout << "July: " << endl;
			cout << "The first Saturday of the month is the International Dnipro Day in Belarus, Russia and Ukraine, July 2 - International Day of Sports Journalist" << endl;
			cout << "July 2 - International Day of Sports Journalist, July 20 - International Chess Day, July 31 - African Woman's Day" << endl;
			break;
		case 8:
			cout << "August: " << endl;
			cout << "August 13 - World Left-Handed Day" << endl;
			cout << "August 14 - The origin (wear) of the honest trees of the Life-giving Cross of the Lord (Honey Savior - among the people) among Orthodox Christians" << endl;
			cout << "August 19 - Transfiguration of the Lord (Apple Savior - among the people) among Christians" << endl;
			break;
		case 9:
			cout << "September: " << endl;
			cout << "Day 256 of the year (September 12 or 13) - Programmer's Day, September 19 - International Pirate Day" << endl;
			cout << "Last Sunday - International Day of the Deaf, September 30 - International Day of the Translator" << endl;
			break;
		case 10:
			cout << "October: " << endl;
			cout << "October 1 - International Day of Older Persons, October 1 - International Day of Music, October 2 - International Day of Non-Violence" << endl;
			cout << "October 5 - World Teachers Day, Second Friday in October - World Egg Day, 1st Monday - World Habitat Day, World Architecture Day" << endl;
			cout << "October 24 - United Nations Day" << endl;
			break;
		case 11:
			cout << "November: " << endl;
			cout << "November 1 - International Vegan Day, November 10 - International day of accountants and auditors, November 17 - International Students Day" << endl;
			cout << "November 19 - International Men's Day, Third Thursday of November - International Day of Philosophy" << endl;
			cout << "Third Sunday in November - World Day of Remembrance for Road Traffic Victims" << endl;
			break;
		case 12:
			cout << "December: " << endl;
			cout << "December 1 - World AIDS Day, December 7 - International Day of Civil Aviation" << endl;
			cout << "December 10 - Human Rights Day, December 31 - New Years Eve" << endl;
			break;
		default:
			cout << "Error: Entered number has value less than 1 or more than 12" << endl;
			break;
		}
	}
	{
		//Завдання 5
		double l; int type;
		cout << "Enter the number to recreate it to meters: "; cin >> l;
		cout << "Enter the type of your number (1 - decimetre; 2 - kilometer; 3 - meter; 4 - millimeter; 5 - centimeter): "; cin >> type;

		switch (type)
		{
		case 1:
			cout << l / 10 << " = " << " meters " << endl; break;
		case 2:
			cout << l * 1000 << " = " << " meters " << endl; break;
		case 3:
			cout << l << " = " << " meters " << endl; break;
		case 4:
			cout << l / 1000 << " = " << " meters " << endl; break;
		case 5:
			cout << l / 100 << " = " << " meters " << endl; break;
		default:
			cout << "Error" << endl;
			break;
		}

	}
}
