//
// Created by Vlad Bartolomei on 14.07.2024.
//
#include "ObjectLoader.h"
#include "OBJLoader.h"


Result ObjectLoader::loadObject(const std::string &objpath)
{
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> textureCoords;

    try {
        std::string command, line, word;
        std::ifstream stream(objpath, std::ios_base::in | std::ios_base::binary); // open the file with path objpath, under name `stream`
        stream.exceptions(std::ifstream::badbit);
        if(!stream.is_open())
            throw std::logic_error(".obj file not found.");

        std::vector<FaceIndices> faceIndices;

        while(std::getline(stream, line)) {
            command = getCommand(line);

            if(command == "#" || command == "s")
                continue;
            if(command == "o") {
                continue;
            }
            if(command == "v") {
                vertices.push_back(parsePosition(line2bagofwords(line)));
                continue;
            }
            if(command == "vn") {
                normals.push_back(parseNormals(line2bagofwords(line)));
                continue;
            }
            if(command == "vt") {
                textureCoords.push_back(parseTextureCoords(line2bagofwords(line)));
                continue;
            }
            if(command == "f") {
                parseFaces(line2bagofwords(line), faceIndices);
                continue;
            }
        }

        float final_verts[8 * vertices.size()];
        int final_inds[faceIndices.size()];

        int indIdx;
        for(indIdx = 0; indIdx < faceIndices.size(); indIdx++) {
            final_inds[indIdx] = faceIndices[indIdx].pos;

            final_verts[final_inds[indIdx]*8 + 0] = vertices[faceIndices[indIdx].pos].x;
            final_verts[final_inds[indIdx]*8 + 1] = vertices[faceIndices[indIdx].pos].y;
            final_verts[final_inds[indIdx]*8 + 2] = vertices[faceIndices[indIdx].pos].z;

            final_verts[final_inds[indIdx]*8 + 3] = textureCoords[faceIndices[indIdx].tex].s;
            final_verts[final_inds[indIdx]*8 + 4] = textureCoords[faceIndices[indIdx].tex].t;

            final_verts[final_inds[indIdx]*8 + 5] = normals[faceIndices[indIdx].normal].x;
            final_verts[final_inds[indIdx]*8 + 6] = normals[faceIndices[indIdx].normal].y;
            final_verts[final_inds[indIdx]*8 + 7] = normals[faceIndices[indIdx].normal].z;
        }

        Result result(8*vertices.size(), faceIndices.size());
        result.copyArrays(final_verts, final_inds);
        return result;
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error: Loading OBJ failed: " << ex.what() << "\n";
        throw ex;
    }
}

std::string ObjectLoader::getCommand(std::string stream) {
    std::string word;
    int idx;
    for(idx = 0; idx <= stream.size(); idx++){
        if(stream[idx] == ' ') { break; }
        word.push_back(stream[idx]);
    }

    return word;
}

std::vector<std::string> ObjectLoader::line2bagofwords(std::string stream) {
    std::vector<std::string> arrayOfWords;
    std::string word;
    int idx;
    for(idx = 0; idx <= stream.size(); idx++){
        word.push_back(stream[idx]);
        if(stream[idx] == ' ' || stream[idx] == 0) {
            arrayOfWords.push_back(word);
            word.clear();
        }
    }

    return arrayOfWords;
}

glm::vec3 ObjectLoader::parsePosition(std::vector<std::string> array) {
    glm::vec3 position;
    position.x = std::stof(array.at(1));
    position.y = std::stof(array.at(2));
    position.z = std::stof(array.at(3));

    return position;
}

glm::vec3 ObjectLoader::parseNormals(std::vector<std::string> array) {
    glm::vec3 normals;
    normals.x = std::stof(array.at(1));
    normals.y = std::stof(array.at(2));
    normals.z = std::stof(array.at(3));

    return normals;
}

glm::vec2 ObjectLoader::parseTextureCoords(std::vector<std::string> array) {
    glm::vec3 texture;
    texture.s = std::stof(array.at(1));
    texture.t = std::stof(array.at(2));

    return texture;
}

void ObjectLoader::parseFaces(std::vector<std::string> array,
                             std::vector<FaceIndices> &faceIndices) {
    faceIndices.push_back(parseOneFace(array.at(1)));
    faceIndices.push_back(parseOneFace(array.at(2)));
    faceIndices.push_back(parseOneFace(array.at(3)));
}

FaceIndices ObjectLoader::parseOneFace(std::string stream) {
    FaceIndices result;

    std::vector<int> cache;

    std::string delimiter = "/";
    size_t pos = 0;
    std::string token;
    while ((pos = stream.find(delimiter)) != std::string::npos) {
        token = stream.substr(0, pos);
        cache.push_back(std::stoi(token));
        stream.erase(0, pos + delimiter.length());
    }
    cache.push_back(std::stoi(stream));
    result.pos = cache.at(0) - 1;
    result.tex = cache.at(1) - 1;
    result.normal = cache.at(2) - 1;

    return result;
}

void ObjectLoader::assembleMesh(float (&final_verts)[], int (&final_inds)[],
                                std::vector<FaceIndices> faceIndices,
                                std::vector<glm::vec3> vertices,
                                std::vector<glm::vec3> normals,
                                std::vector<glm::vec2> textureCoords) {


//    int indIdx;
//    for(indIdx = 0; indIdx < faceIndices.size(); indIdx++) {
//        result.indices[indIdx] = faceIndices[indIdx].pos;
//
//        result.vertices[indIdx*8 + 0] = vertices[faceIndices[indIdx].pos].x;
//        result.vertices[indIdx*8 + 1] = vertices[faceIndices[indIdx].pos].y;
//        result.vertices[indIdx*8 + 2] = vertices[faceIndices[indIdx].pos].z;
//
//        result.vertices[indIdx*8 + 3] = vertices[faceIndices[indIdx].tex].s;
//        result.vertices[indIdx*8 + 4] = vertices[faceIndices[indIdx].tex].t;
//
//        result.vertices[indIdx*8 + 5] = vertices[faceIndices[indIdx].normal].x;
//        result.vertices[indIdx*8 + 6] = vertices[faceIndices[indIdx].normal].y;
//        result.vertices[indIdx*8 + 7] = vertices[faceIndices[indIdx].normal].z;
//    }
}

