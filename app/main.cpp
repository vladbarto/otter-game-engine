#include <iostream>
#include <cstring>
#include "../src/view/utils/Window.h"
#include "../src/model/entity/Shader.h"
#include "../src/model/entity/Program.h"

int main() {

    Window window(640, 480);

    Shader vshader("../src/model/shaders/vertex.glsl", Shader::ShaderEnum::VERTEX);
    Shader fshader("../src/model/shaders/fragment.glsl", Shader::ShaderEnum::FRAGMENT);
    Program program;

    program.setVertexShader(vshader.getId());
    program.setFragmentShader(fshader.getId());
    program.attachShadersAndLinkProgram();

    float vertices[] = {
        -0.5, -0.5, 0.0, 0.0, 1.0, // Hier in 2D + Farbe (xyrgb)
        0.5, -0.5, 0.0, 0.0, 1.0,
        0.5, 0.5, 0.0, 1.0, 0.0,
        0.0, 1.0, 1.0, 0.0, 0.0,
        -0.5, 0.5, 0.0, 1.0, 0.0
    };

    int indices[] = {
        0, 1, 2,
        1, 2, 3
    };
    GLuint vaoID, vboID;

    glGenBuffers(1, &vboID); // generate ID
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

    // activate VAO
    glGenVertexArrays(1, &vaoID);
    //glBindVertexArray(vaoID);

    // describe VBO in the VAO
    glVertexAttribPointer(0, 2, GL_FLOAT, false, 5*sizeof(float), 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, false, 5*sizeof(float), (void*)12);
    glEnableVertexAttribArray(1); 

    // setup IBO //
    GLuint iboID;
    glGenBuffers(1, &iboID); // only works after glGenVertexArrays();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    

    //window.runWindow(program, vaoID, sizeof(indices)/sizeof(int));

     while(!glfwWindowShouldClose(window.getWindow())) {
    
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);

        program.use();
        glBindVertexArray(vaoID);
        glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window.getWindow());
    }

    window.terminate();
    return 0;
}