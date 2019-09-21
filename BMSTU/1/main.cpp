#include "sort.h"

int main()
{
	const int N = 9;
	int m[N] = { -1, 0, 5, -8, 0, 3, 12, 5, 1 };
	int m2[3] = { 3, 2, 1 };

	mergeSort<int>(m, N);
	mergeSort<int>(m2, 3);
	
	std::cin.get();
	return 0;
}