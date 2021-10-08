cmake_minimum_required(VERSION 3.20)
project(ACS_HW_2 LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/bin")
set(BINARY_DIR "${CMAKE_BINARY_DIR}")

add_executable(ACS_HW_2
        main.cpp

        container.cpp
        container.h

        functional.cpp
        functional.h

        objectOriented.cpp
        objectOriented.h

        languages.cpp
        languages.h

        procedural.cpp
        procedural.h

        utils.h)
