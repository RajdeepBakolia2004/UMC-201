#include <stdio.h>
#include <stdlib.h>

long long IC1(long long *arr, long long n);
void merge_sort(long long *arr, long long n);


/**
 * @brief Counts the number of inversions in an array using the divide-and-conquer
 * technique.
 * @param arr The array to count the inversions of.
 * @param n The length of the array.
 * @return The number of inversions in the array.
 */

long long IC1(long long *arr, long long n){
    if(n == 1){
        return 0;
    }
    long long m = n / 2;
    long long* B = (long long *)malloc(m * sizeof(long long));
    long long* C = (long long *)malloc((n - m) * sizeof(long long));
    for(long long i = 0; i < m; i++){
        B[i] = arr[i];
    }
    for(long long i = m; i < n; i++){
        C[i - m] = arr[i];
    }
    long long I2 = IC1(C, n - m);
    long long I1 = IC1(B, m);
    merge_sort(B, m);
    merge_sort(C, n - m);
    long long I3 = 0;
    long long i = 0, j = 0;
    while(i < m && j < n - m){
        if(B[i] <= C[j]){
            i++;
        }else{
            I3 += m - i;
            j++;
        }
    }
    free(B);
    free(C);
    return I1 + I2 + I3;


}


/**
 * @brief Sorts an array using the merge sort algorithm.
 * @param arr The array to sort.
 * @param n The length of the array.
 */

void merge_sort(long long *arr, long long n){
    if(n == 1){
        return;
    }
    long long m = n / 2;
    long long *B = (long long *)malloc(m * sizeof(long long));
    long long *C = (long long *)malloc((n - m) * sizeof(long long));
    for(long long i = 0; i < m; i++){
        B[i] = arr[i];
    }
    for(long long i = m; i < n; i++){
        C[i - m] = arr[i];
    }
    merge_sort(B, m);
    merge_sort(C, n - m);
    long long i = 0, j = 0, k = 0;
    while(i < m && j < n - m){
        if(B[i] <= C[j]){
            arr[k] = B[i];
            i++;
        }else{
            arr[k] = C[j];
            j++;
        }
        k++;
    }
    while(i < m){
        arr[k] = B[i];
        i++;
        k++;
    }
    while(j < n - m){
        arr[k] = C[j];
        j++;
        k++;
    }
    free(B);
    free(C);
}

int main(){
    long long arr[] = {1, 20, 6, 4, 5, 65, 10, 8, 9, 11};
    long long n = sizeof(arr) / sizeof(arr[0]);
    printf("%lld\n", IC1(arr, n));
    return 0;
}