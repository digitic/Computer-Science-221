#pragma once
#include "deme.hh"


/*
This class inherits from the Deme class and overrides whatever is necessary in your judgement 
for your class to replace the parent selection algorithm. 

It can use either Chromosome or ClimbChromosome: experiment with both when you're done and pick the best one.
*/
class TournamentDeme : public Deme
{
public:
    TournamentDeme(const Cities* cities_ptr, unsigned pop_size, double mut_rate, const int power)
        : Deme(cities_ptr, pop_size, mut_rate), power_(power)
        {
            
        }

    virtual ~TournamentDeme() = default;
    
    virtual Chromosome* select_parent() override;

    

private:
    const int power_;
};
