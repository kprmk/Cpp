#include "Car.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cstdio>

using namespace std;

Car::Car()
{
	total = 50;
	cur = 50;
	consump = random();
}

Car::Car(double c)
{
	total = 50;
	cur = c;
	consump = random();
}

double Car::random()
{
	srand(time(NULL));
	return  7.5 + (-100. + rand() % 300) / 100;
}

void Car::petrol()
{
	cur = 50;
}

void Car::trip(double km)
{
	double x;
	if (km > cur / consump)
	{
		while (km > 0)
		{
			x = cur / consump;
			petrol();
			cout << "FULL --- > DONE   " << "CONSUMP ~" << getCONS() << endl;
			consump = random();
			km -= x;
		}
	}
	cout << "Oh?! That was so good, magnificent TRIP <EEE> " << endl;
}