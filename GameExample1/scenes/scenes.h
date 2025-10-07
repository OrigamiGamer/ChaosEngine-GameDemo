#pragma once



#include "game.h"



class MainScene : public Chaos::InternalDevice::Scene {
public:
    Chaos::GraphicX::Viewport viewport_1;
    Chaos::GraphicX::Viewport viewport_2;

    float rotation_line=0.0f;

    MainScene();

    void onEntered();

    bool onExiting();

    void update();

    void onHotkeyPressed(int virtualKey);

    void onHotkeyPressed(std::string hotkeyName);

} g_mainScene;
