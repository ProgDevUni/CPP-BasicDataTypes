#include <cctype>
#include <iostream>
#include <functional> //for std::hash

namespace mystd {
    namespace {
        int h2(int k, int m) {return 1+(k%m);}

        int h1(int k, int m) {return k%m;}
    }

    template <typename T>
    std::size_t HashTable<T>::hash(const T& value, int i) const{
        std::hash<T> hasher;
        int k = hasher(value);
        return (h1(k, capacity) + i*h2(k, capacity-1))%capacity;
    }

    template <typename T>
    void HashTable<T>::insertWithoutResize(const T& value) {
        for (int i = 0; i < capacity; ++i) {
            int q = hash(value, i);
            if (buckets[q].slot == StatusSlot::Empty || 
                buckets[q].slot == StatusSlot::Deleted) {
                buckets[q].value = value;
                buckets[q].slot = StatusSlot::Occupied;
                return;
            }
        }
    }

    template <typename T>
    void HashTable<T>::resizeTable(int newCapacity) {
        Entry<T>* newBuckets = new Entry<T>[newCapacity];
        for (int i=0;i<newCapacity;++i) {
            newBuckets[i].value = T();
            newBuckets[i].slot = StatusSlot::Empty;
        }

        Entry<T>* oldBuckets = buckets;
        int oldCapacity = capacity;
        
        capacity = newCapacity;
        buckets = newBuckets;

        for (int i=0;i<capacity;i++) {
            if (oldBuckets[i].slot == StatusSlot::Occupied) {
                insertWithoutResize(oldBuckets[i].value);
            }
        }

        delete[] oldBuckets;
    }

    template <typename T>
    void HashTable<T>::insert(const T& value) {
        for (int i=0;i<capacity;i++) {
            int q = hash(value, i);
            if (buckets[q].slot == StatusSlot::Empty || buckets[q].slot == StatusSlot::Deleted) {
                buckets[q].value = value;
                buckets[q].slot = StatusSlot::Occupied;
                return;
            }
        }
        
        resizeTable(capacity*2);
        insert(value);
    }

    template <typename T>
    void HashTable<T>::remove(const T& value) {
        int i=0;
        std::size_t q = hash(value, i);
        while (buckets[q].slot != StatusSlot::Empty) {
            if (buckets[q].value == value) {
                buckets[q].value = T();
                buckets[q].slot == StatusSlot::Deleted;
                return;
            }
            i++;
        }
    }

    template <typename T>
    bool HashTable<T>::find(const T& value, T* result) {
        int i=0;
        std::size_t q = hash(value, i);
        while (buckets[q].slot != StatusSlot::Empty) {
            if (buckets[q].value == value) {
                *result = buckets[q].value;
                return true;
            }
            i++;
        }
        return false;
    }

    template <typename T>
    std::size_t HashTable<T>::size(){
        std::size_t s = 0;
        for (int i=0;i<capacity;i++) {
            if (buckets[i].slot == StatusSlot::Occupied) {
                s++;
            }
        }
        return s;
    }

    template <typename T>
    bool HashTable<T>::empty() {return size() == 0;}

    template <typename T>
    void HashTable<T>::printTable() {
        for (int i=0;i<capacity;i++) {
            if (buckets[i].slot == StatusSlot::Occupied) {
                std::cout << buckets[i].value << " ";
            }
        }
        std::cout<<std::endl;
    }
}