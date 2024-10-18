import random
file = open("input2.txt",'w')
for i in range(2000):
    E = random.uniform(-10000, 1000)
    file.write(str(E))
    file.write("\n")
    for _ in range(random.randint(500, 800)):
        file.write(str(random.uniform(-1000, 10000)))
        file.write(" ")
    file.write("\n")
file.write("end\n")
    
    
