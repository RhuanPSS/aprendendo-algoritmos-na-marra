#include <iostream>
#include "estruturas/Vetor.h"
#include "algoritmos/Sort.h"
#include <random> // só pra testar
using namespace std;

int main() {
    // bo depurar as parada na main
    int n = 35;
    vetor<int> vet(n);
    for (int i = 0; i < n; ++i) {
        vet[i] = rand() % (5 * n);
    }
    for (int i : vet) cout << i << ' ';
    cout << "\n\n";
    sort(vet.begin(), vet.end(), [](const int& a, const int& b){
        return a > b;
    });
    for (int i : vet) cout << i << ' ';
    cout << '\n';

    return 0;
}
