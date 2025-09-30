#include <iostream>

#include "stack.hpp"

int main() {
    mystd::Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    for (int i=0;i<4;i++) {
        std::cout << stack.pop() << " ";
    }
    std::cout<<std::endl<<stack.empty()<<std::endl;
    stack.push(-13);
    stack.push(-45);
    stack.push(100);
    stack.push(12222);
    std::cout << stack.size() << " " << stack.peek();
    return 0;
}