CC = g++
CFLAGS = -Wall -shared -fPIC

all: ultra_large_int.so

ultra_large_int.so: ultra_large_int.cpp ultra_large_int.h
	$(CC) $(CFLAGS) -o ultra_large_int.so ultra_large_int.cpp

clean:
	rm -f ultra_large_int.so
