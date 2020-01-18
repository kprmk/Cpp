#ifndef SPIRAL_MATRIX_H
#define SPIRAL_MATRIX_H
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

class spiral_matrix
{
private:
    int **pointer;
    int n;
public:

    spiral_matrix(int n = 5);
    ~spiral_matrix();

    void matrix_print();
    void matrix_circle_around();

};

#endif // SPIRAL_MATRIX_H
