#include "Button.h"

Button::Button(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& text, sf::Font& font) {
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Blue);

    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(24);
    label.setFillColor(sf::Color::White);
    label.setPosition(
        position.x + (size.x - label.getGlobalBounds().width) / 2,
        position.y + (size.y - label.getGlobalBounds().height) / 2 - 5
    );
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(label);
}

bool Button::isClicked(const sf::Vector2i& mousePosition) {
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition));
}
