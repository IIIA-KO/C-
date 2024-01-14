#include <iostream>
using namespace std;
int main()
{
    {
        //Завдання 1
        int first_seconds;
        int end_seconds;

        float start_hour;
        float start_minute;
        float start_second;

        float end_hour;
        float end_minute;
        float end_second;

        cout <<"Enter the seconds since the start of day (one day have only 86, 400 seconds): ";
        cin >> first_seconds;

        end_seconds = 86400 - first_seconds;

        if (first_seconds < 0 or first_seconds > 86400) {
            cout << "Entered seconds have value more than 86, 400 or less than 0" << endl;
        }

        start_hour = first_seconds / 3600;
        start_minute = first_seconds % 3600 / 60;
        start_second = first_seconds % 3600 % 60;

        end_hour = end_seconds / 3600;
        end_minute = end_seconds % 3600 / 60;
        end_second = end_seconds % 3600 % 60;

        cout << "Passed " << start_hour << " hours" << endl << start_minute << " minutes" << endl << start_second << " seconds" << endl;
        cout << endl;
        cout << "Remains " << end_hour << " hours" << endl << end_minute << " minutes" << endl << end_second << " seconds untill the midnight" << endl;
    }
    {
        //Завдання 2
        int start_day;
        int passed_seconds;
        int remains_hour;
        int remain_hours;

        cout << "Enter the hour, when your working day starts: ";
        cin >> start_day;
        cout << "The working day has a duration of 8 hours" << endl;

        if (start_day > 23 or start_day < 0) {
            cout << "Entered hour has value less than '0' or more than 24 !" << endl;
        }

        cout << "Enter the passed seconds since the start of the working day: ";
        cin >> passed_seconds;

        if ((passed_seconds / 3600) >= 8) {
            cout << "Your woring day has already pessed" << endl;
        }

        remain_hours = 8 - (passed_seconds / 3600);
        cout << "Remains " << remain_hours << " hours" << " untill the end of the working day" << endl;
    }
    return 0;
}
