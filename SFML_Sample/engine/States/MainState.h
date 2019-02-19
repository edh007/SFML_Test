#pragma once

#include <SFML/Graphics.hpp>
#include "../State.h"
#include "../BaseEngine.h"

NS_DHL_BEGIN

class MainState : public State {
public:
    MainState(GameDataRef data);

    void Init();

    // No pause() or resume() methods here as this
    // is a very simple example of a game state.

    void HandleInput();
    void Update(float dt);
    void Render(float dt);

private:

    GameDataRef _data;

    sf::Sprite _sprite;
    sf::Text _text;
#ifdef DEBUG
    sf::Text _stats;
#endif
};

NS_DHL_END