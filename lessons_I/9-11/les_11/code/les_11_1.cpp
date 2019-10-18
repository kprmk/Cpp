#include <iostream>
using namespace std;

int main() 
{
    cout << "Output:" << endl;
    try 
    {
        int num1;
        cout << "Enter the first number: ";
        cin >> num1;
    
        int num2;
        cout << "Enter the second number: ";
        cin >> num2;
    
        if(num2 == 0) 
        {
            throw 0;
        }
        cout << "Result: " << num1 / num2;
    }
    catch(int x)
    {
        cout << "Division by zero!";
    }
    return (0);
}
