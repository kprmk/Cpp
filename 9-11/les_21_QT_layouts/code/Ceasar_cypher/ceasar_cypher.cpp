#include "ceasar_cypher.h"

ceasar_cypher::ceasar_cypher()
{
    this->input = "";
    this->shift = 1;
}

ceasar_cypher::ceasar_cypher(string input, int shift = 1)
{
    this->input = input;
    this->shift = shift;
}

void ceasar_cypher::code()
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
            {
                input[i] += shift - 26;
            }
            else
                input[i] += shift;
        }
    }
}

void ceasar_cypher::decode()
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
            {
                input[i] += -shift + 26;
            }
            else
                input[i] -= shift;
        }
    }
}

string ceasar_cypher::getter()
{
    return (this->input);
}

void ceasar_cypher::setter(string str, int num)
{
    this->input = str;
    this->shift = num;
}
