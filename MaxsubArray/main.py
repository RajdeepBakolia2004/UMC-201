import sys
from time import time
from ctypes import cdll, POINTER,c_longlong 

linear = cdll.LoadLibrary("./linear.so")
mss1 = cdll.LoadLibrary("./MSS1.so")
mss2 = cdll.LoadLibrary("./MSS2.so")
naive1 = cdll.LoadLibrary("./naive1.so")
naive2 = cdll.LoadLibrary("./naive2.so")

linear.kadane.argtypes = [POINTER(c_longlong), c_longlong]
linear.kadane.restype = c_longlong

mss1.MSS1.argtypes = [POINTER(c_longlong), c_longlong]
mss1.MSS1.restype = c_longlong

mss2.MSS2.argtypes = [POINTER(c_longlong), c_longlong]
mss2.MSS2.restype = POINTER(c_longlong)

naive1.Naive_Max_subarray.argtypes = [POINTER(c_longlong), c_longlong]
naive1.Naive_Max_subarray.restype = c_longlong

naive2.Naive_Max_subarray.argtypes = [POINTER(c_longlong), c_longlong]
naive2.Naive_Max_subarray.restype = c_longlong

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
    print("Linear: ", linear.kadane(arr, n))
    print("Time: ", time() - initial_time)
    initial_time = time()    
    print("MSS1: ", mss1.MSS1(arr, n))
    print("Time: ", time() - initial_time)
    initial_time = time()
    print("MSS2: ", mss2.MSS2(arr, n)[0])
    print("Time: ", time() - initial_time)
    initial_time = time()
    print("Naive1: ", naive1.Naive_Max_subarray(arr, n))
    print("Time: ", time() - initial_time)
    initial_time = time()
    print("Naive2: ", naive2.Naive_Max_subarray(arr, n))
    print("Time: ", time() - initial_time)
if __name__ == "__main__":
    main()