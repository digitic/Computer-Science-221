CXX = g++
# CCFLAGS = -g -std=c++14
CCFLAGS = -std=c++14  -Wall -Wextra -pedantic


# this is a "Suffix Rule" - how to create a .o from a .cc file
.cc.o:
	$(CXX) $(CCFLAGS) -c $<

highest: highest.o
	$(CXX) $(CCFLAGS) -o highest highest.o

all: source-stats.wc highest

%-stats.wc: %.txt
	wc $< > $<-stats.wc

clean:
	rm -f *.o
	# rm testfile
	rm highest
	rm -f *-stats.wc
