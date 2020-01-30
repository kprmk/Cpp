#include <iostream>

using namespace std;

// h - height
// w - width

void print_map(int h, int w)
{
    char border = '#';
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if (y == 0 || y == h - 1)
            {
                cout << border;
            }
            else if (y != 0 && y != h - 1)
            {
                if (x == 0 || x == w - 1)
                {
                    cout << border;
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}

int main()
{
    int h, w;
    cout << "Enter the width: ";
    cin >> w;
    cout << "Enter the height: ";
    cin >> h;
    print_map(h, w); 

    return (0);
}