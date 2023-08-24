//
// Created by Kevin on 18/08/2023.
//
#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <climits>
#include <cstdlib>
#include <ctime>
#include "heapsort.h"
#include "insertionsort.h"
#include "introsort.h"
using namespace std;

void execute(const string& algorithm, long long int* array, long long int size_of_array){
    auto start = std::chrono::high_resolution_clock::now();

    if (algorithm == "insertionsort") {
        insertionSort(array, size_of_array);
    }
    else if (algorithm == "introsort") {
        introsort(array, size_of_array);
    }
    else if (algorithm == "heapsort") {
        heapSort(array, size_of_array);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    // Abre el archivo una sola vez fuera de las ramas condicionales
    ofstream archivo_salida("../execution_time.txt", std::ios::app);

    if (!archivo_salida) {
        cerr << "No se pudo abrir el archivo." << endl;
    }
    else {
        archivo_salida << "Execution time of " << algorithm << " with array of "<< size_of_array << " elements: " << duration.count() << " microseconds"<< endl;
    }

    // Cierra el archivo
    archivo_salida.close();

    // No necesitas asignar ni eliminar la matriz 'insertion' aquí
}

long long int* create_array(long long int size_of_array){
    srand(time(NULL));
    auto *array = new long long int[size_of_array];
    for (auto i = 0; i < size_of_array; i++) {
        array[i] = rand() % LLONG_MAX;
    }
    return array;
}
int main() {

    srand(time(NULL));
    string algorithm[] = {"insertionsort", "introsort", "heapsort"};
    long int times[] = {10, 100, 1000, 10000,100000,1000000};
    long long int size = NULL; // Size of array
    for (auto number : times){
        size = number;
        auto array = create_array(size);
        for (auto algo : algorithm){
            execute(algo,array,size);
        }
    }

    //auto N = sizeof(array)/sizeof(array[0]);  Not necessary because obtain the same number of size

    return 0;
}