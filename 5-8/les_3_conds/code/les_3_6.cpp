#include <iostream>
using namespace std;

int main()
{
    int mark = 50;
    cout << "Output:" << endl;
    if (mark < 50) 
    {
        cout << "You failed." << endl;
    }
    else if (mark > 50)
    {
        cout << "You passed." << endl;
    }
    else
    {
        cout << "You are lucker. There is 50!" << endl;
    }
    return (0);
}

