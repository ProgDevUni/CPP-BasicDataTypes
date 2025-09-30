#ifndef UTIL_HPP
#define UTIL_HPP

#include <vector>

namespace mystd {
    // vector
    template <typename T>
    T findMin(std::vector<T> &vec);

    template <typename T>
    T findMax(std::vector<T> &vec);

    template <typename T>
    int binarySearch(std::vector<T> &vec, T goal);

    template <typename T>
    void printVector(std::vector<T> &vec);

    //array
    template <typename T>
    T findMin(T arr[], int n);

    template <typename T>
    T findMax(T arr[], int n);

    template <typename T>
    int binarySearch(T arr[], int n, T goal);

    template <typename T>
    void printArray(T arr[], int n);
}

#include "util.tpp"
#endif //UTIL_HPP