#include <iostream>
#include "Vetor.h"
using namespace std;

/*
DSU
D -> Disjoint
S -> Set
U -> Union

Imagine que temos um conjunto A e um conjunto B.
Queremos poder juntar ambos os conjuntos e poder
dizer qual conjunto um elemento X pertence, tudo
da maneira mais rápida possível.

Podemos simplesmente criar um grafo e alocar arestas
entre os elementos. Cada aresta representa que A depende de B
e/ou vice-versa. Cada componente no grafo representará um
conjunto e podemos escolher um elemento arbitrário
pertencente ao componente para representá-lo.
Então, podemos realizar um DFS no componente percente a um elemento
e encontrar seu respectivo conjunto.
Logo, dado dois elementos A e B, verificar se ambos fazem parte do
mesmo conjunto teria complexidade O(N) no pior caso, em que N é o
total de elementos. Para Q consultas, teríamos O(Q*N) no pior caso;

Podemos otimizar a complexidade para simplesmente O(Q + N) com
DSU.
Dado o conjunto '1' a seguir:
         _ 1
        |
        2
        |
        3
        |
        4
        |
        5
Uma otimização que podemos fazer é o "Path Compressing".
Iremos simplesmente "remover" uma aresta que não liga diretamente ao
representante do conjunto. Em outras palavras, transformamos o grafo
em um "grafo-estrela" em que o nodo central é o representante do
conjunto:
            2
            |
       3 -- 1 -- 4
            |
            5
Agora, se guardarmos o 'pai' de cada elemento temos o seguinte:
pai[2] = 1 # pai[3] = 1 # pai[4] = 1 # pai[5] = 1 e
pai[1] = 1 <-- pai do elemento central é sempre ele mesmo.
Agora, dado dois elementos A e B, podemos simplesmente checar se
seus pais são iguais, caso for, então ambos os elementos estão
no mesmo conjunto e não precisamos mais da busca DFS.

Essa simples otimização já transforma a complexidade em
aproximadamente O(Qlog(N)) se feita corretamente.

|K| --> tamanho de K
Imagine que temos dois grafos-estrelas X e Y em que |X| >>> |Y| e
queremos juntar ambos os conjuntos.
É melhor juntar o conjunto X no conjunto Y ou realizar o oposto?
Vamos reduzir o problema em algo mais "comum". Temos duas caixas
de refri e queremos colocar todos os refris em uma única caixa
para poupar espaço, é mais fácil pegar todos os refris da caixa
que possui mais refris e colocar na caixa que tem menos, ou fazer
o oposto? A resposta para essa pergunta é a solução para otimizar
a estrutura para quase que constante :D
            a                   e
            |                   |
       b -- Y              f -- X -- g
É mais eficiente juntar o conjunto Y no conjunto X, mas ao invés
de juntar todos os elementos do conjunto Y, podemos juntar somente
o elemento central Y no elemento central X:
        e
        |
   f -- X -- g
        |
   b -- y -- a
É claro que, sempre que precisarmos percorrer os elementos que não
estão diretamente conectados em X, iremos realizar o Path Compressing
nestes elementos para otimizar a estrutura. Perceba que quanto mais
operações é feita na estrutura, mais rápida ela ficará e portanto,
sua complexidade é quase que O(1) tanto para realizar operações de
junção ou consultas. Este "quase O(1)" possui um nome mais formal
--> O(1) amortizado
que é bem melhor que O(log(N))

Isto reduz a complexidade do nosso problema para praticamente O(Q)
em que Q é o número de consultas \o/
*/

int N, Q; // número de elementos no total e número de consultas
vetor<int> pai, tamanho; // estruturas para o DSU

void init(const int len) {
    pai.resize(len);
    tamanho.resize(len);
    for (int i = 0; i < len; ++i) {
        pai[i] = i; // inicialmente, todos os elmentos são únicos em seus conjuntos
        tamanho[i] = 1; // e o tamanho do conjunto é 1 pois só tem ele mesmo.
    }
}

int find_set(int v) {
    // se o nodo atual é pai dele mesmo, então ele é o representante do conjunto.
    if (pai[v] == v) return v;
    //return find_set(pai[v]); // versão sem path compressing
    return pai[v] = find_set(pai[v]); // path compressing
}

bool union_set(int a, int b) {
    // primeiro, pega o conjunto de cada elemento
    a = find_set(a);
    b = find_set(b);
    if (a == b) return false; // os dois já fazem parte do mesmo conjunto, então só ignora
    if (tamanho[a] > tamanho[b]) swap(a, b); // o conjunto a sempre será o menor
    pai[a] = b; // junta o menor conjunto no maior conjunto
    tamanho[b] += tamanho[a]; // e soma o tamanho do maior conjunto
    return true;
}

int main() {
    cout << "Quantidade de elementos (indexado em 0): ";
    cin >> N;
    cout << "Quantidade de consultas: ";
    cin >> Q;

    // inicializando as estruturas
    init(N); // indexado em 0

    for (int i = 1; i <= Q; ++i) {
        cout << "Consulta " << i << ":\n";
        cout << "1 -> consulta o conjunto de X.\n";
        cout << "2 -> consulta se A e B fazem parte do mesmo conjunto.\n";
        cout << "3 -> junta A e B.\n";
        int op;
        cin >> op;
        switch (op) {
            case 1:
                int X;
                cout << "Informe X: ";
                cin >> X;
                cout << "Conjunto de " << X << " = " << find_set(X) << '\n';
                break;
            case 2:
                int A, B;
                cout << "Informe A e B: ";
                cin >> A >> B;
                if (find_set(A) == find_set(B)) {
                    cout << A << " e " << B << " estão juntos.\n";
                } else {
                    cout << A << " e " << B << " estão disjuntos.\n";
                }
                break;
            case 3:
                cout << "Informe A e B: ";
                cin >> A >> B;
                if (union_set(A, B)) cout << "Juntando " << A << " e " << B << '\n';
                else cout << A << " e " << B << " já estão unidos\n";
                break;
            default:
                cout << "pass\n";
                break;
        }
    }

    return 0;
}
