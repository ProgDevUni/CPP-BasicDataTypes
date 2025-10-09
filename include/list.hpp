#ifndef LIST_HPP
#define LIST_HPP

#include <cctype>

namespace mystd {
    namespace {
        template <typename T>
        class Node {
            public:
                Node *next;
                T value;
        };
    }

    template <typename T>
    class List {
        private:
            Node<T> *head;
            std::size_t count;
        
        public:
            bool empty() const;
            std::size_t size() const;

            void pushFront(const T& value);
            void pushBack(const T& value);
            void insertAt(int index, const T& value);

            void removeFront();
            void removeBack();
            void removeAt(int index);

            T& getFront();
            T& getBack();
            T& getAt(int index);

            int find(const T& value);
            bool contains(const T& value);
            
            void printForward();
            void printBackward();

        List() {
            count = 0;
            head = nullptr;
        }
    };
}

#include "list.tpp"

#endif