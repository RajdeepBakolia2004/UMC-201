#include "largeint.h"


int* string_to_largeint(char* str, int size,int sign){
    int* large_int = (int*)malloc((size+2)*sizeof(int));
    int i = 2;
    large_int[0] = sign;
    large_int[1] = size;
    for(i=size+1;i>1;i--){
	large_int[i] = str[size+1-i] - '0';
    }
    return large_int;
}


int comparison(int* a, int* b){
	int signa = a[0], signb = b[0];
	int sizea = a[1], sizeb = b[1];
	if(signa == 1 && signb == 0)return -1;//a is negative and b is positive
	if(signa == 0 && signb == 1)return 1;//a is positive and b is negative
	if(signa == 1 && signb == 1){//both are negative
		if(sizea > sizeb)return -1;
		if(sizea < sizeb)return 1;
		for(int i=sizea+1;i>1;i--){
			if(a[i] > b[i])return -1;
			if(a[i] < b[i])return 1;
		}
		return 0;
	}
	if(signa == 0 && signb == 0){//both are positive
		if(sizea > sizeb)return 1;
		if(sizea < sizeb)return -1;
		for(int i=sizea+1;i>1;i--){
			if(a[i] > b[i])return 1;
			if(a[i] < b[i])return -1;
		}
		return 0;
	}

}


//return 1 if abs(a)>abs(b) 0 if equal and -1 if abs(a)<abs(b)
int absolute(int* a, int* b){
	int sizea = a[1], sizeb = b[1];
	if(sizea > sizeb)return 1;
	if(sizea < sizeb)return -1;
	for(int i=sizea+1;i>1;i--){
		if(a[i] > b[i])return 1;
		if(a[i] < b[i])return -1;
	}
	return 0;

}
//this function return a-b
int* difference(int* a, int* b) {
    int signa = a[0], signb = b[0];
    int sizea = a[1], sizeb = b[1];
    int size = sizea > sizeb ? sizea : sizeb;
    int* result = (int*)malloc((size + 3) * sizeof(int)); // Allocate memory for the result
    
    // Initialize result array
    for (int i = 2; i <= size + 2; i++) {
        result[i] = 0;
    }

    if (signa == 1 && signb == 0) { // a is negative, b is positive
        // a - b = -( |a| + |b| )
        result[0] = 1;
        result[1] = size + 1;
        int carry = 0;
        for (int i = 2; i <= size + 1; i++) {
            int ai = i > sizea + 1 ? 0 : a[i];
            int bi = i > sizeb + 1 ? 0 : b[i];
            int temp = ai + bi + carry;
            if (temp >= 10) {
                result[i] = temp - 10;
                carry = 1;
            } else {
                result[i] = temp;
                carry = 0;
            }
        }
        if (carry == 1) {
            result[size + 2] = 1;
            return result;
        }
        result = resize(result);
        return result;
    }
    
    if (signa == 0 && signb == 1) { // a is positive, b is negative
        // a - b = |a| + |b|
        result[0] = 0;
        result[1] = size + 1;
        int carry = 0;
        for (int i = 2; i <= size + 1; i++) {
            int ai = i > sizea + 1 ? 0 : a[i];
            int bi = i > sizeb + 1 ? 0 : b[i];
            int temp = ai + bi + carry;
            if (temp > 9) {
                result[i] = temp - 10;
                carry = 1;
            } else {
                result[i] = temp;
                carry = 0;
            }
        }
        if (carry == 1) {
            result[size + 2] = 1;
            return result;
        }
        result = resize(result);
        return result;
    }
    
    if (signa == 1 && signb == 1) { // both are negative
        if (absolute(a, b) == 1) { // |a| > |b|
            result[0] = 1;
            result[1] = size + 1;
            int carry = 0;
            for (int i = 2; i <= sizea + 1; i++) {
                int ai = a[i];
                int bi = i > sizeb + 1 ? 0 : b[i];
                int temp = ai - bi - carry;
                if (temp < 0) {
                    result[i] = temp + 10;
                    carry = 1;
                } else {
                    result[i] = temp;
                    carry = 0;
                }
            }
            result = resize(result);
            return result;
        }
        if (absolute(a, b) == -1) { // |a| < |b|
            result[0] = 0;
            result[1] = size + 1;
            int carry = 0;
            for (int i = 2; i <= sizeb + 1; i++) {
                int ai = i > sizea + 1 ? 0 : a[i];
                int bi = b[i];
                int temp = bi - ai - carry;
                if (temp < 0) {
                    result[i] = temp + 10;
                    carry = 1;
                } else {
                    result[i] = temp;
                    carry = 0;
                }
            }
            result = resize(result);
            return result;
        }
        if (absolute(a, b) == 0) { // |a| == |b|
            return string_to_largeint("0", 1, 0);
        }
    }
    
    if (signa == 0 && signb == 0) { // both are positive
        if (absolute(a, b) == 1) { // |a| > |b|
            result[0] = 0;
            result[1] = size + 1;
            int carry = 0;
            for (int i = 2; i <= sizea + 1; i++) {
                int ai = a[i];
                int bi = i > sizeb + 1 ? 0 : b[i];
                int temp = ai - bi - carry;
                if (temp < 0) {
                    result[i] = temp + 10;
                    carry = 1;
                } else {
                    result[i] = temp;
                    carry = 0;
                }
            }
            result = resize(result);
            return result;
        }
        if (absolute(a, b) == -1) { // |a| < |b|
            result[0] = 1;
            result[1] = size + 1;
            int carry = 0;
            for (int i = 2; i <= sizeb + 1; i++) {
                int ai = i > sizea + 1 ? 0 : a[i];
                int bi = b[i];
                int temp = bi - ai - carry;
                if (temp < 0) {
                    result[i] = temp + 10;
                    carry = 1;
                } else {
                    result[i] = temp;
                    carry = 0;
                }
            }
            result = resize(result);
            return result;
        }
        if (absolute(a, b) == 0) { // |a| == |b|
            return string_to_largeint("0", 1, 0);
        }
    }

    return result;
}

int* resize(int* a){
	int size = a[1];
	int count_end_zero = 0;
	for(int i=size+1;i>1;i--){
		if(a[i] == 0)count_end_zero++;
		else break;
	}
	int* result = (int*)malloc((size-count_end_zero+2)*sizeof(int));
	result[0] = a[0];
	result[1] = size - count_end_zero;
	for(int i=2;i<=size-count_end_zero+1;i++){
		result[i] = a[i];
	}
	return result;
}



void print_largeint(int* large_int) {
    int sign = large_int[0];
    int size = large_int[1];
    if (sign == 1) printf("-");
    for (int i = size + 1; i >= 2; i--) {
        printf("%d", large_int[i]);
    }
    printf("\n");
}

