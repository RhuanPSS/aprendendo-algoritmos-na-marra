#ifndef Vetor
#define Vetor // bo replicar std::vector pq é a melhor STL que tem
#include <iostream>

// vetor é pop, vetor é vida, vetor é tudo
template<typename T> // generaliza o tipo pra mim compilador, porfa
class vetor {
private:
    size_t cap = 1; // capacidade total do array dinâmico
    size_t len = 0; // quantidade de elementos no array dinâmico
    T* arr = nullptr; // o bixão ae

public:
    // construtor base
    vetor() : cap(1), len(0), arr(new T[1]) {}

    // construtores inicializados
    vetor(size_t init_len) : cap(init_len), len(init_len), arr(new T[init_len]()) {}

    vetor(size_t init_len, T val) : cap(init_len), len(init_len), arr(new T[init_len]) {
        for (size_t i = 0; i < len; ++i) {
            arr[i] = val;
        }
    }

    // se passar uma copia ocorre oq? (Rhuan: é algo a se pensar)
    vetor(const vetor& copia) : cap(copia.cap), len(copia.len), arr(new T[copia.cap]) {
        for (size_t i = 0; i < len; ++i) {
            arr[i] = copia.arr[i];
        }
    }

    // Perguntei pra uma IA se faltava algo e ela mencionou um tal de "Rule of Three"
    /*
        se você define qualquer um entre destrutor,
        construtor de cópia e operador de atribuição, você
        quase sempre precisa definir os três.
    */
    // ou seja, eu só tinha lembrado da primeira regra kk (nem sabia q era regra...)
    // "homens. Destruam tudo e todos. Ataquem o templo de Atena."
    // (Destrutor, a primeira regra esquecida :3)
    ~vetor() { delete[] arr; }

    // Operador de atribuição (a segunda regra esquecida :3)
    vetor& operator=(const vetor& outro) {
        if (this == outro) return *this;
        delete[] arr;
        cap = outro.cap;
        len = outro.len;
        arr = new T[cap];
        for (size_t i = 0; i < len; ++i) {
            arr[i] = outro.arr[i];
        }
        return *this;
    }

    // eu ouvi dizer que é importante diferenciar o operador [] const e não-const, falta estudar o pq agora :P
    // R: cria um vetor constante e vê se funciona sem as outras versões do operador.
    const T& operator[](size_t idx) const {
        // considerando size_t como um tipo unsigned, pq é inconveniente checar por idx < 0?
        // R: se é UNsigned, então não tem sinal e não pode ser negativo :/
        if (idx >= len) {
            std::cerr << "Indice invalido D:\n";
            std::exit(1);
        }
        return arr[idx];
    }

    T& operator[](size_t idx) {
        if (idx >= len) {
            std::cerr << "Indice invalido D:\n";
            std::exit(1);
        }
        return arr[idx];
    }

    size_t size() const { return len; }

    bool empty() const { return len == 0; }

    void push_back(T x) {
        if (len == cap) { // se liga no bixão crescendo
            cap *= 2;
            T* temp = new T[cap];
            for (size_t i = 0; i < len; ++i) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
        arr[len] = x;
        ++len;
    }

    T pop_back() { // no std::vector ele retorna o valor popado tbm? Sla... Bo retorna ae
        if (len == 0) {
            std::cout << "Tem mais nada pra popar nao man D:\n";
            std::exit(1);
        }
        T popado = arr[len - 1];
        --len;
        return popado;
    }

    void assign(size_t new_len, T val) { // nem sei se vou usar isso, mas é interessante \o/
        delete[] arr;
        cap = 1, len = new_len;
        while (cap < len) cap *= 2;
        arr = new T[cap];
        for (size_t i = 0; i < len; ++i) {
            arr[i] = val;
        }
    }

    // agora os loop for range for loop range for funciona !!!!
    T* begin() { return arr; }
    T* end() { return arr + len; }
    const T* begin() const { return arr; }
    const T* end() const { return arr + len; }
};

#endif
