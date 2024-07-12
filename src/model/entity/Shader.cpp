#include "Shader.h"

enum class ShaderEnum {VERTEX, GEOMETRY, FRAGMENT};

Shader::Shader(const char* glslPath, ShaderEnum shaderEnum) {

    GLenum shaderType;
    switch(shaderEnum) {
        case ShaderEnum::VERTEX:
            shaderType = GL_VERTEX_SHADER;
            break;
        case ShaderEnum::GEOMETRY:
            shaderType = GL_GEOMETRY_SHADER;
            break;
        case ShaderEnum::FRAGMENT:
            shaderType = GL_FRAGMENT_SHADER;
            break;
        default:
            break;
    }

    this->ID  = glCreateShader(shaderType);

    // give the shader the actual text depicted in `.glsl` file
    glShaderSource(this->ID, 1, &glslPath, NULL);
    glCompileShader(this->ID);
}

void Shader::use() 
{ 
    glUseProgram(ID);
}

GLuint Shader::getId() {
    return this->ID;
}

void Shader::setBool(const std::string &name, bool value) const
{         
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
}

void Shader::setInt(const std::string &name, int value) const
{ 
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
}

void Shader::setFloat(const std::string &name, float value) const
{ 
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
} 