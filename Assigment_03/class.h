#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include <string>

class Character {
private:
    std::string name;
    int health;
    int speed;

public:
    Character(); 
    Character(std::string name, int health, int speed);

    std::string getName() const;
    void setName(const std::string &name);

    int getHealth() const;
    void setHealth(int health);

    int getSpeed() const;
    void setSpeed(int speed);

    virtual void showInfo() const;

    void takeDamage(int damage);
};

class Sonic : public Character {
private:
    bool isSuperSonic;

public:
    Sonic(); 
    Sonic(std::string name, int health, int speed, bool isSuperSonic); 

    void transformIntoSuperSonic();

    bool getIsSuperSonic() const;

    void showInfo() const override;
};

#endif 
