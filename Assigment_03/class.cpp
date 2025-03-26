#include "class.h"
#include <iostream>

Character::Character() : name("Unknown"), health(100), speed(5) {}

Character::Character(std::string name, int health, int speed)
    : name(name), health(health), speed(speed) {}

std::string Character::getName() const {
    return name;
}

void Character::setName(const std::string &name) {
    this->name = name;
}

int Character::getHealth() const {
    return health;
}

void Character::setHealth(int health) {
    this->health = health;
}

int Character::getSpeed() const {
    return speed;
}

void Character::setSpeed(int speed) {
    this->speed = speed;
}

void Character::showInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Speed: " << speed << std::endl;
}

void Character::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}


Sonic::Sonic() : Character("Sonic", 100, 10), isSuperSonic(false) {}

Sonic::Sonic(std::string name, int health, int speed, bool isSuperSonic)
    : Character(name, health, speed), isSuperSonic(isSuperSonic) {}

void Sonic::transformIntoSuperSonic() {
    if (getHealth() > 50) {  
        isSuperSonic = true;
        setSpeed(getSpeed() + 5);  
        std::cout << getName() << " ha transformado en Super Sonic!" << std::endl;
    } else {
        std::cout << getName() << " no tiene suficiente salud para transformarse." << std::endl;
    }
}

bool Sonic::getIsSuperSonic() const {
    return isSuperSonic;
}

void Sonic::showInfo() const {
    Character::showInfo();  
    if (isSuperSonic) {
        std::cout << "¡Es Super Sonic!" << std::endl;
    } else {
        std::cout << "No es Super Sonic." << std::endl;
    }
}
