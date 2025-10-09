#include <iostream>

#include "hashtable.hpp"

int main() {
    mystd::HashTable<int> table(3);
    table.insert(1);
    table.insert(2);
    table.insert(3);
    table.insert(4);
    table.insert(5);
    table.insert(6);

    table.printTable();
    return 0;
}