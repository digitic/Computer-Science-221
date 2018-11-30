#include "htree.cc"

int main()
{
    auto root = HTree(1, 6, 
        std::make_shared<HTree>(2, 10,
            std::make_shared<HTree>(3, 4, nullptr, nullptr),
            std::make_shared<HTree>(4, 13, nullptr, nullptr)),
        std::make_shared<HTree>(5, 20, 
            nullptr,
            std::make_shared<HTree>(6, 100, nullptr, nullptr)));

    std::cout << root.get_key() << "\n";
    std::cout << root.get_value() << "\n";

    root.printPath(4);
    root.printPath(6);
    root.printPath(1);
}