#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <list>
using namespace std;

#define H 5
#define W 5
#define X_S 1
#define Y_S 4
#define X_F 3
#define Y_F 5

struct inf_map
{
	int x, y;
	char area[H][W];
};

void print_char_map(inf_map map);
void input(bool &is_continue, inf_map &map);
void lose();

int main()
{
	ifstream	file("map.txt");
	inf_map		map;
	string		str = "";
	int			row = 0;
	bool		is_continue = true;

	while (getline(file, str))
	{
		for (int i = 0; i < str.size(); ++i)
			map.area[row][i] = str[i];
		row++;
	}
	map.x = X_S;
	map.y = Y_S;
	map.area[map.y][map.x] = '*';
	do
	{
		print_char_map(map);
		input(is_continue, map);
	} while (is_continue);
	lose();
	file.close();
	return (0);
}

void input(bool &is_continue, inf_map &map)
{
	char inp;
	int x = map.x, y = map.y;
	
	cin >> inp;
	if (inp == 'w')
		y--;
	else if (inp == 's')
		y++;
	else if (inp == 'a')
		x--;
	else if (inp == 'd')
		x++;
	
	if (x < 0 || x >= W || y < 0 || y >= H)
		is_continue = false;
	else if (map.area[y][x] != ' ')
		is_continue = false;
	else
	{
		map.area[map.y][map.x] = '.';
		map.x = x;
		map.y = y;
		map.area[map.y][map.x] = '*';
	}
}

void print_char_map(inf_map map)
{
	system("CLS");
	cout << "Coords: " << map.x << ' ' << map.y << endl;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			if (map.area[i][j] == '#')
				cout << "\033[33m";
			else if (map.area[i][j] == '*')
				cout << "\033[32m";
			cout << map.area[i][j] << "\033[0m";
		}
		cout << endl;
	}
}

void lose()
{
	system("CLS");
	cout << "\033[31m";
                                                                                                          
cout << "                                                               lllllll                                                       " << endl;
cout << "                                                               l:::::l                                                       " << endl;
cout << "                                                               l:::::l                                                       " << endl;
cout << "                                                               l:::::l                                                       " << endl;
cout << "yyyyyyy           yyyyyyy ooooooooooo   uuuuuu    uuuuuu        l::::l    ooooooooooo       ssssssssss       eeeeeeeeeeee    " << endl;
cout << " y:::::y         y:::::yoo:::::::::::oo u::::u    u::::u        l::::l  oo:::::::::::oo   ss::::::::::s    ee::::::::::::ee  " << endl;
cout << "  y:::::y       y:::::yo:::::::::::::::ou::::u    u::::u        l::::l o:::::::::::::::oss:::::::::::::s  e::::::eeeee:::::ee" << endl;
cout << "   y:::::y     y:::::y o:::::ooooo:::::ou::::u    u::::u        l::::l o:::::ooooo:::::os::::::ssss:::::se::::::e     e:::::e" << endl;
cout << "    y:::::y   y:::::y  o::::o     o::::ou::::u    u::::u        l::::l o::::o     o::::o s:::::s  ssssss e:::::::eeeee::::::e" << endl;
cout << "     y:::::y y:::::y   o::::o     o::::ou::::u    u::::u        l::::l o::::o     o::::o   s::::::s      e:::::::::::::::::e " << endl;
cout << "      y:::::y:::::y    o::::o     o::::ou::::u    u::::u        l::::l o::::o     o::::o      s::::::s   e::::::eeeeeeeeeee  " << endl;
cout << "       y:::::::::y     o::::o     o::::ou:::::uuuu:::::u        l::::l o::::o     o::::ossssss   s:::::s e:::::::e           " << endl;
cout << "        y:::::::y      o:::::ooooo:::::ou:::::::::::::::uu     l::::::lo:::::ooooo:::::os:::::ssss::::::se::::::::e          " << endl;
cout << "         y:::::y       o:::::::::::::::o u:::::::::::::::u     l::::::lo:::::::::::::::os::::::::::::::s  e::::::::eeeeeeee  " << endl;
cout << "        y:::::y         oo:::::::::::oo   uu::::::::uu:::u     l::::::l oo:::::::::::oo  s:::::::::::ss    ee:::::::::::::e  " << endl;
cout << "       y:::::y            ooooooooooo       uuuuuuuu  uuuu     llllllll   ooooooooooo     sssssssssss        eeeeeeeeeeeeee  " << endl;
cout << "      y:::::y                                                                                                                " << endl;
cout << "     y:::::y                                                                                                                 " << endl;
cout << "    y:::::y                                                                                                                  " << endl;
cout << "   y:::::y                                                                                                                   " << endl;
cout << "  yyyyyyy                                                                                                                    " << endl;

	cout << "\033[0m";

}
