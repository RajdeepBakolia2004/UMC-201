import sys
from time import time
from ctypes import cdll, POINTER,c_longlong 

naive = cdll.LoadLibrary("./naive.so")
recursion1 = cdll.LoadLibrary("./recursion1.so")
recursion2 = cdll.LoadLibrary("./recursion2.so")


naive.naive_inversion.argtypes = [POINTER(c_longlong), c_longlong]
naive.naive_inversion.restype = c_longlong

recursion1.IC1.argtypes = [POINTER(c_longlong), c_longlong]
recursion1.IC1.restype = c_longlong

recursion2.IC2.argtypes = [POINTER(c_longlong), c_longlong]
recursion2.IC2.restype = c_longlong


def main():
    if len(sys.argv) != 2:
        print("Usage: python3 main.py filename")
        sys.exit(1)
    name = str(sys.argv[1])
    file = open(name, "r")
    arr = eval(file.read())
    arr = (c_longlong * len(arr))(*arr)
    n = len(arr)
    initial_time = time()
    print("Naive: ", naive.naive_inversion(arr, n))
    print("Time: ", time() - initial_time)
    initial_time = time()    
    print("recursion1: ", recursion1.IC1(arr, n))
    print("Time: ", time() - initial_time)
    initial_time = time()
    print("recursion2: ", recursion2.IC2(arr, n))
    print("Time: ", time() - initial_time)
if __name__ == "__main__":
    main()