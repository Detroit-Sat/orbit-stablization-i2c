CC = g++
CFLAGS  = -std=c++11
OBJS = *.o

default: all

all: orbit-stabilization

orbit-stabilization: bno055.o gyro.o light-sensor.o orbit-stabilization.o
	$(CC) $(CFLAGS) -o orbit-stabilization bno055.o gyro.o light-sensor.o orbit-stabilization.o

orbit-stabilization.o: orbit-stabilization.cpp
	$(CC) $(CFLAGS) -c orbit-stabilization.cpp

bno055.o: modules/bno055.c modules/bno055.h
	$(CC) $(CFLAGS) -c modules/bno055.c

gyro.o: modules/gyro.cpp modules/gyro.h
	$(CC) $(CFLAGS) -c modules/gyro.cpp

light-sensor.o: modules/light-sensor.cpp modules/light-sensor.h
	$(CC) $(CFLAGS) -c modules/light-sensor.cpp

clean:
	find . -type f | xargs touch
	rm -rf $(OBJS)