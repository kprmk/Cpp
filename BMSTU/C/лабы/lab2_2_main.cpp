#include <stdio.h>
#include <math.h>

int main() 
{
	int num = 2, i;
	for (i = 1; i <= 12; ++i)
	{
		printf("2 ^ %-2d = %-4d\n", i, num);
		num *= 2; // <=> num = num * 2
	}

	getchar();
	return 0;
}