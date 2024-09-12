cmake_minimum_required(VERSION 3.22)
project(ayed_practica_poo)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")

include_directories(include)

add_executable(ayed_practica_poo
        main.cpp
        include/Celda.hpp
        include/Linea.hpp
        include/Tablero.hpp
        src/Celda.cpp
        src/Linea.cpp
        src/Tablero.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "main")