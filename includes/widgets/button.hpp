#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class button {
private:
    RectangleShape shape;
    Text text;
    std::function<void()> on_click_action;

    bool is_mouse_pressed = false;
    bool is_pressed_inside = false;

    sf::Color default_color{245, 73, 39};
    sf::Color hover_color{245, 176, 39};
    sf::Color pressed_color{245, 176, 39};

public:
    button(const sf::Font& font, const std::string& label, const sf::Vector2f& size, const sf::Vector2f& position);

    void set_on_click(std::function<void()> action);
    void update(const sf::RenderWindow& window);
    void render(sf::RenderWindow& window) const;

    RectangleShape get_shape() const;

    void set_default_color(const sf::Color& color);
    void set_pressed_color(const sf::Color& color);
    void set_hover_color(const sf::Color& color);
};
