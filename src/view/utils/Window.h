#include "../../../app/glad.h"
#include <GLFW/glfw3.h>
#include <stdio.h>

#ifndef WINDOW_H
#define WINDOW_H

class Window {
    private:
        GLFWwindow *window;
    public:
        Window(int width, int height);
        GLFWwindow* getWindow() ;
        void runWindow() ;
};

#endif