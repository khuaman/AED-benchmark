#include "insertionsort.h"
#include <iostream>
#include <vector>
#include <random>

using namespace std;
int main(int argc, char const *argv[])
{
    //setear semilla
    srand(time(NULL));

    long long int N = 100;
    //declarar lista
    int *arr = new int[N];
    //llenar lista
    for (long long int i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }
    for (long long int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    
    insertionSort(arr, N);
    for (long long int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
