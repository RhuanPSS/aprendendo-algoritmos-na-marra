#include <iostream>
#include "../estruturas/Vetor.h"
#include "../algoritmos/BFS.h"
using namespace std;

int main() {
    int N, M; // número de nodos e arestas no grafo
    cin >> N >> M;
    vetor<vetor<int>> grafo(N + 1);

    for (int i = 0; i < M; ++i) { // lendo as infos das arestas
        int U, V;
        cin >> U >> V; // aresta entre U e V
        grafo[U].push_back(V);
        grafo[V].push_back(U);
    }

    // busca em largura partindo do nodo 1
    bfs(grafo, 1);

    // poderíamos fazer o BFS partindo de várias origens também
    // isso recebe o nome de Multi-Source BFS
    // e a única diferença é que... Partimos de várias origens kk

    return 0;
}
