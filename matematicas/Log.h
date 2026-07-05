#ifndef Log
#define Log

// isso só vai retornar a parte inteira do resultado (num vai esquecer >:|)
int64_t log2(int64_t x) {
    return (x ? __builtin_clzll(1) - __builtin_clzll(x) : -1);
}

#endif
