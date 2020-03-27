#include <iostream>
#include <vector>
using namespace std;

void    subset(int n, vector<int> *set, int k)
{
    if (k == n + 1)
    {
        for (vector<int>::iterator i = set->begin(); i != set->end(); ++i)
            cout << *i << " ";
        cout << endl;
        return ;
    }
    else
    {
        set->push_back(k);
        subset(n, set, k + 1);
        set->pop_back();
        subset(n, set, k + 1);
    }
}

int main()
{
    int amount;
    vector<int> set;
    cin >> amount;
    subset(amount, &set, 1);
    return (0);
}