#ifndef STR_H
#define STR_H

#include <iostream>
#include <cstdlib>
#include <cstdio>

using std::cout;
using std::endl;

class str
{
private:
    char * string;
    int len;

public:
    str();
    str(char * s);
    ~str();

    void print();
    int size() { return len; }
    char& operator[](int i );
    str& add_symb(int i , char ch);
    int max_sent();
    str& add_gaps();
};

#endif // STR_H
