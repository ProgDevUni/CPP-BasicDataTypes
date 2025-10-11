#include <iostream>

#include "bst.hpp"

void printNode(int value) {
    std::cout << value << " ";
}

int main() {
    mystd::BSTree<int> tree;
    tree.insert(1);
    tree.insert(9);
    tree.insert(5);
    tree.insert(11);
    tree.insert(3);
    tree.insert(4);
    tree.insert(6);

    tree.remove(5);
    tree.insert(7);

    tree.inorder(printNode);
    std::cout << "\n=====\n";
    tree.preorder(printNode);
    return 0;
}