#include <iostream>
#include <string>

template <typename T>
void printAll(T t) {
    std::cout << t << std::endl;
}

template <typename T, typename... Args>
void printAll(T t, Args... args) {
    std::cout << t << " ";
    printAll(args...);
}

int main() {
    printAll(1, 2.5, "Hello", 'c'); 
    printAll("Name:", std::string("Alice"), 25, 3.14f); 
    printAll(true, 42, 'A', "World"); 
}
