#include "ultra_large_int.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Function to subtract two BigIntegers (assuming non-negative results)
BigInteger BigInteger::subtract(const BigInteger& other) const {
    string num1 = value;
    string num2 = other.value;
    bool resultNegative = false;

    // Check which number is larger
    if (num1 < num2) {
        swap(num1, num2);
        resultNegative = true;
    }

    string result = "";
    int carry = 0;
    int n1 = num1.length();
    int n2 = num2.length();

    // Perform subtraction digit by digit
    for (int i = 0; i < n2; ++i) {
        int sub = (num1[n1 - 1 - i] - '0') - (num2[n2 - 1 - i] - '0') - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result = char(sub + '0') + result;
    }

    // Subtract remaining digits of num1
    for (int i = n2; i < n1; ++i) {
        int sub = (num1[n1 - 1 - i] - '0') - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result = char(sub + '0') + result;
    }

    // Remove leading zeros
    size_t pos = result.find_first_not_of('0');
    if (pos != string::npos) {
        result = result.substr(pos);
    } else {
        result = "0";
    }

    // If the result should be negative
    if (resultNegative) {
        result = "-" + result;
    }

    return BigInteger(result);
}

extern "C" int count_pairs(const char** data, const char* target, int n) {
    int result = 0;
    BigInteger targetBig(target);

    // Use an unordered map to count occurrences of each BigInteger
    unordered_map<string, int> numCount;

    // Populate the map with the counts of each number
    for (int i = 0; i < n; ++i) {
        numCount[data[i]]++;
    }

    // Iterate over the numbers and count valid pairs
    for (int i = 0; i < n; ++i) {
        BigInteger num1(data[i]);
        BigInteger targetBigInteger(target);

        for (const auto& pair : numCount) {
            BigInteger num2(pair.first);
            if (num1.subtract(num2) == targetBigInteger) {
                result += pair.second;
            }
        }

        // Decrement the count of the current number to avoid counting the same pair twice
        numCount[data[i]]--;
    }

    return result;
}
