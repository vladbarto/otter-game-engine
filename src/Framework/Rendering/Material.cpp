//
// Created by Vlad Bartolomei on 27.07.2024.
//

#include "Material.h"

#include <iostream>
#include <ostream>

Material::Material() {
    this->materialFilePath = std::string("/Users/vladbarto/Documents/PERSONAL_PROJECTS/otter-game-engine/src/Assets/untitled.mtl");

    // define texture
    glGenTextures(1, &texId); // Generate Texture ID

    parseFile();
}

//------------------------------------------

void Material::parseFile() {
    FILE* pf;

    pf = fopen(this->materialFilePath.c_str(), "r");
    char* line = nullptr;
    size_t len = 0;
    ssize_t linelen;

    while((linelen = getline(&line, &len, pf)) > 0) {
        parseLine(line);
    }
}

void Material::parseLine(std::string stream) {
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

    if("Ks " == arrayOfWords[0]) {
        const auto colour = glm::vec3(stof(arrayOfWords[1]), stof(arrayOfWords[2]), stof(arrayOfWords[3]));
        set_specular_colour(colour);
    }
    else if("Ka " == arrayOfWords[0]) {
        const auto colour = glm::vec3(stof(arrayOfWords[1]), stof(arrayOfWords[2]), stof(arrayOfWords[3]));
        set_ambient_light(colour);
    }
    else if("Ke " == arrayOfWords[0]) {
        const auto colour = glm::vec3(stof(arrayOfWords[1]), stof(arrayOfWords[2]), stof(arrayOfWords[3]));
        set_mat_emissive(colour);
    }
    else if("Kd " == arrayOfWords[0]) {
        const auto colour = glm::vec3(stof(arrayOfWords[1]), stof(arrayOfWords[2]), stof(arrayOfWords[3]));
        set_mat_diffuse(colour);
    }
    else if("Ns " == arrayOfWords[0]) {
        const float glanceFactor = stof(arrayOfWords[1]);
        set_shininess(glanceFactor);
    }
    else if("map_Kd " == arrayOfWords[0]) {
        std::string str = arrayOfWords[1];

        str.erase(std::remove(str.begin(), str.end(), '\n'), str.cend());
        set_texture_path(str);
    }

}

