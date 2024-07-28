//
// Created by Vlad Bartolomei on 14.07.2024.
//

#ifndef OBJECTLOADER_H
#define OBJECTLOADER_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <CommonTypes.h>
#include <stdlib.h>

class Result;

class ObjectLoader {
public:
    ObjectLoader() {}
    ~ObjectLoader() {}

    Result loadObject(const std::string &objpath);
    static std::vector<std::string> lineToTokenArray(std::string stream);
    static std::string getCommand(std::string stream);

    glm::vec3 parsePosition(std::vector<std::string> array);
    glm::vec3 parseNormals(std::vector<std::string> array);
    glm::vec2 parseTextureCoords(std::vector<std::string> array);
    void parseFaces(std::vector<std::string> array, std::vector<FaceIndices> &faceIndices);
    FaceIndices parseOneFace(std::string stream);


    void assembleMesh(Result &result, std::vector<FaceIndices> faceIndices, std::vector<glm::vec3> vertices,
                      std::vector<glm::vec3> normals, std::vector<glm::vec2> textureCoords);

    void
    assembleMesh(float *final_verts, int *final_inds, std::vector<FaceIndices> faceIndices,
                 std::vector<glm::vec3> vertices,
                 std::vector<glm::vec3> normals, std::vector<glm::vec2> textureCoords);

    void
    assembleMesh(float &final_verts, int &final_inds, std::vector<FaceIndices> faceIndices,
                 std::vector<glm::vec3> vertices,
                 std::vector<glm::vec3> normals, std::vector<glm::vec2> textureCoords);

    void assembleMesh(float (&final_verts)[], int (&final_inds)[], std::vector<FaceIndices> faceIndices,
                      std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals,
                      std::vector<glm::vec2> textureCoords);
};

//------------------------------ Class to hold float vertices[] and int indices[] ----------------------------------//

class Result {
private:
    float *vertices;
    int *indices;
    int verticesSize;
    int indicesSize;

public:
    // Default constructor to create an empty Result instance
    Result() : vertices(nullptr), indices(nullptr), verticesSize(0), indicesSize(0) {}


    // Constructor
    Result(int verticesSize, int indicesSize) {
        this->verticesSize = verticesSize;
        this->indicesSize = indicesSize;

        // Allocate memory for vertices array
        vertices = (float*)malloc(verticesSize * sizeof(float));

        // Allocate memory for indices array
        indices = (int*)malloc(indicesSize * sizeof(int));

        // Initialize arrays if needed
        initializeArrays();
    }

    // Destructor
//    ~Result() {
//        // Free allocated memory
//        free(vertices);
//        free(indices);
//    }

    // Function to initialize arrays
    void initializeArrays() {
        for (int i = 0; i < verticesSize; ++i) {
            vertices[i] = 0;
        }

        for (int i = 0; i < indicesSize; ++i) {
            indices[i] = 0;
        }
    }

    // Function to copy arrays from local arrays to instance arrays
    void copyArrays(const float* localVertices, const int* localIndices) {
        for (int i = 0; i < verticesSize; ++i) {
            vertices[i] = localVertices[i];
        }

        for (int i = 0; i < indicesSize; ++i) {
            indices[i] = localIndices[i];
        }
    }

    // Getter function for vertices array
    float* getVertices() const {
        return vertices;
    }

    // Getter function for indices array
    int* getIndices() const {
        return indices;
    }

    // Getter function for vertices array size
    int getVerticesSize() const {
        return verticesSize;
    }

    // Getter function for indices array size
    int getIndicesSize() const {
        return indicesSize;
    }

    // Function to display the content of arrays (example, you can modify as needed)
    void displayArrays() {
        std::cout << "Vertices: ";
        int i;
        for (i = 0; i < verticesSize - 1; ++i) {
            std::cout << vertices[i] << ", ";
        }
        std::cout << vertices[i];
        std::cout << "\nIndices: ";
        for (i = 0; i < indicesSize - 1; ++i) {
            std::cout << indices[i] << ", ";
        }
        std::cout << indices[i];
        std::cout << std::endl;
    }
};

#endif //OBJECTLOADER_H
