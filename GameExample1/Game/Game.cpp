
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
        // initialize engine devices
        Chaos::WindowX::WindowStartupProperty _windowProp;
        _windowProp.onWindowClose = &onWindowClose;
        g_window.initialize(_windowProp);

        g_stage.registerWindow(g_window);
        g_renderer.initialize(g_window);

        g_engine.registerStage(&g_stage);
        g_engine.registerRenderer(&g_renderer);

        g_stage.registerScene(Game::Scene::mainScene);
        g_stage.switchScene("MainScene");

    }



    bool GameExit()
    {

        return true;
    }



    bool onWindowClose()
    {
        return true;
    }



}



#include "Game/Source/Source.cpp"
