#include <iostream>

template <typename X>
X sum(X x) {
    return x;
}

template <typename X, typename... Others>
X sum(X x, Others... others) {
    return x + sum(others...);
}

int main() {
    std::cout << sum(10, 20, 30, 40) << std::endl;        
    std::cout << sum(5.5, 4.5, 6.0) << std::endl;        
}
