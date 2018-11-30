#include "htree.hh"

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

bool isValueHere(tree_ptr_t, int);

int HTree::get_key() const {return key_;}
uint64_t HTree::get_value() const {return value_;}

HTree::tree_ptr_t HTree::get_child(Direction dir) const
{
    if(dir == LEFT and left_)
    {
        return left_;
    }
    else if(dir == RIGHT and right_)
    {
        return right_;
    }
    return nullptr;
}

HTree::path_t HTree::path_to(int key) const
{
    HTree::path_t route = NULL;
    assert(isValueHere(this, key));
    if(left and isValueHere(left, key))
    {
        route = LEFT + left->path_to(key)
    }
    if(right and isValueHere(right, key))
    {
        route = RIGHT + right->path_to(key)
    }
    return route
}

//Helper function for path_to, determines if key is in tree.
bool isValueHere(tree_ptr_t tree, int key)
{
    if (tree->key == key)
    {
        return true;
    }
    if(tree->left != nullptr)
    {
        if(isValueHere(tree->left, key))
        {
            return true;
        }
    }

    if(tree->right != nullptr)
    {
        if(isValueHere(tree->right, key))
        {
            return true;
        }
    }
    return false;
}