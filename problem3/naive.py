import sys
from time import time
def naive_get_nearest_neighbors(E:float, estimate_vector:list[float])->list[float]:
    distance_map = [((E - float(val)) ** 2, idx) for idx, val in enumerate(estimate_vector)]
    distance_map.sort()
    return [idx for dist, idx in distance_map[:6]]
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
            res = naive_get_nearest_neighbors(E, estimate_vector)
            line = file.readline()
        final = time()
        array.append(final-initial)
    print(sum(array)/5)

