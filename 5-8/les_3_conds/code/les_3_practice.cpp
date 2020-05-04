#include <iostream>
using namespace std;

int main()
{
    int num = 50;
    int input_num;
    cout << "Hello" << endl;
    cout << "Please, enter a positive number!" << endl;
    cin >> input_num;
    if (input_num == num)
    {
        cout << "You win!! Congrats!" << endl;
    }
    else if (input_num < num - 20)
    {
        cout << "You lose, it is cold" << endl;
    }
    else if (input_num > num + 20)
    {
        cout << "You lose, it is cold" << endl;
    }
    else if (input_num < num + 20)
    {
        cout << "You lose, but it is hot" << endl;
    }
    else if (input_num > num - 20)
    {
        cout << "You lose, but it is hot" << endl;
    }
    return (0);
}

