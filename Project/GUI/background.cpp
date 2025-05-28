#include "window.h"
#include "animation.h"
#include "button.h"
#include "menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <optional>

int main() {
    //Iniciar ventana
    WindowInit window;

    //Iniciar fuente texto
    sf::Font font;
    window.LoadFont(font, "Images/fonts/LLPIXEL3.ttf");

    //Iniciar Animacion Inicial Gojo
    Animation gojo;
    gojo.LoadTexture("Images/characters/Gojo3.png", 256, 256, 8, 0.2f); // 8 frames, 0.2s por frame
    gojo.GetSprite().setPosition({320, 400});

    //Iniciar Start Button
    Button startButton("Images/buttons/Start_button.png", "Start", {320, 700}, {2.0f, 2.0f}, 200, 80);

    sf::Clock clock;

    // Main loop
    while (window.IsOpen()) {
        window.PollEvents();

        // Detectar clic
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window.GetRenderWindow());
            if (startButton.IsClicked(mousePos)) {
                std::cout << "Boton START presionado!" << std::endl;
                // Cerrar ventana principal
                RunMenuScene();
                return 0;

            }
        }

        window.Clear();
        float dt = clock.restart().asSeconds();
        gojo.Update(dt);

        window.Draw(gojo.GetSprite());
        startButton.Draw(window.GetRenderWindow());
        window.Display();
    }
    return 0;
}


