#include "hforest.hh"
#include <cassert>
#include <iostream>
#include <algorithm>
#include <climits>

HForest::HForest()
{
}

bool compare_trees(HForest::tree_ptr_t, HForest::tree_ptr_t);

int HForest::get_size() const
{
    return size_;
}

void HForest::add_tree(tree_ptr_t tree)
{
    if(tree == nullptr)
    {
        return;
    }
    forest_.push_back(tree);
    std::make_heap(forest_.begin(), forest_.end(), compare_trees);
    size_++;
    return;
}

HForest::tree_ptr_t HForest::pop_tree()
{
    uint64_t highVal = 0;
    tree_ptr_t maxTree;
    int currPos = 0;
    int maxPos = 0;
    for(auto elem : forest_)
    {
        if(elem->get_value() > highVal)
        {
            highVal = elem->get_value();
            maxTree = elem;
            maxPos = currPos;
        }
        currPos++;
    }
    forest_.erase(forest_.begin() + maxPos);
    size_--;
    std::make_heap(forest_.begin(), forest_.end(), compare_trees);
    return maxTree;
}

bool compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2){
    return t1->get_value() < t2->get_value();
}