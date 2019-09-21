#include "phone_book.h"

phone_book::phone_book(std::string name, std::string num)
{
    this->name_surname = name;
    this->number = num;
//    id++;
}

phone_book::~phone_book()
{ }

std::ostream & operator<<(std::ostream &os, phone_book & ph)
{
    os << ph.name_surname << " " << ph.number;
    return os;
}

std::istream & operator>>(std::istream & in, phone_book & ph)
{
    std::string str;
    in >> str;
    ph.name_surname = str;
    in >> str;
    ph.number = str;
    return in;
}

bool phone_book::add()
{
    return true;
}

bool phone_book::del()
{
    return true;
}
