CC = g++
FLAGS = -Wall -lGL -lGLU -lglut -lm -larmadillo -O3
binaries = test main

projet: main.o
		$(CC) *.cpp -o main.o $(FLAGS)

.PHONY: clean

clean: 
		rm -rf *.o $(binaries)