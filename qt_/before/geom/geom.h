#ifndef GEOM_H
#define GEOM_H

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

class geom
{
protected:
    double a;
    double b;

public:
    geom(double s1 , double s2 )
    {
        a = s1;
        b = s2;
    }

    virtual ~geom() { }

    virtual  double area () = 0;
};

#endif // GEOM_H
