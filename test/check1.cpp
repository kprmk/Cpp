#include <iostream>
#include <cstdlib> // for rand() && srand()
#include <time.h>   // time()
using namespace std;

int main()
{
    for (int i = 0; i < 500; i++)
    {
             for (int j = 0; j < 20; j++)
                printf("123412341234\n");
            printf("\e[1;1H\e[2J");
            // usleep(200000);
            printf("CHECK");
    }

    return (0);
}