As I worked through the problems, I started by figuring out how I could use all of the variables given to us in the .hh file. From there I split the situations into cases, first finding relevant information about the current node, then its left child, then its right. 

Once I had all of that working error free, I went about trying to test and solve unusual cases. One case that popped up on every problem is if I was passed a null tree, the program would crash, so I built in special if checks for that case. Another problem with delete was that if I deleted a child of a larger tree, the parent would then point to nothing and crash. I asked Eitan about it and he said to assume we were deleting a root, which I suppose is a solution.

