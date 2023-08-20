//
// Created by Kevin on 18/08/2023.
//
#include <iostream>
#include <chrono>
#include <random>
#include "heapsort.h"
using namespace std;

int main(){
    std::random_device rd;
    std::mt19937_64 generator(rd());
    std::uniform_int_distribution<long long int> distribution(1, 9223372036854775807);


    // 10 elementos
    const long long int size = 100000000; // Size of array
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

    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}