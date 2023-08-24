#include "introsort.h"
#include <chrono>
#include <ctime>

int main() {
    srand(time(NULL));

    long long int N = 100;
    long long int* arr = new long long int[N];
    for (long long int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }

    std::cout << "Original array: ";
    for (long long int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    introsort(arr, N);

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Sorted array: ";
    for (long long int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Time taken by Introsort: " << elapsed.count() << " seconds" << std::endl;

    delete[] arr;Introsort
    return 0;
}