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
    int **matrix;
    int size;

public:
    spiral_matrix();
    ~spiral_matrix();

    void matrix_print();
    void matrix_circle_around();
};

#endif // SPIRAL_MATRIX_H
