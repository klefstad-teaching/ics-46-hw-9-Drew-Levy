CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic

problem: ladder.o src/ladder_main.cpp
	g++ $(CXXFLAGS) ladder.o src/ladder_main.cpp -o problem

main: src/ladder_main.cpp
	g++ $(CXXFLAGS) src/ladder_main.cpp -o main

ladder.o: src/ladder.cpp src/ladder.h
	g++ $(CXXFLAGS) -c src/ladder.cpp -o ladder.o

clean: