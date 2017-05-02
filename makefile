CC = g++
CFLAGS = -o

all: read generator

read: led_read.cpp
	$(CC) $(CFLAGS) read led_read.cpp 

generator: led_generate.cpp
	$(CC) $(CFLAGS) generator led_generate.cpp

clean:
	rm read generator
