#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User {
public:
    explicit User(const std::string& name);
    ~User();
    
    // Copy operations
    User(const User& other);
    User& operator=(const User& other);
    
    // Deleted move operations
    User(User&& other) = delete;
    User& operator=(User&& other) = delete;
    
    // Member functions
    void add_friend(const std::string& name);
    std::string get_name() const;
    size_t size() const;
    void set_friend(size_t index, const std::string& name);
    
    // Operators
    User& operator+=(User& other);
    bool operator<(const User& other) const;  // Added const
    
    // Friend declaration
    friend std::ostream& operator<<(std::ostream& os, const User& user);

private:
    std::string _name;
    std::string* _friends;
    size_t _size;
    size_t _capacity;
};

// Non-member function declaration
std::ostream& operator<<(std::ostream& os, const User& user);

#endif // USER_H
