#include "Window.h"

Window::Window(int width, int height) {
    glfwInit();

    this->window = glfwCreateWindow(width, height, "Fereastra", NULL, NULL);
    glfwMakeContextCurrent(this->window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Couldn't load opengl\n");
        glfwTerminate();
    }

    //glClearColor(0.25f, 0.5f, 0.75f, 1.0f);
}

GLFWwindow* Window::getWindow() {
    return this->window;
}

void Window::runWindow(Program program, GLuint vaoID, int size) {

    while(!glfwWindowShouldClose(this->window)) {
    
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        program.use();
        glBindVertexArray(vaoID);
        glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(this->window);
    }
}

void Window::terminate() {
    glfwTerminate();
}