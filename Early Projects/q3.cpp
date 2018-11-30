#include <iostream>

int main()
{
    std::cout << "Enter your base.\n";
    int b = 0;
    std::cin >> b;
    std::cout << "Enter your exponent.\n";
    int e = 0;
    std::cin >> e;
    bool checkPos(int, int);
    int pow(int, int);
    if(checkPos(b,e))
    {
        std::cout << "" << pow(b, e) << " is " << b << " to the exponent of " << e;
    }
    else
    {
        std::cout << "Both inputs must be positive.\n";
    }
    return 0;
}

int pow(int base, int exponent)
{
    if(exponent > 1)
    {
        return base * pow(base, exponent-1);
    }
    else
    {
        return base;
    }
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




