#include "ceasar.h"

ceasar::ceasar()
{
    this->input = "";
    this->shift = 1;
}

ceasar::ceasar(string input, int shift = 1)
{
    this->input = input;
    this->shift = shift;
}

void ceasar::code()
{
    int shift;
    int len_of_input;

    len_of_input = this->input.length();
    shift = this->shift % 26;
    for (int i = 0; i < len_of_input; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            if ((int)(input[i] + shift) > 122)
                input[i] += shift - 26;
            else
                input[i] += shift;
        }
    }
}

void ceasar::decode()
{
    int shift;
    int len_of_input;

    len_of_input = this->input.length();
    shift = this->shift % 26;
    for (int i = 0; i < len_of_input; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            if (input[i] - shift < 97)
                input[i] += -shift + 26;
            else
                input[i] -= shift;
        }
    }
}

string ceasar::getter()
{
    return (this->input);
}

void ceasar::setter(string str, int num)
{
    this->input = str;
    this->shift = num;
}
