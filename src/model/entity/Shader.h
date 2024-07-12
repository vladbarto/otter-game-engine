#ifndef SHADER_H
#define SHADER_H

#include "../../../app/glad.h" // include glad to get all the required OpenGL headers
  
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
  

class Shader
{
    private:
        // the program ID
        GLuint ID;

    public:
        enum class ShaderEnum {VERTEX, GEOMETRY, FRAGMENT};
        // constructor reads and builds the shader
        Shader(const char* glslPath, ShaderEnum shader);

        // use/activate the shader
        void use();

        GLuint getId();
        // utility uniform functions
        void setBool(const std::string &name, bool value) const;  
        void setInt(const std::string &name, int value) const;   
        void setFloat(const std::string &name, float value) const;
};
#endif