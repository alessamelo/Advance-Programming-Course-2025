#include "user.h"
#include <algorithm>

// Constructor
User::User(const std::string& name) 
    : _name(name), _friends(nullptr), _size(0), _capacity(0) {}

// Destructor
User::~User() {
    delete[] _friends;
}

// Copy constructor
User::User(const User& other) 
    : _name(other._name), _size(other._size), _capacity(other._capacity) {
    _friends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
        _friends[i] = other._friends[i];
    }
}

// Copy assignment
User& User::operator=(const User& other) {
    if (this != &other) {
        delete[] _friends;
        
        _name = other._name;
        _size = other._size;
        _capacity = other._capacity;
        
        _friends = new std::string[_capacity];
        for (size_t i = 0; i < _size; ++i) {
            _friends[i] = other._friends[i];
        }
    }
    return *this;
}

void User::add_friend(const std::string& name) {
    if (_size == _capacity) {
        _capacity = _capacity == 0 ? 1 : _capacity * 2;
        std::string* newFriends = new std::string[_capacity];
        for (size_t i = 0; i < _size; ++i) {
            newFriends[i] = _friends[i];
        }
        delete[] _friends;
        _friends = newFriends;
    }
    _friends[_size++] = name;
}

std::string User::get_name() const {
    return _name;
}

size_t User::size() const {
    return _size;
}

void User::set_friend(size_t index, const std::string& name) {
    if (index < _size) {
        _friends[index] = name;
    }
}

User& User::operator+=(User& other) {
    this->add_friend(other._name);
    other.add_friend(this->_name);
    return *this;
}

bool User::operator<(const User& other) const {
    return _name < other._name;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "User(name=" << user._name << ", friends=[";
    for (size_t i = 0; i < user._size; ++i) {
        if (i != 0) os << ", ";
        os << user._friends[i];
    }
    os << "])";
    return os;
}
