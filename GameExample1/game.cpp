


#include "game.h"



#include "sources.cpp"



int main()
{
    g_engine.initialize();

    Chaos::InternalDevice::EngineStartupProperty engineProp;
    engineProp.fps = 60;
    engineProp.onGameInit = &GameInit;
    g_engine.start(&engineProp);
    g_engine.release();

    return 0;
}



void GameInit()
{
    g_window.initialize();

    g_stage.registerWindow(g_window);
    g_renderer.initialize(g_window);

    g_engine.registerStage(&g_stage);
    g_engine.registerRenderer(&g_renderer);

    g_stage.registerScene(g_mainScene);
    g_stage.switchScene("Main Scene");

    // load images

    std::cout << g_renderer.loadTextureFromImageFile("resources/images/bilibili_blessed_night.png")->name << std::endl;

}

