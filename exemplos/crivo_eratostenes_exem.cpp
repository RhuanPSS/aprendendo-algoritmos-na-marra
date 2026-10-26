#include <iostream>
#include "estruturas/Vetor.h"
#include "matematicas/Crivo_Eratostenes.h"
using namespace std;

int main() {
    int N;
    cin >> N;
    vetor<int> primos = crivo_eratostenes(N);

    cout << "Os primos entre 1 e " << N << " são:\n";
    for (int i : primos) cout << i << " eh primo!\n";

    return 0;
}
