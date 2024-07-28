#pragma once

#include "OpenGLWindow.h"
#include <ShaderProgram.h>
#include <AssetManager.h>

#include "GameObject.h"
#include "ObjectLoader.h"
#include "Transform.h"

class Scene
{
public:
	Scene(OpenGLWindow* window);
	~Scene();

	bool init();
	void shutdown();
	void render(float dt);

	void update(float dt);
	OpenGLWindow* getWindow();

	void onKey(Key key, Action action, Modifier modifier);
	void onMouseMove(MousePosition mouseposition);
	void onMouseButton(MouseButton button, Action action, Modifier modifier);
	void onMouseScroll(double xscroll, double yscroll);
	void onFrameBufferResize(int width, int height);

private:
	OpenGLWindow* m_window;
	AssetManager m_assets;
    ShaderProgram* m_shader{};

	// camera
    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	Transform camera;
	glm::vec3 upVector = glm::vec3(0.0f, 1.0f, 0.0f);

	// scene illumination
	glm::vec3 lightSource;
	glm::vec3 lightColour;
	float lightIntensity;

	// loaded object
	Result attempt;

	// all game objects from a scene
	std::vector<GameObject> gameObject;
};

