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
using namespace std;

void execute(long long int size_of_array){
    srand(time(NULL));
    auto *original_array = new long long int[size_of_array];
    for (auto i = 0; i < size_of_array; i++) {
        //array[i] = distribution(rand() % LLONG_MAX);
        original_array[i] = rand() % LLONG_MAX;
    }


}
int main() {
    //std::random_device rd;
    //std::mt19937_64 generator(rd());
    //std::uniform_int_distribution<long long int> distribution(1, LLONG_MAX);
    srand(time(NULL));
    // 10
    long long int size = 100; // Size of array
    // 100
    size = 1000;
    // 1000
    size = 1000;
    // 10000
    // 100000
    // 1000000

    // 10 elementos
    size = 10; // Size of array
    auto *array = new long long int[size];


    for (auto i = 0; i < size; i++) {
        //array[i] = distribution(rand() % LLONG_MAX);
        array[i] = rand() % LLONG_MAX;
    }

    //auto N = sizeof(array)/sizeof(array[0]);  Not necessary because obtain the same number of size

    auto start = std::chrono::high_resolution_clock::now();

    // Function call
    heapSort(array, size);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    delete[] array;
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;

    ofstream archivo_salida; // Declara una instancia de ofstream para escritura
    archivo_salida.open("../execution_time.txt", std::ios::app); // Abre el archivo en modo "append" para añadir datos

    if (!archivo_salida) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }
    // Escribe nueva data en el archivo sin borrar lo existente
    archivo_salida << "Execution time of heapsort with array with "<< size << " elements: " << duration.count() << " microseconds"<< endl;

    // Cierra el archivo
    archivo_salida.close();

    return 0;
}
