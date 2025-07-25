#pragma once

#include "scenes/scenes.h"



Scene_Main::Scene_Main() : Scene("Main") {}



void Scene_Main::onEntering()
{
    ::engine.renderer->createViewport("viewport_1", &this->viewport_1);
    this->viewport_1->viewPos = { 0,0 };
    this->viewport_1->viewSize = { 500,500 };
    this->viewport_1->size = { 100,100 };

    std::cout << "Scene 'Main' entered" << std::endl;
}



bool Scene_Main::onExiting()
{
    /*
        [CALL] Stage -> Base::release()
        [CALL] Viewport -> Base::~Base()
        [CALL] Scene -> Base::~Base()
        [CALL] Stage -> Base::~Base()
        [CALL] Window -> Base::~Base()
        [CALL]
    */
    // run and end the process, then you'll find something error: index of vector is out of range(?).
    return true;
}



void Scene_Main::update()
{
    Chaos::GraphicX::RenderTask _task;
    Chaos::GraphicX::RenderTaskParam_Line _param_line(
        { 50,50 },
        { 200, 400 },
        2.0F
    );
    _task.param = _param_line;
    _task.type = Chaos::GraphicX::RenderTaskType::Line;
    ::engine.renderer->pushTask(_task);

}