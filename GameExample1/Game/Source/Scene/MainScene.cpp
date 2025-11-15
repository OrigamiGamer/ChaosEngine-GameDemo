#pragma once

#include "Game/Class/Scene/MainScene.h"

namespace Game::Scene {



    MainScene::MainScene() : Scene("MainScene") {}



    void MainScene::onEntered()
    {
        this->viewport_1.viewPos = { 0,0 };
        this->viewport_1.size = { (float)g_window.size.x,(float)g_window.size.y };
        this->viewport_1.viewSize = this->viewport_1.size;

        g_renderer.SetCanvasSize(3000, 3000);
        g_renderer.registerViewport(this->viewport_1, "viewport_1");

        g_window.keyStateBuffer.addHotKey(Chaos::WindowX::VirtualKey::A, "move_left");
        g_window.keyStateBuffer.addHotKey(Chaos::WindowX::VirtualKey::D, "move_right");
        g_window.keyStateBuffer.addHotKey(Chaos::WindowX::VirtualKey::W, "move_up");
        g_window.keyStateBuffer.addHotKey(Chaos::WindowX::VirtualKey::S, "move_down");
        g_window.keyStateBuffer.addHotKey(Chaos::WindowX::VirtualKey::R, "rotation");

        this->texture_player = g_renderer.getLoadedTexture("player_1");
    }



    bool MainScene::onExiting()
    {

        return true;
    }



    void MainScene::update()
    {
        this->viewport_1.size = { (float)g_window.size.x,(float)g_window.size.y };
        this->viewport_1.viewSize = this->viewport_1.size;



        Chaos::GraphicX::RenderTask _task;

        _task.type = Chaos::GraphicX::RenderTaskType::Rectangle;
        _task.param = Chaos::GraphicX::RenderTaskParam_Rectangle(
            { 500,500 },
            { 100,100 },
            true,
            1,
            { 32,32 },
            1,
            { -1,-1 },
            rotationAngle,
            { 1,1 }
        );
        _task.order = 0.0f;
        g_engine.renderer->pushTask(_task);

        _task.type = Chaos::GraphicX::RenderTaskType::Texture;
        _task.param = Chaos::GraphicX::RenderTaskParam_Texture(
            { 0,0 },
            this->texture_player,
            { 200,200 },
            { 0,0 },
            { -1,-1 },
            1.0f,
            { -1,-1 },
            0.0f,
            { 1.0f,1.0f }
        );
        _task.order = 0.0f;
        g_engine.renderer->pushTask(_task);



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
        Chaos::Log::OutputStream out("INFO");
        out.push("the key was pressed -> ")->push(hotkeyName);
        g_logger.print(out);
        out.clear();

        // std::cout << hotkeyName << std::endl;
        if (hotkeyName == "rotation") {
            rotationAngle += 22.5f;

            out.push("the line was rotated to ")->push(rotationAngle);
            g_logger.print(out);
        }

    }



}