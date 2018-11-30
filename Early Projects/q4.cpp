#include <iostream>

int main()
{
    std::cout << "Enter the non-base number.\n";
    int n = 0;
    std::cin >> n;
    std::cout << "Enter the base of the logarithm.\n";
    int b = 0;
    std::cin >> b;
    bool checkPos(int, int);
    int log(int, int);
    if(checkPos(n, b))
    {
        std::cout << "" << log(n, b);
    }
    else
    {
        std::cout << "Both inputs must be positive.\n";
    }
    return 0;
}

int log(int num, int base)
{
    int power = 0;
    int baseToPower = 1;
    while(baseToPower < num)
    {
        power++;
        baseToPower *= base;
    }
    if(baseToPower > num)   // This makes sure to use the floor value of log.
    {
        power--;
    }
    return power;
}

bool checkPos(int num1, int num2)
{
    if(num1 > 0)
    {
        if(num2 > 0)
        {
            return true;
        }
    }
    return false;
}