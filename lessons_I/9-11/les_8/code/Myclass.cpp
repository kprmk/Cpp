// Myclass.cpp
#include "Myclass.h"
#include <iostream>

using namespace std;

Myclass::Myclass()
{
    cout << "You have created obj" << endl;
}

Myclass::~Myclass()
{
    cout << "The obj has been deleted" << endl;
}

/* Myclass.cpp
**
** Для реализации методов класса необходимо 
** подключить заголовочный файл класса
**
** Обращаем внимение на кавычки - 
** для собственных заголовочных файлов 
** используем двойные кавычки, в свою очередь
** для подключения стандартных библиотек -
** используем угловые
*/