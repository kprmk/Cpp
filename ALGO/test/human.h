#include <iostream>
using namespace std;

class human
{
private:
	string name;
	int age;

public:
	human();
	human(string name, int age);
	string get_name();
	string bar();
	int get_age();
	void operator++();
	void say_goodbye();
};



