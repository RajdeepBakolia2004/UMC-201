#ifndef ULTRA_LARGE_INT_H
#define ULTRA_LARGE_INT_H

#include <string>
#include <iostream>

class BigInteger {
public:
    std::string value;

    BigInteger(std::string val) : value(val) {}

    // Function to subtract two BigIntegers
    BigInteger subtract(const BigInteger& other) const;

    // Comparison operators
    bool operator==(const BigInteger& other) const {
        return value == other.value;
    }

    bool operator<(const BigInteger& other) const;

    // Utility to display the BigInteger
    void print() const {
        std::cout << value << std::endl;
    }
};

// Function declaration for counting pairs
extern "C" {
    int count_pairs(const char** data, const char* target, int n);
}

#endif // ULTRA_LARGE_INT_H
