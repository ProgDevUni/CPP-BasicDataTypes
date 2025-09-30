#ifndef SORT_HPP
#define SORT_HPP

#include <vector>

namespace mystd {
    //vector 
    template <typename T>
    void heapsort(std::vector<T> &vec);

    template <typename T>
    void quicksort(std::vector<T> &vec, int p, int r);

    template <typename T>
    void selectionSort(std::vector<T> &vec);

    template <typename T>
    void mergeSort(std::vector<T> &vec, int l, int r);


    // array
    template <typename T>
    void heapsort(T arr[], int n);

    template <typename T>
    void quicksort(T arr[], int p, int r);

    template <typename T>
    void selectionSort(T arr[], int n);

    template <typename T>
    void mergeSort(T arr[], int l, int r);
}

#include "sort.tpp"
#endif