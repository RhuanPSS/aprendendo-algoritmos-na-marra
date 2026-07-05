#include <iostream>
#include "estruturas/MaxHeap.h"
#include "algoritmos/InsertionSort.h"
using namespace std;

int main() {
    // bo depurar as parada na main

    maxHeap<int> pq;
    pq.push(2);
    pq.push(6);
    pq.push(8);
    pq.push(3);
    pq.push(1);
    cout  << pq.front() << '\n';

    while (!pq.empty()) {
        int f = pq.pop();
        cout << f << ' ';
    }
    cout << '\n';

    return 0;
}
