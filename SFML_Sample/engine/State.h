#pragma once

#include "Macro.h"

NS_DHL_BEGIN
    class State {
    public:
        virtual void Init() = 0;

        virtual void HandleInput() = 0;
        virtual void Update(float dt) = 0;
        virtual void Render(float dt) = 0;

        virtual void Pause() { }
        virtual void Resume() { }
    };
NS_DHL_END