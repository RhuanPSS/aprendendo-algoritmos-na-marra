#ifndef Modular
#define Modular
#include "FastPow.h"
#include "MDC.h"

int64_t soma_mod(int64_t a, int64_t b, const int64_t mod) {
    return ((a % mod) + (b % mod)) % mod; // subtração é uma soma tbm
}

int64_t mult_mod(int64_t a, int64_t b, const int64_t mod) {
    return ((a % mod) * (b % mod)) % mod; // divisão é uma multiplicação também
    // MAAASSS é diferente na hora de fazer o módulo
}

int64_t inv_modp(int64_t a, int64_t b, int64_t mod) {
    // Se o módulo for primo, podemos utilizar o Teorema Pequeno de Fermat
    a %= mod;
    int64_t inv = fpow(b, mod - 2, mod);
    return (a * inv) % mod;
}

int64_t inv_mod(int64_t a, int64_t b, const int64_t mod) {
    // Se o módulo não for primo, daí pedimos ajuda pro algoritmo extendido de Euclides
    int64_t aux, k;
    int64_t gcd = ex_euclides(b, mod, aux, k);
    if (gcd != 1) return -1; // se 'b' e 'mod' não forem coprimos, não existe modular inverso
    int64_t inv = (aux % mod + mod) % mod; // as vezes o inverso pode ser negativo, daí é só somar mod dnv
    a %= mod;
    return (a * inv) % mod;
}

#endif
