//
// Created by Vlad Bartolomei on 27.07.2024.
//

#include "SceneManager.h"

SceneManager::SceneManager() {
    try {
        for(auto & scene : scenes) {
            scene.init();
        }
    }
    catch (int e)
    {
        std::cout << "An exception occurred. Exception Nr. " << e << '\n';
    }
}

SceneManager::~SceneManager() = default;

