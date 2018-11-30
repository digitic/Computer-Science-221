#include <iostream>

int main()
{
    std::cout << "Enter the first integer.\n";
    int firstInt = 0;
    std::cin >> firstInt;
    std::cout << "Enter the second integer.\n";
    int secondInt = 0;
    std::cin >> secondInt;
    std::cout << "Enter the third integer.\n";
    int thirdInt = 0;
    std::cin >> thirdInt;
    int larger(int, int);
    std::cout << "The largest int is: " << larger(firstInt, larger(secondInt, thirdInt)) << ".\n"; 
    return 0;
}

int larger(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}