#ifndef HeapSort
#define HeapSort

template<typename Iterador, typename Comparador>
void heapSort(Iterador begin, Iterador end, Comparador cmp) {

}

template<typename Iterador>
void heapSort(Iterador begin, Iterador end) {
    heapSort(begin, end, [](const auto& a, const auto& b){
        return a < b;
    });
}

#endif
