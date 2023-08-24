#include "insertionsort.h"
#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <chrono>
#include <random>
#include <climits>

using namespace std;
int main(int argc, char const *argv[])
{
    //setear semilla
    srand(time(NULL));

    long long int N = 1000000;
    //declarar lista
    int *arr = new int[N];
    //llenar lista
    for (long long int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }
    for (long long int i = 0; i < N; i++) {
        //cout << arr[i] << " ";
    }
    //cout << endl;
    auto start = std::chrono::high_resolution_clock::now();

    insertionSort(arr, N);
    for (long long int i = 0; i < N; i++) {
        //cout << arr[i] << " ";
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    delete[] arr;
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    ofstream archivo_salida; // Declara una instancia de ofstream para escritura
    archivo_salida.open("../execution_time.txt", std::ios::app); // Abre el archivo en modo "append" para añadir datos

    if (!archivo_salida) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    // Escribe nueva data en el archivo sin borrar lo existente
    archivo_salida << "Execution time of heapsort with array with "  << N << " elements:" << duration.count() << endl;

    // Cierra el archivo
    archivo_salida.close();
    return 0;
}
