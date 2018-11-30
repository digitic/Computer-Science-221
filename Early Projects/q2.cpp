#include <iostream>

int main()
{
    std::cout << "Enter your base number now.\n";
    int num = 0;
    std::cin >> num;
    int counter = 0;    // Counter will keep track of how many nums are mults of base.
    int compare = 0;    // Compare will mark the most recently entered number.
    bool isMultiple(int, int);
    for(int x = 1; x <= 10; x++)
    {
        std::cout << "Enter another number.";
        std::cin >> compare;
        if(isMultiple(compare, num))
        {
            counter++;
        }
    }
    std::cout << "" << counter << " of those numbers were multiples of " << num << ".\n";
    return 0;
}

bool isMultiple(int multipleOf, int base)
{
    if(multipleOf % base == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}