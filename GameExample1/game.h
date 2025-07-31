#pragma once



// STL

#include <iostream>
#include <memory>
#include <vector>



// ChaosEngine

#include "ChaosEngine.h"
#include "Definitions.cpp"



// Game

Chaos::WindowX::Window g_window;
Chaos::GraphicX::Renderer g_renderer;
Chaos::InternalDevice::Stage g_stage;
Chaos::InternalDevice::Engine g_engine;

int main();

void GameInit();

class MainScene;

#include "scenes/scenes.h"

