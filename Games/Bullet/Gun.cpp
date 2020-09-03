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
// 		5.1 DRY - Don't Reapet Yourself
//																									//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdlib>
#include <ctime>
// #include <unistd.h>
using namespace std;

#define BLUE		"\033[36m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define PURPLE      "\033[35m"
#define YELLOW      "\033[33m"
#define BOLD        "\033[1m"
#define UNDER       "\033[4m"
#define RED_BACK    "\033[41m"
#define YELLOW_BACK "\033[43m"
#define BLUE_BACK   "\033[46m"
#define RESET       "\033[0m"

void	init_map();
bool	print_map(bool gun=true, int bright_col=-1);
void	add_line(float A);
int		add_trace(float A, float B);
float	get_B(int alpha);
float	get_A(int alpha, int speed);
void	create_obstical(int sh_x, int sh_y);
void	animate(int last_x);
void	print_lose();
void    print_win();

#define W 100 // 255
#define H 30  // 60
#define PI	3.14

char	map[H][W];
char	answer;
bool	is_hurt = false;
int		x_obs, y_obs;		// координаты препядствия (obstacle)
int		tries = 5;
int     entered = 0;
string  answer_2;

int main()
{
    srand(time(0));
    // system ("clear");
    system ("CLS");

    int	speed = 30;
    int	alpha = 45;
	int last_x;
    init_map();
    x_obs = rand() % W / 3 + 30;
    y_obs = rand() % H / 2;
    while(tries > 0 && entered != 3)
    {
        is_hurt = false;
		last_x = add_trace(get_A(alpha, speed), get_B(alpha));
        create_obstical(x_obs, y_obs);
        print_map();
        cout << YELLOW << "You have " << tries << " tries!" << endl;
        cout << "You score " << entered << " points" << endl;
        cout << "Speed: " << speed << " (met/sec)"<<  endl;
        cout << "Angle: " << alpha << " (degreese)" << RESET << endl;
        cout  << endl;
        cout << endl;
        cout <<  PURPLE << "\t\tHello!!!" << endl;
        cout << "\tIt is game \"GUN\" " << endl;
        cout << "If you want to change the angle, press on \'w\' and \'s\' " << endl;
        cout << "If you want to change the speed, press on \'d\' and \'a\' " << endl;
        cout << "If you want to take the shot, press on \'x\' " << endl;
        cout << "If you want to quit , press on \'q\' " << RESET << endl;
        cin >> answer;
        if(answer == 'w')
            alpha += 3;
        else if(answer == 's')
            alpha -= 3;
        else if(answer == 'd')
            speed += 1;
        else if(answer == 'a')
            speed -= 1;
        else if (answer == 'x')
        {
            tries--;
            animate(last_x);
            if(is_hurt == true)
            {
                x_obs = rand() % W / 3 + 30;
                y_obs = rand() % H / 2;
            }
        }
        else if(answer == 'q')
            break;
        init_map();
    }
    if (entered != 3)
        print_lose();    
    else
    {
        print_win();
    }   
    return (0);
}

bool print_map(bool gun, int bright_col)
{
    // system ("clear");
    system ("CLS");
    bool flag = false;
    for (int line = H - 1; line >= 0; line--)
    {
        for (int column = 0; column < W; column++ )
        {
			if (gun == false)
			{
	            if (map[line][column] == '#' && (column == 0 || column == W - 1 || line == 0 || line == H - 1))
                    cout << GREEN << map[line][column] << RESET;
                else if (map[line][column] == '#' && column == bright_col && is_hurt)
                {
                    flag = true;
                    cout << RED << '#' << RESET;
                } 
                else if (map[line][column] == 'o' && column == bright_col)
	                cout << RED << '0' << RESET;
				else if (map[line][column] == 'o')
	                cout << YELLOW << '*' << RESET;
				else
					cout << map[line][column];
			}
			else
			{
	            if(map[line][column] == '#')
	                cout << GREEN << map[line][column] << RESET;
	            else if (map[line][column] == ' ')
	                cout << map[line][column];
				else if (map[line][column] == 'o' && column < 5)
					cout << BLUE << '%' << RESET;
				else if (map[line][column] != 'o')
					cout << YELLOW << map[line][column] << RESET;
				else
					cout << ' ';
			}
        }
        cout << endl;
    }  
    return flag;
}

void add_line(float A)
{   
    for(int x = 1, y = 1; x < W - 1 && y < H - 1 ; x++,y = A * x)
        map[y][x] = 'o'; 
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

int add_trace(float A, float B)
{
	int x = 1;

    for(int y = 1; x < W - 1 && y > 0; x++, y = A * x * x + B * x)
    {
        if(y < H - 1 && y > 0)
            map[y][x] = 'o';
    }
	return x;
}

float get_B(int alpha)
{
    // alpha - это угол в градусах
    return tan(alpha * PI / 180) ;
}

float get_A(int alpha, int speed)
{
    return - 9.8 / (2 * speed * speed * cos(alpha * PI / 180) * cos(alpha * PI / 180));
}

// sh_x - shift_x(здвиг по оси x)
void create_obstical(int sh_x, int sh_y)
{
    for (int y = 1 + sh_y; y < 6 + sh_y; y++ )
    {
        for (int x = 0 + sh_x; x < 4 + sh_x; x++)
        {
            if(y == 1 + sh_y && (x == 0 + sh_x  || x == 3 + sh_x))
            {
                if(map[y][x] != ' ')
                    is_hurt = true;  
                map[y][x] = '#';
            }   
            else if((y == 2 + sh_y  || y == 4 + sh_y) && (x == 1 + sh_x || x == 2 + sh_x)) 
            {        
                if(map[y][x] != ' ')
                    is_hurt = true;  
                map[y][x] = '#';
            }
            else if(y == 3 + sh_y)
            {   
                if(map[y][x] != ' ')
                    is_hurt = true;  
                map[y][x] = '#';
            }            
            else if(y == 5 + sh_y && (x == 1 + sh_x || x == 2 + sh_x))
            {
                if(map[y][x] != ' ')
                    is_hurt = true;
				if (x == 1 + sh_x)  
	                map[y][x] = '/';
				else
	                map[y][x] = '\\';

            }      
            else if(y == 5 + sh_y && (x == 0 + sh_x || x == 3 + sh_x))
            {
                if(map[y][x] != ' ')
                    is_hurt = true;  
                map[y][x] = '_';
            }      
        }
    }
}

void animate(int last_x)
{
	bool flag = true;
	cout << last_x << endl;
	for (int x = 1; is_hurt && x < x_obs + 3 || x < last_x && !is_hurt ; x++)
	{
		print_map(false, x);
        // usleep( 100 * 1000);
	}
	if (is_hurt)
		entered++;
}

void print_lose()
{
	system("clear");
    cout << RED;
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
    cout << RESET;
}

void print_win()
{
    cout << RED << "$$__$$___$$$$___$$__$$" << RESET << endl;
    cout << RED << "_$$$$___$$__$$__$$__$$" << RESET << endl;
    cout << RED << "__$$____$$__$$__$$__$$" << RESET << endl;
    cout << RED << "__$$____$$__$$__$$__$$" << RESET << endl;
    cout << RED << "__$$_____$$$$____$$$$" << RESET << endl;   
    cout << endl;
    cout << RED << "$$___$$_$$$$$$__$$__$$" << RESET << endl;
    cout << RED << "$$___$$___$$____$$$_$$" << RESET << endl;
    cout << RED << "$$_$_$$___$$____$$_$$$" << RESET << endl;
    cout << RED << "$$$$$$$___$$____$$__$$" << RESET << endl;
    cout << RED << "_$$_$$__$$$$$$__$$__$$" << RESET << endl;
}


