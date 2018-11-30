CXX = g++
CCFLAGS = -g -std=c++14

# this is a "Suffix Rule" - how to create a .o from a .cc file
.cpp.o:
	$(CXX) $(CCFLAGS) -c $<

highest: highest.o
	$(CXX) -o highest highest.o

all: %-stats.wc highest

%-stats.wc: %.txt
	wc $< > $@

clean:
	rm -f *.o
	rm -f *-stats.wc
