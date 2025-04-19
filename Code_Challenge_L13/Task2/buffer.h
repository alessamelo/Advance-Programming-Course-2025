#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>

class Buffer {
private:
    int* data;
    size_t size;

public:
    Buffer(size_t s);
    ~Buffer();

    Buffer(const Buffer& other);

    Buffer& operator=(const Buffer& other);

    Buffer(Buffer&& other) noexcept;

    Buffer& operator=(Buffer&& other) noexcept;

    size_t getSize() const { return size; }
};

#endif 
