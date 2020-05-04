#ifndef CEASAR_H
#define CEASAR_H

#include <iostream>
using namespace std;

class ceasar
{
private:
    string  input;
    int     shift;

public:
    ceasar();
    ceasar(string input, int shift);
    void code();
    void decode();
    string getter();
    void setter(string str, int num);
};

#endif // CEASAR
