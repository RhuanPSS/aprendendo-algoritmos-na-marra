#include <iostream>
#include "estruturas/Vetor.h"
#include "algoritmos/HeapSort.h"
using namespace std;

int main() {
    // bo depurar as parada na main

    int n = 10;
    vetor<int> vet;
    for (int i = 1; i <= n; ++i) {
        int j = (i + 3) % n + 1;
        vet.push_back(j);
    }
    for (int i : vet) cout << i << ' ';
    cout << '\n';
    heapSort(vet.begin(), vet.end());
    for (int i : vet) cout << i << ' ';
    cout << '\n';

    return 0;
}
