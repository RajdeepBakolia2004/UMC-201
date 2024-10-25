#include <limits.h>

long long MSS1(long long *arr, long long n);
long long suffix_max(long long *arr, long long n);
long long prefix_max(long long *arr, long long n);
long long max(long long a, long long b, long long c);


/**
 * Divide and Conquer algorithm to find the maximum subarray sum in an array.
 *
 * Divides the array into two halves, and finds the maximum subarray sum for each half.
 * Then, it finds the maximum subarray sum that crosses the two halves.
 * Finally, returns the maximum of the three sums.
 *
 * Time complexity: O(n log n)
 *
 * @param arr Pointer to the array of integers.
 * @param n The number of elements in the array.
 * @return The maximum sum of any subarray within the given array.
 */
long long MSS1(long long *arr, long long n) {
    if(n == 1){
        return arr[0];
    }
    long long m = n/2;
    long long B[m];
    long long C[n-m];
    for(long long i = 0; i < m; i++){
        B[i] = arr[i];
    }
    for(long long i = m; i < n; i++){
        C[i-m] = arr[i];
    }
    long long M1 = MSS1(B, m);
    long long M2 = MSS1(C, n-m);
    long long SM = suffix_max(B, m) + prefix_max(C, n-m);
    return max(M1, M2, SM);
}


/**
 * Finds the maximum suffix sum in an array.
 *
 * Iterates over the array from right to left, keeping track of the maximum suffix sum.
 *
 * Time complexity: O(n)
 *
 * @param arr Pointer to the array of integers.
 * @param n The number of elements in the array.
 * @return The maximum suffix sum of any subarray within the given array.
 */
long long suffix_max(long long *arr, long long n){
    long long sum = 0;
    long long max_sum = LLONG_MIN;
    for(long long i = n-1; i >= 0; i--){
        sum += arr[i];
        if(sum > max_sum){
            max_sum = sum;
        }
    }
    return max_sum;
}

/**
 * Finds the maximum prefix sum in an array.
 *
 * Iterates over the array from left to right, keeping track of the maximum prefix sum.
 *
 * Time complexity: O(n)
 *
 * @param arr Pointer to the array of integers.
 * @param n The number of elements in the array.
 * @return The maximum prefix sum of any subarray within the given array.
 */
long long prefix_max(long long *arr, long long n){
    long long sum = 0;
    long long max_sum = LLONG_MIN;
    for(long long i = 0; i < n; i++){
        sum += arr[i];
        if(sum > max_sum){
            max_sum = sum;
        }
    }
    return max_sum;
}

/**
 * Returns the maximum of the three given long long values.
 *
 * @param a The first value to compare.
 * @param b The second value to compare.
 * @param c The third value to compare.
 *
 * @return The maximum of the three given values.
 */
long long max(long long a, long long b, long long c){
    if(a >= b && a >= c){
        return a;
    }
    else if(b >= a && b >= c){
        return b;
    }
    else{
        return c;
    }
}

