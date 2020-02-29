#include <iostream>
using namespace std;

template<class T, class U>
T bigger(T first, U second)
{
    return ((first > second) ? first : second);
}

char bigger(char first, string second)
{
    return ((first - second[0] > 0) ? first : second[0]);
}

char bigger(string first, char second)
{
    return ((first[0] - second > 0) ? first[0] : second);
}

int main()
{
    char f = 'a';
    string s = "bbc";
    cout << bigger(s, f);
    return (0);
}