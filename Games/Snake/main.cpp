#include <iostream>
#include <cstdlib>
#include <list>

/***************************/
#include <conio.h>
/***************************/

using namespace std;

#define W 20
#define H 10

int x_f, y_f;
int score;

list<int> x_l;
list<int> y_l;

bool is_over = true;

void parse_input_data();
void print_hint_for_user();
void print_map(bool end);

int x_v = 1;
int y_v = 0;
#include <iostream>
#include <conio.h>
 
using namespace std;
 
int main()
{
    char a;
    while((a = getch())!=27)
    {
        cout << (int)a << endl;
    }
}

// int main()
// {
// 	system("CLS");

// 	score = 0;

// 	x_l.push_back(rand() % (W - 2) + 1);
// 	y_l.push_back(rand() % (H - 2) + 1);

// 	x_f = rand() % (W - 2) + 1;
// 	y_f = rand() % (H - 2) + 1;

// 	while (is_over == true)
//     {
//         print_map(false);
//         print_hint_for_user();
// 		_sleep(30);
//         parse_input_data();
//         system("CLS");
//     }
//     system("CLS");
// 	print_map(true);
//     return 0;
// }

void print_map(bool end)
{
	bool check = false;

    for(int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
			if (!end)
			{
	            if (y == 0 || y == H - 1)
				{
	                cout << "\033[7;31;43m" << '#' << "\033[0m";
				}
	            else if (x == 0 || x == W - 1)
				{
	                cout << "\033[7;31;43m" << '#' << "\033[0m";
				}
	            else if (x_f == x && y_f == y)
				{
	                cout << "\033[1;32;43m" << '&' << "\033[0m";
				}
	            else
				{
					bool is_empty = false;
					for (auto i_x = x_l.begin(), i_y = y_l.begin(); i_x != x_l.end() && i_y != y_l.end(); i_x++, i_y++)
					{
						if (*i_x == x && *i_y == y)
						{
							cout << "\033[1;43;35m" << 'o' << "\033[0m";
							is_empty = true;
						}
					}
					if (is_empty == false)
						cout << "\033[43m" << ' ' << "\033[0m";
				}
			}
			else
			{
				if (y == 0 || y == H - 1)
				{
	                cout << "\033[7;31;43m" << '#' << "\033[0m";
				}
	            else if (x == 0 || x == W - 1)
				{
	                cout << "\033[7;31;43m" << '#' << "\033[0m";
				}
				else
				{
	                cout << "\033[1;36;43mTHE END! \033[0m";
					x += 8;
				}
			}
		}
        cout << endl;
    }
}

void print_hint_for_user()
{
	cout << endl;
    cout << endl;
	cout << "\033[1;4;31mScore: " << score << "\033[0m" << endl << endl;
    cout << "\033[32mUse \'w\', \'a\', \'s\', \'d\' for moving the castle" << endl;
    cout << "\'q\' for finish!\033[0m" << endl;
}

void parse_input_data()
{
    char input;

	int x_c = x_l.front();
	int y_c = y_l.front();


	if (_kbhit())
		input = _getch();
    if (input == 'q')
        is_over = false;
    else
    {
        switch ((int)input)
        {
            case 72:
				y_v = -1;
				x_v = 0;
                break;
            case 80:
				x_v = 0;
				y_v = 1;
                break;
            case 75:
				y_v = 0;
				x_v = -1;
                break;
            case 77:
				y_v = 0;
                x_v = 1;
                break;
        }
    }

	x_c += x_v;
	y_c += y_v;

	if (x_c == W - 1)
		x_c = 1;
	else if (x_c == 0)
		x_c = W - 2;
	else if (y_c == 0)
		y_c = H - 2;
	else if (y_c == H - 1)
		y_c = 1;

	if (x_c == x_f && y_c == y_f)
	{
		score++;
		bool ch;
		do
		{
			ch = false;
			x_f = rand() % (W - 2) + 1;
			y_f = rand() % (H - 2) + 1;
			for (auto it1 = x_l.begin(), it2 = y_l.begin(); it1 != x_l.end(); ++it1, ++it2)
			{
				if (x_f == *it1 && y_f == *it2)
					ch = true;
			}
		} while (ch);
	}
	else
	{
		x_l.pop_back();
		y_l.pop_back();
	}
	bool ch = false;
	for (auto it1 = x_l.begin(), it2 = y_l.begin(); it1 != x_l.end(); ++it1, ++it2)
	{
		if (x_c == *it1 && y_c == *it2)
			ch = true;
	}
	if (!ch)
	{
		x_l.push_front(x_c);
		y_l.push_front(y_c);	
	}
	else
	{
		is_over = false;
	}
}


















