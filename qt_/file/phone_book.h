#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include<iostream>
#include<string>

using std::cout;
using std::endl;

class phone_book
{
private:

//    static int id;
    std::string name_surname;
    std::string number;

public:
    phone_book(std::string name = " ", std::string num = " " );
    ~phone_book();

    friend std::ostream & operator<<(std::ostream & os, phone_book & ph);
    friend std::istream & operator>>(std::istream & in, phone_book & ph);

    bool add();
    bool del();
//    std::string read();

};

#endif // PHONE_BOOK_H
