#ifndef Busca_Binaria_h
#define Busca_Binaria_h
#include "../estruturas/Vetor.h"
/*
Se você consegue devorar uma coxinha em 5 minutos, será que também
consegue em 6 minutos? E em 7, 10, 20, 100 minutos? Se é capaz
em 5 minutos então também será capaz para qualquer tempo maior ou
igual a 5 minutos (considerando que é a mesma coxinha kk)
Mas e para um tempo menor? Se 5 minutos for o mais rápido que consegue
então é óbvio que para qualquer tempo inferior não conseguirá.
Então suponha que temos um vetor em que cada posição representa
uma unidade de minuto, logo:
  1min   2min   3min  4min   5min  6min  7min      inf min
[false, false, false, false, true, true, true, ..., true]
Em que:
false -> não consegue devorar a coxinha no i-ésimo minuto
true -> consegue devorar a coxinha no i-ésimo minuto

Perceba que este vetor é ordenado pois temos false, false, ..., false, true, true, ..., true
e em espaços ordenados podemos fazer um ótimo uso de divisão e conquista!

Como assim divisão e conquista? Suponha que queremos encontrar a primeira
ocorrência de um "true". Inicialmente temos todo o intervalo de possibilidades (vetor inteiro)
mas o que acontece se chutarmos o elemento no meio deste intervalo?
Seja M a posição do elemento chutado, se este elemento for "false"
então todos os elementos em posições menores que M também serão "false".
O processo é semelhante caso o elemento na posição M for "true",
isso dirá que todos os elementos nas posições maiores que M também
serão "true".

Então a divisão e conquista é feita da seguinte forma:
Dado que temos um intervalo [L, R], o meio será M = (L + R) / 2.
Então, fazemos a "conquista" em M, ou seja, checa se
alguma tarefa/objetivo satisfaz neste M.
Dependendo da resposta obtida em nossa conquista, dividimos o próximo
intervalo de busca para [L, M] ou [M, R] e repetimos o processo até
sobrar um intervalo de tamanho único ([1, 1], ou [2, 2], ou [k, k]).

Perceba que estamos sempre dividindo o intervalo de possibilidades ao meio
e este processo possui complexidade log(N), em que N é o tamanho inicial
do intervalo :D
A conquista também possui sua complexidade, mas isto depende do processo
exigido no problema.
*/

template<typename T>
int busca_binaria(vetor<T> vet, T x) {
    // queremos encontrar a primeira posição que 'x' ocorre dado
    // um vetor ordenado
    int N = vet.size();
    int L = 0, R = N - 1;

    while (L <= R) { // enquanto o intervalo de busca não for único
        int M = (L + R) / 2; // pega o meio do intervalo
        // faz a conquista e divide a próxima busca dependendo da resposta
        if (vet[M] >= x) R = M - 1;
        else L = M + 1;
    }
    // Estamos retornando L pois quando vet[M] >= x, dizemos que R = M - 1
    // ou seja, o elemento vet[R] < x, uma vez que R = M - 1 e vet[M] >= x
    // Por outro lado, quando vet[M] < x, dizemos que L = M + 1 e portanto
    // o elemento vet[L] >= x, uma vez que L = M + 1 e vet[M] < x
    return L;
}
#endif
