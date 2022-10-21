all: main

main:  pid.o main.o
	g++ -o main pid.o main.o

pid.o: ../pid.cpp ../pid.hpp
	g++ -c ../pid.cpp

main.o: main.cpp
	g++ -c main.cpp

.PHONY: clean
clean: 
	rm main main.o pid.o 