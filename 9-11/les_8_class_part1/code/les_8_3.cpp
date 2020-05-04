// main.cpp
#include <iostream>
#include "file.h"

using namespace std;

int main()
{
    cout << "Output:\n";
    Date date_of_birth = Date(25, 03, 2000);
    Date *pointer = &date_of_birth;
    date_of_birth.getDate(); // для доступа к методу getDate() посредством самого объекта пользуемся .
    pointer->getDate(); // для доступа к методу getDate() посредством указателя на объекта пользуемся ->
    return (0);
}

