#pragma once
#include <iostream>
#include "point.h"

class line
{
public:
	line(){}
	virtual ~line(){}

	virtual point fttt(const double t) = 0;

	double length(double t0, double t1)
	{
		double sum = 0;
		/*point a = fttt(t0);
		point b = fttt(t1);*/
		//point c = a;
		//double dx = abs(/*point::*/a.getx(), /*point::*/b.getx()) / 1000;
		//double dy = abs(/*point::*/a.gety(), /*point::*/b.gety()) / 1000;
		//point e (dx, dy);
		double t = (t1 - t0) / 1000.;
		//std::cout << t0 << std::endl;
		//std::cout << t1 << std::endl;
		//std::cout << t << std::endl;
		int i = 0;
		while (i < 100)
		{ 
			
			/*c += e;*/
			sum += distat(fttt(t0) , fttt(t0 + t));
			/*a += e;*/
			t0 += t;
			i++;
			//std::cout << distat(fttt(t0), fttt(t0 + t)) << std::endl;
		}

		return sum;
	}

};

