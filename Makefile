CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic

problem: dijkstras.o src/dijkstras_main.cpp
	g++ $(CXXFLAGS) dijkstras.o src/dijkstras_main.cpp -o problem

main: src/dijkstras_main.cpp
	g++ $(CXXFLAGS) src/dijkstras_main.cpp -o main

dijkstras.o: src/dijkstras.cpp src/dijkstras.h
	g++ $(CXXFLAGS) -c src/dijkstras.cpp -o dijkstras.o

clean:
