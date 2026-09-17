#ifndef Comparadores
#define Comparadores

template<typename T>
struct maior {
    bool operator()(const T& a, const T& b) const {
        return a > b;
    }
};

template<typename T>
bool max(T a, T b) { return a > b; }

template<typename T>
struct menor {
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

template<typename T>
bool min(T a, T b) { return a < b; }

#endif
