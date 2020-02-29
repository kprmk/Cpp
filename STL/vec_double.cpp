#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> double_vec;
    srand(time(NULL));
    int size = 3;

    for(int i = 0; i < size; i++)
    {
        double_vec.push_back(vector<int>());
        for(int j = 0; j < size; j++)
            double_vec[i].push_back(rand() % 9 + 1);
    }
    for(vector<vector<int> >::iterator it = double_vec.begin(); it != double_vec.end(); ++it)
    {
        for(vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
            cout << *it2 << " ";
        cout << endl;
    }
    return (0);
}

