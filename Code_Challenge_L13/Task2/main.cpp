#include "Buffer.h"

int main() {
    Buffer b1(10);
    Buffer b2 = b1;            // Copy constructor
    Buffer b3 = std::move(b1); // Move constructor

    b2 = b3;                   // Copy assignment
    b3 = Buffer(20);           // Move assignment

    return 0;
}
