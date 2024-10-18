# Modify this file to implement the count_pairs_file function
# using ultra-large integers in C/C++.
import ctypes

def read_file(filename: str) -> tuple[list[int], int]:
    with open(filename) as file:
        # First line is the target
        target = int(file.readline())
        # Second line is the number of integers
        n = int(file.readline())
        # Read the n integers and return them as a list
        return ([int(file.readline()) for _ in range(n)], target)


def count_pairs(data: list[int], target: int) -> int:
    # """Count the number of pairs of list indices i < j such that
    # data[i] - data[j] = target.
    # Optimized to O(n) using a hash map.
    # """
    # result = 0
    # freq = {}
    # for value in data:
    #     needed = value + target
    #     if needed in freq:
    #         result += freq[needed]
    #     if value in freq:
    #         freq[value] += 1
    #     else:
    #         freq[value] = 1
    # return result
    temp=ctypes.CDLL("./UltraLargeNumber.so")
    return temp.Count_Pairs()

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
    count_pairs(data, target)
