//
// Created by Vlad Bartolomei on 28.07.2024.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Material.h"
#include "Transform.h"


class GameObject {
private:
    Transform transform;
    Material material;
    GLuint vao;
    GLuint vbo;
    GLuint ibo;
    std::string object_path;
public:
    explicit GameObject(const std::string &object_path)
        : object_path(object_path) {
    }

    std::string get_object_path() const {
        return object_path;
    }

    Material get_material() {
        return material;
    }

    void set_transform(const Transform &transform) {
        this->transform = transform;
    }

    void set_material(const Material &material) {
        this->material = material;
    }

    void set_vao(GLuint vao) {
        this->vao = vao;
    }

    void set_vbo(GLuint vbo) {
        this->vbo = vbo;
    }

    void set_ibo(GLuint ibo) {
        this->ibo = ibo;
    }

    void set_object_path(const std::string &object_path) {
        this->object_path = object_path;
    }

    Transform get_transform() const {
        return transform;
    }

    GLuint get_vao() const {
        return vao;
    }

    GLuint get_vbo() const {
        return vbo;
    }

    GLuint get_ibo() const {
        return ibo;
    }
};

#endif //GAMEOBJECT_H
