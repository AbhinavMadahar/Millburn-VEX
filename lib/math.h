/*******************************************************************************
This file manages math-related activities such as:
	* finding the least or greatest number
    * swapping the values of 2 variables
*******************************************************************************/

// to swap the values of variables a and b, use swap(&a, &b)
void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}
