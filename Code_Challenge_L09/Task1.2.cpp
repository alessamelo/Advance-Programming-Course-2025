#include <iostream>
#include <string>

//Write a code of a simple template function
template <typename T> 
T maximo(T a, T b) {
    if (a > b){
        return a;
    } 
    if (a == b) {
        std::cout << "Los valores" << a << " y " << b << "son iguales" << std::endl;
        return a;
    }
    else {
        return b;
    }
}

template <typename T>
T maximo (T a, T b, T c){
    return maximo(a, maximo(b, c));
}

int main(){
    std::cout << maximo(5, 10) << std::endl;
    std::cout << maximo(3.5, 2.1) << std::endl;
    std::cout << maximo(std::string ("orange"), std::string ("watermelon"));

    std::cout << maximo(5, 10, 11) << std::endl;
    std::cout << maximo(3.5, 2.1, 5.5) << std::endl;
    std::cout << maximo(std::string ("orange"), std::string ("watermelon"), std::string ("strawberry"));
    return 0;
}