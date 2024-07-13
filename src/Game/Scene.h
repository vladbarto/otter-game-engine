#pragma once

#include "OpenGLWindow.h"
#include <ShaderProgram.h>
#include <memory>
#include <AssetManager.h>
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
    ShaderProgram* m_shader;
    GLuint vaoID_tyre, vaoID_cube, vboID_tyre, vboID_cube;

    glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, -10.0f);

    Transform FrontAxis_L;
    Transform FrontAxis_R;
    Transform RearAxis_L;
    Transform RearAxis_R;

    Transform Floor;
    Transform Cockpit;
    Transform Chair_bottom;
    Transform Chair_back;
    Transform Pillar_L;
    Transform Pillar_R;
    Transform Spoiler;

    Transform cube;

    glm::vec3 lichtQuelle;
    glm::vec3 lichtFarbe;
    float lichtIntensitat;
    glm::vec3 ambientLight;
    glm::vec3 specularFarbe;  // 1.Materialparameter
    float shininess;  // 2.Materialparameter; Glanzfaktor k
    glm::vec3 matDiffuse;
    glm::vec3 matEmissive;

    void Szenegraph_Tyres();

    void Szenegraph_Main_Body();

    void Szenegraph_Spoiler();

    void render_shapes_on_screen();
};

