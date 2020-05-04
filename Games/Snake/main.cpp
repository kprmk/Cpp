#include <iostream>
#include <cstdlib>

using namespace std;

#define W 20
#define H 10

int len = 1, x_f, y_f;
int x_s[100];
int y_s[100];
bool is_over = true;

void parse_input_data();
void print_hint_for_user();
void print_map();

int main()
{
	x_s[0] = rand() % (W - 2) + 1;
	y_s[0] = rand() % (H - 2) + 1;
	x_f = rand() % (W - 2) + 1;
	y_f = rand() % (H - 2) + 1;
    
	system("CLS");

	while (is_over)
    {
        print_map();
        print_hint_for_user();
        parse_input_data();
        system("CLS");
    }
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
				check = false;
				for (int i = 0; i < len; i++)
				{
					if (x_s[i] == x && y_s[i] == y)
					{
						check = true;
						cout << 'o'; 
					}
				}
				if (check == false)
	                cout << " ";
			}
		}
        cout << endl;
    }
}

void print_hint_for_user()
{
    cout << endl << endl;
    cout << "Use \'w\', \'a\', \'s\', \'d\' for moving the castle" << endl;
    cout << "\'q\' for finish!" << endl;
}

void parse_input_data()
{
    char input;
	int x_c = x_s[0];
	int y_c = y_s[0];

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
		len++;
		x_f = rand() % (W - 2) + 1;
		y_f = rand() % (H - 2) + 1;
	}

	int prev_x = x_s[0];
	int prev_y = y_s[0];
	for (int i = 1, temp_x = 0, temp_y = 0; i < len; i++)
	{
		temp_x = x_s[i];
		temp_y = y_s[i];

		x_s[i] = prev_x;
		y_s[i] = prev_y;

		prev_x = temp_x;
		prev_y = temp_y;
	}

	x_s[0] = x_c;
	y_s[0] = y_c;
}