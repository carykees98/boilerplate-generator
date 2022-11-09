all: main clean

main: src/main.cpp bpg.o
	g++ -std=c++17 src/main.cpp src/bpg.o -o builds/boilerplategen

bpg.o: src/bpg.h src/bpg.cpp
	g++ -std=c++17 -c src/bpg.cpp -o src/bpg.o

clean:
	rm src/bpg.o