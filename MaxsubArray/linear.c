#include <limits.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
long long kadane(long long *arr, long long n);


/**
 * Kadane's algorithm to find the maximum subarray sum in an array.
 *
 * This function iterates over the array, keeping track of the maximum subarray sum
 * ending at each position. The overall maximum subarray sum is the maximum of these
 * values.
 *
 * Time complexity: O(n)
 *
 * @param arr Pointer to the array of integers.
 * @param n The number of elements in the array.
 * @return The maximum sum of any subarray within the given array.
 */
long long kadane(long long *arr, long long n) {
    long long max_ending_here = arr[0];
    long long max_so_far = arr[0];

    for (long long i = 1; i < n; i++) {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

