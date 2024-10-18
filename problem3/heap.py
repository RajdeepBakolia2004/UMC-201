import heapq
import sys
from time import time
import heapq
def neighbor(E,vector):
    square = [[(E-element)**2,index] for index,element in enumerate(vector)]
    heapq.heapify(square)
    result = []
    for i in range(min(6,len(vector))):
        result.append((heapq.heappop(square))[1])
    return result
if __name__ == "__main__":
    array = []
    for i in range(5):
        initial = time()
        filename = sys.argv[1]
        file = open(filename)
        line = file.readline()
        while line != "end\n":
            E = float(line)
            estimate_vector = [float(ele) for ele in file.readline().split()]        
            res = neighbor(E, estimate_vector)
            line = file.readline()
        final = time()
        array.append(final-initial)
    print(sum(array)/5)

