#include <iostream>
#include <fstream>
#include "phone_book.h"

using std::cout;
using std::endl;


int main()
{


//    std::ofstream fout;
//    fout.open("newfile.txt", std::ofstream::app);
//    if(!fout.is_open())
//    {
//        cout << "ERROR"<< endl;
//    }
//    else
//    {
//        for(int i = 0; i < 5 ; i++)
//        {
//            //fout << i << '\n';
//        }
//    }

//    std::ifstream fin;
//    fin.open("newfile.txt");
//    if(fin.is_open())
//    {
//        cout << "plus" << endl;
//    }
//    else
//    {
//        cout << "minus" << endl;
//    }

//    std::string cur;
//    while(!fin.eof())
//    {
//        std::getline(fin, cur);
//        cout << cur << endl;
//    }

//    fout.close();
//    fin.close();


    phone_book ph("PETYA", "+790");
    std::fstream fs;
    fs.open("newfile.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    if(!fs.is_open())
    {    cout << "ERROR" <<endl;  }
    else {   fs <<  ph << "\n"; }


    return 0;
}
