#ifndef BST_HPP
#define BST_HPP

#include <functional> //for std::function

namespace mystd {
    namespace {
        template <typename T>
        class Node {
            public:
                T value;
                Node<T>* left;
                Node<T>* right;
        };
    }

    template <typename T>
    class BSTree{
        private:
            Node<T>* root = nullptr;
        
        public:
            void insert(const T& value);
            void remove(const T& value);
            bool contains(const T& value);

            int size();
            bool empty();

            void inorder(const std::function<void (const T&)>& visit) const;
            void preorder(const std::function<void (const T&)>& visit) const;
            void postrder(const std::function<void (const T&)>& visit) const;

            T min();
            T max();
    };
}

#include "bst.tpp"

#endif