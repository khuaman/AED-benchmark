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
    if (algorithm == "insertionsort"){
        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(array, size_of_array);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        delete[] array;
        cout << "Execution time: " << duration.count() << " microseconds" << endl;
        ofstream archivo_salida; // Declara una instancia de ofstream para escritura
        archivo_salida.open("../execution_time.txt", std::ios::app); // Abre el archivo en modo "append" para añadir datos

        if (!archivo_salida) {
            cerr << "No se pudo abrir el archivo." << endl;
        }
        else{
            archivo_salida << "Execution time of insertionsort with array with "<< size_of_array << " elements: " << duration.count() << " microseconds"<< endl;
        }
        // Cierra el archivo
        archivo_salida.close();
    }
    else if (algorithm == "introsort"){
        auto start = std::chrono::high_resolution_clock::now();
        introsort(array, size_of_array);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        delete[] array;
        cout << "Execution time: " << duration.count() << " microseconds" << endl;
        ofstream archivo_salida; // Declara una instancia de ofstream para escritura
        archivo_salida.open("../execution_time.txt", std::ios::app); // Abre el archivo en modo "append" para añadir datos

        if (!archivo_salida) {
            cerr << "No se pudo abrir el archivo." << endl;
        }
        else{
            archivo_salida << "Execution time of introsort with array with "<< size_of_array << " elements: " << duration.count() << " microseconds"<< endl;
        }
        // Cierra el archivo
        archivo_salida.close();
    }
    else if (algorithm == "heapsort"){
        auto start = std::chrono::high_resolution_clock::now();
        heapSort(array, size_of_array);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        delete[] array;
        cout << "Execution time: " << duration.count() << " microseconds" << endl;
        ofstream archivo_salida; // Declara una instancia de ofstream para escritura
        archivo_salida.open("../execution_time.txt", std::ios::app); // Abre el archivo en modo "append" para añadir datos

        if (!archivo_salida) {
            cerr << "No se pudo abrir el archivo." << endl;
        }
        else{
            archivo_salida << "Execution time of heapsort with array with "<< size_of_array << " elements: " << duration.count() << " microseconds"<< endl;
        }
        // Cierra el archivo
        archivo_salida.close();
    }
    auto *insertion = new long long int[size_of_array];

    delete[] insertion;
}

long long int* create_array(long long int size_of_array){
    srand(time(NULL));
    auto *array = new long long int[size_of_array];
    for (auto i = 0; i < size_of_array; i++) {
        //array[i] = distribution(rand() % LLONG_MAX);
        array[i] = rand() % LLONG_MAX;
    }
    return array;
}
int main() {
    //std::random_device rd;
    //std::mt19937_64 generator(rd());
    //std::uniform_int_distribution<long long int> distribution(1, LLONG_MAX);
    srand(time(NULL));
    // 10
    long long int size = 1000; // Size of array
    auto array10 = create_array(size);

    // 100
    //size = 1000;
    // 1000
    //size = 1000;
    // 10000
    // 100000
    // 1000000

    // 10 elementos
    //size = 100000; // Size of array
    //auto *array = new long long int[size];


    for (auto i = 0; i < size; i++) {
        //array[i] = distribution(rand() % LLONG_MAX);
        array10[i] = rand() % LLONG_MAX;
    }
    string algorithm[] = {"insertionsort", "introsort", "heapsort"};
    for (auto e : algorithm){
        //long long int* temp = new long long int[size];
        //temp = array10;
        execute(e,array10,size);
    }
    //auto N = sizeof(array)/sizeof(array[0]);  Not necessary because obtain the same number of size

    return 0;
}