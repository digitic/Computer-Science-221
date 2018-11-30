CXX = g++-8
# CCFLAGS = -g -std=c++14
CCFLAGS = -std=c++14  -Wall -Wextra -pedantic -Werror


# this is a "Suffix Rule" - how to create a .o from a .cc file
.cc.o:
	$(CXX) $(CCFLAGS) -c $<

#htree: testHtree.o
	#$(CXX) $(CCFLAGS) -o testHtree testHtree.o

testHforest: testHforest.o
	$(CXX) $(CCFLAGS) -o testHforest testHforest.o

all: htree testHforest

clean:
	rm -f *.o
	
