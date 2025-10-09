#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <cctype>

namespace mystd {
    namespace {
        enum class StatusSlot {
            Empty, 
            Occupied,
            Deleted
        };

        template <typename T>
        class Entry {
            public:
                T value;
                StatusSlot slot;
        };
    }

    template <typename T>
    class HashTable {
        private:
            int capacity;
            Entry<T>* buckets;

            std::size_t hash(const T& value, int i) const;
            void insertWithoutResize(const T& value);
            void resizeTable(int newCapacity);

        public:
            HashTable(int cap) {
                capacity = cap;
                buckets = new Entry<T>[cap];
            }

            void insert(const T& value);
            void remove(const T& value);
            bool find(const T& value, T* result);

            std::size_t size();
            bool empty();

            void printTable();
    };
}

#include "hashtable.tpp"

#endif