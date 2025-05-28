#include "animation.h"
#include <iostream>

Animation::Animation() : frameWidth(0), frameHeight(0), currentFrame(0), totalFrames(0), timer(0.f), timerMax(1.f) {

}

void Animation::LoadTexture(const std::string& path, int frameW, int frameH, int totalF, float frameTime) {
    if (!texture.loadFromFile(path)) {
        std::cerr << "Error: Could not load " << path << std::endl;
        return;
    }
    texture.setSmooth(true);

    sprite.emplace(texture);  

    frameWidth = frameW;
    frameHeight = frameH;
    totalFrames = totalF;
    timerMax = frameTime;

    sprite->setTextureRect({{0, 0}, {frameW, frameH}});
    sprite->setOrigin({frameW / 2.f, frameH / 2.f});
    sprite->setScale({2.0f, 2.0f});
}


void Animation::Update(float dt) {
    timer += dt;
    if (timer >= timerMax && sprite.has_value()) {
        currentFrame = (currentFrame + 1) % totalFrames;
        sprite->setTextureRect({{frameWidth * currentFrame, 0}, {frameWidth, frameHeight}});
        timer = 0.f;
    }
}


void Animation::Draw(sf::RenderWindow& window) {
    if (sprite.has_value()) {
        window.draw(*sprite);
    }
}


sf::Sprite& Animation::GetSprite() {
    if (!sprite.has_value()) {
        throw std::runtime_error("Sprite not loaded!");
    }
    return *sprite;
}
