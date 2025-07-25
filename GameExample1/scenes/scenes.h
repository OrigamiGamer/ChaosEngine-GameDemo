#pragma once



#include "game.h"



class Scene_Main : public Chaos::InternalDevice::Scene {
public:
    std::shared_ptr<Chaos::GraphicX::Viewport> viewport_1;

    Scene_Main();

    void onEntering();

    bool onExiting();

    void update();

} scene_main;
