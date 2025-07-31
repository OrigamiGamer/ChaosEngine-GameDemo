#pragma once

#include "scenes/scenes.h"



MainScene::MainScene() : Scene("Main Scene") {}



void MainScene::onEntered()
{
    ::g_engine.renderer->createViewport("viewport_1", &this->viewport_1);   // TODO: register externally like other devices of engine
    this->viewport_1->viewPos = { 0,0 };
    this->viewport_1->viewSize = { 500,500 };
    this->viewport_1->size = { 500,500 };

    ::g_engine.renderer->createViewport("viewport_2", &this->viewport_2);
    this->viewport_2->viewPos = { 100,100 };
    this->viewport_2->viewSize = { 600,600 };
    this->viewport_2->size = { 500,500 };
    this->viewport_2->pos = { 500,0 };


    std::cout << "Scene 'Main' entered" << std::endl;
}



bool MainScene::onExiting()
{

    return true;
}



void MainScene::update()
{
    Chaos::GraphicX::RenderTask _task(
        Chaos::GraphicX::RenderTaskType::Line,
        Chaos::GraphicX::RenderTaskParam_Line(
            { 50, 50 },
            { 200, 400 },
            5.0F
        )
    );
    ::g_engine.renderer->pushTask(_task);

}