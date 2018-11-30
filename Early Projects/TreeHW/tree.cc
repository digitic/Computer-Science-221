#include "tree.hh"
#include <iostream>
#include <cassert>

// Located below path_to
bool isValueHere(tree_ptr_t, key_t);

tree_ptr_t create_tree(const key_t& key, const value_t& value, tree_ptr_t left, tree_ptr_t right)
{
    tree_ptr_t createdTree = new Tree({key, value, left, right});
    return createdTree;
}

void destroy_tree(tree_ptr_t tree)
{
    if(tree == nullptr)
    {
        return;
    }
    if(tree->left_ != nullptr)
    {
        destroy_tree(tree->left_);
    }

    if(tree->right_ != nullptr)
    {
        destroy_tree(tree->right_);
    }
    delete tree;
    return;
}

std::string path_to(tree_ptr_t tree, key_t key)
{
    if(tree == nullptr)
    {
        return "";
    }
    std::string path = "";
    if(tree->key_ == key)
    {
        return path;
    }
    if(tree->left_ != nullptr)
    {
        if(isValueHere(tree->left_, key))
        {
            return "L" + path_to(tree->left_, key);
        }
    }
    if(tree->right_ != nullptr)
    {
        if(isValueHere(tree->right_, key))
        {
            return "R" + path_to(tree->right_, key);
        }
    }
    assert(false);
}

//Helper function to path_to, determines if key exists in given tree.
bool isValueHere(tree_ptr_t tree, key_t key)
{
    if (tree->key_ == key)
    {
        return true;
    }
    if(tree->left_ != nullptr)
    {
        if(isValueHere(tree->left_, key))
        {
            return true;
        }
    }

    if(tree->right_ != nullptr)
    {
        if(isValueHere(tree->right_, key))
        {
            return true;
        }
    }
    return false;
}

tree_ptr_t node_at(tree_ptr_t tree, std::string path)
{
    if(tree == nullptr)
    {
        return nullptr;
    }
    if(path == "")
    {
        return tree;
    }
    for(auto c : path)
    {
        if(tree->left_ and c == 'L')
        {
            tree = tree->left_;        
        }
        else if(tree->right_ and c == 'R')
        {
            tree = tree->right_;
        }
        else
        {
            return nullptr;
        }
    }
    return tree;
}



