#include <iostream>

template <int N>
struct Fib {
    static constexpr int resultado = Fib<N - 1>::resultado + Fib<N - 2>::resultado;
};

template <>
struct Fib<0> {
    static constexpr int resultado = 0;
};

template <>
struct Fib<1> {
    static constexpr int resultado = 1;
};

int main() {
    constexpr int valor = Fib<8>::resultado;
    std::cout << valor << std::endl; 
}
