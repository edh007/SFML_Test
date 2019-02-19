#include "BaseEngine.h"
#include "States/MainState.h"

NS_DHL_BEGIN

BaseEngine::BaseEngine(int width, int height, std::string title)
{
    _data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    _data->stateMachine.AddState(StateRef(new MainState(_data)));

    Run();
}

void BaseEngine::Run()
{
    float newTime, frameTime, interpolation;

    float currentTime = _clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;

    while (_data->window.isOpen()) {
        _data->stateMachine.ProcessStateChanges();

        newTime = _clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;

        if (frameTime > 0.25f) {
            frameTime = 0.25f;
        }

        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= dt) {
            CalculateUpdatesPerSecond();

            _data->stateMachine.GetActiveState()->HandleInput();
            _data->stateMachine.GetActiveState()->Update(dt);

            accumulator -= dt;
        }

        CalculateFramesPerSecond();

        interpolation = accumulator / dt;
        _data->stateMachine.GetActiveState()->Render(interpolation);
    }
}

#ifdef DEBUG
void BaseEngine::CalculateUpdatesPerSecond() {
    _updates++;
    float time = _upsClock.getElapsedTime().asSeconds();
    if (time >= 1.0f) {
        _data->UPS = _updates;

        _upsClock.restart();
        _updates = 0;
    }
}
#endif

#ifdef DEBUG
void BaseEngine::CalculateFramesPerSecond() {
    _frames++;
    float time = _fpsClock.getElapsedTime().asSeconds();
    if (time >= 1.0f) {
        _data->FPS = _frames;

        _fpsClock.restart();
        _frames = 0;
    }
}
#endif

NS_DHL_END