#include "cities.hh"
#include <math.h>

Cities Cities::reorder(const permutation_t& ordering) const
{
    Cities output;
    for(auto i : ordering)
    {
        output.cityList_.push_back(this->cityList_.at(i));
    }
    return output;
}

double Cities::total_path_distance(const Cities::permutation_t& ordering) const
{
    
}

std::istream& Cities::operator>>(std::istream& is)
{
    is >> cityList_.push_back(is);
}

double get_distance(const coord_t city1, const coord_t city2)
{
    auto a = pow(city2.first - city1.first, 2);
    auto b = pow(city2.second - city1.second, 2);
    auto result = sqrt(a+b);
    return result;
}

std::ostream& Cities::operator<<(std::ostream& os)
{
    for(int i = 0; i < cityList_.size(), i++)
    {
        os << cityList_.at(cityList_.begin() + i);
    }
}