cmake_minimum_required(VERSION 3.28)
project(snake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(snake src/main.cpp
        src/config.cpp
        src/config.h
        src/animation.cpp
        src/animation.h
 "src/ui_screen.cpp" "src/ui_screen.h" "src/food.h"  "src/food.cpp" "src/snake.h" "src/snake.cpp")
