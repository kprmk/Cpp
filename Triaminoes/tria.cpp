#include "tria.h"

tria::tria(int width, int height): w(width), h(height)
{
	this->map = new char *[h];
	for (int i = 0; i < h; ++i)
	{
		this->map[i] = new char [w];
		for (int j = 0; j < w; ++j)
			this->map[i][j] = '0';
	}
	cout << "1) There's been " << this->solver() << " options on " << w << " x " << h << " map." << endl;
	cout << "2) There's been " << this->solver_2() << " options on " << w << " x " << h << " map." << endl;
	// 2) There's been 13727 options on 5 x 8 map.
}

tria::~tria()
{
	for (int i = 0; i < h; ++i)
		delete [] this->map[i];
	delete [] this->map;
	this->map = NULL;
}

void tria::print()
{
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
			cout << map[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

int tria::solver(int y)
{
	if (y == h)
		return 1;
	
	int x = 0;
	while (x < w && map[y][x] != '0')
		++x;
	
	if (x == w)
		return this->solver(y + 1);

	lli ans = 0;
	// ##
	// #
	if (y < h - 1 && x < w - 1)
	{
		if (map[y][x] == '0' && map[y][x + 1] == '0' && map[y + 1][x] == '0')
		{
			map[y][x] = map[y][x + 1] = map[y + 1][x] = 1 + '0';
			ans += solver(y);
			map[y][x] = map[y][x + 1] = map[y + 1][x] = '0';
		}
	}
	// ##
	//  #
	if (y < h - 1 && x < w - 1)
	{
		if (map[y][x] == '0' && map[y][x + 1] == '0'  && map[y + 1][x + 1] == '0')
		{
			map[y][x] = map[y][x + 1] = map[y + 1][x + 1] = 2 + '0';
			ans += solver(y);
			map[y][x] = map[y][x + 1] = map[y + 1][x + 1] = '0';
		}
	}
	// #
	// ##
	if (y < h - 1 && x < w - 1)
	{
		if (map[y][x] == '0' && map[y + 1][x + 1] == '0'  && map[y + 1][x] == '0')
		{
			map[y][x] = map[y + 1][x + 1] = map[y + 1][x] = 3 + '0';
			ans += solver(y);
			map[y][x] = map[y + 1][x + 1] = map[y + 1][x] = '0';
		}
	}
	//  #
	// ##
	if (y < h - 1 && x <= w - 1 && x > 0)
	{
		if (map[y][x] == '0' && map[y + 1][x] == '0'  && map[y + 1][x - 1] == '0')
		{
			map[y][x] = map[y + 1][x] = map[y + 1][x - 1] = 4 + '0';
			ans += solver(y);
			map[y][x] = map[y + 1][x] = map[y + 1][x - 1] = '0';
		}
	}
	// ###
	if (y <= h - 1 && x < w - 2)
	{
		if (map[y][x] == '0' && map[y][x + 1] == '0'  && map[y][x + 2] == '0')
		{
			map[y][x] = map[y][x + 1] = map[y][x + 2] = 5 + '0';
			ans += solver(y);
			map[y][x] = map[y][x + 1] = map[y][x + 2] = '0';
		}		
	}
	// #
	// #
	// #
	if (y < h - 2 && x <= w - 1)
	{
		if (map[y][x] == '0' && map[y + 1][x] == '0'  && map[y + 2][x] == '0')
		{
			map[y][x] = map[y + 1][x] = map[y + 2][x] = 6 + '0';
			ans += solver(y);
			map[y][x] = map[y + 1][x] = map[y + 2][x] = '0';
		}
	}
	return (ans);
}

int tria::solver_2(int y)
{
	if (y == h)
		return 1;
	
	int x = 0;
	while (x < w && map[y][x] != '0')
		++x;
	
	if (x == w)
		return this->solver(y + 1);

	lli ans = 0;
	// ##
	// #
	if (y < h - 1 && x < w - 1)
	{
		if (map[y][x] == '0' && map[y][x + 1] == '0' && map[y + 1][x] == '0')
		{
			map[y][x] = map[y][x + 1] = map[y + 1][x] = 1 + '0';
			ans += solver(y);
			map[y][x] = map[y][x + 1] = map[y + 1][x] = '0';
		}
	}
	// ##
	//  #
	if (y < h - 1 && x < w - 1)
	{
		if (map[y][x] == '0' && map[y][x + 1] == '0'  && map[y + 1][x + 1] == '0')
		{
			map[y][x] = map[y][x + 1] = map[y + 1][x + 1] = 2 + '0';
			ans += solver(y);
			map[y][x] = map[y][x + 1] = map[y + 1][x + 1] = '0';
		}
	}
	// #
	// ##
	if (y < h - 1 && x < w - 1)
	{
		if (map[y][x] == '0' && map[y + 1][x + 1] == '0'  && map[y + 1][x] == '0')
		{
			map[y][x] = map[y + 1][x + 1] = map[y + 1][x] = 3 + '0';
			ans += solver(y);
			map[y][x] = map[y + 1][x + 1] = map[y + 1][x] = '0';
		}
	}
	//  #
	// ##
	if (y < h - 1 && x <= w - 1 && x > 0)
	{
		if (map[y][x] == '0' && map[y + 1][x] == '0'  && map[y + 1][x - 1] == '0')
		{
			map[y][x] = map[y + 1][x] = map[y + 1][x - 1] = 4 + '0';
			ans += solver(y);
			map[y][x] = map[y + 1][x] = map[y + 1][x - 1] = '0';
		}
	}
	// ###
	if (y <= h - 1 && x < w - 2)
	{
		if (map[y][x] == '0' && map[y][x + 1] == '0'  && map[y][x + 2] == '0')
		{
			map[y][x] = map[y][x + 1] = map[y][x + 2] = 5 + '0';
			ans += solver(y);
			map[y][x] = map[y][x + 1] = map[y][x + 2] = '0';
		}		
	}
	// #
	// #
	// #
	if (y < h - 2 && x <= w - 1)
	{
		if (map[y][x] == '0' && map[y + 1][x] == '0'  && map[y + 2][x] == '0')
		{
			map[y][x] = map[y + 1][x] = map[y + 2][x] = 6 + '0';
			ans += solver(y);
			map[y][x] = map[y + 1][x] = map[y + 2][x] = '0';
		}
	}
	// ##
	//  ##
	if (y < h - 1 && x < w - 2)
	{
		if (map[y][x] == '0' && map[y][x + 1] == '0' &&
			map[y + 1][x + 1] == '0' && map[y + 1][x + 2] == '0')
		{
			map[y][x] = map[y][x + 1] = map[y + 1][x + 1] = map[y + 1][x + 2] = 7 + '0';
			ans += solver(y);
			map[y][x] = map[y][x + 1] = map[y + 1][x + 1] = map[y + 1][x + 2] = '0';
		}
	}
	//  ##
	// ##
	if (y < h - 1 && x < w - 1 && x > 0)
	{
		if (map[y][x] == '0' && map[y][x + 1] == '0' &&
			map[y + 1][x] == '0' && map[y + 1][x - 1] == '0')
		{
			map[y][x] = map[y][x + 1] = map[y + 1][x] = map[y + 1][x - 1] = 8 + '0';
			ans += solver(y);
			map[y][x] = map[y][x + 1] = map[y + 1][x] = map[y + 1][x - 1] = '0';
		}
	}
	//  #
	// ##
	// #
	if (y < h - 2 && x <= w - 1 && x > 0)
	{
		if (map[y][x] == '0' && map[y + 1][x] == '0' &&
			map[y + 1][x - 1] == '0' && map[y + 2][x - 1] == '0')
		{
			map[y][x] = map[y + 1][x] = map[y + 1][x - 1] = map[y + 2][x - 1] = 9 + '0';
			ans += solver(y);
			map[y][x] = map[y + 1][x] = map[y + 1][x - 1] = map[y + 2][x - 1] = '0';
		}
	}
	//  #
	//  ##
	//   #
	if (y < h - 2 && x < w - 1)
	{
		if (map[y][x] == '0' && map[y + 1][x] == '0' &&
			map[y + 1][x + 1] == '0' && map[y + 2][x + 1] == '0')
		{
			map[y][x] = map[y + 1][x] = map[y + 1][x + 1] = map[y + 2][x + 1] = '$';
			ans += solver(y);
			map[y][x] = map[y + 1][x] = map[y + 1][x + 1] = map[y + 2][x + 1] = '0';
		}
	}

	return (ans);
}

int tria::solver_for(int y)
{
	if (y == h)
		return 1;
	
	int x = 0;
	while (x < w && map[y][x] != '0')
		++x;
	
	if (x == w)
		return this->solver(y + 1);

	lli ans = 0;

	for (int i = 0; i < 6; ++i)
	{
		if (y < h - this->opts[i][3][1] && x < w - this->opts[i][3][0])
		{
			if (map[y + this->opts[i][0][1]][y + this->opts[i][0][0]] == '0' &&
			map[y + this->opts[i][1][1]][y + this->opts[i][1][0]] == '0' &&				map[y + this->opts[i][2][1]][y + this->opts[i][2][0]] == '0')
			{
				// map[y][x] = map[y][x + 1] = map[y + 1][x] = 1 + '0';
				map[y + this->opts[i][0][1]][y + this->opts[i][0][0]] =
				map[y + this->opts[i][1][1]][y + this->opts[i][1][0]] =
				map[y + this->opts[i][2][1]][y + this->opts[i][2][0]] = '0' + 1;
				ans += solver(y);
				// map[y][x] = map[y][x + 1] = map[y + 1][x] = '0';
				map[y + this->opts[i][0][1]][y + this->opts[i][0][0]] =
				map[y + this->opts[i][1][1]][y + this->opts[i][1][0]] =
				map[y + this->opts[i][2][1]][y + this->opts[i][2][0]] = '0';
			}
		}
	}

	// ##
	// #
	if (y < h - 1 && x < w - 1)
	{
		if (map[y][x] == '0' && map[y][x + 1] == '0' && map[y + 1][x] == '0')
		{
			map[y][x] = map[y][x + 1] = map[y + 1][x] = 1 + '0';
			ans += solver(y);
			map[y][x] = map[y][x + 1] = map[y + 1][x] = '0';
		}
	}
	// ##
	//  #
	if (y < h - 1 && x < w - 1)
	{
		if (map[y][x] == '0' && map[y][x + 1] == '0'  && map[y + 1][x + 1] == '0')
		{
			map[y][x] = map[y][x + 1] = map[y + 1][x + 1] = 2 + '0';
			ans += solver(y);
			map[y][x] = map[y][x + 1] = map[y + 1][x + 1] = '0';
		}
	}
	// #
	// ##
	if (y < h - 1 && x < w - 1)
	{
		if (map[y][x] == '0' && map[y + 1][x + 1] == '0'  && map[y + 1][x] == '0')
		{
			map[y][x] = map[y + 1][x + 1] = map[y + 1][x] = 3 + '0';
			ans += solver(y);
			map[y][x] = map[y + 1][x + 1] = map[y + 1][x] = '0';
		}
	}
	//  #
	// ##
	if (y < h - 1 && x <= w - 1 && x > 0)
	{
		if (map[y][x] == '0' && map[y + 1][x] == '0'  && map[y + 1][x - 1] == '0')
		{
			map[y][x] = map[y + 1][x] = map[y + 1][x - 1] = 4 + '0';
			ans += solver(y);
			map[y][x] = map[y + 1][x] = map[y + 1][x - 1] = '0';
		}
	}
	// ###
	if (y <= h - 1 && x < w - 2)
	{
		if (map[y][x] == '0' && map[y][x + 1] == '0'  && map[y][x + 2] == '0')
		{
			map[y][x] = map[y][x + 1] = map[y][x + 2] = 5 + '0';
			ans += solver(y);
			map[y][x] = map[y][x + 1] = map[y][x + 2] = '0';
		}		
	}
	// #
	// #
	// #
	if (y < h - 2 && x <= w - 1)
	{
		if (map[y][x] == '0' && map[y + 1][x] == '0'  && map[y + 2][x] == '0')
		{
			map[y][x] = map[y + 1][x] = map[y + 2][x] = 6 + '0';
			ans += solver(y);
			map[y][x] = map[y + 1][x] = map[y + 2][x] = '0';
		}
	}
	return (ans);
}
