import random
import heapq
import sys
from time import time


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
            res = optimized_get_nearest_neighbors(E, estimate_vector)
            line = file.readline()
        final = time()
        array.append(final-initial)
    print(sum(array)/5)


