cmake_minimum_required(VERSION 3.26)
project(Sistemas_Distribuidos C)

set(CMAKE_C_STANDARD 11)

add_executable(Sistemas_Distribuidos
        "Lab1/p1.c"
        Lab1/p2.c
        Lab2/apoyo/p1.c
        Lab2/apoyo/p6.c
        Lab2/apoyo/p7.c
        Lab2/apoyo/pi.c
        Lab2/apoyo/pi2.c)
