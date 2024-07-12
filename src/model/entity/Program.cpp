#include "Program.h"

Program::Program() {   
    this->program = glCreateProgram();
   
}

void Program::setVertexShader(const GLuint vshader) {
    this->vertexShader= vshader;
}

void Program::setFragmentShader(const GLuint fshader) {
    this->fragmentShader = fshader;
}

void Program::attachShadersAndLinkProgram() {
    glAttachShader(this->program, this->vertexShader);
    glAttachShader(this->program, this->fragmentShader);

    glLinkProgram(this->program);

    GLint program_linked;
    glGetProgramiv(program, GL_LINK_STATUS, &program_linked);
    if (program_linked != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetProgramInfoLog(program, 1024, &log_length, message);
        // Write the error to a log
    }
}

void Program::use() {
    glUseProgram(this->program);
}