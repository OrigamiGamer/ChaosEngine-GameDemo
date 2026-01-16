cmake_minimum_required(VERSION 3.10)

project(GameExample1 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)



# includes

# Please locate this path according to the engine folder storaged on your PC.
set(CHAOS_ENGINE_ROOT "D:/Dev/Src/ChaosProjects/ChaosEngineCPP")

set(INCLUDE_LIST
    .
    ${CHAOS_ENGINE_ROOT}
    "${CHAOS_ENGINE_ROOT}/ChaosEngine"
)
include_directories(${INCLUDE_LIST})



# libraries

set(LINK_LIST
    .
    "${CHAOS_ENGINE_ROOT}/ChaosEngine/ExternalLibrary"
    "${CHAOS_ENGINE_ROOT}/out/build/GCC"
)
link_directories(${LINK_LIST})

link_libraries("libChaosEngine.lib" "glfw3.lib" "D2D1.lib" "OpenAL32.lib" "sndfile.lib")

file(COPY
    "${CHAOS_ENGINE_ROOT}/ChaosEngine/Dependences/OpenAL32.dll"
    "${CHAOS_ENGINE_ROOT}/ChaosEngine/Dependences/sndfile.dll"
    "./resources"
    DESTINATION "."
)



# targets

add_executable(debug "Game/Game.cpp")
set_target_properties(debug PROPERTIES OUTPUT_NAME "game_debug" SUFFIX ".exe")
