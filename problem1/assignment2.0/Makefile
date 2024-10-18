CC = gcc
CFLAGS = -Wall -shared -fPIC -O3
all : largeint.so
largeint.so : large_int.c largeint.h 
	$(CC) $(CFLAGS) -o largeint.so large_int.c
clean :
	rm -f largeint.so

