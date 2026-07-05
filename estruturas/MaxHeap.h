#ifndef MaxHeap
#define MaxHeap // fila de prioridade só é "ruim" na vida real :3
#include <iostream>
#include "Vetor.h"
#include "Comparadores.h"

template<typename T, typename Comparador = maior<T>>
class maxHeap {
private:
    vetor<T> heap; // rip
    Comparador cmp;

    void heapifar_acima(size_t idx) { // checa o pai, depois o pai do pai, depois o (tá bom, parei)
        while (idx > 0) {
            size_t pai = (idx - 1) / 2;
            if (cmp(heap[pai], heap[idx])) break;
            T aux = heap[idx];
            heap[idx] = heap[pai];
            heap[pai] = aux;
            idx = pai;
        }
    }

    void heapifar_abaixo(size_t idx) { // checa os filhos, depois os filhos do filho, depois o ( -.- )
        while (true) {
            size_t best = idx; // best é o cara que mais vence nas comparações
            size_t esq = 2 * idx + 1;
            size_t dir = 2 * idx + 2;
            if (esq < heap.size() && cmp(heap[esq], heap[best])) best = esq;
            if (dir < heap.size() && cmp(heap[dir], heap[best])) best = dir;
            if (best == idx) break;
            T aux = heap[best];
            heap[best] = heap[idx];
            heap[idx] = aux;
            idx = best; // num vai esquecer de atualizar o índice zé
        }
    }

public:
    maxHeap() {}

    maxHeap(Comparador c) : cmp(c) {}

    size_t size() const { return heap.size(); }

    bool empty() const { return heap.size() == 0; }

    void push(T k) {
        heap.push_back(k); // se eu insiro no final
        heapifar_acima(heap.size() - 1); // então só ripa os cara no teto
    }

    T front() const {
        if (heap.empty()) {
            std::cerr << "Nem tem nada na fila man D:\n";
            exit(1);
        }
        return heap[0];
    }

    T pop() { // azideia aqui é trocar a raíz com o último mano e ripar da nova raíz pra baixo
        T popado = front();
        size_t fim = heap.size() - 1;
        T aux = heap[0];
        heap[0] = heap[fim];
        heap[fim] = aux;
        heap.pop_back();
        heapifar_abaixo(0);
        return popado;
    }
};

#endif
