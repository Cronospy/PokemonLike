#pragma once

class game_engine;

class game_states {
    protected:
        game_engine* game_engine = nullptr;
    public:
        virtual ~game_states()= default;

        void set_game_engine(class game_engine* game_engine);

        virtual void update() = 0;
        virtual void render() = 0;
};
