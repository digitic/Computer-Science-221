//HForest: A collection of HTree objects, arranged in a heap.
#pragma once

#include <memory>
#include <list>
#include "htree.cc"
#include <vector>

class HForest {
 public:
  using tree_ptr_t = std::shared_ptr<const HTree>;

  // Initialize with no parameters:
  HForest();
  ~HForest() = default;

  int get_size() const; // Return size.
  void add_tree(tree_ptr_t tree); // Adds a tree to the forest, doesn't return anything.
  tree_ptr_t pop_tree(); // Removes and returns tree with highest root-node value in the forest.

  private:
    int size_ = 0;
    std::vector<tree_ptr_t> forest_;

};