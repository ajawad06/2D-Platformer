#include "Platform.h"

Platform::Platform(float width, float height, float x, float y, bool isMoving,
    float velocityX, float velocityY, float rangeX, float rangeY)
    : isMoving(isMoving), velocityX(velocityX), velocityY(velocityY),
    rangeX(rangeX), rangeY(rangeY), movingForwardX(true), movingForwardY(true) {
    platform.setSize(sf::Vector2f(width, height));
    platform.setPosition(x, y);
    startX = x;
    startY = y;
}

void Platform::update(float deltaTime) {
    if (isMoving) {
        sf::Vector2f position = platform.getPosition();

        // Horizontal movement logic
        if (rangeX > 0) {
            if (movingForwardX) {
                position.x += velocityX * deltaTime;
                if (position.x > startX + rangeX) {
                    position.x = startX + rangeX;
                    movingForwardX = false;
                }
            }
            else {
                position.x -= velocityX * deltaTime;
                if (position.x < startX) {
                    position.x = startX;
                    movingForwardX = true;
                }
            }
        }

        // Vertical movement logic
        if (rangeY > 0) {
            if (movingForwardY) {
                position.y += velocityY * deltaTime;
                if (position.y > startY + rangeY) {
                    position.y = startY + rangeY;
                    movingForwardY = false;
                }
            }
            else {
                position.y -= velocityY * deltaTime;
                if (position.y < startY) {
                    position.y = startY;
                    movingForwardY = true;
                }
            }
        }

        platform.setPosition(position);
    }
}

void Platform::draw(sf::RenderWindow& window) {
    window.draw(platform);
}

sf::FloatRect Platform::getBounds() const {
    return platform.getGlobalBounds();
}

void Platform::setTexture(const sf::Texture& texture) {
    platform.setTexture(&texture);
}
