#include "window.h"
#include <iostream>


WindowInit::WindowInit()
    : window(sf::VideoMode({640, 800}), "C++") {
    window.setFramerateLimit(60);
}

void WindowInit::PollEvents() {
    while (std::optional<sf::Event> event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}



void WindowInit::LoadFont(sf::Font &font, std::string str){
    if(!font.openFromFile(str)){
        std::cerr <<"ERROR:  COULD NOT LOAD FILE::"<< str<< "!!!"<< std::endl;
    }
}

void WindowInit::Draw(const sf::Drawable& drawable) {
    window.draw(drawable);
}

void WindowInit::Clear() {
    window.clear(sf::Color(0xFFC0CBFF));
}

void WindowInit::Display() {
    window.display();
}

bool WindowInit::IsOpen() const {
    return window.isOpen();
}

sf::RenderWindow& WindowInit::GetRenderWindow() {
    return window;
}
