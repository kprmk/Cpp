#include <iostream>
#include <string>
using namespace std;

class ceasar_cypher
{
private:
    string  to_code;
    int     shift;
public:
    ceasar_cypher(string input_string, int number_for_shift);
    void code();
    string getter_str();
    void setter_str(string input);
    
};

string ceasar_cypher::getter_str()
{
    return to_code;
}

void ceasar_cypher::setter_str(string input)
{
    to_code = input;
}

ceasar_cypher::ceasar_cypher(string input_string, int number_for_shift)
{
    to_code = input_string;
    shift = number_for_shift % 26;
}

void ceasar_cypher::code()
{
    for (int i = 0; i < to_code.length(); i++)
    {
        if (to_code[i]  >= 'a' && to_code[i] <= 'z')
        {
            to_code[i] += shift;
            if (to_code[i] > 'z')
                to_code[i] -= 26;
        }
    }
}

int main()
{

    // char ch = getchar();
    // cout << ch;
    string input;
    int sh;
    getline(cin, input);
    cin >> sh;
    // cout << endl;
    ceasar_cypher test1 = ceasar_cypher(input, sh);
    test1.code();
    cout << test1.getter_str() << endl;
}

/*
____________________________________________________________________
AlGORITHM

1.  PRINT MAP
    1.1 GET THE DATA FROM THE USER
    (CHARACTER OF THE BORDER, HEIGHT AND WIDTH 
    OF THE MAP ARE ENTERED BY USER)
    1.2 EACH POSITION ON THE MAP
    1.3 IF FIRST OR LAST STRING -> PRINT CHAR_BORDER IN EACH COLUMN
    1.4 IF NOT FIRST AND NOT LAST STRING -> PRINT CHAR_BORDER
            FIRST AND LAST COLUMN
2.  PRINT MAIN_CHAR
3.  MOVE MAIN_CHAR

####
#$ #
#  #
####

'D' -> GO TO THE RIGHT
'A' -> GO TO THE LEFT
'W' -> GO UP
'S' -> GO DOWN

D

####
# %#
#  #
####

'D' -> GO TO THE RIGHT
'A' -> GO TO THE LEFT
'W' -> GO UP
'S' -> GO DOWN

W

####
#  #
# %#
####

*/