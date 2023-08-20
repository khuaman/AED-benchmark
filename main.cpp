//
// Created by Kevin on 18/08/2023.
//
#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <climits>
#include "heapsort.h"
using namespace std;

int main() {
    std::random_device rd;
    std::mt19937_64 generator(rd());
    std::uniform_int_distribution<long long int> distribution(1, LLONG_MAX);


    // 10 elementos
    const long long int size = 1000000; // Size of array
    auto array = new long long int[size];


    for (auto i = 0; i < size; i++) {
        array[i] = distribution(generator);
    }

    //auto N = sizeof(array)/sizeof(array[0]);  Not necessary because obtain the same number of size

    auto start = std::chrono::high_resolution_clock::now();

    // Function call
    heapSort(array, size);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    delete[] array;

    cout << "Execution time: " << duration.count() << " milliseconds" << endl;


    ofstream archivo_salida; // Declara una instancia de ofstream para escritura
    archivo_salida.open("../execution_time.txt", std::ios::app); // Abre el archivo en modo "append" para añadir datos

    if (!archivo_salida) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    // Escribe nueva data en el archivo sin borrar lo existente
    archivo_salida << "Execution time of heapsort with array with "<< size << " elements:" << duration.count() << endl;

    // Cierra el archivo
    archivo_salida.close();

    return 0;
}