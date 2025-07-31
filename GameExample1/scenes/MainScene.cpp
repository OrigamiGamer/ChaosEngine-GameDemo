#pragma once

#include "scenes/scenes.h"



MainScene::MainScene() : Scene("Main Scene") {}



void MainScene::onEntered()
{
    this->viewport_1.viewPos = { 0,0 };
    this->viewport_1.viewSize = { 500,500 };
    this->viewport_1.size = { 500,500 };

    this->viewport_2.viewPos = { 100,100 };
    this->viewport_2.viewSize = { 500,500 };
    this->viewport_2.size = { 500,500 };
    this->viewport_2.pos = { 510,0 };

    ::g_renderer.registerViewport(this->viewport_1, "viewport_1");
    ::g_renderer.registerViewport(this->viewport_2, "viewport_2");

    std::cout << "Scene 'Main' entered" << std::endl;
}



bool MainScene::onExiting()
{

    return true;
}



void MainScene::update()
{
    Chaos::GraphicX::RenderTask _task;

    _task.type = Chaos::GraphicX::RenderTaskType::Line;
    _task.param = Chaos::GraphicX::RenderTaskParam_Line(
        { 50, 50 },
        { 200, 400 },
        5.0F
    );
    _task.order = 0.0F;
    ::g_engine.renderer->pushTask(_task);

    _task.type = Chaos::GraphicX::RenderTaskType::Texture;
    _task.param = Chaos::GraphicX::RenderTaskParam_Texture(
        { 50,50 },
        ::g_renderer.getLoadedTexture("bilibili_blessed_night.png"),
        { 1242 / 6, 1863 / 6 }
    );
    _task.order = 0.0F;
    ::g_engine.renderer->pushTask(_task);

    static float _dx = 1;
    this->viewport_2.viewPos.x -= _dx;
    this->viewport_2.viewPos.y += _dx;  // updated: fixing out of range of world

}