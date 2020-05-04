#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

#define W 20
#define H 10

int x_f, y_f;

list<int> x_l;
list<int> y_l;

bool is_over = true;

void parse_input_data();
void print_hint_for_user();
void print_map();

int main()
{
	// /*************************/
	system("CLS");
	// system("color 3");
	// /*************************/


	x_l.push_back(rand() % (W - 2) + 1);
	y_l.push_back(rand() % (H - 2) + 1);

	x_f = rand() % (W - 2) + 1;
	y_f = rand() % (H - 2) + 1;
    

	while (is_over == true)
    {
        print_map();
        print_hint_for_user();
        parse_input_data();
        system("CLS");
    }
    system("CLS");
    return 0;
}

void print_map()
{
	bool check = false;

    for(int y = 0; y < H; y++)
    {
        for (int x = 0; x < W; x++)
        {
            if (y == 0 || y == H - 1)
                cout << '#';
            else if (x == 0 || x == W - 1)
                cout << '#';
            else if (x_f == x && y_f == y)
                cout << '$';
            else
			{
				bool is_empty = false;
				for (auto i_x = x_l.begin(), i_y = y_l.begin(); i_x != x_l.end() && i_y != y_l.end(); i_x++, i_y++)
				{
					if (*i_x == x && *i_y == y)
					{
						// #define BOLDMAGENTA       /* Bold Magenta */
						cout << "\033[1m\033[35m" << 'o' << "\033[0m";
						is_empty = true;
					}
				}
				if (is_empty == false)
					cout << ' ';
			}
		}
        cout << endl;
    }
}

void print_hint_for_user()
{
	cout << endl;
    cout << endl << endl;
    cout << "Use \'w\', \'a\', \'s\', \'d\' for moving the castle" << endl;
    cout << "\'q\' for finish!" << endl;
}

void parse_input_data()
{
    char input;

	int x_c = x_l.front();
	int y_c = y_l.front();

    cin >> input;
    if (input == 'q')
        is_over = false;
    else
    {
        switch (input)
        {
            case 'w':
                y_c -= 1;
                break;
            case 's':
                y_c += 1;
                break;
            case 'a':
                x_c -= 1;
                break;
            case 'd':
                x_c += 1;
                break;
        }
    }

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
		x_f = rand() % (W - 2) + 1;
		y_f = rand() % (H - 2) + 1;
	}
	else
	{
		x_l.pop_back();
		y_l.pop_back();
	}
	
	x_l.push_front(x_c);
	y_l.push_front(y_c);	
}


















