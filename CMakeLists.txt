cmake_minimum_required(VERSION 3.15)
project(sero_core)

set(CMAKE_CXX_STANDARD 20)

find_package(Threads)

add_subdirectory(external/glfw)

add_library(sero_core_opengl
        src/core-opengl.cpp
        external/glad/src/glad.c
        )

target_link_libraries(sero_core_opengl
        PUBLIC ${CMAKE_THREAD_LIBS_INIT}
        PUBLIC glfw
        )

target_include_directories(sero_core_opengl
        PUBLIC include
        PUBLIC external/glad/include
        )

add_executable(temp
        temp.cpp
        )

target_link_libraries(temp
        PRIVATE sero_core_opengl
        )

add_library(sero::core_opengl ALIAS sero_core_opengl)