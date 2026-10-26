#ifndef Crivo_Eratostenes_h
#define Crivo_Eratostenes_h
#include "../estruturas/Vetor.h"

/*
Para saber se uma pessoa já levou a sério a mamãe Matemática é
só perguntar a ela o seguinte: Como você encontraria todos os
números primos entre 1 e 100?
O processo que a pessoa responder vai dizer muito sobre ela kk

A forma mais trivial de responder isto é: Percorrer todos os
números no intervalo [1, 100] e para cada número, percorremos
todos os números menores que ele para verificar se divide ou não.
Caso nenhum dividir, então o número atual só pode ser primo!

Esse processo tem complexidade O(N^2) no pior caso...
Podemos melhorar para O(sqrt(N) * N) ao perceber que podemos
verificar somente os sqrt(atual) divisores do número atual.

Podemos melhorar mais ainda com o Crivo de Eratóstenes! E a complexidade
vai para O(N log(log(N))) \o/\o/\o/
É claro que podemos melhorar AINDA mais, mas isso vai exigir algoritmos
heurísticos (heurísticos == ultra super max tryhard em matemática)

Como que este crivo funciona? Simples, diga que todos os números são primos.
Agora, seja P um número REALMENTE primo:
Para cada número P, iremos percorrer seus múltiplos.
Quem são seus múltiplos? P * k em que k é um inteiro > 1
(na verdade k é qualquer inteiro, mas vamos considerar somente aqueles com k > 1);
Como um número primo divide 1 e somente ele, isso significa que o
número P * k não é um número primo, então marca ele como falso;
Continue incrementando k até que o número P * k > 100 (100 pode ser N aqui).

Agora olha só, vamos fazer isso para o primeiro número primo que é o 2.
Isso vai marcar exatos 100 / 2 números, ou seja, metade das possibilidades.
Isso também significa que não precisamos fazer o mesmo processo para os
números 4, 6, 8, ... 2 * k (múltiplos de P em que P = 2).
Mas então vamos repetir o processo para qual número? O próximo primo
maior que 2, ou seja 3, e depois 5 e depois 7 e depois P_i+1 até
que P_i + k > N.

Note que ainda iremos percorrer todos os números entre 1 e N, mas
para todos os números marcados como falso, podemos provar que não
é primo e não precisamos realizar o processo para estes.
O processo será feito somente para aqueles números que se mantém marcados
como verdadeiros, ou seja, os números primos!!

Tá, eu entendo que a complexidade é pelo menos O(N) pois estamos
percorrendo todos os números entre 1 e N. Mas o processo da parte
de marcar múltiplos como falso também não é O(N)? Isso no final não
é O(N^2)???
R: Na verdade... A complexidade de marcar múltiplos é aproximadamente O(log(log(N)))!

Vamos calcular quantos números iremos percorrer em cada primo P:
2 --> N / 2
3 --> N / 3
5 --> N / 5
7 --> N / 7
...
P --> N / P
A complexidade será a soma disso tudo, logo:
ΣN/P --> N é constante --> N * Σ1/P
o somatório Σ1/P pode ser aproximado como log(log(N)) e portanto
a complexidade fica O(N log(log(N))).

Se ainda tiver dúvidas quanto ao algoritmo, calcule N log(log(N)) e
incremente uma variável no loop mais interno. Você perceberá que a
diferença é bem baixa \o/\o/\o/
*/

vetor<int> crivo_eratostenes(const int N) {
    vetor<bool> eh_primo(N + 1, true);
    vetor<int> num_primos;

    for (int i = 2; i <= N; ++i) {
        if (!eh_primo[i]) continue; // número não primo só pula
        // percorre os múltiplos de i
        for (int j = i * 2; j <= N; j += i) {
            // cuidado com overflow nesse int j = alguma coisa
            eh_primo[j] = false;
        }
        num_primos.push_back(i);
    }

    return num_primos;
}

/*
Podemos otimizar o loop interno para:
for (int j = i * i; j <= N; j += i)
pois o primeiro múltiplo ainda não marcado será o número P * P.
P * 2, P * 3, P * 5 e por aí vai, já foram marcados, mas P * P ainda não :D

Podemos otimizar mais um pouquinho fazendo:
for (int j = i * i; j <= N; j += (i & 1) ? 2 * i : i)
Ou seja, se o primo for ímpar (todos com exceção do 2), não precisamos
percorrer um múltiplo que seja par, por isso podemos somar 2 * i.
Mas se o primo for par, daí temos que somar i mermo...
*/

#endif
