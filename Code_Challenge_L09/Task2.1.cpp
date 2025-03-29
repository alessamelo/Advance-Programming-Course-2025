#include <iostream>
#include <string>
#include <concepts>

//concepts
template <typename T> 
concept Numeric = std::integral<T> || std::floating_point<T>;

template <Numeric T>
T add(T a, T b){
    return a+b;
}

int main() {
    int c1, c2;
    double c3, c4;

    std::cout << "Agregue dos numeros enteros: ";
    std::cin >> c1 >> c2;

    std::cout << "Agregue dos numeros flotantes: ";
    std::cin >> c3 >> c4;

    std::cout << "Suma de enteros: " << add(c1, c2) << "\n";
    std::cout << "Suma de flotantes: " << add(c3, c4) << "\n";
    return 0;
}
