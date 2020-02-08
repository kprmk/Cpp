#include <iostream>
#include "ceasar_cypher.h"

using namespace std;

int main()
{
    string  input;
    int     num;

    cin >> input;
    cin >> num;
    ceasar_cypher test = ceasar_cypher(input, num);
    test.code();
    cout << test.getter() << endl;
    test.decode();
    cout << test.getter() << endl;
    return 0;
}
