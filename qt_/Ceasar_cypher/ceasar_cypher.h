#ifndef CEASAR_CYPHER_H
#define CEASAR_CYPHER_H

#include <iostream>
using namespace std;

class ceasar_cypher
{
private:
    string  input;
    int     shift;

public:
    ceasar_cypher();
    ceasar_cypher(string input, int shift);
    void code();
    void decode();
    string getter();
    void setter(string str, int num);
};

#endif // CEASAR_CYPHER_H
