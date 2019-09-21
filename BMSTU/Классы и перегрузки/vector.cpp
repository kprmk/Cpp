#define _CRT_SECURE_NO_WARNINGS
#include "vector.h"
#include<ctime>
#include<cstdlib>

vector::vector(int N, int a)
{
	space = N;
	mas = new float[N];
	for (int i = 0; i < space; i++)
	{
		mas[i] = 0;
	}
}

vector::vector(int N, float * a)
{
	space = N;
	mas = new float[N];
	for (int i = 0; i < space; i++)
	{
		mas[i] = a[i];
	}
}

vector::vector(const vector &a)
{
	space = a.space;
	mas = new float[space];
	for (int i = 0; i < space; i++)
	{
		mas[i] = a.mas[i];
	}
}

vector :: vector(int N, char a)
{
	srand(time(NULL));
	space = N;
	mas = new float[N];
	for (int i = 0; i < space; i++)
	{
		mas[i] = rand() % 10;
	}
}

vector::vector(int N)
{
	space = N;
	mas = new float[N];
	this->zapolny(N);
}

vector::~vector()
{
	delete[] mas;
}

std::ostream& operator<<(std::ostream &os, const vector & v)
{
	for (int i = 0; i < v.space; i++)
	{
		os << v.mas[i] << ' ';
	}
	return os;
}

void vector::zapolny(int N)
{
	/*std::cout << "ENTER SPACE" << std::endl;
	std::cin >> space;
	mas = new float[space];*/
	std::cout << "ENTER ELEMENTS ACROSS <EEEEENTERRRRRRRRR>";
	for (int i = 0; i < N; i++)
	{
		std::cin >> mas[i];
	}
	std::cout << *this;
	//return * this;
}

vector vector::operator+(const vector & a)
{
	if (space == a.space)
	{
		vector q(space, 0);

		for (int i = 0; i < space; i++)
		{
			q.mas[i] = mas[i] + a.mas[i];
		}
	//	std::cout << q << std::endl;
		return q;
	}
	else
	{
		if (space <= a.space)
		{
			vector q(a.space, 0);

			int i = 0;
			for (; i < space; i++)
			{
				q.mas[i] = mas[i] + a.mas[i];
			}
			for (;i < a.space;i++)
			{
				q.mas[i] = a.mas[i];
			}
			return q;
		}
		else
		{
			vector q(space, 0);

			int i = 0;
			for (; i < a.space; i++)
			{
				q.mas[i] = mas[i] + a.mas[i];
			}
			for (; i < space; i++)
			{
				q.mas[i] = mas[i];
			}
			return q;
		}
	}
}

vector vector:: operator-(const vector & a)
{
	{
		if (space == a.space)
		{
			vector q(space, 0);

			for (int i = 0; i < space; i++)
			{
				q.mas[i] = mas[i] - a.mas[i];
			}
			return q;
		}
		else
		{
			if (space <= a.space)
			{
				vector q(a.space, 0);

				int i = 0;
				for (; i < space; i++)
				{
					q.mas[i] = mas[i] - a.mas[i];
				}
				for (; i < a.space; i++)
				{
					q.mas[i] = -a.mas[i];
				}
				return q;
			}
			else
			{
				vector q(space, 0);

				int i = 0;
				for (; i < a.space; i++)
				{
					q.mas[i] = mas[i] - a.mas[i];
				}
				for (; i < space; i++)
				{
					q.mas[i] = mas[i];
				}
				return q;
			}
			//return q;
		}
	}
}

vector& vector::operator=(const vector & a)
{
	for (int i = 0; i < space; i++)
	{
		mas[i] = a.mas[i];
	}
	return *this;
}

double & vector:: operator*(const vector & a)
{
	if (space == a.space)
	{
		double n = 0;
		for (int i = 0; i < space; i++)
		{
			n += mas[i] * a.mas[i];
			//std::cout << "CCODDDDEEEE\t" << n << std::endl;
		}
		return n;
		//std::cout << "CCODDDDEEEE\t"<< n << std::endl;
	}
	else
	{
		if (space < a.space)
		{
			double n = 0;

			int i = 0;
			for (; i < space; i++)
			{
				n += mas[i] * a.mas[i];
			}
			return n;
		}
		else
		{
			double n = 0;

			int i = 0;
			for (; i < a.space; i++)
			{
				n += mas[i] * a.mas[i];
			}
			return n;
		}
	}
}

vector vector:: operator*(int a)
{
	vector q(space, 0);
	for (int i = 0; i < space; i++)
	{
		q.mas[i] = mas[i] * a;
	}
	//std::cout << q << std::endl;
	return q;
}

const float vector::operator[](const int i)const
{
	return mas[i];
}