#ifndef PROGRAM_H
#define PROGRAM_H

#include "../../../app/glad.h" // include glad to get all the required OpenGL headers

class Program {
    public:
        GLuint program;
        GLuint vertexShader, fragmentShader;

        Program();

        void setVertexShader(const GLuint vshader);
        void setFragmentShader(const GLuint fshader);
        void attachShadersAndLinkProgram();
        void use();
};

#endif