#include <stdio.h>
#include <stdlib.h>

long long IC2(long long *arr, long long n);

long long IC2(long long *arr, long long n){
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
    long long I1 = IC2(B, m);
    long long I2 = IC2(C, n - m);
    long long I3 = 0;
    long long i = 0, j = 0;
    while(i < m && j < n - m){
        if(B[i] > C[j]){
            I3 += m - i;
            arr[i + j] = C[j];
            j++;
        }else{
            arr[i + j] = B[i];
            i++;
        }
    }
    if(i == m){
        while(j < n - m){
            arr[i + j ] = C[j];
            j++;
        }
    }
    if(j == n - m){
        while(i < m){            
            arr[i + j ] = B[i];
            i++;
        }
    }
    free(B);
    free(C);
    return I1 + I2 + I3;
}

int main() {
    long long arr[] = {1, 20, 6, 4, 5, 65, 10, 8, 9, 11};
    //long long arr[] = {1, 20, 6, 4, 5, 65};
    long long n = sizeof(arr) / sizeof(arr[0]);
    printf("%lld\n", IC2(arr, n));
    return 0;
}