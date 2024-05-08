cmake_minimum_required(VERSION 3.27)
project(Sortowania)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sortowania main.cpp
        SortingAlgorithms.cpp
        SortingAlgorithms.h
        DataGenerator.cpp
        DataGenerator.h
        Menu.cpp
        Menu.h
        Simulation.cpp
        Simulation.h
)
