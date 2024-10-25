#include <stdlib.h>

long long* MSS2(long long* array, long long n);
long long max(long long a, long long b, long long c);

/**
 * Divide and Conquer algorithm to find the maximum subarray sum in an array.
 * 
 * This function divides the array into two halves and recursively calculates 
 * the maximum subarray sum for each half. It also calculates the maximum prefix 
 * sum, maximum suffix sum, and total sum for each half. The results are 
 * combined to determine the overall maximum subarray sum, maximum prefix sum, 
 * maximum suffix sum, and total sum of the array.
 *
 * Time complexity: O(n)
 *
 * @param array Pointer to the array of integers.
 * @param n The number of elements in the array.
 * @return A pointer to an array of four long long integers: 
 *         - The maximum subarray sum.
 *         - The maximum prefix sum.
 *         - The maximum suffix sum.
 *         - The total sum of the array.
 */
long long* MSS2(long long* array, long long n) {
    if (n == 1) {
        long long* result = (long long*)malloc(4 * sizeof(long long));
        result[0] = array[0]; // Maximum subarray sum
        result[1] = array[0]; // Prefix maximum
        result[2] = array[0]; // Suffix maximum
        result[3] = array[0]; // Total sum
        return result;
    }

    long long m = n / 2;
    long long* left = MSS2(array, m);
    long long* right = MSS2(array + m, n - m);

    long long PM = (left[1] > left[3] + right[1]) ? left[1] : left[3] + right[1];
    long long SM = (right[2] > right[3] + left[2]) ? right[2] : right[3] + left[2];
    long long OLM = left[2] + right[1];
    long long BS = left[3] + right[3];

    long long* result = (long long*)malloc(4 * sizeof(long long));
    result[0] = max(left[0], right[0], OLM);
    result[1] = PM;
    result[2] = SM;
    result[3] = BS;

    free(left);
    free(right);

    return result;
}


/**
 * Returns the maximum of the three given long long values.
 *
 * Compares three long long integers and returns the largest value.
 *
 * @param a The first value to compare.
 * @param b The second value to compare.
 * @param c The third value to compare.
 * @return The maximum of the three given values.
 */
long long max(long long a, long long b, long long c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}
