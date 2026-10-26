#ifndef BFS_h
#define BFS_h
#include <iostream>
#include "../estruturas/Vetor.h"
#include "../estruturas/Fila.h"
using namespace std;
/*
BFS
B -> Breadth (Largura)
F -> First (Primeiro)
S -> Search (Busca)

Supondo que nosso ponto de partida (origem) seja um nodo X qualquer
em um grafo (também qualquer).
1. Colocamos a origem em uma fila;
2. Marcamos como visitado o primeiro nodo na fila;
3. Percorremos todos os vizinhos ainda não visitados do primeiro nodo
na fila e colocamos eles na fila;
4. Retira o primeiro nodo da fila;
5. Repita os passos 2 ao 4 até não puder mais.
Lembre-se que um elemento, ao chegar em uma fila, sempre chegará no
fim dela.
Bora pra um exemplo, considere o grafo abaixo:
            1
           / \
          /   \
         2     3
        /     / \
       4     5   6
              \
               7
Para a origem = 1 ~
fila = {1}
visitados = {}

           {1}
           / \
          /   \
        -2-   -3-
        /     / \
       4     5   6
              \
               7

fila = {2, 3}
visitados = {1}

           x1x
           / \
          /   \
        {2}   -3-
        /     / \
      -4-    5   6
              \
               7

fila = {3, 4}
visitados = {1, 2}

           x1x
           / \
          /   \
        x2x   {3}
        /     / \
      -4-   -5- -6-
              \
               7

fila = {4, 5, 6}
visitados = {1, 2, 3}

           x1x
           / \
          /   \
        x2x   x3x
        /     / \
      {4}   -5- -6-
              \
               7

fila = {5, 6}
visitados = {1, 2, 3, 4}

           x1x
           / \
          /   \
        x2x   x3x
        /     / \
      x4x   {5} -6-
              \
              -7-

fila = {6, 7}
visitados = {1, 2, 3, 4, 5}

           x1x
           / \
          /   \
        x2x   x3x
        /     / \
      x4x   x5x {6}
              \
              -7-

fila = {7}
visitados = {1, 2, 3, 4, 5, 6}

           x1x
           / \
          /   \
        x2x   x3x
        /     / \
      x4x   x5x x6x
              \
              {7}

fila = {}
visitados = {1, 2, 3, 4, 5, 6, 7}

           x1x
           / \
          /   \
        x2x   x3x
        /     / \
      x4x   x5x x6x
              \
              x7x

Perceba que não é possível prosseguir os passos 2 ao 4 pois a fila
está vazia :D
Isso significa que já visitamos todos os nodos conexos ao nodo de
origem!
*/
void bfs(vetor<vetor<int>> grafo, int origem) {
    // --------- PASSO 1 ---------
    int N = grafo.size();
    vetor<bool> visitado(N, false); // tudo começa não visitado hein
    fila<int> Fila;
    Fila.push(origem);
    // ---------------------------

    // --------- while pra verificar PASSO 5 -----------
    while (!Fila.empty()) {
        // --------- PASSO 2 ----------
        int atual = Fila.top();
        Fila.pop(); // esse é o PASSO 4, mas eu coloco sempre aqui pra não esquecer ele :3
        visitado[atual] = true;
        // ----------------------------
        cout << "Do nodo " << atual << " visitamos os nodos: { ";
        // -------- PASSO 3 -----------
        for (int proximo : grafo[atual]) { // percorre os vizinhos do nodo atual
            if (visitado[proximo]) continue; // já visitamos esse vizinho, então pula ele
            Fila.push(proximo);
            cout << proximo << " ";
        }
        // ----------------------------
        cout << "}\n\n";
        if (!Fila.empty()) cout << "E continuamos a busca para o nodo " << Fila.top() << "\n";
    }
    // --------------------------------------------------
}

#endif
