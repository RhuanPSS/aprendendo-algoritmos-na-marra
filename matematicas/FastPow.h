#ifndef FastPow
#define FastPow

const int64_t _infp = 9223372036854775783; // 2^63 - 25 é primo

int64_t fpow(int64_t x, int64_t y, const int64_t mod) {
    int64_t ret = 1;
    while (y > 0) {
        if (y & 1) {
            ret = ret * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}

int64_t fpow(int64_t x, int64_t y) {
    return fpow(x, y, _infp);
}

#endif
