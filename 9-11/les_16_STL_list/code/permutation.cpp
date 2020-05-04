#include <iostream>
#include <vector>
using namespace std;

void    search_perm(vector<int> *vec, vector<bool> *chosen, int n, int *c)
{
    if (vec->size() == n)
    {
        (*c)++;
        cout << *c << " ->\t{ ";
        for (auto i: *vec)
            cout << i << " ";
        cout << "}" << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (chosen->at(i) == true)
                continue;
            chosen->at(i) = true;
            vec->push_back(i);
            search_perm(vec, chosen, n, c);
            chosen->at(i) = false;
            vec->pop_back();
        }
    }
}

void permutation(int n)
{
    vector<int> vec;
    vector<bool> is_empty(n + 1, false);
    int counter = 0;
    search_perm(&vec, &is_empty, n, &counter);
}


int main()
{
    int amount;
    cin >> amount;
    permutation(amount);
    return (0);
}