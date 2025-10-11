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
            if (buckets[q].slot == StatusSlot::Empty || buckets[q].slot == StatusSlot::Deleted) {
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

        for (int i=0;i<oldCapacity;i++) {
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
        for (int i=0;i<capacity;i++) {
            std::size_t q = hash(value, i);
            if (buckets[q].value == value) {
                buckets[q].value = T();
                buckets[q].slot = StatusSlot::Deleted;
                return;
            }
        }
    }

    template <typename T>
    bool HashTable<T>::find(const T& value, T* result) {
        for (int i=0;i<capacity;i++) {
            std::size_t q = hash(value, i);
            if (buckets[q].value == value) {
                *result = buckets[q].value;
                return true;
            }
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

/*

mystd::HashTable<int> table(4);
    table.insert(1);
    table.insert(2);
    table.insert(3);
    table.insert(4);
    table.insert(5);
    table.insert(6);

    std::cout << "SIZE: " << table.size() << std::endl;
    std::cout << "IS EMPTY: " << (table.empty() ? "YES" : "NO") << std::endl;

    std::cout << "====FIND TEST===" << std::endl;
    int res;

    std::cout << "FIND FOR 30     ";
    if (table.find(30, &res)) {
        std::cout<<"\t"<<res<<std::endl;
    }
    else{
        std::cout<<"\tNO"<<std::endl;
    }

    std::cout << "FIND FOR 20     ";
    if (table.find(20, &res)) {
        std::cout<<"\t"<<res<<std::endl;
    }
    else{
        std::cout<<"\tNO"<<std::endl;
    }

    std::cout << "FIND FOR 1     ";
    if (table.find(1, &res)) {
        std::cout<<"\t"<<res<<std::endl;
    }
    else{
        std::cout<<"\tNO"<<std::endl;
    }

    std::cout << "FIND FOR 2     ";
    if (table.find(2, &res)) {
        std::cout<<"\t"<<res<<std::endl;
    }
    else{
        std::cout<<"\tNO"<<std::endl;
    }


    std::cout<<"=====REMOVE TEST====" <<std::endl;
    table.remove(1);
    table.remove(5);
    std::cout << "SIZE: " << table.size() << std::endl;
    std::cout << "IS EMPTY: " << (table.empty() ? "YES" : "NO") << std::endl;
    
    std::cout<<"=====REINSERT TEST====" <<std::endl;
    table.insert(30);
    table.insert(40);
    std::cout << "SIZE: " << table.size() << std::endl;
    std::cout << "IS EMPTY: " << (table.empty() ? "YES" : "NO") << std::endl;

    std::cout<<"===REMOVE ALL===" <<std::endl;
    table.remove(40);
    table.remove(30);
    table.remove(2);
    table.remove(3);
    table.remove(4);
    table.remove(6);
    std::cout << "IS EMPTY: " << (table.empty() ? "YES" : "NO") << std::endl;
*/