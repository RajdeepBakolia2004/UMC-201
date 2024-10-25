#include <limits.h>

/**
 * Naive algorithm to find the maximum subarray sum in an array.
 *
 * Finds the maximum subarray sum by looping through all possible subarrays.
 * Time complexity is O(n^3).
 *
 * @param arr The array to find the maximum subarray sum in.
 * @param n The number of elements in @p arr.
 *
 * @return The maximum subarray sum.
 */
long long Naive_Max_subarray(long long *arr, long long n) {
    long long max_sum = LLONG_MIN;
    for (long long i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int result = 0;
            for (int k = i; k <= j; k++) {
                result += arr[k];
            }
            if (result > max_sum) {
                max_sum = result;
            }
        }
    }
    return max_sum;
}

