#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1 = {1, 2, 3, 4};
    std::vector<int> v2 = v1;        // Copy constructor
    std::vector<int> v3 = std::move(v1); // Constructor de movimiento
    //El vector v1 queda vacio

    std::cout << "v1 size: " << v1.size() << std::endl;
    std::cout << "v2 size: " << v2.size() << std::endl;
    std::cout << "v3 size: " << v3.size() << std::endl;

    return 0;
}

/*
Questions:

1. What is the ouput of the program?
v1 size: 0
v2 size: 4
v3 size: 4

2. Why does v1.size() return 0 after the move?
Because we are using the move constructor, and all the content of `v1` is transferred to `v3`.

3. What does std::move do?
std::move` transform v1 into a mobile value, allowing to tranfer v1 contents to another memory direction 

4. Why is v1 still in a valid but unspecified state?
Because the move operation transfers the internal resources (like memory pointers) from v1 to v3.  
After the move, v1 remains in a valid state, so we can call methods like .size() without crashing,  
but its internal content is unspecified, typically empty.

*/