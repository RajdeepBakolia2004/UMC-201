

/**
 * Calculate the number of inversions in a given array using the naive
 * O(n^2) algorithm.
 *
 * @param arr The array to calculate the number of inversions for
 * @param n The length of the array
 *
 * @returns The number of inversions in the array
 */
long long naive_inversion(long long *arr, long long n) {
    long long inv = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                inv++;
            }
        }
    }
    return inv;
}

