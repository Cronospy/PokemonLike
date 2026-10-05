#pragma once

#include <SFML/Graphics.hpp>

class events {
    private:
        bool finished = false;
    public:
        virtual ~events() = default;

        virtual void update(const sf::RenderWindow& window) = 0;
        virtual void render(sf::RenderWindow& window) = 0;

        bool is_finished() const { return finished; }

        void finish() { finished = true; }
};

