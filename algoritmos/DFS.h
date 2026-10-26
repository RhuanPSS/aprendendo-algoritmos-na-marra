#ifndef DFS_h
#define DFS_h
#include <iostream>
using namespace std;
/*
DFS
D -> Depth (Profundidade)
F -> First (Primeiro)
S -> Search (Busca)

Supondo que nosso ponto de partida (origem) seja um nodo X qualquer
em um grafo (também qualquer).
1. Colocamos a origem em uma pilha;
2. Marcamos como visitado o primeiro nodo na pilha;
3. Percorremos algum vizinho ainda não visitado do primeiro nodo na pilha
e coloca ele na pilha;
4. Repita os passos 2 e 3 até não puder mais.
5. Retira-se o primeiro nodo na pilha e tenta repetir passos 2 ao 4;
Lembre-se que um elemento, ao chegar em uma pilha, sempre chegará no
início dela.
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
pilha = {1}
visitados = {1}

           {1}
           / \
          /   \
        -2-    3
        /     / \
       4     5   6
              \
               7

pilha = {2, 1}
visitados = {1, 2}

           x1x
           / \
          /   \
        {2}    3
        /     / \
      -4-    5   6
              \
               7

pilha = {4, 2, 1}
visitados = {1, 2, 4}

           x1x
           / \
          /   \
        x2x    3
        /     / \
      {4}    5   6
              \
               7

pilha = {1}
visitados = {1, 2, 4}

          {x1x}
           / \
          /   \
        x2x   -3-
        /     / \
      x4x    5   6
              \
               7

pilha = {3, 1}
visitados = {1, 2, 3, 4}

           x1x
           / \
          /   \
        x2x   {3}
        /     / \
      x4x   -5-  6
              \
               7

pilha = {5, 3, 1}
visitados = {1, 2, 3, 4, 5}

           x1x
           / \
          /   \
        x2x   x3x
        /     / \
      x4x   {5}  6
              \
              -7-

pilha = {7, 5, 3, 1}
visitados = {1, 2, 3, 4, 5, 7}

           x1x
           / \
          /   \
        x2x   x3x
        /     / \
      x4x   x5x  6
              \
              {7}

pilha = {3, 1}
visitados = {1, 2, 3, 4, 5, 7}

           x1x
           / \
          /   \
        x2x  {x3x}
        /     / \
      x4x   x5x -6-
              \
              x7x

pilha = {6, 3, 1}
visitados = {1, 2, 3, 4, 5, 6, 7}

           x1x
           / \
          /   \
        x2x   x3x
        /     / \
      x4x   x5x {6}
              \
              x7x

pilha = {}
visitados = {1, 2, 3, 4, 5, 6, 7}

           x1x
           / \
          /   \
        x2x   x3x
        /     / \
      x4x   x5x x6x
              \
              x7x

Perceba que não é possível prosseguir os passos 2 ao 4 pois a pilha
está vazia :D
Isso significa que já visitamos todos os nodos conexos ao nodo de
origem!
*/

bool visitado[int(5e5)];
// Podemos representar a pilha como uma função recursiva
void dfs(const vetor<vetor<int>> &grafo, int atual) {
    visitado[atual] = true;
    for (int vizinho : grafo[atual]) { // percorre os vizinhos do nodo atual
        if (visitado[vizinho]) continue; // caso já visitamos este nodo
        cout << "Do nodo " << atual << " visitamos o nodo " << vizinho << '\n';
        dfs(grafo, vizinho); // equivalente a colocar o nodo vizinho na pilha
    }
}
#endif
