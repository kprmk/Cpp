#include "human.h"

// this

human::human()
{
	cout << "I was born" << endl;
}

human::human(string name, int age)
{
	this->name = name;  //(*this).name = name;
	this->age = age;
}

string human::get_name()
{
	return (name);
}

int human::get_age()
{
	return (age);
}

void human::say_goodbye()
{
	cout << "GOOD BYE!" << endl;
}

void human::operator++()
{
	age++;
}

string human::bar()
{
	return (age > 18 ? "Let's go" : "NOPE");
}