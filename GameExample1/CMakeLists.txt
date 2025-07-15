cmake_minimum_required(VERSION 3.10)

project(GameExample1 VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# includes

set(CHAOS_ENGINE_ROOT "D:/Dev/Src/ChaosProjects/ChaosEngineCPP/ChaosEngine")

set(INCLUDE_LIST
    ${CHAOS_ENGINE_ROOT}
    .
)
include_directories(${INCLUDE_LIST})

# libraries

set(LINK_LIST
    "${CHAOS_ENGINE_ROOT}/Lib"
    .
)
link_directories(${LINK_LIST})

link_libraries("D2D1.lib" "libglfw3.a")

# targets

add_executable(debug "main.cpp")
set_target_properties(debug PROPERTIES OUTPUT_NAME "debug" SUFFIX ".exe")
