#include <iostream>
#include <cstdlib> // for rand() && srand()
#include <ctime>   // time()
using namespace std;

void ceasar_cypher()
{
    string  input;
    int     shift;
    cout << "Enter string to code:" << endl;
    getline(cin, input); // cin >> input;
    cout << "Enter number to shift: ";
    cin >> shift;
    shift = shift % 26;
    cout << input << endl;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            if (input[i] + shift > 'z')
            {
                input[i] = input[i] - 26;
            }
            input[i] = input[i] + shift;
        }
    }
    cout << input << endl;
}

int main()
{
    // ceasar_cypher();
    srand(time(0));
    for (int j = 0; j < 1000; j++)
    {
        for (int i = 0; i < 100000000; i++) ;
        cout << rand() % 6 + 1 << endl  ;   
    }
    return (0);
}