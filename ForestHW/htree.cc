#include "htree.hh"
#include <cassert>
#include <iostream>

HTree::HTree(int key,
        uint64_t value,
        tree_ptr_t left,
        tree_ptr_t right)
        {
            key_ = key;
            value_ = value;
            left_ = left;
            right_ = right;
        }

int HTree::get_key() const {return key_;}
uint64_t HTree::get_value() const {return value_;}

HTree::tree_ptr_t HTree::get_child(Direction dir) const
{
    if(dir == Direction::LEFT and left_)
    {
        return left_;
    }
    else if(dir == Direction::RIGHT and right_)
    {
        return right_;
    }
    return nullptr;
}

HTree::path_t HTree::path_to(int key) const
{
    path_t route;
    assert(isValueHere(key));
    if(left_ and left_->isValueHere(key))
    {
        route.push_back(Direction::LEFT);
        route.splice(route.end(), left_->path_to(key));
    }
    if(right_ and right_->isValueHere(key))
    {
        route.push_back(Direction::RIGHT);
        route.splice(route.end(), right_->path_to(key));
    }
    return route;
}

//Helper function for path_to, determines if key is in tree.
bool HTree::isValueHere(int key) const
{
    if (key_ == key)
    {
        return true;
    }
    if(left_ != nullptr)
    {
        if(left_->isValueHere(key))
        {
            return true;
        }
    }

    if(right_ != nullptr)
    {
        if(right_->isValueHere(key))
        {
            return true;
        }
    }
    return false;
}

void HTree::printPath(int key) const
{

    HTree::path_t path = path_to(key);
    for(auto elem : path)
    {
        if(elem == Direction::LEFT)
        {
            std::cout << 'L';
        }
        else if(elem == Direction::RIGHT)
        {
            std::cout << 'R';
        }
    }
    std::cout << "\n";
}

