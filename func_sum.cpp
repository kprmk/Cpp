#include <iostream>
using namespace std;

// DECLARATION OF FUNCTION
int sum(int n1, int n2);

int main()
{
    int result_of_sum;
    result_of_sum = sum(1, 1000);
    cout << result_of_sum << endl;
    return (0);
}

// DEFINITION OF FUNCTION
int sum(int n1, int n2)
{
    int res;
    res = n1 + n2;
    return res;
}