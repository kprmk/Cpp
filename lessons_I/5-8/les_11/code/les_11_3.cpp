#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
    ofstream MyFile("test.txt");

    if (MyFile.is_open()) 
    {
        MyFile << "File has been opened! \n";
    }
    else 
    {
        cout << "Something went wrong";
    }
    MyFile.close();
    return (0);
}

