#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <string>
#include <optional>

class Button {
private:
    sf::Texture texture;
    std::optional<sf::Sprite> sprite;
    std::string name;


public:
    Button(const std::string& imagePath, const std::string& name, sf::Vector2f position, sf::Vector2f scale, int width, int height);
    void Draw(sf::RenderWindow& window) const;
    bool IsClicked(const sf::Vector2i& mousePos) const;
    const std::string& GetName() const;
    sf::Sprite& GetSprite();
};

#endif
