CXX = g++-8
# CCFLAGS = -g -std=c++14
CCFLAGS = -std=c++14  -Wall -Wextra -pedantic -Werror


# this is a "Suffix Rule" - how to create a .o from a .cc file
.cc.o:
	$(CXX) $(CCFLAGS) -c $<

htree: htree.o
	$(CXX) $(CCFLAGS) -o htree htree.o

all: htree

clean:
	rm -f *.o
	
