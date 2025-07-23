


// STL



#include <iostream>
#include <memory>
#include <vector>



// ChaosEngine



#include "ChaosEngine.h"
#include "Definitions.cpp"



Chaos::InternalDevice::Engine engine;



int main()
{
    engine.initialize();

    engine.createWindow();

    Chaos::InternalDevice::EngineStartupProperty engineProp;
    engine.start(&engineProp);


    return 0;
}
