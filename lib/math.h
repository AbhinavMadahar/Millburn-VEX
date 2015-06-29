/*******************************************************************************
This file manages math-related activities such as:
	* finding the least or greatest number
	* swapping the values of 2 variables
*******************************************************************************/
#define included__math true

#ifndef included__syntax
	#include "syntax.h"
#endif

// to swap the values of variables a and b, use swap(&a, &b)
void swap(int *a, int *b) {
	int aux = *a;
	*a = *b;
	*b = aux;
}

int least(int a, int b) {
	return (a < b) ? a : b;
}

int least(int a, int b, int c) {
	return least(least(a, b), c);
}

int least(int a, int b, int c, int d) {
	return least(least(a, b, c), d);
}

int greatest(int a, int b) {
	return (a > b) ? a : b;
}

int greatest(int a, int b, int c) {
	return greatest(greatest(a, b), c);
}

int greatest(int a, int b, int c, int d) {
	return greatest(greatest(a, b, c), d);
}
