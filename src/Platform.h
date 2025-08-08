#pragma once
#include <SFML/Graphics.hpp>

class Platform {
public:
    Platform(float width, float height, float x, float y, bool isMoving = false,
        float velocityX = 0.0f, float velocityY = 0.0f, float rangeX = 0.0f, float rangeY = 0.0f);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    void setTexture(const sf::Texture& texture);

private:
    sf::RectangleShape platform;

    bool isMoving; // Whether the platform is moving or not
    float velocityX, velocityY;
    float rangeX, rangeY;
    bool movingForwardX, movingForwardY;
    float startX, startY;
};
