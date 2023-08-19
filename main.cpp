//
// Created by Kevin on 18/08/2023.
//
#include <iostream>
#include <chrono>
#include <random>
#include "heapsort.h"
using namespace std;

int main(){
    srand(static_cast<unsigned int>(time(nullptr)));

    // 10 elementos
    const int size = 1000000; // Tamaño del array
    long long int* array = new long long int[size];


    for (auto i = 0; i < size; i++) {
        array[i] = (rand() % 9223372036854775807) + 1;
    }

    // auto N = sizeof(*array) / sizeof(array[0]);

    auto start = std::chrono::high_resolution_clock::now();

    // FUNCION

    // Function call
    heapSort(array, size);

    auto final = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(final - start);

    delete[] array;

    std::cout << "Tiempo de ejecucion: " << duration.count() << " milisegundos" << std::endl;

    return 0;
}