#ifndef TETRAGON_H
#define TETRAGON_H
#include "triangle.h"


class tetragon : public triangle
{
protected:
    double d;
    double diag_1;

public:
    tetragon(double s1,double s2,double s3,double s4, double s5) :
        triangle(s1,s2,s3)
    {
        d = s4;
        diag_1 = s5;
    }
    ~tetragon() {  }

    double area()
    {
        double cosp1, cosp2, p, cos_p1p2;
        cosp1 = (a*a+b*b-diag_1*diag_1)/(2*a*b);
        cosp2 = (c*c+d*d-diag_1*diag_1)/(2*c*d);

         p = (a + b + c + d) / 2;
         cos_p1p2 = (0.5+0.5*(cosp1*cosp2-pow((1-cosp1*cosp1)*(1-cosp2*cosp2),0.5)));

        return pow(((p-a)*(p-b)*(p-c)*(p-d)-a*b*c*d*cos_p1p2),0.5);
    }
};

#endif // TETRAGON_H
