#include "str.h"

str::str()
{
    string = new char[0];
    * string = '\0';
}

str::str(char *s)
{
    int l = 0;
    for (int i = 0; *(s + i); i++) { l++; }
    len = l;
//    cout << len << endl;
    string = new char [len + 1];
    for (int i = 0; *(s + i); i++) { *(string + i) = *(s + i); }
     * (string + len + 1) = '\0';
//     for (int i = 0; *(string + i); i++) { cout << *(string + i); }
}

str::~str()
{
    delete [] string;
}

void str::print()
{
    for (int q = 0; q < this->size() ; q++) { cout << string[q]; }
    cout << endl;
}

char & str::operator[](int i )
{
    return *(string + i);
}

str & str::add_symb(int i, char ch)
{
    char * s_temp = new char [this->size() + 2];
    for (int j = 0; j < this->size() + 1; j++ )
    {
        if(i > j)
            s_temp[j] = this->string[j];
        if(i == j)
            s_temp[j] = ch;
        if(i < j)
             s_temp[j] = this->string[j - 1];
    }
    s_temp[this->size() + 2] = '\0';
//    for (int j = 0; * (s_temp + j); j++ ) { this->string[j] = s_temp[j] ; }
    this->~str();
    str str (s_temp);
    * this = str;
//    for (int j = 0; * (this->string + j); j++ ) { cout << this->string[j]; }
//    cout << endl;
    delete [] s_temp;
    return  * this;
}

int str::max_sent()
{
    int max = 0;
    for (int cur_l = 0, i = 0 ; i < this->size(); i++)
    {
        if(string[i] == '.')
        {
            max = max < cur_l? cur_l : max;
            cur_l = -2;
        }
        cur_l++;
    }
    return max;
}

str& str::add_gaps()
{
    for (int i = 0 ; i < this->size(); i++)
    {
        if(string[i] == '.')
        {
            if(string[i + 1] != ' ')
                this->add_symb(i + 1, ' ');
        }
    }
    return * this;
}
