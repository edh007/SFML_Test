#pragma once

#include <SFML/Graphics.hpp>
#include "../State.h"
#include "../BaseEngine.h"

NS_DHL_BEGIN

class PauseState : public State {
public:
    PauseState(GameDataRef data);

    void Init();

    // No pause() or resume() methods here as this
    // is a very simple example of a game state.

    void HandleInput();
    void Update(float dt) {}
    void Render(float dt);

private:
    GameDataRef _data;
    sf::Text _text;
};

NS_DHL_END