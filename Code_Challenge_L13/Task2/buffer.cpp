#include "buffer.h"

Buffer::Buffer(size_t s) : size(s), data(new int[s]) {
    std::cout << "Constructor called\n";
}

Buffer::~Buffer() {
    delete[] data;
    std::cout << "Destructor called\n";
}


Buffer::Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {
    std::cout << "Copy constructor called\n";
    std::copy(other.data, other.data + other.size, data);
}


Buffer& Buffer::operator=(const Buffer& other) {
    std::cout << "Copy assignment called\n";
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        std::copy(other.data, other.data + size, data);
    }
    return *this;
}

Buffer::Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
    std::cout << "Move constructor called\n";
    other.data = nullptr;
    other.size = 0;
}

Buffer& Buffer::operator=(Buffer&& other) noexcept {
    std::cout << "Move assignment called\n";
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}
