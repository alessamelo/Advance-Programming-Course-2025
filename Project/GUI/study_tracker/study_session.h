#ifndef STUDY_SESSION_H
#define STUDY_SESSION_H

#include <SFML/Graphics.hpp>
#include <string>

class StudySession {
private:
    float accumulatedTime;
    bool paused;
    sf::Clock clock;

public:
    StudySession();

    void Start();
    void Pause();
    void Resume();
    void Reset();
    void Update();
    bool IsPaused() const;
    float GetElapsedTime() const;
    std::string GetFormattedTime() const;
};

#endif
