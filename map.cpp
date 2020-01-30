#include <iostream>
using namespace std;

void create_map(int height, int width, char border, int x, int y)
{
    char castle = '$';
    if ((x > 0 && x < width) && (y > 0 && y < height))
    {   
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (i == 0 || i == height - 1)
                {
                    cout << border;
                }
                else
                {
                    if (j == 0 || j == width - 1)
                    {
                        cout << border;
                    }
                    else if (i == x && j == y)
                    {
                        cout << castle;
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
    else
    {
        cout << "There has been an error!" << endl;
    }
}

int main()
{
    int width = 0;
    int height = 0;
    int x = 0, y = 0;
    char border;
    cout << "Please, enter the width of the map" << endl;
    cin >> width;
    cout << "Please, enter the height of the map" << endl;
    cin >> height;
    cout << "Please, enter the character for the border" << endl;
    cin >> border;
    cout << "Please, enter the x of the castle" << endl;
    cin >> x;
    cout << "Please, enter the y of the castle" << endl;
    cin >> y;
    create_map(height, width, border, x, y);

    return (0);
}
