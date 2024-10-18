#ifndef LARGEINT_H
#define LARGEINT_H

#include <stdlib.h>
#include <stdio.h>

// Function prototypes

// Convert a string to a large integer representation
int* string_to_largeint(char* str, int size, int sign);

// Compare two large integers (returns 1 if a > b, 0 if a == b, -1 if a < b)
int comparison(int* a, int* b);

// Compare absolute values of two large integers (returns 1 if |a| > |b|, 0 if equal, -1 if |a| < |b|)
int absolute(int* a, int* b);

// Perform subtraction of two large integers (returns a - b)
int* difference(int* a, int* b);

// Resize the large integer by removing leading zeros
int* resize(int* a);

// Print the large integer to the console
void print_largeint(int* large_int);

#endif /* LARGEINT_H */