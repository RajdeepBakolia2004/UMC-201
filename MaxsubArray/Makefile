CC = gcc
CFLAGS = -Wall -shared -fPIC -O3
all : linear.so MSS1.so MSS2.so naive1.so naive2.so 
linear.so : linear.c
	$(CC) $(CFLAGS) -o linear.so linear.c
MSS1.so : MSS1.c
	$(CC) $(CFLAGS) -o MSS1.so MSS1.c
MSS2.so : MSS2.c
	$(CC) $(CFLAGS) -o MSS2.so MSS2.c
naive1.so : naive1.c
	$(CC) $(CFLAGS) -o naive1.so naive1.c
naive2.so : naive2.c
	$(CC) $(CFLAGS) -o naive2.so naive2.c
clean :
	rm -f largeint.so

