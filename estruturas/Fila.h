#ifndef Fila_h
#define Fila_h
#include <iostream>
#include "Vetor.h"
/*
Uma fila nada mais é doq uma pilha esvaziada em outra pilha.
Por exemplo, suponha que eu tenha duas pilhas:
pilha1 = {1, 2, 3, 4}
pilha2 = {}

daí eu esvazio a pilha1 na pilha2:
pilha1 = {}
pilha2 = {4, 3, 2, 1}

Agora, o elemento no topo da pilha2 (4) representa o primeiro elemento
de uma fila! :D

Então podemos fazer o seguinte (pra evitar de mexer com std:deque):
Sempre que quisermos colocar um elemento na fila, iremos colocar na
pilha1;
Sempre que quisermos o primeiro elemento da fila, vamos pegar o
primeiro elemento da pilha2. Isto vale no caso de remover também;
Caso a pilha2 estiver vazia e quisermos o primeiro elemento. Vamos
esvaziar a pilha1 na pilha2 para poder fazer a operação.

Supondo que a fila possui N elementos. Por mais que estamos mexendo
com duas pilhas, vamos percorrer todos os N elementos no máximo duas
vezes e não mais que isso para poder representá-la. A complexidade
se mantém O(N) (já que a constante 2 some e bla bla bla :D)!

Nossa Rhuan, mas O(2 * N) não é pior que a implementação do std:deque?
R: Irmão... Tu sabe como que o std:deque é implementado? Não querendo
ser rude mas só Deus sabe como que aquilo funciona kk
*/

template<typename T>
class fila {
private:
    vetor<T> pilha1; // Um vetor funciona como uma pilha se
    vetor<T> pilha2; // tu parar pra pensar...

public:
    fila() {}

    int size() { return pilha1.size() + pilha2.size(); }

    bool empty() { return pilha1.empty() & pilha2.empty(); }

    void push(T k) {
        pilha1.push_back(k);
    }

    T pop() {
        if (empty()) {
            std::cout << "A fila tá vazia man D:\n";
            std::exit(1);
        }
        if (pilha2.empty()) {
            while (!pilha1.empty()) {
                pilha2.push_back(pilha1.back());
                pilha1.pop_back();
            }
        }
        return pilha2.pop_back();
    }

    T top() {
        if (empty()) {
            std::cout << "A fila tá vazia man D:\n";
            std::exit(1);
        }
        if (pilha2.empty()) {
            while (!pilha1.empty()) {
                pilha2.push_back(pilha1.back());
                pilha1.pop_back();
            }
        }
        return pilha2.back();
    }
};

#endif
