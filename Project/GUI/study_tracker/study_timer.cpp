#include "study_timer.h"
#include "../button.h"
#include "../window.h"
#include "study_session.h"
#include "study.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <optional>

void RunStudyTimerScene(const std::string& subjectName) {
    WindowInit timerWindow;
    StudySession session;
    Estudio estudio("registro_estudio.csv");

    std::string nombre_dia, fecha_formateada;
    int dia_mes;
    estudio.obtenerFechaActual(nombre_dia, dia_mes, fecha_formateada);
    
    session.Start();

    Button pauseButton("Images/buttons/play.png", "play", {100.f, 700.f}, {1.0f, 1.0f}, 200, 200);
    Button stopButton("Images/buttons/stop.png", "stop", {540.f, 700.f}, {1.0f, 1.0f}, 200, 200);

    sf::Font font;
    timerWindow.LoadFont(font, "Images/fonts/LLPIXEL3.ttf");

    sf::Text timerText(font);          
    timerText.setString("00:00:00");
    timerText.setCharacterSize(36);


    sf::Clock clock;

    while (timerWindow.IsOpen()) {
        timerWindow.PollEvents();
        float dt = clock.restart().asSeconds();
        session.Update();

        sf::Vector2i mousePos = sf::Mouse::getPosition(timerWindow.GetRenderWindow());

        // Click en botones
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            if (pauseButton.IsClicked(mousePos)) {
                session.IsPaused() ? session.Resume() : session.Pause();
            }
            if (stopButton.IsClicked(mousePos)) {
                float tiempoEstudio = session.GetElapsedTime();
                estudio.registrarTiempoGUI(subjectName, tiempoEstudio, nombre_dia);
                std::cout << "Guardado: " << tiempoEstudio << " segundos\n";
                return;  // Salir de la escena
            }
        }

        // Actualizar texto del temporizador
        timerText.setString(session.GetFormattedTime());

        // Dibujar todo
        timerWindow.Clear();
        timerWindow.Draw(timerText);
        pauseButton.Draw(timerWindow.GetRenderWindow());
        stopButton.Draw(timerWindow.GetRenderWindow());
        timerWindow.Display();
    }
}

