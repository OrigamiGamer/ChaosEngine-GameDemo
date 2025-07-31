#pragma once



#include "game.h"



class MainScene : public Chaos::InternalDevice::Scene {
public:
    Chaos::GraphicX::Viewport viewport_1;
    Chaos::GraphicX::Viewport viewport_2;

    MainScene();

    void onEntered();

    bool onExiting();

    void update();

} g_mainScene;
