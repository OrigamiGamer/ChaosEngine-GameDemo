cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

project(GameExample1 VERSION 0.1.0 LANGUAGES CXX)



# includes

set(CHAOS_ENGINE_ROOT "F:/Dev/Src/ChaosProjects/ChaosEngineCPP/ChaosEngine") # Please rewrite by yourself

set(INCLUDE_LIST
    ${CHAOS_ENGINE_ROOT}
    .
)
include_directories(${INCLUDE_LIST})



# libraries

set(LINK_LIST
    "${CHAOS_ENGINE_ROOT}/ExternalLibrary"
    .
)
link_directories(${LINK_LIST})

link_libraries("D2D1.lib" "libglfw3.a")



# targets

add_executable(debug "game.cpp")
set_target_properties(debug PROPERTIES OUTPUT_NAME "debug" SUFFIX ".exe")
