#include "triangle.h"
#include "tetragon.h"

using namespace std;

int main()
{
    geom * pointer;
    double a = 3, b = 4, c = 3, d = 4, q = 5;
    cout << "#Triangle " << endl;
    triangle tr(a , b , q);
    pointer = & tr;
    cout << "Sides: "<< a << ' ' << b << ' ' << q << endl <<
            "Area " << pointer->area() << endl << endl;

    cout << "#Tetragon " << endl;
    tetragon tetr( a, b, c, d, q);
    pointer = & tetr;
    cout << "Sides: "<< a << ' ' << b << ' ' << c << ' ' << d << endl
         << "Diag " << q << endl <<
            "Area " << pointer->area() << endl << endl;

    return 0;
}
