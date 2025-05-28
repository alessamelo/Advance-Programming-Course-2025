#include "study_session.h"
#include <sstream>
#include <iomanip>
#include <chrono>


StudySession::StudySession() : accumulatedTime(0.f),  paused(true) {}

void StudySession::Start() {
    clock.restart();
    paused = false;
    accumulatedTime = 0.f;
}

void StudySession::Pause() {
    if (!paused) {
        accumulatedTime += clock.getElapsedTime().asSeconds();
        paused = true;
    }
}

void StudySession::Resume() {
    if (paused) {
        clock.restart();
        paused = false;
    }
}

void StudySession::Reset() {
    accumulatedTime = 0.f;
    paused = true;
}

void StudySession::Update() {
    if (!paused) {
        // actualizamos el tiempo acumulado pero sin reiniciar
        accumulatedTime += clock.restart().asSeconds();
    }
}

float StudySession::GetElapsedTime() const {
    return paused ? accumulatedTime : accumulatedTime + clock.getElapsedTime().asSeconds();
}

std::string StudySession::GetFormattedTime() const {
    int totalSeconds = static_cast<int>(GetElapsedTime());
    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;

    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << hours << ":"
        << std::setw(2) << minutes << ":"
        << std::setw(2) << seconds;
    return oss.str();
}

bool StudySession::IsPaused() const {
    return paused;
}
