npoints (Returned estimate) [Time]
10      (3.52)              [0.005s]
100     (3.1812)            [0.005s]
1000    (3.14554)           [0.016s]
10000   (3.14199)           [0.862s]

Complexity:
This function is O(n^3), or cubic time (assuming hypotenuse runs linearly).
The only non-constant operations are two while loops (X and Y 'coordinates', respectively) and the hypotenuse function. All three are linear (O(n)), so in total the function is O(n^3).

Notes on Timing:
These values do seem to match my expectations of being O(n^3), although they're a bit extreme. As the number gets larger, the time it takes skyrockets (looking at you, 10000), but it starts out taking almost no time.

Compile Time:
npoints (Returned estimate) [Time]
10      (3.52)              [0.005s]
100     (3.1812)            [0.005s]
1000    (3.14554)           [0.016s]
10000   (3.14199)           [0.859s]

Notes on Compile Time:
What follows is the line I used to compile the second version of pi.

g++ -std=c++14 -O3 -Wall -Wextra -pedantic compiletimepi.cc -o pi2

Something that bugs me is that it accepted the code with only the declaration changed. At first I didn't have the -std=c++14 line, and the compiler threw errors at me saying that it didn't know what constexpr was. At first I tried c++11, but I got a few warnings that declaring a variable inside the constexpr function was c++14 functionality (and also an error that a while loop wasn't allowed), so I changed it to c++14 and it just accepted the code as is. Nothing seems to have changed, except that the 10000 estimate got 0.003 seconds faster, but that could just be a mistake in timing it.
