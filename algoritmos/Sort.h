#ifndef Sort
#define Sort
#include "../matematicas/Log.h"
#include "InsertionSort.h"
#include "HeapSort.h"
#include <iostream>
/*
 bo troca umas ideia e pensar um pouco.
 Quero ordenar um vetor :D, preferencialmente em O(N log N)
 Quais as opções? Merge Sort ou Quick Sort... E qual a diferença entre eles?
 Um garante a complexidade esperada mas usa mais memória (ruim),
 outro não possui problemas quanto a memória mas possui problemas
 quanto ao pior caso (O(N^2) == ruim tbm)
 O pior caso do Quick Sort tem solução, a função rand() pra
 selecionar um pivot aleatório e reduzir drasticamente
 a chance do pior caso.
 Mas eu só tô usando include do iostream... \o/ rand() não dá \o/

 Então vai ter que ser o sort pesadão com Merge? Ou eu posso forçar
 a barra e implementar meu rand() :3
 ... .. .
 Introsort: Hello there?
 */

template<typename T>
void swap(T& a, T& b) {
    T aux = a;
    a = b;
    b = aux;
}

 template<typename Iterador, typename Comparador>
 Iterador mediana(Iterador a, Iterador b, Iterador c, Comparador cmp) {
    // 'a' é o valor no meio
    if (cmp(*b, *a) && !cmp(*a, *c)) return a;
    if (cmp(*c, *a) && !cmp(*a, *b)) return a;

    // 'b' é o valor no meio
    if (cmp(*a, *b) && !cmp(*b, *c)) return b;
    if (cmp(*c, *b) && !cmp(*b, *a)) return b;

    return c;
 }

 template<typename Iterador, typename Comparador>
 Iterador particionar(Iterador begin, Iterador end, Comparador cmp) {
    // Isso aqui vai pegar o pivot e jogar tudo que é menor que ele
    // à esquerda e tudo que for maior à direita
    auto pivot = end;
    Iterador i = begin;
    for (Iterador j = begin; j < end; ++j) {
        if (cmp(*j, *pivot)) {
            swap(*j, *i);
            ++i;
        }
    }
    swap(*i, *pivot);
    return i; // retorna o ponto de quebra
 }

template<typename Iterador, typename Comparador>
void sort(Iterador begin, Iterador end, int chamadas, Comparador cmp) {
    int len = end - begin; // tamanho dos elementos a ser ordenados

    // se o tamanho for menor que isso aqui
    if (len <= 16) {
        // então o insertion sort vai ser mais rápido que qualquer outra coisa
        inSort(begin, end, cmp);
        return;
    }

    // se a quantidade de chamadas recursivas for 0
    // então estamos a caminho do pior caso do quick sort O(N²)
    if (chamadas == 0) {
        // bora garantir complexidade O(N log N) com heap sort
        heapSort(begin, end, cmp);
        return;
    }

    // se nada mencionado anteriormente ocorrer, tá suave fazer quick sort
    Iterador aux = end - 1;
    Iterador pivot = mediana(begin, begin + len / 2, aux, cmp); // pega a mediana
    swap(*pivot, *aux); // bota ela no fim pra comparar na partição
    Iterador particao = particionar(begin, aux, cmp);

    sort(begin, particao, chamadas - 1, cmp); // ordena os menores que pivot
    sort(particao + 1, end, chamadas - 1, cmp); // ordena os maiores que pivot
}

template<typename Iterador>
void sort(Iterador begin, Iterador end) {
    int N = 2 * log2(end - begin);
    sort(begin, end, N, [](const auto& a, const auto& b){
        return a < b;
    });
}

/*
O Introsort combina 3 estratégias de ordenamento distintas!
Primeiro, vamos aplicar a divisão e conquista do Quick Sort.
Se este processo começar a levar tempo demais (2 * log N),
vamos garantir o resto em O(N log N) pelo Heap Sort!
E a cereja do bolo (ou só pra tirar onda mermo), se restar uma
quantidade baixa de elementos a serem ordenados, usaremos a
alta eficiência em casos pequenos do Insertion Sort pra dar conta!
*/

#endif
