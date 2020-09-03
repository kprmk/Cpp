#include <iostream>	// input output stream
#include <fstream>	// file stream
#include <cstdlib>
#include <string>

using namespace std;

#define H 4
#define W 8

void print_map(string map[H]);

int main()
{
	ifstream	file("test.txt");  // input file stream
	string		str = "";
	string		map[H];
	int			index = 0;
	int			y = 3, x = 3;
	bool		returned_value;

	while (getline(file, str))
	{
		map[index] = str;
		index++;
	}

	print_map(map);
	map[y][x] = '%';
	print_map(map);
	// map[y][x] = ' ';
	// x++;
	// map[y][x] = '%';
	// print_map(map);

	return 0;
}

void print_map(string map[H])
{
	for (int i = 0; i < H; i++)
	// цвет сделали
		cout << map[i] << endl;
	cout << endl;
}
