#include "spiral_matrix.h"

int main()
{
    int n;
    
    n = 0;
    cout << "Please, enter size of\nsquare matrix (one number)" << endl;
    std::cin >> n;
    spiral_matrix mat(n);
    mat.matrix_circle_around();
    mat.matrix_print();

    return 0;
}

