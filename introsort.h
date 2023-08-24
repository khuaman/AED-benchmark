#ifndef AED_BENCHMARK_INTROSORT_H
#define AED_BENCHMARK_INTROSORT_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>


// Función para realizar la operación Heapify en Heapsort
void introsort_introsort_heapify(long long int* arr, long long int n, long long int i) {
    auto largest = i;
    auto left = 2 * i + 1;
    auto right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        introsort_introsort_heapify(arr, n, largest);
    }
}

// Función de ordenamiento Heapsort
void introsort_heapsort(long long int arr[], long long int n) {
    for (auto i = n / 2 - 1; i >= 0; i--)
        introsort_introsort_heapify(arr, n, i);

    for (auto i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        introsort_introsort_heapify(arr, i, 0);
    }
}

// Función de ordenamiento por inserción
void introsort_insertionSort(long long* arr, long long n) {
    for (auto i = 1; i < n; i++) {
        auto key = arr[i];
        auto j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Función de partición para el algoritmo Quicksort
int partition(long long int* arr, long long int low, long long int high) {
    auto pivot = arr[high];
    auto i = (low - 1);

    for (auto j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Función de ordenamiento Quicksort
void introsort_quicksort(long long int* arr, long long int low, long long int high, long long int depthLimit) {
    while (high - low > 16) {
        if (depthLimit == 0) {
            introsort_heapsort(arr, high - low + 1);
            return;
        }
        depthLimit--;

        int pivotIndex = partition(arr, low, high);
        introsort_quicksort(arr, low, pivotIndex - 1, depthLimit);
        low = pivotIndex + 1;
    }

    introsort_insertionSort(arr + low, high - low + 1);
}

// Función de ordenamiento Introsort
void introsort(long long int* arr, long long int n) {
    auto depthLimit = 2 * static_cast<long long int>(std::log2(n));
    introsort_quicksort(arr, 0, n - 1, depthLimit);
}
#endif
