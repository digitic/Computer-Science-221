#include "hforest.cc"
#include <iostream>

int main()
{
    // Make a bunch of trees
    auto root = std::make_shared<HTree> (HTree(1, 6, 
        std::make_shared<HTree>(2, 10,
            std::make_shared<HTree>(3, 4, nullptr, nullptr),
            std::make_shared<HTree>(4, 13, nullptr, nullptr)),
        std::make_shared<HTree>(5, 20, 
            nullptr,
            std::make_shared<HTree>(6, 100, nullptr, nullptr))));
    auto empty = std::make_shared<HTree> (HTree(0, 0, nullptr, nullptr));
    auto none = nullptr;
    auto rootBack = std::make_shared<HTree> (HTree(6, 1, 
        std::make_shared<HTree>(10, 2,
            std::make_shared<HTree>(4, 3, nullptr, nullptr),
            std::make_shared<HTree>(13, 4, nullptr, nullptr)),
        std::make_shared<HTree>(20, 5, 
            nullptr,
            std::make_shared<HTree>(100, 6, nullptr, nullptr))));
    auto max = std::make_shared<HTree> (HTree(0, 400, nullptr, nullptr));

    // Make the forest
    auto forest = HForest();
    // check size
    std::cout << "" << forest.get_size() << "\n";
    // add some trees
    forest.add_tree(root);
    forest.add_tree(none);
    forest.add_tree(empty);
    // check size again
    std::cout << "" << forest.get_size() << "\n";
    // add last tree
    forest.add_tree(rootBack);
    forest.add_tree(max);
    // check size again
    std::cout << "" << forest.get_size() << "\n";
    //Pop biggest, return its value.
    std::cout << "" << forest.pop_tree()->get_value() << "\n";
    std::cout << "" << forest.pop_tree()->get_value() << "\n";
    // check size again
    std::cout << "" << forest.get_size() << "\n";

}