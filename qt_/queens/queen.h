#ifndef QUEEN_H
#define QUEEN_H

#include <vector>
#include <map>
#include <QDebug>
#include <iostream>
#include <cstdlib>

using namespace std;

class queen
{
private:
    int size, counter;
    map<int, vector<int>> ans;

    const int size_of_pic;

    vector<int> x;
    vector<int> d1;
    vector<int> d2;
    vector<int> x_c;
public:
    queen();
    queen(int n);
    int getter_counter();
    map<int, vector<int>> getter_ans();
    void solve(int y = 0);
};

#endif // QUEEN_H
