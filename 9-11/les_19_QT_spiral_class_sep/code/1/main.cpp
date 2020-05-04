#include "matrix.h"

int main()
{
    int **matrix = NULL;
    int size = 0;

    size = user_input();
    matrix = init_matrix(matrix, size);
    matrix = spiral(matrix, size);
    print_matrix(matrix, size);
    del_memory(matrix, size);
    return 0;
}


