
// Game

#include "Game/Game.h"



int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    Game::GameMain();
    return 0;
}



namespace Game {



    void GameMain()
    {
        g_engine.initialize();

        Chaos::InternalDevice::EngineStartupProperty engineProp;
        engineProp.fps = 120;
        engineProp.onGameInit = &GameInit;
        engineProp.onGameExit = &GameExit;
        g_engine.start(&engineProp);

        g_engine.release();
    }



    void GameInit()
    {
        g_window.initialize();

        g_renderer.initialize(g_window);
        g_stage.registerWindow(g_window);

        g_engine.registerStage(&g_stage);
        g_engine.registerRenderer(&g_renderer);

        g_stage.registerScene(Game::Scene::mainScene);
        g_stage.switchScene("MainScene");

        // load images
        g_renderer.loadTextureFromImageFile("resources/images/bilibili_blessed_night.png", "bilibili_blessed_night");
        g_renderer.loadTextureFromImageFile("resources/images/player_1.png", "player_1");

    }



    bool GameExit()
    {

        return true;
    }



}



#include "Game/Source/Source.cpp"
