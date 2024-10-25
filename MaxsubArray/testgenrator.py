#write a python code that ask for input n and creste a list of n random numer and save it in a file whose name is input by user the number should be random between -1000 to 1000

import random
n = int(input("Enter the number of elements: "))
name = str(input("Enter the name of the file: "))
arr = [random.randint(-1000, 1000) for i in range(n)]
file = open(name, "w")
file.write(str(arr))
file.close()
print("File created successfully")
