//
// Created by Vlad Bartolomei on 27.07.2024.
//

#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>

#include "Transform.h"

class Material {

private:
    glm::vec3 ambientLight{};
    glm::vec3 specularColour{};  // 1st Material Parameter
    float shininess{};  // 2nd Material Parameter; Glance Factor k
    glm::vec3 matDiffuse{};
    glm::vec3 matEmissive{};

    std::string texturePath;
    std::string materialFilePath;
    GLuint texId;

    void parseFile();
    void parseLine(std::string line);

public:
    Material();

    glm::vec3 get_ambient_light() const {
        return ambientLight;
    }

    glm::vec3 get_specular_colour() const {
        return specularColour;
    }

    float get_shininess() const {
        return shininess;
    }

    glm::vec3 get_mat_diffuse() const {
        return matDiffuse;
    }

    glm::vec3 get_mat_emissive() const {
        return matEmissive;
    }

    void set_ambient_light(const glm::vec3 &ambient_light) {
        ambientLight = ambient_light;
    }

    void set_specular_colour(const glm::vec3 &specular_colour) {
        specularColour = specular_colour;
    }

    void set_shininess(float shininess) {
        this->shininess = shininess;
    }

    void set_mat_diffuse(const glm::vec3 &mat_diffuse) {
        matDiffuse = mat_diffuse;
    }

    void set_mat_emissive(const glm::vec3 &mat_emissive) {
        matEmissive = mat_emissive;
    }

    void set_texture_path(const std::string &path) {
        texturePath = path;
    }

    void set_tex_id(GLuint tex_id) {
        texId = tex_id;
    }

    std::string get_texture_path() {
        return texturePath;
    }

    GLuint get_tex_id() const {
        return texId;
    }
};

#endif //MATERIAL_H
