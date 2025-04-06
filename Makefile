CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -fstack-protector

DEBUG_FLAGS = -O0 -ggdb3 -D_DEBUG
RELEASE_FLAGS = -O2 -DNDEBUG

CXXFLAGS += $(DEBUG_FLAGS)
##CXXFLAGS = $(RELEASE_FLAGS)

CXX = g++

run:       ./bin/main.o ./bin/bin_tree.o ./bin/func.o ./bin/html.o ./bin/akinator.o ./bin/dump.o
	$(CXX) ./bin/main.o ./bin/bin_tree.o ./bin/func.o ./bin/html.o ./bin/akinator.o ./bin/dump.o $(CXXFLAGS) -o main

./bin/main.o:   src/main.c h/bin_tree.h h/dump.h h/html.h
	$(CXX) -c ./src/main.c $(CXXFLAGS) -o ./bin/main.o

./bin/bin_tree.o: src/bin_tree.c h/bin_tree.h
	$(CXX) -c ./src/bin_tree.c $(CXXFLAGS) -o ./bin/bin_tree.o

./bin/func.o: src/func.c h/func.h
	$(CXX) -c ./src/func.c $(CXXFLAGS) -o ./bin/func.o

./bin/html.o: src/html.c h/html.h
	$(CXX) -c ./src/html.c $(CXXFLAGS) -o ./bin/html.o

./bin/akinator.o: src/akinator.c h/bin_tree.h
	$(CXX) -c ./src/akinator.c $(CXXFLAGS) -o ./bin/akinator.o

./bin/dump.o: src/dump.c h/dump.h
	$(CXX) -c ./src/dump.c $(CXXFLAGS) -o ./bin/dump.o

clean:
	rm -f main ./bin/*.o ./bin/png/*.png