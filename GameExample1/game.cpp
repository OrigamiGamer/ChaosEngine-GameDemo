


#include "game.h"

#include "sources.cpp"



int main()
{
    engine.initialize();

    engine.createWindow();

    Chaos::InternalDevice::EngineStartupProperty engineProp;
    engineProp.fps = 60;
    engineProp.onGameInit = &GameInit;
    engine.start(&engineProp);
    engine.release();
    return 0;
}



void GameInit()
{
    engine.createRenderer();
    engine.createStage();
    engine.stage->registerScene(scene_main);
    engine.stage->switchScene("Main");
    
}

