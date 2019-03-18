all:asdf.exe test

asdf.exe: main.cpp MemoryLeakChecker.cpp
	g++ -o asdf -std=c++11 main.cpp MemoryLeakChecker.cpp
test: asdf.exe
	./asdf.exe