//////////////////////////////////////////////////////////////////////////////////////////////////////
//																									//
// 				План для создания траектории (линии вдоль которой летит ядро/снаряд)				//
//																									//
// 1. Понять, как нарисовать бросок			(+)														//
//																									//
// 2. Понять, как отобразить бросок			(+)														//
//		2.1 Найти чиселки % и @ для формулы -> y = % * x - @ * x ^ 2, % и @ - это какие-то числа, 	//
//						зависящие от угла броска и скорости бросания снаряда						//
//			(Физики дали нам формулы по которым мы сможем определить эти числа % и @)				//
//		2.2 Нарисовать y = % * x - @ * x ^ 2														//
//			(Подставляя значения x (по горизнтали), получаем значения y (по вертикали) 				//
//				-> рисуем точку (символ 'o'))														//
//																									//
// 3. Понять, как вывести это на экран		(+)														//
//		3.1 Представим нашу систему координат в качестве двумерного массивами типа данных char		//
//			В точке на карте, где побывал снаряд, в ходе полёта, мы заносим 'o', а во всех			//
//				остальных местах заносим ' '														//
//		3.2 Но карта получается перевёрнутый -> мы должны печатать с последней строчки в массиве	//
//			не for (int i = 0; i < height; i++),													//
//			а for (int i = height - 1; i >= 0; i--)													//
// 4. Как разбить программу: 1) печать карты 2) См. 2.1 3) Для значений x 							//
//		(от нуля до ширины карты, которую мы выберем) найти значения y и занести по этом 			//
// 			значениям символы в двумерный массив 	(+)												//
//																									//
// 5. По существующему плану написать проагрмму  (-)												//
//																									//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>	//C++ Math
#include <cstdlib>
#include <ctime>

using namespace std;

#define BLUE        "\033[36m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define PURPLE      "\033[35m"
#define YELLOW      "\033[33m"
#define BOLD        "\033[1m"
#define UNDER       "\033[4m"
#define RED_BACK    "\033[41m"
#define YELLOW_BACK "\033[43m"
#define BLUE_BACK   "\033[46m"
#define RESET       "\033[0m"

void	init_map();
void	print_map(int entire = 1, int flag = -1);
void	add_line(float A);
void	add_trace(float A, float B);
float	get_B(int alpha);
float	get_A(int alpha, int speed);
void	animate(float A, float B);
void	create_obstacle(int, int);

#define W 100
#define H 30

#define PI 3.14

char	map[H][W];
bool	is_hurt = false;
int		x_obst; // координата x преядствия
int		y_obst; // координата y преядствия

int main()
{
	srand(time(0));
	system ("CLS");
	int		speed = 40; // метров в секунду
	int		alpha = 45; // градусов5
    char	ans;

    init_map();
	x_obst = rand() % W / 3 + 30;
	x_obst = rand() % H / 2;
	while (true)
	{
		is_hurt = false;
		if (is_hurt == true)
		{
			x_obst = rand() % W / 3 + 30;
			y_obst = rand() % H / 2;
		}
	    add_trace(get_A(alpha, speed), get_B(alpha));
		print_map(0);
		cin >> ans;
		if (ans == 'w')
			alpha += 5;
		else if (ans == 's')
			alpha -= 5;
		else if (ans == 'd')
			speed += 1;
		else if (ans == 'a')
			speed -= 1;
		else if (ans == 'p')
		{
			create_obstacle(x_obst, y_obst);
			animate(get_A(alpha, speed), get_B(alpha));
		}
		else if (ans == 'q')
			break;
	}
    
    return (0);
}

void print_map(int entire, int flag)
{
	system ("CLS");
	if (entire == 1)
	{
	    for (int line = H - 1; line >= 0; line-- )
	    {
	        for (int column = 0; column < W; column++ )
	        {
				if (column == flag && line != 0 && line != H - 1)
					cout << RED << map[line][column] << RESET;
				else
					cout << map[line][column];
	            // if(map[line][column] == '#')
	                // cout << GREEN;
	            // else 
	                // cout << RED;
	        }
	        cout << endl;
	    }  
	}
	else
	{
	    for (int line = H - 1; line >= 0; line-- )
	    {
	        for (int column = 0; column < W; column++ )
	        {	
				if (map[line][column] != 'o')
					cout << map[line][column];
				else if (column < 8 && map[line][column] == 'o')
					cout << map[line][column];
				else
					cout << ' ';
	        }
	        cout << endl;
	    }  

	}
}

void add_line(float A)
{   
    for(int x = 1, y = 1; x < W - 1 && y < H - 1 ; x++,y = A * x)
        map[y][x] = 'o'; 
}

void add_trace(float A, float B)
{
	init_map();
    for(int x = 1, y = 0; x < W - 1 && y < H - 1; x++, y = A * x * x + B * x)
	{
		// cout << x << ' '<< y << endl;
		if  (y > 0 && x > 0)
			map[y][x] = 'o'; 
	}
}

void init_map()
{
    //инициализуруем(задаём первоначальные значения)
    for (int line = 0; line < H; line++ )
    {
        for (int column = 0; column < W; column++ )
        {
            if ( line == 0 || line == H - 1 ) 
                map[line][column] = '#';
            else if ( column == 0 || column == W -1 )
                map[line][column] = '#';
            else
                map[line][column] = ' ';
        }
    }  
}

float get_B(int alpha)
{
	// alpha - это угол в градусах
	// alpha * PI / 180 - угол в радианах
	return tan(alpha * PI / 180);
}

float get_A(int alpha, int speed)
{
	return - 9.8 / (2 * speed * speed * cos(alpha * PI / 180) * cos(alpha * PI / 180));
}

void	animate(float A, float B)
{
	for(int x = 1; x < W - 1; ++x)
	{
		print_map(1, x);
	}
}

// sh_x - shift x (сдвиг по оси x)
void	create_obstacle(int sh_x, int sh_y)
{
	for (int y = sh_y + 1; y < sh_y + 6; y++)
	{
		for (int x = 0 + sh_x; x < 4 + sh_x; x++)
		{
			if (y == sh_y + 1 && (x == 0 + sh_x || x == 3 + sh_x))
			{
				if (map[y][x] != ' ')
					is_hurt = true;
				map[y][x] = '*';
			}
			else if ((y == sh_y + 2 || y == sh_y + 4) && (x == 1 + sh_x || x == 2 + sh_x))
			{
				if (map[y][x] != ' ')
					is_hurt = true;
				map[y][x] = '*';
			}
			else if (y == sh_y + 3)
			{
				if (map[y][x] != ' ')
					is_hurt = true;
				map[y][x] = '*';
			}
			else if (y == sh_y + 5 && (x == 1 + sh_x || x == 2 + sh_x))
			{
				if (map[y][x] != ' ')
					is_hurt = true;
				map[y][x] = '%';
			}
		}
	}
}
















