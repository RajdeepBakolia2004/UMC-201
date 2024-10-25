#include <limits.h>

/**
 * Naive algorithm to find the maximum subarray sum in an array.
 *
 * This function iterates over all possible subarrays to determine
 * the subarray with the largest sum.
 * 
 * Time complexity: O(n^2)
 *
 * @param arr Pointer to the array of integers.
 * @param n The number of elements in the array.
 * @return The maximum sum of any subarray within the given array.
 */

long long Naive_Max_subarray(long long *arr, long long n) {
    long long max_sum = LLONG_MIN;
    for (long long i = 0; i < n; i++) {
        long long result = 0;    
        for (long long j = i; j < n; j++) {
            result += arr[j];
            if (result > max_sum) {
                max_sum = result;
            }
        }
    }
    return max_sum;
}

