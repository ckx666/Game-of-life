cmake_minimum_required(VERSION 3.19)
project(Gametest C)

set(CMAKE_C_STANDARD 11)

link_libraries(SDL2)

add_executable(Gametest main.c LifeGame.h SDL2operation.c FIleoperation.c Evolveoperation.c)
