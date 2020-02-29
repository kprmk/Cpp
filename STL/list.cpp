#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> list_int_nums;
    list_int_nums.push_back(1);
    list_int_nums.push_front(100);

    list<int>::iterator it = list_int_nums.begin();
    cout << (*it) << " ";

    list_int_nums.sort();

    list_int_nums[1] // !!!
    
    return (0);
}

