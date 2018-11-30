#include <iostream>
#include <initializer_list>

const int* highest(int val, const int* start, const int* finish)
{
    if(start == nullptr)
    {
        return nullptr;
    }
    if(start == finish)
    {
        if(val == *start)
        {
            return start;
        }
        else
        {
            return nullptr;
        }
    }
    else
    {
        const int* median = start + ((finish - start) / 2);
        if (*median == val)
        {
            while (*(median + 1) == val)
            {
                median++;
            }
            return median;
        }
        else if (val > *median)
        {
            return highest(val, median, finish);
        }
        else if (val < *median)
        {
            return highest(val, start, median);
        }
    return nullptr;
    }
}

#include <iostream>

int main()
{
    const int DATA_LEN = 9;
    const int data[DATA_LEN] = { 1, 1, 1, 4, 4, 5, 6, 7, 10 };

    for (auto search : { 0, 1, 2, 4, 7, 8, 9, 10, 11 }) {
        const auto where = highest(search, data, data + DATA_LEN);
        std::cout << "Index of elem: " << search << " is: ";
        if (where == nullptr) {
            std::cout << "not found!" << std::endl;
        } else {
            std::cout << (where-data) << std::endl;
        }

    }
    return 0;

}
