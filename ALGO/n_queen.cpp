#include <iostream>
#include <vector>
#define N 10
using namespace std;

bool col[N];
bool diag1[2 * N - 1];
bool diag2[2 * N - 1];
int count = 0;

void queen(int y)
{
    if (y == N)
    {
        count++;
        return ;
    }
    else
    {
        for (int x = 0; x < N; x++)
        {
            if (col[x] || diag1[x + y] || diag2[x - y + N - 1])
                continue;
            col[x] = 1;
            diag1[x + y] = 1;
            diag2[x - y + N - 1] = 1;
            queen(y + 1);
            col[x] = 0;
            diag1[x + y] = 0;
            diag2[x - y + N - 1] = 0;
        }
    }
}

int main()
{
    queen(0);
    cout << count;
    return (0);
}