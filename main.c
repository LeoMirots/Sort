#include "sort.h"
#include <stdio.h>

int main(void)
{
	printf("vettore disordinato:\n");
	int v[10] = { 3,4,7,5,8,6,10,2,1,9 };
	for (size_t i = 0; i < 9; ++i)
		printf(" %d, ", v[i]);
	printf("%d;\n", v[9]);
	
	quickSort(v, 0, 9);

	printf("vettore ordinato con quickSort:\n");
	for (size_t i = 0; i < 9; ++i)
		printf(" %d, ", v[i]);
	printf("%d;\n", v[9]);
	system("PAUSE");
	
	return EXIT_SUCCESS;
}