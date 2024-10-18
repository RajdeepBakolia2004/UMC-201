import sys
import heapq
import random
def neighbor(E,vector):
    square = [[(E-element)**2,index] for index,element in enumerate(vector)]
    heapq.heapify(square)
    result = []
    for i in range(min(6,len(vector))):
        result.append((heapq.heappop(square))[1])
    return result
def create_stable_min_heap(tuple_list):
    heapq.heapify(tuple_list)
    return [heapq.heappop(tuple_list) for _ in range(len(tuple_list))]

def heap_to_sorted_indices(min_heap):
    sorted_list = [heapq.heappop(min_heap) for _ in range(len(min_heap))]
    new_sorted_list = [(-dist, -idx) for dist, idx in sorted_list]
    new_sorted_list.sort()
    return [idx for _, idx in new_sorted_list]

def optimized_get_nearest_neighbors(E, estimate_vector):
    n = len(estimate_vector)
    
    # If <= 6 elements, just sort and return all indices as per original code
    if n <= 6:
        distance_map = [((E - float(val)) ** 2, idx) for idx, val in enumerate(estimate_vector)]
        distance_map.sort()
        return [idx for dist, idx in distance_map[:6]]
    else:
        distance_list = []
        for i in range(6):
            distance_list.append((-((E - estimate_vector[i]) ** 2), -i))
        heap = create_stable_min_heap(distance_list)

    # Track the maximum distance (least value in heap)
    max_dist = -heap[0][0]

    # Process the remaining elements beyond the first 6 
    for i in range(6, n):
        dist = (E - estimate_vector[i]) ** 2
        
        if dist < max_dist:
            heapq.heappushpop(heap, (-dist, -i))  # Push new element, pop the largest distance 
            max_dist = -heap[0][0]  # Update max distance
        
    # Extract the indices of the 6 nearest neighbors from the heap
    return heap_to_sorted_indices(heap)
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
def get_nearest_neighbors(E:float, estimate_vector:list[float])->list[float]:
    if len(estimate_vector) <= 6:
        distance_map = [((E - float(val)) ** 2, idx) for idx, val in enumerate(estimate_vector)]
        distance_map.sort()
        return [idx for dist, idx in distance_map[:6]]
    else:
        result = []
        for index in range(6):
            result.append([(E - float(estimate_vector[index])) ** 2, index])
        result.sort()
        for index in range(6, len(estimate_vector)):
            if (E - float(estimate_vector[index])) ** 2 < result[-1][0]:
                result.pop()
                result.append([(E - float(estimate_vector[index])) ** 2, index])
                result.sort()
        return [idx for dist, idx in result]
def naive_get_nearest_neighbors(E:float, estimate_vector:list[float])->list[float]:
    distance_map = [((E - float(val)) ** 2, idx) for idx, val in enumerate(estimate_vector)]
    distance_map.sort()
    return [idx for dist, idx in distance_map[:6]]
if __name__ == "__main__":
    filename = sys.argv[1]
    file = open(filename)
    line = file.readline()
    while line != "end\n":
        E = float(line)
        estimate_vector = [float(ele) for ele in file.readline().split()]        
        res1 = naive_get_nearest_neighbors(E, estimate_vector)
        res2 =recursive_get_nearest_neighbors(E, estimate_vector)
        res3 = get_nearest_neighbors(E, estimate_vector)
        res4 = optimized_get_nearest_neighbors(E, estimate_vector)
        res5 = neighbor(E,estimate_vector)
        if res1 == res2 and res2 == res3 and res3 == res4 and res4 == res5:
            pass
        else:
            print(res1,res2,res3,res4,res5,sep = '\n')
            break
        line = file.readline()
    else:
        print(True)

