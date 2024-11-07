import splay
from random import randint,random
from time import time
import random

def generate_list(m, c):
    # Calculate the number of 1's
    count_ones = int(c * m)
    
    # Create a list with `count_ones` 1's and the remaining 0's
    result = [1] * count_ones + [0] * (m - count_ones)
    
    # Shuffle the list to randomize the order
    random.shuffle(result)
    
    return result



def main():
    array = eval(input("enter the number n of elements in the array eg[100,500...]: "))
    c = float(input("enter a number between 0 and 1"))
    file = open("output.txt","a")
    for n in array:
        s = splay.SplayTree()
        values = []
        while len(values) < n:
            value = randint(0, n)
            if value not in values:
                values.append(value)
                s.insert(value)
        m = n*100
        key = values[randint(0,n-1)]
        array = generate_list(m,c)
        time_taken = 0
        no_of_search = 0
        for i in array:
            if i == 1:
                initial = time()
                s.search(key)
                time_taken = time() - initial
                no_of_search += 1
            else:
                temp = values[randint(0,n-1)]
                while temp == key:
                    temp = values[randint(0,n-1)]
                else:
                    s.search(temp)
        
        if no_of_search == 0:
            continue
        time_taken = time_taken/no_of_search
        file.write(str(n)+ "   "+str(time_taken)+'\n')
    file.close()



if __name__ == "__main__":
    main()
