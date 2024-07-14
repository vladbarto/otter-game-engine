#include "Scene.h"
#include "Cube_normals.h"
#include "Transform.h"
#include "Tyre.h"
#include <AssetManager.h>
#include <stdio.h>

#include "ObjectLoader.h"

int FrameCounter = 0;

Scene::Scene(OpenGLWindow * window) :
	m_window(window)
{
	assert(window != nullptr);
}

Scene::~Scene()
{}

void Scene::Szenegraph_Tyres () {
    glm::vec4 translate_front_left = glm::vec4(-1.5f, 0.0f, +0.7f, 1.0f);
    glm::vec4 translate_front_right = glm::vec4(-1.5f, 0.0f, -0.7f, 1.0f);
    glm::vec4 translate_rear_left = glm::vec4(+1.5f, 0.0f, +0.7f, 1.0f);
    glm::vec4 translate_rear_right = glm::vec4(+1.5f, 0.0f, -0.7f, 1.0f);

    FrontAxis_L.translate(translate_front_left);
    FrontAxis_R.translate(translate_front_right);
    RearAxis_L.translate(translate_rear_left);
    RearAxis_R.translate(translate_rear_right);
}
void Scene::Szenegraph_Main_Body () {
    glm::vec4 shrink_floor = glm::vec4(3.0f, 0.2f, 1.5f, 1.0f);
    Floor.scale(shrink_floor);

    glm::vec4 scale_cockpit = glm::vec4(2.0f, 1.0f, 1.0f, 1.0f);
    glm::vec4 translate_cockpit = glm::vec4(-1.0f, 0.5f, 0.0f, 1.0f);
    Cockpit.translate(translate_cockpit);
    Cockpit.scale(scale_cockpit);

    glm::vec4 scale_chair_bottom = glm::vec4(0.5f, 0.2f, 0.5f, 1.0f);
    glm::vec4 translate_chair_bottom = glm::vec4(0.2f, 0.2f, 0.0f, 1.0f);
    Chair_bottom.translate(translate_chair_bottom);
    Chair_bottom.scale(scale_chair_bottom);

    glm::vec4 scale_chair_back = glm::vec4(0.1f, 1.5f, 0.5f, 1.0f);
    float thetaDegrees = -10.0f;
    float thetaRadians = glm::radians(thetaDegrees);
    glm::vec3 axis = glm::vec3(0.0f, 0.0f, 1.0f);
    glm::quat tilt_chair_back = glm::angleAxis(thetaRadians, axis);
    glm::vec4 translate_chair_back = glm::vec4(0.5f, 0.7f, 0.0f, 1.0f);
    Chair_back.translate(translate_chair_back);
    Chair_back.rotate(tilt_chair_back);
    Chair_back.scale(scale_chair_back);

    glm::vec4 scale_platform = glm::vec4(30.0, 0.1, 30.0, 1.0);
    glm::vec4 translate_platform = glm::vec4(0.0f, -2.0f, 0.0f, 1.0f);
    cube.translate(translate_platform);
    cube.scale(scale_platform);

}
void Scene::Szenegraph_Spoiler () {
    glm::vec4 scale_pillar = glm::vec4(0.05f, 1.5f, 0.05f, 1.0f);
    float thetaDegrees = -5.0f;
    float thetaRadians = glm::radians(thetaDegrees);
    glm::vec3 axis = glm::vec3(0.0f, 0.0f, 1.0f);
    glm::quat tilt_pillar = glm::angleAxis(thetaRadians, axis);
    glm::vec4 translate_pillar_left = glm::vec4(1.2f, 0.7f, 0.5f, 1.0f);
    glm::vec4 translate_pillar_right = glm::vec4(1.2f, 0.7f, -0.5f, 1.0f);

    Pillar_L.translate(translate_pillar_left);
    Pillar_L.rotate(tilt_pillar);
    Pillar_L.scale(scale_pillar);

    Pillar_R.translate(translate_pillar_right);
    Pillar_R.rotate(tilt_pillar);
    Pillar_R.scale(scale_pillar);

    float alphaDegrees = +15.0f;
    float alphaRadians = glm::radians(alphaDegrees);
    glm::vec3 axis_2 = glm::vec3(0.0f, 0.0f, 1.0f);
    glm::quat tilt_spoiler = glm::angleAxis(alphaRadians, axis_2);
    glm::vec4 scale_spoiler = glm::vec4(0.7f, 0.1f, 1.5f, 1.0f);
    glm::vec4 translate_spoiler = glm::vec4(1.2f, 1.4f, 0.0f, 1.0f);

    Spoiler.translate(translate_spoiler);
    Spoiler.rotate(tilt_spoiler);
    Spoiler.scale(scale_spoiler);
}

void load_obj(const char* filename,
              std::vector<glm::vec4> &vertices,
              std::vector<glm::vec3> &normals,
              std::vector<GLushort> &elements)
{
    // https://en.wikibooks.org/wiki/OpenGL_Programming/Modern_OpenGL_Tutorial_Load_OBJ
    std::ifstream in(filename, std::ios::in);
    if (!in)
    {
        std::cerr << "Cannot open " << filename << std::endl; exit(1);
    }

    std::string line;
    while (getline(in, line))
    {
        if (line.substr(0,2) == "v ")
        {
            std::istringstream s(line.substr(2));
            glm::vec4 v; s >> v.x; s >> v.y; s >> v.z; v.w = 1.0f;
            vertices.push_back(v);
        }
        else if (line.substr(0,2) == "f ")
        {
            std::istringstream s(line.substr(2));
            GLushort a,b,c;
            s >> a; s >> b; s >> c;
            a--; b--; c--;
            elements.push_back(a); elements.push_back(b); elements.push_back(c);
        }
        /* anything else is ignored */
    }

    normals.resize(vertices.size(), glm::vec3(0.0, 0.0, 0.0));
    for (int i = 0; i < elements.size(); i+=3)
    {
        GLushort ia = elements[i];
        GLushort ib = elements[i+1];
        GLushort ic = elements[i+2];
        glm::vec3 normal = glm::normalize(glm::cross(
                glm::vec3(vertices[ib]) - glm::vec3(vertices[ia]),
                glm::vec3(vertices[ic]) - glm::vec3(vertices[ia])));
        normals[ia] = normals[ib] = normals[ic] = normal;
    }
}

bool Scene::init()
{
	try
	{
		//Load shader
		m_assets.addShaderProgram("shader", AssetManager::createShaderProgram("assets/shaders/vertex.glsl", "assets/shaders/fragment.glsl"));
		m_shader = m_assets.getShaderProgram("shader");
        m_shader->use();

	    // load object
	    std::string objpath = "/Users/vladbarto/Documents/PERSONAL_PROJECTS/otter-game-engine/src/Game/Blender_objects/cone.obj";
//        objResult = OBJLoader::loadOBJ(objpath);
        ObjectLoader objectLoader;
	    attempt = objectLoader.loadObject(objpath);
	    attempt.displayArrays();

	    std::vector<glm::vec4> vertices;
        std::vector<glm::vec3> normals;
        std::vector<GLushort> elements;

	    load_obj(objpath.c_str(), vertices, normals, elements);

        // generate and activate VBO and upload data
	    glGenBuffers(1, &vboID);
	    glBindBuffer(GL_ARRAY_BUFFER, vboID);
	    glBufferData(GL_ARRAY_BUFFER,
	        attempt.getVerticesSize(),// * sizeof(Vertex),
	        attempt.getVertices(),
	        GL_STATIC_DRAW);

	    // generate and activate VAO
	    glGenVertexArrays(1, &vaoID);
	    glBindVertexArray(vaoID);

	    int stride = 8*sizeof(int);
	    // describe VBO in the VAO
	    glVertexAttribPointer(0, 3, GL_FLOAT, false, stride, 0);
	    glEnableVertexAttribArray(0);
	    glVertexAttribPointer(1, 2, GL_FLOAT, false, stride, (void*)12);
	    glEnableVertexAttribArray(1);
	    glVertexAttribPointer(2, 3, GL_FLOAT, false, stride, (void*)20);
	    glEnableVertexAttribArray(2);

	    // setup IBO
	    GLuint iboID;
	    glGenBuffers(1, &iboID);
	    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
	    glBufferData(GL_ELEMENT_ARRAY_BUFFER, attempt.getIndicesSize(),
	        attempt.getIndices(), GL_STATIC_DRAW);

        lichtQuelle = glm::vec3(0.0, 0.0, 0.0);
        //lichtFarbe = glm::vec3(1.0, 94.0/255., 5.0/255.0);
        lichtFarbe = glm::vec3(1.0, 1.0, 1.0);
        lichtIntensitat = 0.003f; // doens't affect
        ambientLight = glm::vec3(255, 94, 5); // Ambiental Light Example
        specularFarbe = glm::vec3(1.0f, 1.0f, 1.0f);
        shininess = 30.0f;
        matDiffuse = glm::vec3(0.0, 0.37, 0.63);
        matEmissive = glm::vec3(0.0, 1.0, 0.0);

        // Aufgabe 1.4
        // glEnable(GL_CULL_FACE);
        // glFrontFace(GL_CCW);
        // glCullFace(GL_BACK);

        // Aufgabe 2.3.3: Deep Test activation for OpenGL
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        glClearDepth(1.0);
        static Transform xyz;
        std::cout << "Scene initialization done\n";
        return true;
	}
	catch (std::exception& ex)
	{
	    throw std::logic_error("Scene initialization failed:\n" + std::string(ex.what()) + "\n");
	}
}

//Global:
float displacement_factor = 0;
int launchTrigger = 0;

void Scene::render(float dt)
{
    /**
     * Aufgabe 2.3.2: Hintergrund löschen
     */
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // activate VAO
    m_shader->setUniform("model", suzanne.getMatrix(), false);
    glBindVertexArray(vaoID);
    glDrawElements(GL_TRIANGLES, attempt.getIndicesSize(), GL_UNSIGNED_INT, 0);

    /**
     * Deal with color animation
     */
    static float animationTime = 0.0f;
    animationTime += dt;
    m_shader->setUniform("animation", animationTime/10);

    glBindVertexArray(0); // good programmers should use reset
    /**
     * Remark: the code only works with convex forms. Any concave form and it will break
     */
}

// Global:
MousePosition mousePosition;
float cameraTargetX = 0.0f;
float cameraTargetY = 0.0f;
float cameraTargetZ = 0.0f;
float fov = glm::radians(60.0f); // Field of view in degrees, convert to radians

void Scene::update(float dt)
{
    int width = 16;
    int height = 9;
    float aspectRatio = width / height;  // Adjust the aspect ratio based on your window size
    float nearClip = 0.1f;
    float farClip = 100.0f;


    // Tastatureingabe
    if(m_window->getInput().getKeyState(Key::W) == KeyState::Pressed) {
        cameraPosition.y += 0.1f;
        cameraTargetY += 0.1f;
    }
    if(m_window->getInput().getKeyState(Key::S) == KeyState::Pressed) {
        cameraPosition.y -= 0.1f;
        cameraTargetY -= 0.1f;
    }
    if(m_window->getInput().getKeyState(Key::A) == KeyState::Pressed) {
        cameraPosition.x += 0.1f;
        cameraTargetX += 0.1f;
    }
    if(m_window->getInput().getKeyState(Key::D) == KeyState::Pressed) {
        cameraPosition.x -= 0.1f;
        cameraTargetX -= 0.1f;
    }
    if(m_window->getInput().getKeyState(Key::E) == KeyState::Pressed) {
        cameraPosition.z += 0.1f;
        cameraTargetZ += 0.1f;
    }
    if(m_window->getInput().getKeyState(Key::Q) == KeyState::Pressed) {
        cameraPosition.z -= 0.1f;
        cameraTargetZ -= 0.1f;
    }

    if(m_window->getInput().getKeyState(Key::L) == KeyState::Pressed) {
        launchTrigger = (launchTrigger == 0)? 1:0;
    }

    glm::vec3 upVector = glm::vec3(0.0f, 1.0f, 0.0f);
    //cameraPosition = glm::vec3(cameraPositionX, cameraPositionY, cameraPositionZ);
    glm::vec3 cameraTarget(cameraTargetX, cameraTargetY, cameraTargetZ);

    /** View and Projection Matrices loading into Vertex Shader */
    glm::mat4 view = glm::lookAt(cameraPosition, cameraTarget, upVector);
    m_shader->setUniform("view", view, false);

    glm::mat4 projection = glm::perspective(fov, aspectRatio, nearClip, farClip);
    m_shader->setUniform("projection", projection, false);

    /**
     * <- and -> move Light source on x-Axis
     * up and down move Light source on y-Axis
     * , and . move Light source on z-Axis
     */
    if(m_window->getInput().getKeyState(Key::Up) == KeyState::Pressed) {
        lichtQuelle.y += 0.1f;
    }
    if(m_window->getInput().getKeyState(Key::Down) == KeyState::Pressed) {
        lichtQuelle.y -= 0.1f;
    }
    if(m_window->getInput().getKeyState(Key::Right) == KeyState::Pressed) {
        lichtQuelle.x -= 0.1f;
    }
    if(m_window->getInput().getKeyState(Key::Left) == KeyState::Pressed) {
        lichtQuelle.x += 0.1f;
    }
    if(m_window->getInput().getKeyState(Key::Period) == KeyState::Pressed) {
        lichtQuelle.z += 0.1f;
    }
    if(m_window->getInput().getKeyState(Key::Comma) == KeyState::Pressed) {
        lichtQuelle.z -= 0.1f;
    }

    /**
     * Place for updating other factors like lichtQuelle, lichtFarbe and all of the below
     */

    // După această actualizare, puteți transmite acești parametri către shaderul OpenGL, similar cu modul în care este transmisă matricea de vedere și proiecție.
    m_shader->setUniform("lightPos", lichtQuelle);
    m_shader->setUniform("lightColor", lichtFarbe);
    m_shader->setUniform("lightIntensity", lichtIntensitat);
    m_shader->setUniform("lightColorAmbient", ambientLight);
    m_shader->setUniform("matSpecular", specularFarbe);
    m_shader->setUniform("matShininess", shininess);
    //m_shader->setUniform("matDiffuse", matDiffuse);
    //m_shader->setUniform("matEmissive", matEmissive);

    if(m_window->getInput().getKeyState(Key::O) == KeyState::Pressed) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    if(m_window->getInput().getKeyState(Key::P) == KeyState::Pressed) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
}

OpenGLWindow * Scene::getWindow()
{
	return m_window;
}

void Scene::onKey(Key key, Action action, Modifier modifier)
{

}

float dot_product_two_vectors(glm::vec3 A, glm::vec3 B) {
    return (A.x * B.x) +
            (A.y * B.y) +
             (A.z * B.z);
}
float length_of_a_vector(glm::vec3 V) {
    return sqrt(V.x * V.x +
                    V.y * V.y +
                        V.z * V.z);
}
float arccos_two_vectors (glm::vec3 a, glm::vec3 b) {
    //Returns in Degrees
    return acos((dot_product_two_vectors(a, b)) / (length_of_a_vector(a) * length_of_a_vector(b))) * 3.14 * 10000 / 180;
}
float det_z_with_respect_to_xy(glm::vec2 center, float radius, float xy) {
    // I am using here the equation of Circle
    return center.y + sqrt(radius*radius - (xy-center.x) * (xy-center.x));
}
void Scene::onMouseMove(MousePosition mouse)
{
    int prescaler = 1;

    // Check if the right mouse button is pressed (you can modify this based on your setup)
    if (m_window->getInput().getKeyState(Key::LeftShift) == KeyState::Pressed) {
        // Calculate the change in mouse position
        float dx = -static_cast<float>(mouse.X - mousePosition.X) / prescaler;
        float dy = static_cast<float>(mouse.Y - mousePosition.Y) / prescaler;

        // Create rotation matrices
        glm::mat4 rotateX = glm::rotate(glm::mat4(1.0f), glm::radians(dy), glm::vec3(1.0f, 0.0f, 0.0f));
        glm::mat4 rotateY = glm::rotate(glm::mat4(1.0f), glm::radians(dx), glm::vec3(0.0f, 1.0f, 0.0f));

        // Apply rotations to camera position
        glm::vec4 rotatedPosition = rotateX * rotateY * glm::vec4(cameraPosition, 1.0f);
        cameraPosition = glm::vec3(rotatedPosition);

        // Update the camera target accordingly (assuming it's a look-at camera)
        glm::vec3 upVector = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::mat4 view = glm::lookAt(cameraPosition, cameraTarget, upVector);
        m_shader->setUniform("view", view, false);
    }

    // Update the mouse position for the next frame
    mousePosition = mouse;
}

void Scene::onMouseButton(MouseButton button, Action action, Modifier modifier)
{

}

void Scene::onMouseScroll(double xscroll, double yscroll)
{
    fov -= glm::radians((float)yscroll);
}

void Scene::onFrameBufferResize(int width, int height)
{

}
void Scene::shutdown()
{

}