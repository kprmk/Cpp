#include <iostream>

using namespace std;

void print_map(int ht, int wh, char border, int x_c, int y_c, char castle)
{
    for(int y = 0; y < ht; y++)
    {
        for (int x = 0; x < wh; x++)
        {
            if (y == 0 || y == ht - 1)
                cout << border;
            else if (x == 0 || x == wh - 1)
                cout << border;
            else if (x == x_c && y == y_c)
                cout << castle;
			else
				cout << ' ';
        }
        cout << endl;
    }
}

int main()
{
    system("CLS");
    int width, height, x_c, y_c;
    char ch_of_castle, ch_of_border;
    cout << "Please, enter height and width";
    cin >> width;
    cin >> height;
    cout << "Enter a char for representation of border" << endl;
    cin >> ch_of_border;
    cout << "Enter the coords of the castle" << endl;
    cin >> x_c;
    cin >> y_c;
    cout << "Enter a char for representation of the castle" << endl;
    cin >> ch_of_castle;
    cout << endl;

	print_map(height, width, ch_of_border, x_c, y_c, ch_of_castle);

    return 0;
}


