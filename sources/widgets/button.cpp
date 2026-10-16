#include "../../includes/widgets/button.hpp"

button::button(const sf::Font& font, const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position)
    : text(font, label, 50) // Initialisation compatible SFML 3
{
    // Rectangle
    shape.setSize(size);
    shape.setOrigin(shape.getGeometricCenter());
    shape.setPosition(position);
    shape.setFillColor(default_color);

    // Texte centré sur le bouton
    text.setFillColor(sf::Color::Black);

    auto bounds = text.getLocalBounds();
    sf::Vector2f center(bounds.position.x + bounds.size.x / 2.f,
                        bounds.position.y + bounds.size.y / 2.f);
    text.setOrigin(center);

    text.setPosition(position);
}

void button::set_on_click(std::function<void()> action) {
    on_click_action = std::move(action);
}

void button::update(const sf::RenderWindow& window) {
    sf::Vector2i mouse_pixel = sf::Mouse::getPosition(window);
    sf::Vector2f mouse_pos = window.mapPixelToCoords(mouse_pixel);

    bool is_hover = shape.getGlobalBounds().contains(mouse_pos);
    bool mouse_down = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

    bool on_press = false;
    bool on_release = false;

    if (mouse_down) {
        if (!is_mouse_pressed) on_press = true;
        is_mouse_pressed = true;
    } else {
        if (is_mouse_pressed) on_release = true;
        is_mouse_pressed = false;
    }

    if (is_hover) {
        if (on_press) is_pressed_inside = true;

        if (on_release && is_pressed_inside) {
            if (on_click_action) on_click_action();
        }

        if (is_mouse_pressed && is_pressed_inside) {
            shape.setFillColor(pressed_color);
        } else {
            shape.setFillColor(hover_color);
        }
    } else {
        shape.setFillColor(default_color);
    }

    if (!is_mouse_pressed) is_pressed_inside = false;
}

void button::render(sf::RenderWindow& window) const {
    window.draw(shape);
    window.draw(text);
}

RectangleShape button::get_shape() const {
    return shape;
}

void button::set_default_color(const sf::Color &color) {
    default_color = color;
}

void button::set_pressed_color(const sf::Color &color) {
    pressed_color = color;
}

void button::set_hover_color(const sf::Color &color) {
    hover_color = color;
}
