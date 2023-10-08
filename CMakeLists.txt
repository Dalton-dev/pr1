cmake_minimum_required(VERSION 3.26)
project(pr1)

set(CMAKE_CXX_STANDARD 17)

add_executable(pr1 main.cpp
        VDinamico.h
        Aeropuerto.cpp
        Aeropuerto.h
        UTM.cpp
        UTM.h
)
