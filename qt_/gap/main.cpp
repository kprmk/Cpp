#include <string>
#include "str.h"

using std::cout;
using std::endl;

int main()
{
    // The first one
    std::string cur_str("Hello.How are you?. qweewq");
    cout <<"The first one\n\n" << cur_str << endl;
    int max = 0;
    for (int cur_l = 0, i = 0 ; i < cur_str.size(); i++)
    {
        if(cur_str[i] == '.')
        {
            if(cur_str[i + 1] != ' ')
            {
            cur_str.insert(cur_str.begin() + i + 1, ' ');
            }
            max = max < cur_l? cur_l : max;
            cur_l = -2;
        }
        cur_l++;
    }
    cout << cur_str << endl;
    cout << "There are "<< max << " characters in the biggest sentence" << endl << endl;


    //The second one
    str string("Hello.How are you?. qweewq");
    cout <<"The second one\n" << endl;
    string.print();

    string.add_gaps();
    string.print();

    cout << "There are "<< string.max_sent() << " characters in the biggest sentence\n" << endl;

    return 0;
}

