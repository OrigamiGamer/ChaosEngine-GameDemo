#pragma once

#include "Game/Class/Class.h"



// Game

GLFWwindow* g_window = nullptr;
ID2D1Factory* g_factory = nullptr;
ID2D1HwndRenderTarget* g_renderTarget = nullptr;

bool g_gameRunning = false;

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);

void initializeGame();

void startGame();

void updateWindow();

void releaseGame();





#include "Game/Class/Class.h"
