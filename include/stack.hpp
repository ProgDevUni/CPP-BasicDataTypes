#ifndef MYSTD_STACK_HPP
#define MYSTD_STACK_HPP

#include <vector>

namespace mystd {

    template <typename T>
    class Stack {
        private:
            std::vector<T> data;
        public:
            bool empty() const;
            size_t size() const;
            void push(const T& value);
            T& peek();
            const T& peek() const;
            T& pop();
    };
}

#include "stack.tpp"

#endif //STACK_HPP