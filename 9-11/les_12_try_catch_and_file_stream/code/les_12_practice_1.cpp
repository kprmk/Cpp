#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
    ofstream MyFile("test.txt");
    try
    {
        if (MyFile.is_open()) 
        {
            cout << "File has been opened!\n"; 
            MyFile << "I was here!\n";
        }
        else 
        {
            throw 0;
        }
    }
    catch (int x)
    {
        cout << "There has been error" << endl;
        cout << "File " << "test.txt" << "hasn't been opened!" <<  endl;
    }
    MyFile.close();
    return (0);
}

