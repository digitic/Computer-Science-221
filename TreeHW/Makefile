CXX = g++
# CCFLAGS = -g -std=c++14
CCFLAGS = -std=c++14  -Wall -Wextra -pedantic -Werror


# this is a "Suffix Rule" - how to create a .o from a .cc file
.cc.o:
	$(CXX) $(CCFLAGS) -c $<

testTree: testTree.o
	$(CXX) $(CCFLAGS) -o testTree testTree.o

all: testTree

clean:
	rm -f *.o
	
