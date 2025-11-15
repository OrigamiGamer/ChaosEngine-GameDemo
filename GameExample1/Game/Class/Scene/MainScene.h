#pragma once

#include "Game/Class/Scene/Scene.h"

namespace Game::Scene {



    class MainScene : public Chaos::InternalDevice::Scene {
    public:
        Chaos::GraphicX::Viewport viewport_1;
        Chaos::GraphicX::Viewport viewport_2;

        float rotationAngle = 0.0f;
        Chaos::GraphicX::Texture* texture_player = nullptr;

        MainScene();

        void onEntered();

        bool onExiting();

        void update();

        void onHotkeyPressed(int virtualKey);

        void onHotkeyPressed(std::string hotkeyName);

    };



}