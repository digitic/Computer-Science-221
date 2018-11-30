#include "tree.cc"
#include "tree.hh"

int main()
{
    // Create tree
    tree_ptr_t treeLL = create_tree(1, 5,nullptr,nullptr);
    tree_ptr_t treeLR = create_tree(2, 3,nullptr,nullptr);
    tree_ptr_t treeR = create_tree(3, -4,nullptr,nullptr);
    tree_ptr_t treeL = create_tree(4, 1, treeLL, treeLR);
    tree_ptr_t treeHead = create_tree(5, 14, treeL, treeR);
    // Path to tests (Does crash if invalid)
    std::cout << path_to(treeHead, 2);
    std::cout << "\n";
    std::cout << path_to(treeHead, 5);
    std::cout << "\n";
    std::cout << path_to(treeHead, 3);
    std::cout << "\n";
    // Node At tests (Crashes if invalid, tries to find nullptr's "key")
    tree_ptr_t newNode = node_at(treeHead, "LR");
    std::cout << newNode->key_;
    std::cout << "\n";
    newNode = node_at(treeHead, "");
    std::cout << newNode->key_;
    std::cout << "\n";
    newNode = node_at(treeHead, "LL");
    std::cout << newNode->key_;
    std::cout << "\n";
    // Destroy tree test
    destroy_tree(treeHead);
    // New, null tree
    tree_ptr_t blankTree = nullptr;
    
}