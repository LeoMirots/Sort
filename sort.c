/*
Codice dei principali algoritmi di ordinamento, per ordinare in
ordine crescente un vettore di qualsiasi tipo di dato numerico;
*/

#include "sort.h"

void naiveSort(numbers *v, size_t dim)
{
	while (dim > 1) /*Finchè il vettore non è unitario*/
	{
		/*Identifico il valore massimo nel vettore*/
		size_t p = 0; /*p = posizione del massimo nel vettore, ipotizzo che il primo elemento sia il valore massimo;*/
		for (size_t i = 1; i < dim; ++i)
		{
			if (v[p] < v[i])
				p = i; /*Se identifico un elemento più grande del mio massimo, aggiorno il massimo;*/
		}

		/* Se la posizione del mio massimo non è quella alla fine del vettore, scambio il massimo con l'elemento che si trova alla fine;*/
		if (p < dim - 1)
		{
			numbers tmp = v[dim - 1];
			v[dim - 1] = v[p];
			v[p] = tmp;
		}
		dim -= 1; /*Decremento la lunghezza del vettore, perchè alla fine ho già messo il valore massimo e non devo più considerare quindi l'ultima posizione;*/
	}
	return;
}

void bubbleSort(numbers *v, size_t dim) /*Si tratta di un naiveSort intelligente, che si accorge quando il vettore è ordinato e salta iterazioni inutili;*/
{
	bool ordinato = false;
	while (dim > 1 && ordinato == false) /*Se capisce che il vettore è ordinato, interrompe il ciclo prima di raggiungere la fine del vettore;*/
	{
		ordinato = true;	/*Ipotizzo sia ordinato;*/
		for (size_t i = 0; i < dim - 1; ++i) /*Scorrendo tutto il vettore:*/
		{
			if (v[i] > v[i + 1]) /*Analizzando 2 a 2 se le coppie sono ordinate;*/
			{
				numbers tmp = v[i + 1]; /*Se non sono ordinate scambio i 2 numeri;*/
				v[i + 1] = v[i];
				v[i] = tmp;

				ordinato = false; /*Se viene scambiata una coppia non è più detto che il vettore sia ordinato; 6,7,5 -> 6,7 Ok -> 7,5 Scambio -> 6,5,7 Non ordinato*/
			}
		}
		--dim; /*Decremento dim perchè sicuramente l'ultima posizione contiene il valore massimo, e quindi non devo più considerarla;*/
	}
	return;
}

void insertSort(numbers *v, size_t dim) /*Questo algoritmo inserisce il numero x considerato nella posizione giusta in cui andrebbe, x viene inizializzato partendo dall'inizio del vettore fino all'ultimo elemento*/
{
	for (size_t i = 1; i < dim; ++i) /*Scorrendo tutto il vettore:*/
	{
		size_t c;
		numbers x = v[i];	/*x è l'elemento del vettore all'indice i;*/
		for (c = i - 1; c >= 0 && x < v[c]; --c)	/*c è l'elemento del vettore precedente all'indice i;*/
		{
			v[c + 1] = v[c]; /*Crea lo spazio, spostando avanti tutti gli altri elementi;*/
		}
		v[c + 1] = x; /*Inserisco l'elemento x nel punto giusto del vettore;*/
	}
	return;
}

/*
Ordinare un vettore corto costa meno di ordinarne uno lungo, l'idea del quickSort consiste nel partizionare
il vettore da ordinare in 2 sottovettori delimitati da un elemento "sentinella".
L'obbiettivo è avere nel primo sottovettore solo elementi <= al pivot, e nel secondo solo >= al pivot,
i due sottovettori possono poi essere ordinati separatamente riapplicando lo stesso procedimento -> algoritmo ricorsivo.
*/
void quickSort(numbers *v, size_t first, size_t last)
{
	if (v == NULL)
		return;
	size_t i, j;
	numbers pivot;
	if (first < last)
	{
		i = first;	j = last;
		pivot = v[(first + last) / 2]; /*Imposto il pivot alla metà tra l'inizio e la fine del vettore considerato;*/

		do
		{
			while (v[i] < pivot) 
				++i;				/*Dopo questo ciclo i valori da v[first] a v[i] sono tutti < del pivot;*/
			while (v[j] > pivot)
				--j;				/*Dopo questo ciclo i valori da v[j] a v[last] sono tutti > del pivot*/
			if (i <= j)
			{
				numbers tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;

				++i;
				--j;
			}
		} while (i <= j);	/*i viene sempre incrementato, j viene sempre diminuito, a un certo punto si incontrano/incrociano;*/

		quickSort(v, first, j);
		quickSort(v, i, last);
	}
	return;
}

/*Variante del quickSort che divide i vettori sempre a metà e ottenendo dei vettori di dimensioni più simmetriche possibile;*/
void mergeSort(numbers *v, size_t first, size_t last)
{
	if (v == NULL)
		return;
	size_t mid = 0;
	if (first < last)
	{
		mid = (last + first) / 2;
		mergeSort(v, first, mid);
		mergeSort(v, mid + 1, last);
	}

	//	numbers *vout = malloc(sizeof(numbers)); /* vout: vettore temporaneo;*/
	numbers vout[100]; /*vettore temporaneo*/
	size_t i = first, j = mid + 1, k = first;
	while (i <= mid && j <= last)
	{
		if (v[i] < v[j])
			vout[k] = v[i++];
		else
			vout[k] = v[j++];
		++k;
	}
	while (i <= mid)
	{
		vout[k] = v[i++];
		++k;
	}
	while (j <= last)
	{
		vout[k] = v[j++];
		++k;
	}
	for (i = first; i <= last; ++i)
		v[i] = vout[i];
}