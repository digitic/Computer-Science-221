#include "tournament_deme.hh"
#include <algorithm>

Chromosome* TournamentDeme::select_parent()
{
    unsigned poolTotal = pow(2, power_);
    while(poolTotal > pop_.size())
    {
        poolTotal /= 2;
    }

    std::vector<Chromosome*> parentPool;
    for(unsigned i = 0; i < poolTotal; i++)
    {
        auto parent = Deme::select_parent();
        //If the parent is already in the pool
        if(std::find(parentPool.cbegin(), parentPool.cend(), parent) != parentPool.cend())
        {
            i--;
        }
        else
        {
            parentPool.push_back(parent);
        }
    }

    std::vector<Chromosome*> tempVector = parentPool;
    while(tempVector.size() != 1)
    {
        auto poolEnd = parentPool.end();
        for(unsigned j = 0; j < poolTotal; j += 2)
        {
            auto parent1 = tempVector[j];
            auto parent2 = tempVector[j+1];
            if(parent1->get_fitness() < parent2->get_fitness())
            {
                tempVector.push_back(parent2);
            }
            else
            {
                tempVector.push_back(parent1);
            }
        }
        tempVector.erase(tempVector.begin(), poolEnd);
    }
    return tempVector[0];
}