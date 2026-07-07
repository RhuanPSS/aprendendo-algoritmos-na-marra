#ifndef MDC
#define MDC

/*
    Seja G = MDC(A, B) e que A <= B, então G | A e G | B.
    Se G divide A e G divide B então G | (B - A)
    pois (B - A) / G = B / G - A / G (ambos os termos são inteiros)
    Portanto, G = MDC(A, X) onde X = B - A. Assuma que k é um inteiro qualquer.
    Perceba que se B > A * k então X > A e podemos subtrair A novamente.
    Quantas vezes iremos subtrair A e por que pararíamos de subtraí-lo?
    Quando X < A, temos de trocar as posições e fazer A - X,
    seja R = B - A * k, iremos trocar exatamente quando X = R em que
    R é o resto da divisão de B / A pelo Teorema Fundamental da Divisão.
    Com isto, concluímos que G = MDC(A, B % A).

    toma esse MDC em log(A) na cara \o/ \o/ \o/ (vlw mano Euclides)
*/
int64_t mdc(int64_t a, int64_t b) {
    if (b == 0) return a;
    return mdc(b, a % b);
}

int64_t mmc(int64_t a, int64_t b) {
    // pensa que o resultado deve ser múltiplo de 'a' e 'b' então faz
    // a * b. "Ah mas quero o menor possível" daí divide a * b pelo mdc
    return a / mdc(a, b) * b;
}

/*
    Ao encontrar o MDC, podemos extender o processo por meio de
    equações diofantinas de duas variáveis.
    Suponha que g = MCD(a, b)
    Então a * x + b * y = g e temos a "carinha" de uma equação diofantina
    Sabemos que o algoritmo de Euclides termina quando b = 0 e a = g
    portanto, nosso caso base será a = g, x = 1, b = 0 e y = 0
    e podemos utilizar a técnica de backtracking para calcular
    demais estados.
*/
int64_t ex_euclides(int64_t a, int64_t b, int64_t& x, int64_t& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int64_t n, m;
    int64_t g = ex_euclides(b, a % b, n, m);
    x = m;
    y = n - m * (a / b);
    return g;
}

#endif
