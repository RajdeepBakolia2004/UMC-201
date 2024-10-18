#include "largeint.h"

void main() {
    // Test cases for comparison and subtraction
    int* num1 = string_to_largeint("16234", 5, 0);  // Positive number
    int* num2 = string_to_largeint("81234", 5, 0);  // Positive number
    int* num3 = string_to_largeint("12345", 5, 1);  // Negative number
    int* num4 = string_to_largeint("54321", 5, 1);  // Negative number
    int* num5 = string_to_largeint("12345", 5, 0);  // Positive number same as num3 but positive

    // Find and print the difference
    int* diff1 = difference(num1, num2);
    printf("Difference (num1 - num2): ");
    print_largeint(diff1);

    int* diff2 = difference(num3, num4);
    printf("Difference (num3 - num4): ");
    print_largeint(diff2);

    int* diff3 = difference(num5, num1);
    printf("Difference (num5 - num1): ");
    print_largeint(diff3);

    // Free allocated memory
    free(num1);
    free(num2);
    free(num3);
    free(num4);
    free(num5);
    free(diff1);
    free(diff2);
    free(diff3);
}
