#include <vector>
#include <iostream>

namespace mystd {
    // vector 
    template <typename T>
    T findMin(std::vector<T> &vec) {
        T min = vec[0];
        for (T val : vec) {
            if (val < min) {min = val;}
        }
        return min;
    }

    template <typename T>
    T findMax(std::vector<T> &vec) {
        T max = vec[0];
        for (T val : vec) {
            if (val > max) {max = val;}
        }
        return max;
    }

    template <typename T>
    int binarySearch(std::vector<T> &vec, T goal) {
        int st = 0;
        int fn = vec.size();
        while (st < fn) {
            int mid = (st+fn)/2;
            if (vec[mid] == goal) {return mid;}
            else if (vec[mid] > goal) {fn = mid;}
            else {st = mid+1;}
        }
        return -1;
    }

    template <typename T>
    void printVector(std::vector<T> &vec) {
        for (T val : vec) {
            std::cout<<val<<" ";
        }
        std::cout<<std::endl;
    }


    // array 
    template <typename T>
    T findMin(T arr[], int n) {
        T min = arr[0];
        for (int i=1; i < n; i++) {
            if (arr[i] < min) {min = arr[i];}
        }
        return min;
    }

    template <typename T>
    T findMax(T arr[], int n) {
        T max = arr[0];
        for (int i=1; i < n; i++) {
            if (arr[i] > max) {max = arr[i];}
        }
        return max;
    }

    template <typename T>
    int binarySearch(T arr[], int n, T goal) {
        int st = 0;
        int fn = n;
        while (st < fn) {
            int mid = (st+fn)/2;
            if (arr[mid] == goal) {return mid;}
            else if (arr[mid] > goal) {fn = mid;}
            else {st = mid+1;}
        }
        return -1;
    }

    template <typename T>
    void printArray(T arr[], int n) {
        for (int i=0; i<n; i++) {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
    }
}