#include <iostream>
#include <vector>

using namespace std;


void    search(vector<int> subset, int n, int k, int *counter)
{
    if (k == n + 1)
    {
        (*counter)++;
        cout << *counter << " ->\t{ ";
        for (auto i: subset)
            cout << i << " ";
        cout << "}" << endl;
    }
    else
    {
        subset.push_back(k);
        search(subset, n, k + 1, counter);
        subset.pop_back();
        search(subset, n, k + 1, counter);
    }
}

void subset(int n)
{
    vector<int> subset;
    int counter = 0;
    search(subset, n, 1, &counter);
}

int main()
{
    int amount;
    cin >> amount;
    subset(amount);
    return (0);
}

