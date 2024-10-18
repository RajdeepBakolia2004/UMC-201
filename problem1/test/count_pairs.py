# Modify this file to implement the count_pairs_file function
# using ultra-large integers in C/C++.

import ctypes
from ctypes import cdll, c_char_p, POINTER, c_int

# Load the C++ shared library
lib = cdll.LoadLibrary("./ultra_large_int.so")

# Define the return type and argument types for the C function
lib.count_pairs.argtypes = [POINTER(c_char_p), c_char_p, c_int]
lib.count_pairs.restype = c_int


def read_file(filename: str) -> tuple[list[int], int]:
    with open(filename) as file:
        # First line is the target
        target = int(file.readline())
        # Second line is the number of integers
        n = int(file.readline())
        # Read the n integers and return them as a list
        return ([int(file.readline()) for _ in range(n)], target)


# def count_pairs(data: list[int], target: int) -> int:
#     """Count the number of pairs of
#     list indices i < j such that
#     data[i] - data[j] = target.
#     Time complexity: Naive O(n^2).
#     """
#     result = 0
#     n = len(data)
#     for i in range(n - 1):
#         for j in range(i + 1, n):
#             if data[i] - data[j] == target:
#                 result += 1
#     return result

def count_pairs(data: list[int], target: int) -> int:
    """Count the number of pairs using the C/C++ implementation."""
   # Convert the list of integers to a list of strings
    data_str = [str(d) for d in data]
    
    # Convert the Python list of strings to an array of C strings
    data_array = (c_char_p * len(data_str))(*[s.encode('utf-8') for s in data_str])
    target_c = str(target).encode('utf-8')
    n = len(data_str)

    # print(data_array)
    # print(target_c)
    # print(n)
    # Call the C++ function
    return lib.count_pairs(data_array, target_c, n)


def test_count_pairs():
    # Simple correctness tests
    assert count_pairs([1, 2, 3, 4, 5], 1) == 0
    assert count_pairs([5, 4, 3, 2, 1], 1) == 4
    assert count_pairs([1, 2, 3, 4, 5], -3) == 2
    # Test with huge integers
    assert count_pairs([10**20 + 2, 10**20 + 1, 10**20], 1) == 2
    print("count_pairs.py: All tests passed")


def count_pairs_file(filename: str) -> int:
    data, target = read_file(filename)
    # test_count_pairs()
    return count_pairs(data, target)