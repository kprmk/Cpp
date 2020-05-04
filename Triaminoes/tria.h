#pragma once

#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long lli;

class tria
{
	private:
		const int w, h;
		char **map;
		const int opts[6][4][2] = {
								{{1, 1}, {0, 0}, {0, 1}, {1, 1}},
								{{-1, 1}, {0, 1}, {1, 1}, {1, 0}},
								{{1, 1}, {1, 1}, {1, 0}, {0, 0}},
								{{1, 1}, {1, 0}, {0, 0}, {0, 1}},
								{{0, 2}, {0, 0}, {0, 1}, {0, 2}},
								{{2, 0}, {0, 0}, {1, 0}, {2, 0}}
								};
		void print();
		int solver(int y = 0);
		int solver2(int y = 0);
	public:
		tria(int width=2, int height=9);
		~tria();
};
