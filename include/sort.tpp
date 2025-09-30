#include <vector>

namespace mystd {
    namespace {
        //vector
        template <typename T>
        void heapify(std::vector<T> &vec, int n, int i) {
            int largest = i;
            int l = 2*i;
            int r = 2*i+1;

            if (l<n && vec[l] > vec[largest]) {largest = l;}
            if (r<n && vec[r] > vec[largest]) {largest = r;}
            if (largest != i) {
                T temp = vec[i];
                vec[i] = vec[largest];
                vec[largest] = temp;

                heapify(vec, n, largest);
            }
        }

        template <typename T>
        int partion(std::vector<T> &vec, int p, int r) {
            T x = vec[r];
            int i = p-1;
            T temp;

            for (int j=p; j<=r-1; j++) {
                if (vec[j] <= x) {
                    i++;
                    temp = vec[i];
                    vec[i] = vec[j];
                    vec[j] = temp; 
                }
            }

            temp = vec[i+1];
            vec[i+1] = vec[r];
            vec[r] = temp;

            return i+1;
        }

        template <typename T>
        void merge(std::vector<T> &vec, int l, int m, int r) {
            int i,j,k;
            int n1 = m-l+1;
            int n2 = r-m;

            T L[n1], R[n2];

            for (i=0; i<n1; i++) {L[i] = vec[l+i];}
            for (j=0; j<n2; j++) {R[j] = vec[m+1+j];}

            i=0;j=0;k=l;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                    vec[k] = L[i];
                    i++;
                }
                else {
                    vec[k] = R[j];
                    j++;
                }
                k++;
            }

            while (i < n1) {
                vec[k] = L[i];
                i++;
                k++;
            }

            while (j < n2) {
                vec[k] = R[j];
                j++;
                k++;
            }
        }


        //array
        template <typename T>
        void heapify(T arr[], int n, int i) {
            int largest = i;
            int l = 2*i;
            int r = 2*i+1;

            if (l<n && arr[l] > arr[largest]) {largest = l;}
            if (r<n && arr[r] > arr[largest]) {largest = r;}
            if (largest != i) {
                T temp = arr[i];
                arr[i] = arr[largest];
                arr[largest] = temp;

                heapify(arr, n, largest);
            }
        }

        template <typename T>
        int partion(T arr[], int p, int r) {
            T x = arr[r];
            int i = p-1;
            T temp;

            for (int j=p; j<=r-1; j++) {
                if (arr[j] <= x) {
                    i++;
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp; 
                }
            }

            temp = arr[i+1];
            arr[i+1] = arr[r];
            arr[r] = temp;

            return i+1;
        }

        template <typename T>
        void merge(T arr[], int l, int m, int r) {
            int i,j,k;
            int n1 = m-l+1;
            int n2 = r-m;

            T L[n1], R[n2];

            for (i=0; i<n1; i++) {L[i] = arr[l+i];}
            for (j=0; j<n2; j++) {R[j] = arr[m+1+j];}

            i=0;j=0;k=l;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                    arr[k] = L[i];
                    i++;
                }
                else {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }

            while (i < n1) {
                arr[k] = L[i];
                i++;
                k++;
            }

            while (j < n2) {
                arr[k] = R[j];
                j++;
                k++;
            }
        }
    }

    //vector 
    template <typename T>
    void heapsort(std::vector<T> &vec) {
        for (int i=vec.size()/2-1; i>=0; i--) {heapify(vec, vec.size(), i);}

        for (int i=vec.size()-1; i>=0; i--) {
            T temp = vec[0];
            vec[0] = vec[i];
            vec[i] = temp;

            heapify(vec, i, 0);
        }
    }

    template <typename T>
    void quicksort(std::vector<T> &vec, int p, int r) {
        if (p < r) {
            int q = partion(vec, p, r);
            quicksort(vec, p, q-1);
            quicksort(vec, q+1, r);
        }
    }

    template <typename T>
    void selectionSort(std::vector<T> &vec) {
        for (int i=0; i<vec.size(); i++) {
            T min = vec[i];
            int minIndex = i;
            for (int j=i+1;j<vec.size();j++) {
                if (vec[j] < min) {
                    min = vec[j];
                    minIndex = j;
                }
            }
            T temp = vec[i];
            vec[i] = vec[minIndex];
            vec[minIndex] = temp;
        }
    }

    template <typename T>
    void mergeSort(std::vector<T> &vec, int l, int r) {
        if (l < r) {
            int m = (l+r) / 2;

            mergeSort(vec, l, m);
            mergeSort(vec, m+1, r);

            merge(vec, l, m, r);
        }
    }


    // array
    template <typename T>
    void heapsort(T arr[], int n) {
        for (int i=n/2-1; i>=0; i--) {heapify(arr, n, i);}

        for (int i=n-1; i>=0; i--) {
            T temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapify(arr, i, 0);
        }
    }

    template <typename T>
    void quicksort(T arr[], int p, int r) {
        if (p < r) {
            int q = partion(arr, p, r);
            quicksort(arr, p, q-1);
            quicksort(arr, q+1, r);
        }
    }

    template <typename T>
    void selectionSort(T arr[], int n) {
        for (int i=0; i<n; i++) {
            T min = arr[i];
            int minIndex = i;
            for (int j=i+1;j<n;j++) {
                if (arr[j] < min) {
                    min = arr[j];
                    minIndex = j;
                }
            }
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    template <typename T>
    void mergeSort(T arr[], int l, int r) {
        if (l < r) {
            int m = (l+r) / 2;

            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);

            merge(arr, l, m, r);
        }
    }
}

/*
std::cout<<"VECTOR:\n";
    std::vector<double> vec = {57.23, 12.89, 91.47, 34.15, 76.08, 5.64, 88.32, 41.90, 63.57, 29.11};
    
    auto tempM = vec;
    mystd::mergeSort(tempM, 0, tempM.size()-1);
    mystd::printVector(tempM);

    auto tempS = vec;
    mystd::selectionSort(tempS);
    mystd::printVector(tempS);

    auto tempQ = vec;
    mystd::quicksort(tempQ, 0, tempQ.size()-1);
    mystd::printVector(tempQ);

    auto tempH = vec;
    mystd::heapsort(tempH);
    mystd::printVector(tempH);
    

    std::cout<<"ARRAY:\n";
    double arr[] = {57.23, 12.89, 91.47, 34.15, 76.08, 5.64, 88.32, 41.90, 63.57, 29.11};
    double tempA[10];

    std::copy(arr, arr+10, tempA);
    mystd::mergeSort(tempA, 0, 9);
    mystd::printArray(tempA, 10);

    std::copy(arr, arr+10, tempA);
    mystd::selectionSort(tempA, 10);
    mystd::printArray(tempA, 10);

    std::copy(arr, arr+10, tempA);
    mystd::quicksort(tempA, 0, 9);
    mystd::printArray(tempA, 10);

    std::copy(arr, arr+10, tempA);
    mystd::heapsort(tempA, 10);
    mystd::printArray(tempA, 10);
*/