#include <iostream>

template <int N>
struct Factorial {
    static constexpr int resultado = N * Factorial<N - 1>::resultado;
};

template <>
struct Factorial<0> {
    static constexpr int resultado = 1;
};

int main() {
    constexpr int valor = Factorial<6>::resultado;
    std::cout << valor << std::endl; 
}
