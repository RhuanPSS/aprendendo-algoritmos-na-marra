#ifndef ABB
#define ABB // árvore binária de busca (essa é balanceada por AVL)
#include <iostream>
#include "Comparadores.h"

template<typename T>
class nodo {
    public:
        T key;
        int altura;
        nodo* left;
        nodo* right;
        nodo(T val) {
            left = nullptr;
            right = nullptr;
            key = val;
            altura = 1;
        }
        ~nodo() {
            delete left;
            delete right;
        }
};

template<typename T>
class abb {
    private:
        nodo<T>* root = nullptr;

        int getAltura(nodo<T>* curr) {
            if (curr == nullptr) return 0;
            return curr->altura;
        }

        int diffAltura(nodo<T>* raiz) { // pra ajudar a dizer se tá desbalanceado
            if (raiz == nullptr) return 0;
            return getAltura(raiz->left) - getAltura(raiz->right);
        }

        nodo<T>* rotDir(nodo<T>* raiz) {
            nodo<T>* filho = raiz->left;
            nodo<T>* ffDir = filho->right; // filho à direita do filho
            raiz->left = ffDir;
            filho->right = raiz;
            filho->altura = 1 + max(getAltura(filho->left), getAltura(filho->right));
            raiz->altura = 1 + max(getAltura(raiz->left), getAltura(raiz->right));
            return filho;
        }

        nodo<T>* rotEsq(nodo<T>* raiz) {
            nodo<T>* filho = raiz->right;
            nodo<T>* ffEsq = filho->left; // filho à esquerda do filho
            raiz->right = ffEsq;
            filho->left = raiz;
            filho->altura = 1 + max(getAltura(filho->left), getAltura(filho->right));
            raiz->altura = 1 + max(getAltura(raiz->left), getAltura(raiz->right));
            return filho;
        }

        nodo<T>* inserir(nodo<T>* curr, T x) {
            if (curr == nullptr) return new nodo<T>(x);
            if (curr->key > x) curr->left = inserir(curr->left, x);
            else if (curr->key < x) curr->right = inserir(curr->right, x);
            else return curr;
            curr->altura = 1 + max(getAltura(curr->left), getAltura(curr->right));
            int diff = diffAltura(curr);
            // Esquerda-Esquerda
            if (diff > 1 && x < curr->left->key) {
                return rotDir(curr->left);
            }
            // Direita-Direita
            if (diff < -1 && x > curr->right->key) {
                return rotEsq(curr->right);
            }
            // Esquerda-Direita
            if (diff > 1 && x > curr->left->key) {
                curr->left = rotEsq(curr->left);
                return rotDir(curr);
            }
            // Direita-Esquerda
            if (diff < -1 && x < curr->right->key) {
                curr->right = rotDir(curr->right);
                return rotEsq(curr);
            }
            // Sem desbalanço na inserção
            return curr;
        }

        nodo<T>* buscar(nodo<T>* curr, T x) {
            if (curr == nullptr) return nullptr;
            if (curr->key == x) return curr;
            if (curr->key > x) return buscar(curr->left, x);
            else return buscar(curr->right, x);
        }

        nodo<T>* sucessor(nodo<T>* raiz) {
            while (raiz != nullptr && raiz->left != nullptr) {
                raiz = raiz->left;
            }
            return raiz;
        }

        nodo<T>* deletar(nodo<T>* curr, T x) {
            if (curr == nullptr) return nullptr;
            if (curr->key > x) curr->left = deletar(curr->left, x);
            else if (curr->key < x) curr->right = deletar(curr->right, x);
            else {
                if (curr->left == nullptr) {
                    nodo<T>* aux = curr->right;
                    delete curr;
                    return aux;
                }
                if (curr->right == nullptr) {
                    nodo<T>* aux = curr->left;
                    delete curr;
                    return aux;
                }
                nodo<T>* aux = sucessor(curr->right);
                curr->key = aux->key;
                curr->right = deletar(curr->right, aux->key);
            }
            curr->altura = 1 + max(getAltura(curr->left), getAltura(curr->right));
            int diff = diffAltura(curr);
            // Esquerda-Esquerda
            if (diff > 1 && diffAltura(curr->left) >= 0) {
                return rotDir(curr);
            }
            // Direita-Direita
            if (diff < -1 && diffAltura(curr->right) <= 0) {
                return rotEsq(curr);
            }
            // Esquerda-Direita
            if (diff > 1 && diffAltura(curr->left) < 0) {
                curr->left = rotEsq(curr->left);
                return rotDir(curr);
            }
            // Direita-Esquerda
            if (diff < -1 && diffAltura(curr->right) > 0) {
                curr->right = rotDir(curr->right);
                return rotEsq(curr);
            }
            // segue balanceado :D
            return curr;
        }

        void inorder(nodo<T>* curr) {
            if (curr == nullptr) return;
            inorder(curr->left);
            std::cout << curr->key << ' ';
            inorder(curr->right);
        }

    public:
        ~abb() { delete root; }

        void inserir(T x) { root = inserir(root, x); }

        void deletar(T x) { root = deletar(root, x); }

        bool buscar(T x) { return buscar(root, x) != nullptr; }

        void inorder() {
            inorder(root);
            std::cout << '\n';
        }
};

#endif
