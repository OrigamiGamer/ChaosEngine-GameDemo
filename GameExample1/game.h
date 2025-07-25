#pragma once



// STL

#include <iostream>
#include <memory>
#include <vector>



// ChaosEngine

#include "ChaosEngine.h"
#include "Definitions.cpp"



// Game

Chaos::InternalDevice::Engine engine;

int main();

void GameInit();

class Scene_Main;

#include "scenes/scenes.h"

