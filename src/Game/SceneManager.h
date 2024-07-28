//
// Created by Vlad Bartolomei on 27.07.2024.
//

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include "Scene.h"


class SceneManager {
public:
    std::vector<Scene> scenes;

    SceneManager();
    ~SceneManager();

};



#endif //SCENEMANAGER_H
