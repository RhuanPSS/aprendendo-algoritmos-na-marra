#include <iostream>
#include "../estruturas/Vetor.h"
#include "../algoritmos/Kruskal.h"
using namespace std;

int main() {
    int N, M; // número de nodos e arestas no grafo
    cin >> N >> M;
    struct aresta {
        int U, V, peso;
        bool operator < (const aresta& outro) const {
            if (peso == outro.peso) {
                return U < outro.U;
            }
            return peso < outro.peso;
        }
        bool operator <= (const aresta& outro) const {
            if (peso == outro.peso) {
                return U <= outro.U;
            }
            return peso <= outro.peso;
        }
    };
    vetor<vetor<aresta>> grafo(N + 1);

    for (int i = 0; i < M; ++i) { // lendo as infos das arestas
        int U, V, peso;
        cin >> U >> V >> peso; // aresta entre U e V com peso
        grafo[U].push_back({U, V, peso});
        grafo[V].push_back({V, U, peso});
    }

    // algoritmo de kruskal
    int mst = kruskal(grafo);
    cout << "Custo total da arvore geradora minima: " << mst << '\n';

    return 0;
}
