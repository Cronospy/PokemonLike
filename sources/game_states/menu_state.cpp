#include "../../includes/game_states/menu_state.hpp"

#include <iostream>
#include <ostream>
#include "../../includes/game_engine.hpp"
#include "../../includes/game_states/starter_state.hpp"
#include <SFML/Graphics.hpp>

menu_state::menu_state() {
    if (!background_texture.loadFromFile("assets/images/menu_bg.jpg"))
        std::cerr << "Error: Could not display background image" << std::endl;
    if (!locklass_texture.loadFromFile("assets/images/pokemon/131.png"))
        std::cerr << "Error: Could not load image!" << std::endl;
    if (!title_font.openFromFile( "assets/fonts/fiftiesMovies.ttf"))
        std::cerr << "Can't find the font file" << std::endl;
    if (!flambusard_texture.loadFromFile("assets/images/pokemon/663.png"))
        std::cerr << "Error: Could not load image!" << std::endl;
    if (!ouvrifier_texture.loadFromFile("assets/images/pokemon/532.png"))
        std::cerr << "Error: Could not load image!" << std::endl;

    play_btn = std::make_unique<button>(title_font, "Jouer", sf::Vector2f{500.f, 150.f}, sf::Vector2f{625.f, 475.f});

    play_btn->set_on_click([this]() {
        engine->set_game_state(std::make_unique<starter_state>());
    });
}

void menu_state::update() {
    play_btn->update(*engine->get_window());
}

void menu_state::render() {
    set_background();
    title_draw();
    locklass_draw();
    flambusard_draw();
    ouvrifier_draw();
    play_btn->render(*engine->get_window());
}

void menu_state::set_background() {
    sf::Sprite backgroundImage(background_texture);

    backgroundImage.setTexture(background_texture, true);
    engine->get_window()->draw(backgroundImage);
}

void menu_state::title_draw() {
    sf::Text title_text(title_font, std::string("Pokemon Like"));
    title_text.setStyle( sf::Text::Bold );
    title_text.setFillColor( sf::Color::Black );
    title_text.setCharacterSize( 112 );
    title_text.setPosition({150,100});

    engine->get_window()->draw(title_text);
}

void menu_state::locklass_draw() {
    sf::Sprite locklass_sprite(locklass_texture);
    locklass_sprite.setPosition({300,600});
    locklass_sprite.setScale({-2.0f,2.0f});
    engine->get_window()->draw(locklass_sprite);
}

void menu_state::flambusard_draw() {
    sf::Sprite flambusard_sprite(flambusard_texture);
    flambusard_sprite.setPosition({1000,100});
    flambusard_sprite.setScale({2.0f,2.0f});
    engine->get_window()->draw(flambusard_sprite);
}

void menu_state::ouvrifier_draw() {
    sf::Sprite ouvrifier_sprite(ouvrifier_texture);
    ouvrifier_sprite.setPosition({1050,600});
    ouvrifier_sprite.setScale({-2.0f,2.0f});
    engine->get_window()->draw(ouvrifier_sprite);
}