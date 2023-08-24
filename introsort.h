#ifndef AED_BENCHMARK_INTROSORT_H
#define AED_BENCHMARK_INTROSORT_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

// Función para realizar la operación Heapify en Heapsort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Función de ordenamiento Heapsort
void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Función de ordenamiento por inserción
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Función de partición para el algoritmo Quicksort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}
// Función de ordenamiento Quicksort
void quicksort(int arr[], int low, int high, int depthLimit) {
    while (high - low > 16) {
        if (depthLimit == 0) {
            heapsort(arr, high - low + 1);
            return;
        }
        depthLimit--;
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1, depthLimit);
        low = pivotIndex + 1;
    }
    insertionSort(arr + low, high - low + 1);
}
// Función de ordenamiento Introsort
void introsort(int arr[], int n) {
    int depthLimit = 2 * static_cast<int>(std::log2(n));
    quicksort(arr, 0, n - 1, depthLimit);
}
#endif
