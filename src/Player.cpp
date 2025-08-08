#include "Player.h"

Player::Player(float x, float y) : velocity(0.f, 0.f), onGround(false) {
    player.setSize(sf::Vector2f(40.f, 40.f));
    player.setPosition(x, y);
    player.setFillColor(sf::Color::White);
}

void Player::update(sf::Time deltaTime, const std::vector<Platform>& platforms) {
    const float gravity = 500.f; // Gravity force
    const float jumpStrength = -300.f; // Jump velocity
    const float movementSpeed = 200.f; // Horizontal speed

    // Apply horizontal movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player.setScale(-1.f, 1.f); // Flip horizontally
        player.setOrigin(player.getSize().x, 0.f); // Adjust origin to maintain position
        player.move(-movementSpeed * deltaTime.asSeconds(), 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player.setScale(1.f, 1.f); // Normal orientation
        player.setOrigin(0.f, 0.f); // Reset origin to default
        player.move(movementSpeed * deltaTime.asSeconds(), 0.f);
    }

    // Handle jumping
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && onGround) {
        velocity.y = jumpStrength; // Apply jump velocity
        onGround = false; // Player is no longer on the ground after jumping
    }

    // Apply gravity (falling downwards)
    velocity.y += gravity * deltaTime.asSeconds();

    // Update the player's position vertically
    player.move(0.f, velocity.y * deltaTime.asSeconds());

    // Check collisions with platforms to detect top, bottom, and sides collisions
    onGround = false; // Reset onGround before collision checks

    for (const auto& platform : platforms) {
        sf::FloatRect playerBounds = player.getGlobalBounds();
        sf::FloatRect platformBounds = platform.getBounds();

        // Check for intersection between player and platform
        if (playerBounds.intersects(platformBounds)) {
            // Bottom collision (player is falling)
            if (velocity.y > 0 && playerBounds.top + playerBounds.height <= platformBounds.top + 5.f) {
                player.setPosition(player.getPosition().x, platformBounds.top - playerBounds.height);
                velocity.y = 0.f; // Stop downward movement
                onGround = true; // Player is considered on the ground
            }
            // Top collision (player is moving upwards)
            else if (velocity.y < 0 && playerBounds.top >= platformBounds.top + platformBounds.height - 5.f) {
                player.setPosition(player.getPosition().x, platformBounds.top + platformBounds.height);
                velocity.y = 0.f; // Stop upward movement
            }
            // Side collisions: Touching the left or right side of the platform
            else if (playerBounds.left < platformBounds.left && playerBounds.left + playerBounds.width > platformBounds.left) {
                // Player is touching the left side of the platform
                player.setPosition(player.getPosition().x, platformBounds.top - playerBounds.height);
                velocity.y = 0.f;
                onGround = true;
            }
            else if (playerBounds.left < platformBounds.left + platformBounds.width && playerBounds.left + playerBounds.width > platformBounds.left + platformBounds.width) {
                // Player is touching the right side of the platform
                player.setPosition(player.getPosition().x, platformBounds.top - playerBounds.height);
                velocity.y = 0.f;
                onGround = true;
            }
        }
    }
    if (player.getPosition().y > 600.f) {
        isDead = true; // Mark the player as dead
        return;        // Skip further updates
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(player);
}

void Player::setTexture(const sf::Texture& texture) {
    player.setTexture(&texture);
}

// New method to get the player's position
sf::Vector2f Player::getPosition() const {
    return player.getPosition();
}
