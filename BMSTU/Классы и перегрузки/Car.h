#pragma once

class Car
{
	private:
		double total;
		double cur;
		double consump;
	public:
		Car ();
		Car (double c);
		~Car() {}

		double getTOT() { return total; };
		double getCUR() { return cur; };
		double getCONS() { return consump; };

		double random();
		void petrol();
		void trip(double km);
};