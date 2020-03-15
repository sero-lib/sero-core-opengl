cmake_minimum_required(VERSION 3.15)
project(sero_core)

set(CMAKE_CXX_STANDARD 20)

find_package(Threads)

add_library(sero_core_opengl
        src/core-opengl.cpp
        )

target_link_libraries(sero_core_opengl
        PUBLIC ${CMAKE_THREAD_LIBS_INIT}
        )

target_include_directories(sero_core_opengl
        PUBLIC include
        )

add_executable(sero_core_opengl_tests
        tests/main.cpp
        )

target_link_libraries(sero_core_opengl_tests
        PRIVATE sero_core_opengl
        PRIVATE gtest
        )

add_executable(temp
        temp.cpp
        )

target_link_libraries(temp
        PRIVATE sero_core_opengl
        )
