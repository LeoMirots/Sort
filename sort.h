#if !defined SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdbool.h>

typedef int numbers;  /*Il tipo di dato numbers può essere qualsiasi tipo di dato numerico, è sufficiente cambiare la definizione;*/

/*Gli algoritmi di ordinamento sono riportati in ordine crescente di efficenza:*/
extern void naiveSort(numbers *v, size_t dim);					/*Complessità: n al quadrato;*/
extern void bubbleSort(numbers *v, size_t dim);					/*Complessità: varia da (n - 1) fino a n al quadrato;*/
extern void insertSort(numbers *v, size_t dim);					/*Complessità: varia da (n - 1) fino a n al quadrato;*/
extern void quickSort(numbers *v, size_t first, size_t last);	/*Complessità: varia da (n*log2(n)) fino a n al quadrato;*/
extern void mergeSort(numbers *v, size_t first, size_t last);	/*Complessità: sempre (n*log2(n));*/

#endif //SORT_H