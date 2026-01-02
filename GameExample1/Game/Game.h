#pragma once



// STL

#include <iostream>
#include <memory>
#include <vector>



// ChaosEngine

#include "ChaosEngine/Class/Class.h"
#include "ChaosEngine/Source/Source.cpp"





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

}



namespace Game::Scene {

    class MainScene;

}



#include "Game/Class/Class.h"
