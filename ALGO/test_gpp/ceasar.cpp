#include "ceasar.h"

ceasar::ceasar()
{
	this->input = "";
	this->shift = 0;
}

ceasar::ceasar(string input, int shift)
{
	this->input = input;
	this->shift = shift;
}

void ceasar::to_code()
{
	for (int i = 0; i < this->input.length(); i++)
	{
		this->input[i] += this->shift; 
	}
}
const string ceasar::getter()
{
	return this->input;
}