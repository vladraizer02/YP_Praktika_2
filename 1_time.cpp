#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main(int argc, char **argv)
{
    int day = 7;
    int months = 12;
    string weekday_ru[day] = {"Пнд", "Втр", "Сре", "Чтв", "Птн", "Суб", "Вск"};
    string weekday_en[day] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    string month_ru[months] = {"Янв", "Фев", "Мар", "Апр", "Май", "Июн", "Июл", "Авг", "Сен", "Окт", "Ноя", "Дек"};
    string month_en[months] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    time_t t = time(NULL);
    tm * ptm;
    ptm = localtime(&t);
    string time_en = asctime(ptm);
    string time_ru;
    for (int i=0; i < day; i++) {
        if (time_en.find(weekday_en[i]) != string::npos){
            time_ru = weekday_ru[i] + " ";
            time_en.erase(0, 4);
            break;
        }
    }
    for (int i=0; i < months; i++) {
        if (time_en.find(month_en[i]) != string::npos){
            time_ru = time_ru + month_ru[i] + " ";
            time_en.erase(0, 4);
            break;
        }
    }
    time_ru = time_ru + time_en;
    cout<<time_ru;
    return 0;
}
