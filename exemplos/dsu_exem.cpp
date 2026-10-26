#include <iostream>
#include "../estruturas/DSU.h"
using namespace std;

int main() {
    int N, Q;
    cout << "Quantidade de elementos (indexado em 0): ";
    cin >> N;
    cout << "Quantidade de consultas: ";
    cin >> Q;

    // inicializando a estrutura
    dsu conjunto(N);

    for (int i = 1; i <= Q; ++i) {
        cout << "Consulta " << i << ":\n";
        cout << "1 -> consulta o conjunto de X.\n";
        cout << "2 -> consulta se A e B fazem parte do mesmo conjunto.\n";
        cout << "3 -> junta A e B.\n";
        int op;
        cin >> op;
        switch (op) {
            case 1: {
                int X;
                cout << "Informe X: ";
                cin >> X;
                cout << "Conjunto de " << X << " = " << conjunto.find_set(X) << '\n';
                break;
            }
            case 2: {
                int A, B;
                cout << "Informe A e B: ";
                cin >> A >> B;
                if (conjunto.same_set(A, B)) {
                    cout << A << " e " << B << " estão juntos.\n";
                } else {
                    cout << A << " e " << B << " estão disjuntos.\n";
                }
                break;
            }
            case 3: {
                int A, B;
                cout << "Informe A e B: ";
                cin >> A >> B;
                if (conjunto.union_set(A, B)) cout << "Juntando " << A << " e " << B << '\n';
                else cout << A << " e " << B << " já estão unidos\n";
                break;
            }
            default:
                cout << "pass\n";
                break;
        }
    }

    return 0;
}
