#include "Game/Game.h"



// Game

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    initializeGame();



    return 0;
}



void initializeGame()
{
    // create window
    g_window = glfwCreateWindow(1280, 720, "Direct2D-Demo", nullptr, nullptr);


    // initialize Direct2D
    HRESULT hr = S_OK;
    hr = D2D1CreateFactory(
        D2D1_FACTORY_TYPE_MULTI_THREADED,
        &g_factory
    );

    D2D1_RENDER_TARGET_PROPERTIES _renderTargetProp;
    _renderTargetProp.type = D2D1_RENDER_TARGET_TYPE_HARDWARE;
    _renderTargetProp.pixelFormat.alphaMode = D2D1_ALPHA_MODE_PREMULTIPLIED;
    _renderTargetProp.pixelFormat.format = DXGI_FORMAT_B8G8R8A8_UNORM;
    _renderTargetProp.dpiX = 96.0f;
    _renderTargetProp.dpiY = 96.0f;
    _renderTargetProp.usage = D2D1_RENDER_TARGET_USAGE_NONE;
    _renderTargetProp.minLevel = D2D1_FEATURE_LEVEL_DEFAULT;

    D2D1_HWND_RENDER_TARGET_PROPERTIES _hwndRenderTargetProp;
    _hwndRenderTargetProp.hwnd = glfwGetWin32Window(g_window);
    _hwndRenderTargetProp.pixelSize = D2D1_SIZE_U(1280, 720);
    _hwndRenderTargetProp.presentOptions = D2D1_PRESENT_OPTIONS_NONE;

    g_factory->CreateHwndRenderTarget(
        &_renderTargetProp,
        &_hwndRenderTargetProp,
        &g_renderTarget
    );



}



void startGame()
{
    g_gameRunning = true;

    // Game Loop
    unsigned long long timeSlept = 0;
    while (g_gameRunning) {

        // update window
        updateWindow();

        // // control fps
        // unsigned long long cycleTime = (1000 * 1000) / 60;
        // timeSlept += this->deltaEngineTime;
        // if (timeSlept >= cycleTime) {
        //     // update engine
        //     engineUpdate();
        //     timeSlept -= cycleTime;
        //     if (timeSlept < 0) timeSlept = 0;
        // }

        // // while one frame finished
        // currentEngineTime = System::getSystemTime();
        // this->deltaEngineTime = currentEngineTime - lastEngineTime;
        // lastEngineTime = currentEngineTime;

    }
}



void updateWindow()
{
    // handle window message
    if (!glfwWindowShouldClose(g_window)) {
        glfwSwapBuffers(g_window);
        glfwPollEvents();
    }
    else {
        // user denied
        glfwSetWindowShouldClose(g_window, false);
    }
}



void releaseGame()
{
    g_gameRunning = false;
    
}




#include "Game/Source/Source.cpp"
