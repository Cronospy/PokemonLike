#include "../../includes/game_states/win_state.hpp"
#include "../../includes/game_engine.hpp"
#include <iostream>

win_state::win_state(game_engine* engine) {
    this->engine = engine;
    if (!background_texture.loadFromFile("assets/images/win_bg.png"))
        std::cerr << "Error: Could not display background image" << std::endl;
    if (!title_font.openFromFile( "assets/fonts/fiftiesMovies.ttf"))
        std::cerr << "Can't find the font file" << std::endl;
    team_widget = std::make_unique<team_display>(
    engine->get_player()->get_team(), sf::Vector2f{112.f, 350.f}, false);
}

void win_state::update() {

}

void win_state::render() {
    set_background();
    title_draw();
    team_widget->render(*engine->get_window());
}

void win_state::set_background() {
    sf::Sprite backgroundImage(background_texture);

    backgroundImage.setTexture(background_texture, true);
    engine->get_window()->draw(backgroundImage);
}

void win_state::title_draw() {
    sf::Text title_text(title_font, std::string("Congratulations!"));
    title_text.setStyle( sf::Text::Bold );
    title_text.setFillColor( sf::Color::Yellow );
    title_text.setCharacterSize( 112 );
    title_text.setPosition({150,100});

    engine->get_window()->draw(title_text);
}
