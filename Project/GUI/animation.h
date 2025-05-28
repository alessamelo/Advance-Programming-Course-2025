#ifndef ANIMATION_HPP
#define ANIMATION_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <optional>

class Animation {
private:
    std::optional<sf::Sprite> sprite; // <--- Esto es lo importante
    sf::Texture texture;
    int frameWidth;
    int frameHeight;
    int currentFrame;
    int totalFrames;
    float timer;
    float timerMax;

public:
    Animation();
    void LoadTexture(const std::string& path, int frameW, int frameH, int totalF, float frameTime);
    void Update(float dt);
    void Draw(sf::RenderWindow& window);
    sf::Sprite& GetSprite();
};

#endif