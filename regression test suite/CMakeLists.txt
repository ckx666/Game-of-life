cmake_minimum_required(VERSION 3.19)
project(regressionTestSuite C)

set(CMAKE_C_STANDARD 11)

link_libraries(SDL2)

add_executable(regressionTestSuite t_main.c LifeGame.h t_SDL2operation.c t_FIleoperation.c t_Evolveoperation.c)
