#pragma once
#include <vector>

#include "../events/events.hpp"
#include "game_states.hpp"

class playing_state : public game_states{
    private:
        std::vector<std::unique_ptr<events>> events;
        int current_id;
    public:
        playing_state(game_engine* engine);
        void render() override;
        void update() override;

};
