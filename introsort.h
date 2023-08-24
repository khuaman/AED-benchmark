#ifndef AED_BENCHMARK_INTROSORT_H
#define AED_BENCHMARK_INTROSORT_H

#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
void insertionsort(T* array, long long int size) {
    for (int i=1; i<size; i++){
        int j=i;
        T element = array[i];
        while(j!=0 and array[j-1] > element){
            array[j] = array[j-1];
            j--;
        }
        array[j] = element;
    }
}


template <typename T>
int QuickOrdenacion(T* array, int inicio, int final){
    int i = inicio;
    int puntero = i-1;
    T pivote = array[final];
    while(i<=final) {
        if (array[i] <= pivote) {
            puntero++;
            if (i > puntero) {
                T temporal = array[puntero];
                array[puntero] = array[i];
                array[i] = temporal;
            } else if (i == puntero) {
                i++;
            }
        } else {
            i++;
        }
    }
    return puntero;
}

template <typename T>
void heapify(T* arr, long long int N, long long int i) {
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

template <typename T>
void heapSort(T* arr, long long int N) {
    for (auto i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (auto i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

template<typename T>
void introsort(T* array, int inicio, int final, int depth_limit) {
    if (final - inicio <= 8) {  // Umbral para usar InsertionSort
        insertionsort(array + inicio, final - inicio + 1);
        return;
    }

    if (depth_limit == 0) {  // Umbral de recursión, usar HeapSort
        heapSort(array + inicio, final - inicio + 1);
        return;
    }

    int separador = QuickOrdenacion(array, inicio, final);
    introsort(array, inicio, separador - 1, depth_limit - 1);
    introsort(array, separador + 1, final, depth_limit - 1);
}

template<typename T>
void introsort(T* array, int size) {
    int depth_limit = 2 * log(size);  // Límite de recursión, puedes ajustarlo
    introsort(array, 0, size - 1, depth_limit);
}

#endif
