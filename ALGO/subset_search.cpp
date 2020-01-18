#include <iostream>
#include <vector>
using namespace std;

void    search(vector<int> subset, int n, int k, int *counter)
{
    if (k == n + 1)
    {
        *counter += 1;
        printf("%d -> { ", *counter);
        for (auto i: subset)
            printf("%d ", i);
        printf("}\n");
    }
    else
    {
        subset.push_back(k);
        search(subset, n, k + 1, counter);
        subset.pop_back();
        search(subset, n, k + 1, counter);
    }
}

int main()
{    
    vector<int> subset;
    int n = 3;
    int counter = 0;
    search(subset, n, 1, &counter);

    return (0);
}

