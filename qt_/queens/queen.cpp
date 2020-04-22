#include "queen.h"

queen::queen(int n): x(n, 0), d1(2 * n - 1, 0), d2(2 * n - 1, 0)
{
    this->size = n;
    this->counter = 0;
}

int queen::getter_counter()
{
    return this->counter;
}

map<int, vector<int>> queen::getter_ans()
{
    return this->ans;
}

void queen::solve(int y)
{
    if (y == this->size)
        this->ans[this->counter++] = this->x_c;
    else
    {
        for (int i = 0; i < this->size; i++)
        {
            if (x[i] == 1 || d1[y + i] == 1 || d2[y - i + size - 1] == 1)
                continue;
            x[i] = d1[y + i] = d2[y - i + size - 1] = 1;
            x_c.push_back(i);
            this->solve(y + 1);
            x[i] = d1[y + i] = d2[y - i + size - 1] = 0;
            x_c.pop_back();
        }
    }
}
