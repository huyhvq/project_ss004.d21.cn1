cmake_minimum_required(VERSION 3.28)
project(snake)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(snake src/main.cpp
        src/ui_screen.cpp
        src/ui_screen.h
        src/snake.cpp
        src/snake.h
        src/point.cpp
        src/point.h
        src/config.cpp
        src/config.h
        src/food.cpp
        src/food.h
        src/animation.cpp
        src/animation.h
        src/handler.cpp
        src/handler.h
)
