#pragma once

#include "Game/Class/Class.h"



// Game

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);

namespace Game {

    Chaos::Log::Logger g_logger;
    Chaos::WindowX::Window g_window;
    Chaos::Graphics::Renderer g_renderer;
    Chaos::InternalDevice::Stage g_stage;
    Chaos::InternalDevice::Engine g_engine;

    void GameMain();

    void GameInit();

    bool GameExit();

    bool onWindowClose();

}



namespace Game::Scene {

    class MainScene;

}



#include "Game/Class/Class.h"
