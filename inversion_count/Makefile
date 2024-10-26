CC = gcc
CFLAGS = -Wall -shared -fPIC -O3
all : naive.so recursion1.so recursion2.so
naive.so : naive.c
	$(CC) $(CFLAGS) -o $@ $^
recursion1.so : recursion1.c
	$(CC) $(CFLAGS) -o $@ $^
recursion2.so : recursion2.c
	$(CC) $(CFLAGS) -o $@ $^
clean :
	rm -f largeint.so

