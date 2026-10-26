#ifndef Kruskal_h
#define Kruskal_h
#include "../estruturas/Vetor.h"
#include "../estruturas/DSU.h"
#include "Sort.h"
using namespace std;
/*
O algoritmo de Kruskal nos ajuda a encontrar uma árvore geradora mínima
(minimum spanning tree) em um grafo.

A forma como o algoritmo funciona se baseia em uma ideia gulosa simples:
Vamos ordenar todas as arestas do grafo pelo menor peso.
Agora é simples, vamos percorrer todas as arestas ordenadas e selecionar
as que possuem o menor peso mas tendo o cuidado para não formar ciclos!

Por que ter o cuidado de não formar ciclos?
R: Uma árvore é um grafo acíclico (sem ciclos) significando que se
ela tiver N nodos, terá exatamente N - 1 arestas.

Como podemos verificar se, dado uma aresta qualquer do grafo, ao selecionar
esta aresta iremos formar ou não um ciclo?
Inicialmente, todos os nodos do grafo estão desconexos, ou seja,
o conjunto que eles fazem parte é um conjunto único dele mesmo.
Ao selecionar uma aresta X----Y é o equivalente a juntar os nodos
X e Y em um mesmo conjunto. Seja X o nome do conjunto em que o nodo X está contido.
Se selecionarmos a aresta X----Z, no conjunto X teremos os nodos {X, Y, Z} e
isto significa que todos estes nodos estão conexos (partindo de um é possível chegar em outro).

Perceba que, se selecionarmos a aresta Y----Z, teríamos um ciclo:
Grafo antes da seleção
             X
            / \
           /   \
          Y     Z

Grafo depois da seleção
             X
            / \
           /   \
          Y --- Z

Com isto, podemos concluir que, se dois nodos A e B fazem parte do
mesmo conjunto, não podemos selecionar a aresta A----B pois formaríamos
um ciclo!

Agora a única coisa que nos resta é decidir como representar os conjuntos!
A estrutura DSU é perfeita para isso, uma vez que podemos juntar dois valores
e dizer se dois valores estão juntos ou disjuntos em tempo quase constante!
*/
template<typename T>
int kruskal(const vetor<vetor<T>>& grafo) {
    // ------ inicializando estruturas ------
    const int N = grafo.size();
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
    vetor<aresta> ares;
    dsu DSU(N + 1);
    for (int u = 1; u < N; ++u) { // pegando todas as aresta do grafo
        for (auto [_, v, peso] : grafo[u]) {
            ares.push_back({u, v, peso});
        }
    }
    sort(ares.begin(), ares.end());
    int mst = 0; // custo da árvore geradora mínima
    // ----------------------------------------

    cout << "A árvore geradora mínima possui as arestas abaixo:\n";
    for (size_t i = 0; i < ares.size(); ++i) {
        aresta curr = ares[i];

        // os nodos da aresta já fazem parte do mesmo conjunto (ciclo)
        if (DSU.same_set(curr.U, curr.V)) continue; // daí só ignora

        // caso contrário, une os dois nodos e soma o peso da aresta
        DSU.union_set(curr.U, curr.V);
        mst += curr.peso;
        cout << curr.U << " --- " << curr.V << " { peso = " << curr.peso << " }\n";
    }
    return mst;
}

#endif
