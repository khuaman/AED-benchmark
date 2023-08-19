//
// Created by Kevin on 18/08/2023.
//

#ifndef AED_BENCHMARK_HEAPSORT_H
#define AED_BENCHMARK_HEAPSORT_H
// C++ program for implementation of Heap Sort

#include <iostream>
using namespace std;

void heapify(long long int arr[], long long int N, long long int i) {
    auto largest = i;
    auto left = 2 * i + 1;
    auto right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])
        largest = left;

    if (right < N && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(long long int arr[], long long int N) {
    for (auto i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (auto i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

#endif //AED_BENCHMARK_HEAPSORT_H
