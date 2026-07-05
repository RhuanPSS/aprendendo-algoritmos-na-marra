#ifndef HeapSort
#define HeapSort

// função auxiliar para o intro sort
template<typename Iterador, typename Comparador>
void heapSort(Iterador begin, Iterador end, Comparador cmp) {
    // a ideia é fazer o heap pra cima pra cada subárvore (com exceção da raíz)
    // depois pega a raíz e troca com o último elemento do vetor
    // repete o processo mas sem este último elemento e por aí vai :D
     while (begin < end) {
        int sz = end - begin;
        for (int idx = 1; idx < sz; ++idx) {
            int last = idx;
            int pai = (idx - 1) / 2;
            while (pai != last && cmp(*(begin + pai), *(begin + last))) {
                auto aux = *(begin + last);
                *(begin + last) = *(begin + pai);
                *(begin + pai) = aux;
                last = pai;
                pai = (pai - 1) / 2;
            }
        }
        auto aux = *begin;
        *begin = *(end - 1);
        *(end - 1) = aux;
        --end;
     }
}

template<typename Iterador>
void heapSort(Iterador begin, Iterador end) {
    heapSort(begin, end, [](const auto& a, const auto& b){
        return a < b;
    });
}

#endif
