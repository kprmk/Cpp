#include <iostream>
using namespace std;

template <class T_1, class T_2>
T_1     bigger(T_1 first, T_2 second)
{
    return (first > second ? first : second);
}

char  bigger(string str, char ch)
{
    return (str[0] > ch ? str[0] : ch);
}

char  bigger(char ch, string str)
{
    return (str[0] > ch ? str[0] : ch);
}

int main () 
{
    int     a = 1, b = 10;
    double  c = 1.89;
    float   d = 13.2;
    char    ch_1 = 'b', ch_2 = '%';
    string  str_1 = "abc", str_2 = "abcd";

    cout << bigger(a, b) << endl;
    cout << bigger(c, b) << endl;
    cout << bigger(c, d) << endl;
    cout << bigger(d, c) << endl;
    cout << bigger(ch_1, ch_2) << endl;
    cout << bigger(str_1, ch_2) << endl;
    cout << bigger(ch_1, str_2) << endl;
    
    return (0);
}

