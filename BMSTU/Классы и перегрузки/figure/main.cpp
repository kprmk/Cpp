#include <iostream>
#include "figure.h"
#include "rectangle.h"
#include "square.h"
#include "triangle.h"
#include "ellipse.h"
#include "circle.h"
#include "fig3D.h"
#include "cube.h"
#include "ball.h"

using namespace std;

int main()
{
	/*figure a(7, 2, 3);
	cout << "FIGURE" << endl;
	a.printk();
	a.replace(10, 10, 10);
	a.printk();
	a.move(-5, -5);
	a.printk();
	a.rotate(100);
	a.printk();*/

	cout << "```RECTANGLE```" << endl;
	figure * pa;
	rectangle r(1, 1, 1, 4, 5);
	pa = &r;
	pa->print();

	cout << "```SQUARE```" << endl;
	square k(1, 1, 1, 5);
	pa = &k;
	pa->print();

	cout << "```TRIANGLE```" << endl;
	triangle t(1, 1, 1, 3, 4, 5);
	pa = &t;
	pa->print();

	cout << "```ELLIPSE```" << endl;
	ellipse el(1, 1, 1, 4, 5);
	pa = &el;
	pa->print();

	cout << "```CIRCLE```" << endl;
	circle c(1, 1, 1, 10);
	pa = &c;
	pa->print();

	cout << "```CUBE```" << endl;
	cube cu(1, 1, 1, 1, 1, 1, 3);
	pa = &cu;
	pa->print();

	cout << "```BALL```" << endl;
	ball b(1, 1, 1, 1, 1, 1, 10);
	pa = &b;
	pa->print();

	getchar();
	return 0;
}