#include "button.h"
#include <iostream>

Button::Button(const std::string& imagePath, const std::string& name, sf::Vector2f position, sf::Vector2f scale, int width, int height)
    : name(name) {
    if (!texture.loadFromFile(imagePath)) {
        std::cerr << "Error loading: " << imagePath << std::endl;
    }

    sprite.emplace(texture);  // Emplace del sprite
    sprite->setTextureRect({{0, 0}, {width, height}});
    sprite->setOrigin({width / 2.f, height / 2.f});
    sprite->setPosition(position);
    sprite->setScale(scale);
}

void Button::Draw(sf::RenderWindow& window) const {
    if (sprite.has_value()) {
        window.draw(*sprite);
    }
}

bool Button::IsClicked(const sf::Vector2i& mousePos) const {
    if (!sprite.has_value()) return false;
    return sprite->getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

const std::string& Button::GetName() const {
    return name;
}

sf::Sprite& Button::GetSprite() {
    if (!sprite.has_value()) throw std::runtime_error("Sprite not loaded!");
    return *sprite;
}
