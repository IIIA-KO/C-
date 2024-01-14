#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Ukrainian");
    {
        //Завдання 1
        cout << "Розрахнок необхiдної швидкостi, щоб встигнути до аеропорта " << endl;

        double m;
        double hv;
        double mhv;
        double km;

        double h;
        double kmh;

        cout << "Введiть вiдстань до аеропрта в метрах: ";
        cin >> m;

        cout << "Введiть час, за який потрiбно потрапити до аеропорта в хвилинах: ";
        cin >> hv;

        mhv = m / hv;
        km = m / 1000;
        h = hv / 60;

        kmh = km / h;

        cout << "Вам необхiдно рухатися зi швидкiстю " << kmh << "км/год" << endl;

    }

    {
        //Завдання 2
        cout << "Розрахунок вартостi телефонного дзвiнка, якщо вартiсть однiєї хвилтни розмови - 30 копiйок" << endl;
        cout << "Для початку потрiбно ввести час початку та закiнчення телефонної розмови (години, хвилини, секунди)" << endl
            << "Максимальне значення для годин - 23, хвилин - 59, секунд - 59" << endl;

        float start_hour, start_minute, start_second;

        float end_hour, end_minute, end_second;

        float hour, minute, second;

        float all_time;

        float cost, all_cost;

        cout << "Введiть годину, о котрiй почнеться розмова: ";
        cin >> start_hour;
        cout << endl;

        cout << "Введiть хвилину, о котрiй почнеться розмова: ";
        cin >> start_minute;
        cout << endl;

        cout << "Введiть секунду, о котрiй почнеться розмова: ";
        cin >> start_second;
        cout << endl;

        cout << "Введiть годину, о котрiй закiнчиться розмова: ";
        cin >> end_hour;
        cout << endl;

        cout << "Введiть хвилину, о котрiй закiнчиться розмова: ";
        cin >> end_minute;
        cout << endl;

        cout << "Введiть секунду, о котрiй закiнчиться розмова: ";
        cin >> end_second;
        cout << endl;

        if (start_hour < 0 or start_hour > 23) {
            cout << "Недопустиме значення для годин !" << endl;
        }
        if (start_minute < 0 or start_minute > 59) {
            cout << "Недопустиме значення для хвилин !" << endl;
        }
        if (start_second < 0 or start_second > 59) {
            cout << "Недопустиме значення для секунд !" << endl;
        }
     
        if (end_hour < 0 or end_hour > 23) {
            cout << "Недопустиме значення для годин !" << endl;
        }
        if (end_minute < 0 or end_minute > 59) {
            cout << "Недопустиме значення для хвилин !" << endl;
        }
        if (end_second < 0 or end_second > 59) {
            cout << "Недопустиме значення для секунд !" << endl;
        }

        if (start_hour > end_hour) {
            hour = 24 + (end_hour - start_hour);
        }
        else if (start_hour < end_hour and start_minute > end_minute){
            hour = (end_hour - start_hour) - 1;
        }
        else {
            hour = (end_hour - start_hour);
        }

        if (start_minute > end_minute) {
           minute = 60 + (end_minute - start_minute);
        }
        else if(start_minute < end_minute and start_second > end_second){
            minute = (end_minute - start_minute) - 1;
        }
        else {
            minute = (end_minute - start_minute);
        }

        if (start_second > end_second) {
            second = 60 + (end_second - start_second);
        }
        else {
            second = (end_second - start_second);
        }
        
        cost = 30.0;
        all_cost = (cost * ((hour * 60) + (minute) + (second / 60))) / 100;

        cout << "Години: " << hour << endl <<"Хвилини: " << minute << endl << "Секунди: " << second << endl;

        cout << "Треба заплатити: " << all_cost << " гривень" << endl;

        {
            //Завдання 3
            float distance;
            float km_distance;

            float gas_cost_1;
            float gas_cost_2;
            float gas_cost_3;

            float cost_1;
            float cost_2;
            float cost_3;

            float one_km_cost_1;
            float one_km_cost_2;
            float one_km_cost_3;

            float consumption;
            float one_km_consumption;

            float distance_cost_1;
            float distance_cost_2;
            float distance_cost_3;

            cout << "Розрахунок порiвняльної таблицi трьох видiв бензину" << endl << "Введiть вiдстань, яку необхiдно проїхати у метрах: ";
            cin >> distance;
            cout << endl;

            cout << "Введiть кiлькiсть витрачених лiтрiв бензину на 100 кiлометрiв шляху: ";
            cin >> consumption;
            cout << endl;

            cout << "Введiть вартiсть одного лiтра бензину першого типу у гривнях: ";
            cin >> gas_cost_1;
            cout << endl;

            cout << "Введiть вартiсть одного лiтра бензину другого типу у гривнях: ";
            cin >> gas_cost_2;
            cout << endl;

            cout << "Введiть вартiсть одного лiтра бензину третього типу у гривнях: ";
            cin >> gas_cost_3;
            cout << endl;

            km_distance = distance / 1000;
            one_km_consumption = consumption / 100;

            one_km_cost_1 = gas_cost_1 * one_km_consumption;
            one_km_cost_2 = gas_cost_2 * one_km_consumption;
            one_km_cost_3 = gas_cost_3 * one_km_consumption;

            distance_cost_1 = one_km_cost_1 * km_distance;
            distance_cost_2 = one_km_cost_2 * km_distance;
            distance_cost_3 = one_km_cost_3 * km_distance;
			
            cout << "_____________________________________________________________________________________________________" << endl;
            cout << "|" << "Номер Бeнзину" << "|" << "Вартiсть поїздки на задану вiдстань" << "|" << "Вартiсть поїздки на один кiлометр" << "|" << "Задана Вiдстань" << "|" << endl;
            cout << "|" <<"________________________________________________________________________я____________________________" << endl;
            cout << "|" << "#1           " << "|" << distance_cost_1 << " гривень                        " << "|" << one_km_cost_1 << " гривень                       " << "|" << km_distance << " кiлометрiв  " << "|" << endl;
            cout << "|" <<"____________________________________________________________________________________________________" << endl;
            cout << "|" << "#2           " << "|" << distance_cost_2 << " гривень                        " << "|" << one_km_cost_2 << " гривень                       " << "|" << km_distance << " кiлометрiв  " << "|" << endl;
            cout << "|" <<"____________________________________________________________________________________________________" << endl;
            cout << "|" << "#3           " << "|" << distance_cost_3 << " гривень                        " << "|" << one_km_cost_3 << " гривень                       " << "|" << km_distance << " кiлометрiв  " << "|" << endl;
            cout << "|" <<"____________________________________________________________________________________________________" << endl;
        }

    }
    return 0;
}