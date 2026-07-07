#ifndef FastPow
#define FastPow

const int64_t _infp = 9223372036854775783; // 2^63 - 25 é primo

/*
    Veja bem, bo calcular 7^5
    7^5 = 7 * 7 * 7 * 7 * 7
        = 7^2 * 7^2 * 7
        = 7^4 * 7
    ou seja, tu pode só manter a base e somar os expoentes.
    Então se temos 7 = 7^1 também temos 7^2 = 7^1 * 7^1
    Se temos 7^2 também temos 7^4 e assim por diante.
    Agora pega a representação binária do expoente = 5 (...000101)
    e imagina que cada bit equivale a 7^(2^i) em que
    'i' é a posição do bit.
    Daí tu vai percebendo que é só percorrer a representação binária
    do expoente pra calcular base^expoente...
    x = 7, y = 5 = ²(101)
     i            i           i
  y: 1 0 1      1 0 1     1 0 1
  x: 7^1        7^2       7^4
ret: 1 * 7^1    7         7 * 7^4
*/
int64_t fpow(int64_t x, int64_t y, const int64_t mod) {
    x %= mod;
    int64_t ret = 1;
    while (y > 0) {
        if (y & 1) {
            ret = (ret * x) % mod;
        }
        x = (x * x) % mod;
        y >>= 1;
    }
    return ret;
}

int64_t fpow(int64_t x, int64_t y) {
    return fpow(x, y, _infp);
}

#endif
