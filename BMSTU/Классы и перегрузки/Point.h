#pragma once
//Класс точки

class Point
{
	private:
		int x;
		int y;

	public:
		Point();
		Point(int x, int y);
		~Point() {}

		int getX() { return x; }
		int getY() { return y; }
		void move(int dx, int dy);
		void move(int dx);
};