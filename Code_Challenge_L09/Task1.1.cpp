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

int main(){
    std::cout << maximo(5, 10) << std::endl;
    std::cout << maximo(3.5, 2.1) << std::endl;
    std::cout << maximo(std::string ("orange"), std::string ("watermelon"));
    return 0;
}