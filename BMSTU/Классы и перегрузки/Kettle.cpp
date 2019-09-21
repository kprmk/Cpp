#include "Kettle.h"
#include <cstdio>
#include <iostream>
#include <cmath>
//volume ---> Ml ; temp ---> grad
using namespace std;

Kettle::Kettle()
{
	total_volume = 1000;
	cur_volume = 1000;
	cur_temp = 70;
}

Kettle::Kettle(unsigned kur_vol)
{
	total_volume = 1000;
	cur_volume = kur_vol;
	cur_temp = 70;
}

Kettle::~Kettle()
{
}

void Kettle::vol_up()
{
	cur_temp = total_volume * cur_temp / cur_volume;
	cur_volume = total_volume;
	cout << "FULL, TEMP == " << get_ct() << endl;
}

void Kettle::boil()
{
	cur_temp = 100;
	cout << "BOIL___BOIL___BOIL" << endl;
}

void Kettle::cup_of(unsigned down)
{
	cur_volume -= down;
	cout << "CURRENT VOLUME == " << get_cv() << endl;
}

void Kettle::cool_down(unsigned time)
{
	cur_temp = 20 + (cur_temp - 20) * 1 / exp_pow(time);
	cout << "COOL DOWN ---> CURRENT TEMP = " << get_ct() << endl;
}

float Kettle::exp_pow(unsigned time)
{
	//cout << "exp == " << exp(1) << endl;
	cout << "exp^^^ == " <<  1 / (pow(exp(1), 0.001 * time)) << endl;
	return pow(exp(1), 0.001 * time);
}