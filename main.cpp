#include <iostream>
#include "estruturas/Vetor.h"
using namespace std;

int main() {
	// bo depurar as parada na main

	int n;
	cin >> n;
	vetor<int> vet(n);
	for (int& i : vet) {
		cin >> i;
	}
	for (int i : vet) {
		cout << i + 2 << ' ';
	}
	cout << '\n'; // meu std::vector da Alienxpress tá funfando :D (eu acho)

	return 0;
}
