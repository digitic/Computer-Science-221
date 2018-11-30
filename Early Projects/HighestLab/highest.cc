#include <iostream>
#include <initializer_list>

// using namespace std;
const int* highest(int val, const int* start, const int* finish)
{
    if(start == nullptr)
    {
        return nullptr;
    }
    if(finish - start == 1)
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
        if (val == *median)
        {
            auto x = 0;
            auto higherSame = true;
            while(median+x < finish and higherSame)
            {
                higherSame = false;
                for(; val == *(median+x); )
                {
                    higherSame = true;
                    x++;
                }
            }
            return start + ((finish - start) / 2) + x;
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

int main()
{
    const int DATA_LEN = 13;
    const int data[DATA_LEN] = {-4, -2, 0, 1, 1, 1, 4, 4, 5, 6, 7, 10, 500 };
    for (auto search : {-3, 0, 1, 2, 4, 7, 8, 9, 10, 11, 500}) {
        const auto where = highest(search, data, data + DATA_LEN);
        std::cout << "Index of elem: " << search << " is: ";
        if (where == nullptr) {
            std::cout << "not found!" << std::endl;
        } else {
            std::cout << (where-data-1) << std::endl;
        }

    }
    return 0;

}
