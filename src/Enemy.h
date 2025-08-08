#pragma once
#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy(float x, float y, float width, float height); // Constructor

    void update(sf::Time deltaTime, float platformLeft, float platformRight);   // Update the enemy's position
    void draw(sf::RenderWindow& window); // Draw the enemy on the window
    sf::FloatRect getBounds() const;  // Get the enemy's bounding box for collision detection
    void setTexture(const sf::Texture& texture);

private:
    sf::RectangleShape enemy;         // Rectangle to represent the enemy
    sf::Vector2f velocity;            // Movement speed and direction
};