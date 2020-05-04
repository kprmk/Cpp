#include <iostream>
using namespace std;

void say_age(string name = "Denis", int age = 18);

int main()
{
	say_age();
    return 0;
}

void say_age(string name, int age)
{
	cout << "Hi, my name is " 
	<< name << " I'm " << age << endl;
}