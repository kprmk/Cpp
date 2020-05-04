#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

#define W 20
#define H 10

int len, x_f, y_f;

vector<int> x_v;
vector<int> y_v;

bool is_over = true;

void parse_input_data();
void print_hint_for_user();
void print_map();

int main()
{
	/*************************/
	system("CLS");
	// system("color r");
	/*************************/


	x_v.push_back(rand() % (W - 2) + 1);
	y_v.push_back(rand() % (H - 2) + 1);
	len = 1;

	x_f = rand() % (W - 2) + 1;
	y_f = rand() % (H - 2) + 1;
    
	while (is_over == true)
    {
        print_map();
        print_hint_for_user();
        parse_input_data();
        system("CLS");
		system("color 5")
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
				bool is_empty = false;
				for (int j = x_v.size() - 1, l = len; l > 0; j--, l--)
				{
					if (x_v[j] == x && y_v[j] == y)
					{
						cout << 'o';
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
	int x_c = x_v[x_v.size() - 1];
	int y_c = y_v[y_v.size() - 1];

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

	x_v.push_back(x_c);
	y_v.push_back(y_c);
}

