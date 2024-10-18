# Modify this file to implement the count_pairs_file function
# using ultra-large integers in C/C++.
import ctypes
from ctypes import cdll, c_char_p, c_int, POINTER # Import the required types

lib = cdll.LoadLibrary("./largeint.so") # Load the shared library


# string_to_largeint(char* str, int size, int sign) -> int*
lib.string_to_largeint.argtypes = [c_char_p, c_int, c_int]
lib.string_to_largeint.restype = POINTER(c_int)

# comparison(int* a, int* b) -> int
lib.comparison.argtypes = [POINTER(c_int), POINTER(c_int)]
lib.comparison.restype = c_int

# absolute(int* a, int* b) -> int
lib.absolute.argtypes = [POINTER(c_int), POINTER(c_int)]
lib.absolute.restype = c_int

# difference(int* a, int* b) -> int*
lib.difference.argtypes = [POINTER(c_int), POINTER(c_int)]
lib.difference.restype = POINTER(c_int)

# resize(int* a) -> int*
lib.resize.argtypes = [POINTER(c_int)]
lib.resize.restype = POINTER(c_int)

#print_largeint(int* large_int) -> void
lib.print_largeint.argtypes = [POINTER(c_int)]
lib.print_largeint.restype = None

#to conver string to integer in C
def convert_string_to_largeint(number_str):
    # Determine the sign
    if number_str.startswith('-'):
        sign = 1
        number_str = number_str[1:]  # Remove the minus sign for processing
    else:
        sign = 0

    # Calculate the size of the number (number of digits)
    size = len(number_str)

    # Convert the string to bytes
    number_bytes = number_str.encode('ascii')

    # Call the C function
    large_int = lib.string_to_largeint(number_bytes, size, sign)

    return large_int

def read_file(filename: str) -> tuple[list[int], int]:
    with open(filename) as file:
        # First line is the target
        target = convert_string_to_largeint(file.readline()[:-1])
        # Second line is the number of integers
        n = int(file.readline())
        # Read the n integers and return them as a list
        return ([convert_string_to_largeint(file.readline()[:-1]) for _ in range(n)], target,n)


#old function O(n^2)
def count_pairs(data ,target,n) -> int:
    """Count the number of pairs of
    list indices i < j such that
    data[i] - data[j] = target.
    Time complexity: Naive O(n^2).
    """
    result = 0
    se = {data[0],data[1]}
    for i in range(n - 1):
        for j in range(i + 1, n):
            temp =  (lib.comparison(lib.difference(data[i], data[j]), target))
            if temp == 0:
                result += 1
    return result

def count_pairs_file(filename: str) -> int:
    data, target,n = read_file(filename)
    return count_pairs(data, target,n)
