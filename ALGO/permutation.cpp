#include <iostream>
#include <vector>
#define N 3
using namespace std;

void    search_perm(vector<int> vec)
{
    static bool chosen[N + 1];
    
    if (vec.size() == N)
    {
        printf("{ ");
        for (auto i: vec)
            printf("%d ", i);
        printf("}\n");
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            if (chosen[i])
                continue;
            chosen[i] = true;
            vec.push_back(i);
            search_perm(vec);
            chosen[i] = false;
            vec.pop_back();
        }
    }
}

int main()
{
    vector<int> vec;
    search_perm(vec);
    return (0);
}