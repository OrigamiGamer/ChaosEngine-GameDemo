#pragma once

#include "scenes/scenes.h"



MainScene::MainScene() : Scene("Main Scene") {}



void MainScene::onEntered()
{
    this->viewport_1.viewPos = { 0,0 };
    this->viewport_1.viewSize = { 1280,720 };
    this->viewport_1.size = { (float)g_window.size.x,(float)g_window.size.y };

    ::g_renderer.SetCanvasSize(3000, 3000);
    ::g_renderer.registerViewport(this->viewport_1, "viewport_1");

    g_window.keyStateBuffer.addHotKey(Chaos::WindowX::VirtualKey::A, "move_left");
    g_window.keyStateBuffer.addHotKey(Chaos::WindowX::VirtualKey::D, "move_right");
    g_window.keyStateBuffer.addHotKey(Chaos::WindowX::VirtualKey::W, "move_up");
    g_window.keyStateBuffer.addHotKey(Chaos::WindowX::VirtualKey::S, "move_down");
    g_window.keyStateBuffer.addHotKey(Chaos::WindowX::VirtualKey::R, "rotation_line");


    std::cout << "Scene 'Main' entered" << std::endl;
}



bool MainScene::onExiting()
{

    return true;
}



void MainScene::update()
{
    this->viewport_1.size = { (float)g_window.size.x,(float)g_window.size.y };

    Chaos::GraphicX::RenderTask _task;

    _task.type = Chaos::GraphicX::RenderTaskType::Line;
    _task.param = Chaos::GraphicX::RenderTaskParam_Line(
        { 50, 50 },
        { 200, 400 },
        5.0f,
        1.0f,
        { 0.0f,0.0f },
        rotation_line
    );
    _task.order = 0.0f;
    ::g_engine.renderer->pushTask(_task);

    _task.type = Chaos::GraphicX::RenderTaskType::Texture;
    for (size_t i = 0; i < 1000; i++) {
        _task.param = Chaos::GraphicX::RenderTaskParam_Texture(
            { (float)(50 + 70 * i),(float)(50 + 50 * i) },
            ::g_renderer.getLoadedTexture("bilibili_blessed_night"),
            { 1242 , 1863 }
        );
        _task.order = (float)i;
        ::g_engine.renderer->pushTask(_task);
    }

    static float _moveStep = 25;

    if (g_window.keyStateBuffer.getKeyState(Chaos::WindowX::VirtualKey::A)) {
        this->viewport_1.viewPos.x -= _moveStep;
    }
    if (g_window.keyStateBuffer.getKeyState(Chaos::WindowX::VirtualKey::D)) {
        this->viewport_1.viewPos.x += _moveStep;
    }
    if (g_window.keyStateBuffer.getKeyState(Chaos::WindowX::VirtualKey::W)) {
        this->viewport_1.viewPos.y -= _moveStep;
    }
    if (g_window.keyStateBuffer.getKeyState(Chaos::WindowX::VirtualKey::S)) {
        this->viewport_1.viewPos.y += _moveStep;
    }

}



void MainScene::onHotkeyPressed(int virtualKey)
{

}



void MainScene::onHotkeyPressed(std::string hotkeyName)
{
    // std::cout << hotkeyName << std::endl;
    if (hotkeyName == "rotation_line")
        rotation_line += 45;
}
