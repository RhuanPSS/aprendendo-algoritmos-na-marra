#ifndef NCK
#define NCK

int64_t fatorial(int64_t k) {
    int64_t ret = 1;
    for (int i = 1; i <= k; ++i) ret = ret * i;
    return ret;
}

int64_t nck(int64_t n, int64_t k) {
    /*
    numerador: n * (n - 1) * (n - 2) * ... * (n - k - 1) * (n - k)!
    denominador: k! * (n - k)!
    Daí "corta" em cima com o de baixo e fica linear em k
    Então temos
    n   (n - 1)  ...  (n - k + 1)
    / *    /   * ... *     /
    1      2     ...       k
    o mesmo vale para quando k > n - k
    */
    int64_t r = (k <= n - k ? k : n - k); // nCk = nCr em que r = n - k
    int64_t numerador = 1, denominador = fatorial(r);
    for (int64_t i = 0; i < r; ++i) {
        numerador = numerador * (n - i);
    }
    return numerador / denominador;
}

#endif
