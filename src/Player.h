//#pragma once
//#include <SFML/Graphics.hpp>
//#include "Platform.h"
//#include <vector>
//
//class Player {
//public:
//    Player(float x, float y);
//
//    void update(sf::Time deltaTime, const std::vector<Platform>& platforms); // Added platforms parameter
//    void draw(sf::RenderWindow& window);
//    void setTexture(const sf::Texture& texture);
#pragma once
#include <SFML/Graphics.hpp>
#include "Platform.h"
#include <vector>

class Player {
public:
    Player(float x, float y);
    bool isDead = false;
    void update(sf::Time deltaTime, const std::vector<Platform>& platforms); // Added platforms parameter
    void draw(sf::RenderWindow& window);
    void setTexture(const sf::Texture& texture);
    sf::Vector2f getPosition() const; // New method to get player position

private:
    sf::RectangleShape player;
    sf::Vector2f velocity;
    bool onGround;

public:
    const sf::FloatRect getBounds() const { return player.getGlobalBounds(); }
};
