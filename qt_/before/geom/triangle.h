#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "geom.h"


class triangle : public geom
{
protected:
    double c;

public:
    triangle(double s1, double s2, double s3) : geom(s1 , s2) { c = s3; }
    ~triangle() { }

    double area()
    {
        double p = (a + b + c) / 2;
        return pow(p*(p-a)*(p-b)*(p-c), 0.5);
    }
};

#endif // TRIANGLE_H
