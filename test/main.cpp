#include <iostream>
using namespace std;

int main()
{
    string  input;
    int     shift;
    cout << "Enter number to shift: ";
    cin >> shift;
    cout << "Enter string to code:" << endl;
    cin >> input;
    cout << input << endl;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 97 && input[i] <= 122)
        {
            input[i] = input[i] + shift;
        }
    }
    cout << input << endl;
    return (0);
}

