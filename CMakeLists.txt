cmake_minimum_required(VERSION 3.0.0)
project(otter_engine VERSION 0.1.0)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

add_executable(otter_engine 
    app/main.cpp 
    app/glad.h 
    app/glad.c 
    src/view/utils/Window.cpp  # Add this line
)

target_link_libraries(otter_engine 
    glfw
    OpenGL::GL
)
