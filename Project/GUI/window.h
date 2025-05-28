
#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Graphics.hpp>
#include <string>

class WindowInit {
private:
    unsigned int width;
    unsigned int height;
    sf::RenderWindow window;
    sf::Font font;

public:
    WindowInit();
    void PollEvents();
    void Draw(const sf::Drawable& drawable);
    void LoadFont(sf::Font &font, std::string str);
    void Clear();
    void Display();
    bool IsOpen() const;
    sf::RenderWindow& GetRenderWindow();
};

#endif