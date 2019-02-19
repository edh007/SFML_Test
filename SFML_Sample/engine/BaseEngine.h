#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "Macro.h"

#define DEBUG

NS_DHL_BEGIN

    struct GameData {
        StateMachine stateMachine;
        sf::RenderWindow window;
        AssetManager assets;
#ifdef DEBUG
        int FPS, UPS;
#endif
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class BaseEngine {
    public:
        BaseEngine(int width, int height, std::string title);

    private:
        // Updates run at 30 per second.
        const float dt = 1.0f / 30.0f;
        sf::Clock _clock;

#ifdef DEBUG
        sf::Clock _upsClock;
        sf::Clock _fpsClock;
        int _updates;
        int _frames;

        void CalculateUpdatesPerSecond();
        void CalculateFramesPerSecond();
#endif

        GameDataRef _data = std::make_shared<GameData>();

        void Run();
    };

NS_DHL_END
