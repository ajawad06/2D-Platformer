#include "Enemy.h"

Enemy::Enemy(float x, float y, float width, float height) : velocity(200.f, 0.f) {
    enemy.setSize(sf::Vector2f(width, height));
    enemy.setPosition(x, y);
    enemy.setFillColor(sf::Color::White);
}

void Enemy::update(sf::Time deltaTime, float platformLeft, float platformRight) {
    // Move the enemy horizontally
    enemy.move(velocity.x * deltaTime.asSeconds(), 0.f);
    /*float buffer = 10.f;*/
    // Reverse direction if enemy moves off the platform
    if (enemy.getPosition().x <= platformLeft ||
        enemy.getPosition().x + enemy.getSize().x >= platformRight) {
        velocity.x = -velocity.x; // Reverse direction
    }
}


void Enemy::draw(sf::RenderWindow& window) {
    window.draw(enemy); // Draw the enemy rectangle
}

sf::FloatRect Enemy::getBounds() const {
    return enemy.getGlobalBounds(); // Return the enemy's bounding box
}

void Enemy::setTexture(const sf::Texture& texture)
{
    enemy.setTexture(&texture);
}
