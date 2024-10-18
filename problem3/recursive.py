import sys
from time import time
def recursive_get_nearest_neighbors(E, estimate_vector):
    def recursive_get_nearest_neighbors_helper(E, estimate_vector):
        #base case
        if len(estimate_vector) <= 6:
            return (sorted([[(ele-E)**2,index] for index,ele in enumerate(estimate_vector)])+[[float("inf"),None]])
        else:
            n = len(estimate_vector)//2
            res1 = recursive_get_nearest_neighbors_helper(E, estimate_vector[:n])
            res2 = recursive_get_nearest_neighbors_helper(E, estimate_vector[n:])
            pointer1,pointer2 = 0,0
            result = []
            for _ in range(6):
                if res2[pointer2][0] < res1[pointer1][0]:
                    result.append([res2[pointer2][0],res2[pointer2][1]+n])
                    pointer2 += 1
                else:
                    result.append([res1[pointer1][0],res1[pointer1][1]])
                    pointer1 += 1
            result.append([float("inf"),None])
            return result
    res = recursive_get_nearest_neighbors_helper(E,estimate_vector)
    result = [ind for val,ind in res if val < float("inf")]
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
            res = recursive_get_nearest_neighbors(E, estimate_vector)
            line = file.readline()
        final = time()
        array.append(final-initial)
    print(sum(array)/5)


