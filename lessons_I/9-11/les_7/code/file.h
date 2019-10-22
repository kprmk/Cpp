// file.h
#include <iostream>
using namespace std;
 
// объявление класса
class Date // имя класса
{
private: // спецификатор доступа private
    int day; // день
    int month; // месяц
    int year; // год

public: // спецификатор доступа public
    Date(int date_day, int date_month, int date_year ) // конструктор класса
    {
        setDate(date_day, date_month, date_year); // вызов функции установки даты
    }
    void message() // функция (метод класса) выводящая сообщение на экран
    {
        cout << "nwebsite: Date.comntheme: Classes and Objects in C + +n";
    }
    void setDate(int date_day, int date_month, int date_year) // установка даты в формате дд.мм.гг (setter)
    {
        day   = date_day; // инициализация день
        month = date_month; // инициализация месяц
        year  = date_year; // инициализация год
    }
    void getDate() // отобразить текущую дату (getter)
    {
        cout << "date: " << day << "." << month << "." << year << endl;
    }
}; // конец объявления класса Date