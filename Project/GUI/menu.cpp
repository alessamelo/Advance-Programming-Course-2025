#include "menu.h"
#include "button.h"
#include "window.h"
#include "study_tracker/study.h"
#include <iostream>
#include "study_tracker/study_timer.h"

void RunMenuScene() {
    WindowInit menuWindow;
    Estudio estudio("registro_estudio.csv");

    if (!estudio.archivoExiste()) {
        estudio.crearArchivo();
    }

    std::string nombre_dia, fecha_formateada;
    int dia_mes;

    estudio.obtenerFechaActual(nombre_dia, dia_mes, fecha_formateada);

    std::cout << "Hoy es " << nombre_dia << ", " << fecha_formateada << "\n";

    // Crear botones para las materias
    Button subject1("Images/buttons/Subject1.png", "Subject1", {160.f, 250.f}, {1.5f, 1.5f}, 200, 200);
    Button subject2("Images/buttons/Subject2.png", "Subject2", {400.f, 250.f}, {1.5f, 1.5f}, 200, 200);
    Button subject3("Images/buttons/Subject3.png", "Subject3", {160.f, 500.f}, {1.5f, 1.5f}, 200, 200);
    Button subject4("Images/buttons/Subject4.png", "Subject4", {480.f, 500.f}, {1.5f, 1.5f}, 200, 200);

    while (menuWindow.IsOpen()) {
        menuWindow.PollEvents();

        // Manejar clics
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(menuWindow.GetRenderWindow());
            if (subject1.IsClicked(mousePos)) {
                RunStudyTimerScene("Subject1");
            }
            if (subject2.IsClicked(mousePos)) {
                RunStudyTimerScene("Subject2");
            }
            if (subject3.IsClicked(mousePos)) {
                RunStudyTimerScene("Subject3");
            }
            if (subject4.IsClicked(mousePos)) {
                RunStudyTimerScene("Subject4");
            }
        }

        menuWindow.Clear();
        subject1.Draw(menuWindow.GetRenderWindow());
        subject2.Draw(menuWindow.GetRenderWindow());
        subject3.Draw(menuWindow.GetRenderWindow());
        subject4.Draw(menuWindow.GetRenderWindow());
        menuWindow.Display();
    }
}