#include <iostream>
#include "matematicas/NCK.h"
#include "matematicas/Modular.h"
#include "matematicas/FastPow.h"
using namespace std;

int main() {
    // bo depurar as parada na main

    cout << fpow(3, 15) << '\n';
    cout << mdc(1086, 828) << '\n';
    cout << mmc(1086, 828) << '\n';
    cout << nck(35, 3) << '\n';

    return 0;
}
