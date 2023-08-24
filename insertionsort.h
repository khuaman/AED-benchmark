#include <iostream>
#include <vector>

template<typename T>

void insertionSort(T *arr, long long int N) {
    for (long long int i = 1; i < N; i++) {
        for (long long int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                T temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else {
                break;
            }
        }
    }
}