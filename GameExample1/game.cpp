
#include "game.h"

#include "sources.cpp"



int main()
{
    g_engine.initialize();

    Chaos::InternalDevice::EngineStartupProperty engineProp;
    engineProp.fps = 60;
    engineProp.onGameInit = &GameInit;
    engineProp.onGameExit = &GameExit;
    g_engine.start(&engineProp);
    g_engine.release();

    return 0;
}



OpenAL::AudioEngine audioEngine;
OpenAL::AudioPlayer* audioPlayer;

void GameInit()
{
    g_window.initialize();

    g_renderer.initialize(g_window);
    g_stage.registerWindow(g_window);

    g_engine.registerStage(&g_stage);
    g_engine.registerRenderer(&g_renderer);

    g_stage.registerScene(g_mainScene);
    g_stage.switchScene("Main Scene");

    // load images
    g_renderer.loadTextureFromImageFile("resources/images/bilibili_blessed_night.png", "bilibili_blessed_night");


    // Audio Debug
    audioEngine.initialize();
    audioPlayer = audioEngine.createAudioPlayer();

    OpenAL::Buffer* buffer_bgm = audioPlayer->loadAudioFile(Chaos::System::locate("/resources/audio/bgm2_low_dB.mp3"));

    OpenAL::Source* source = audioPlayer->createSource();
    source->pushBuffer(buffer_bgm);
    source->play();

    source->setVolume(0.2);

    source->setTimeOffset(8 * 60 + 52);

}



bool GameExit()
{
    audioEngine.release();

    return true;
}