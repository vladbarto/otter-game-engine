#include "Scene.h"
#include "Transform.h"
#include <AssetManager.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "ObjectLoader.h"
#include <iostream>

#include "Material.h"
int FrameCounter = 0;

Scene::Scene(OpenGLWindow * window) :
	m_window(window)
{
	assert(window != nullptr);
}

Scene::~Scene()
{}

bool Scene::init()
{
	try
	{
		//Load shader
		m_assets.addShaderProgram("shader", AssetManager::createShaderProgram("assets/shaders/vertex.glsl", "assets/shaders/fragment.glsl"));
		m_shader = m_assets.getShaderProgram("shader");
        m_shader->use();

		std::string str = ("/Users/vladbarto/Documents/PERSONAL_PROJECTS/otter-game-engine/src/Assets/untitled.obj");
		GameObject game_object = GameObject(str);
		gameObject.push_back(game_object);

		ObjectLoader object_loader;
		if(!gameObject.empty()) {
			for(int i = 0; i < gameObject.size(); i++) {

				// load object
				attempt = object_loader.loadObject(gameObject[i].get_object_path());



			    glActiveTexture(GL_TEXTURE0);
			    glBindTexture(GL_TEXTURE_2D, gameObject[i].get_material().get_tex_id()); // Bind or Activate Texture
			    // Image loading in memory, as well as getting:
			    //      - width
			    //      - height
			    //      - and channels
			    int width, height, channels;
			    unsigned char* image = stbi_load( gameObject[i].get_material().get_texture_path().c_str(),
	    			&width, &height, &channels, STBI_rgb_alpha);

				if (!image) {
			        throw std::logic_error("Failed to load texture");
			    }

			    // Define Texture and Send Data
			    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
			    stbi_image_free(image);

			    // Set parameters:
			    // Wrapping
			    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			    // Filtering
			    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glUniform1i(glGetUniformLocation(m_shader->prog, "tex0"), 0);

				// generate and activate VBO and upload data
				GLuint vbo, vao, ibo;
				glGenBuffers(1, &vbo);
				gameObject[i].set_vbo(vbo);
				glBindBuffer(GL_ARRAY_BUFFER, gameObject[i].get_vbo());
				glBufferData(GL_ARRAY_BUFFER, attempt.getVerticesSize()*4,attempt.getVertices(), GL_STATIC_DRAW);

				// generate and activate VAO
				glGenVertexArrays(1, &vao);
				gameObject[i].set_vao(vao);
				glBindVertexArray(gameObject[i].get_vao());

				constexpr int stride = 8*sizeof(int);

				// describe VBO in the VAO
				glVertexAttribPointer(0, 3, GL_FLOAT, false, stride, reinterpret_cast<void *>(0));
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(1, 2, GL_FLOAT, false, stride, reinterpret_cast<void *>(12));
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(2, 3, GL_FLOAT, false, stride, reinterpret_cast<void *>(20));
				glEnableVertexAttribArray(2);

				// setup IBO
				glGenBuffers(1, &ibo);
				gameObject[i].set_ibo(ibo);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gameObject[i].get_ibo());
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, attempt.getIndicesSize()*4, attempt.getIndices(), GL_STATIC_DRAW);
			}
		}

		lightSource = glm::vec3(0.0, 0.0, 0.0);
		lightColour = glm::vec3(1.0, 1.0, 1.0);
		lightIntensity = 0.003f;

        // Aufgabe 1.4
        // glEnable(GL_CULL_FACE);
        // glFrontFace(GL_CCW);
        // glCullFace(GL_BACK);
		camera.setPosition(glm::vec3(0.0f,0.0f,-10.0f));
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
	if(!gameObject.empty()) {
		for(int i = 0; i < gameObject.size(); i++) {
			// activate VAO
		    m_shader->setUniform("model", gameObject[i].get_transform().getMatrix(), false);
		    glBindVertexArray(gameObject[i].get_vao());
		    glDrawElements(GL_TRIANGLES, attempt.getIndicesSize(), GL_UNSIGNED_INT, nullptr);
		}
	}
    

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
float fov = glm::radians(60.0f); // Field of view in degrees, convert to radians

void Scene::update(float dt)
{
    int width = 18;
    int height = 9;
    float aspectRatio = width / height;  // Adjust the aspect ratio based on your window size
    float nearClip = 0.1f;
    float farClip = 100.0f;

    if(m_window->getInput().getKeyState(Key::E) == KeyState::Pressed) {
    	float thetaDegrees = -5.0f;
    	float thetaRadians = glm::radians(thetaDegrees);
    	glm::vec3 axis = glm::vec3(0.0f, 1.0f, 0.0f);
    	glm::quat rotate_quaternion = glm::angleAxis(thetaRadians, axis);
    	camera.rotateAroundPoint(cameraTarget, rotate_quaternion);
    }
	if(m_window->getInput().getKeyState(Key::R) == KeyState::Pressed) {
		float thetaDegrees = 5.0f;
		float thetaRadians = glm::radians(thetaDegrees);
		glm::vec3 axis = glm::vec3(0.0f, 1.0f, 0.0f);
		glm::quat rotate_quaternion = glm::angleAxis(thetaRadians, axis);
		camera.rotateAroundPoint(cameraTarget, rotate_quaternion);
	}
	if(m_window->getInput().getKeyState(Key::F) == KeyState::Pressed) {
		float thetaDegrees = -5.0f;
		float thetaRadians = glm::radians(thetaDegrees);
		glm::vec3 axis = glm::vec3(1.0f, 0.0f, 0.0f);
		glm::quat rotate_quaternion = glm::angleAxis(thetaRadians, axis);
		camera.rotateAroundPoint(cameraTarget, rotate_quaternion);
	}
	if(m_window->getInput().getKeyState(Key::G) == KeyState::Pressed) {
		float thetaDegrees = 5.0f;
		float thetaRadians = glm::radians(thetaDegrees);
		glm::vec3 axis = glm::vec3(1.0f, 0.0f, 0.0f);
		glm::quat rotate_quaternion = glm::angleAxis(thetaRadians, axis);
		camera.rotateAroundPoint(cameraTarget, rotate_quaternion);
	}

	if(m_window->getInput().getKeyState(Key::W) == KeyState::Pressed) {
		cameraTarget.y += 0.1f;
	}
	if(m_window->getInput().getKeyState(Key::S) == KeyState::Pressed) {
		cameraTarget.y -= 0.1f;
	}
	if(m_window->getInput().getKeyState(Key::A) == KeyState::Pressed) {
		cameraTarget.x += 0.1f;
	}
	if(m_window->getInput().getKeyState(Key::D) == KeyState::Pressed) {
		cameraTarget.x -= 0.1f;
	}

    /** View and Projection Matrices loading into Vertex Shader */
    glm::mat4 view = glm::lookAt(camera.getPosition(), cameraTarget, upVector);
    m_shader->setUniform("view", view, false);

    glm::mat4 projection = glm::perspective(fov, aspectRatio, nearClip, farClip);
    m_shader->setUniform("projection", projection, false);

    /**
     * <- and -> move Light source on x-Axis
     * up and down move Light source on y-Axis
     * , and . move Light source on z-Axis
     */
    if(m_window->getInput().getKeyState(Key::Up) == KeyState::Pressed) {
        lightSource.y += 0.1f;
    }
    if(m_window->getInput().getKeyState(Key::Down) == KeyState::Pressed) {
        lightSource.y -= 0.1f;
    }
    if(m_window->getInput().getKeyState(Key::Right) == KeyState::Pressed) {
        lightSource.x -= 0.1f;
    }
    if(m_window->getInput().getKeyState(Key::Left) == KeyState::Pressed) {
        lightSource.x += 0.1f;
    }
    if(m_window->getInput().getKeyState(Key::Period) == KeyState::Pressed) {
        lightSource.z += 0.1f;
    }
    if(m_window->getInput().getKeyState(Key::Comma) == KeyState::Pressed) {
        lightSource.z -= 0.1f;
    }

	if(!gameObject.empty()) {
		for(int i = 0; i < gameObject.size(); i++) {
			m_shader->setUniform("lightColorAmbient", gameObject[i].get_material().get_ambient_light());
		    m_shader->setUniform("matSpecular", gameObject[i].get_material().get_specular_colour());
		    m_shader->setUniform("matShininess", gameObject[i].get_material().get_shininess());
		    m_shader->setUniform("matDiffuse", gameObject[i].get_material().get_mat_diffuse());
		    m_shader->setUniform("matEmissive", gameObject[i].get_material().get_mat_emissive());
		}
	}
    m_shader->setUniform("lightPos", lightSource);
    m_shader->setUniform("lightColor", lightColour);
    m_shader->setUniform("lightIntensity", lightIntensity);


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

void Scene::onKey(Key key, Action action, Modifier modifier) {}

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

void Scene::onMouseMove(MousePosition mouse) {}

void Scene::onMouseButton(MouseButton button, Action action, Modifier modifier) {}

void Scene::onMouseScroll(double xscroll, double yscroll)
{
    fov -= glm::radians((float)yscroll);
}

void Scene::onFrameBufferResize(int width, int height) {}
void Scene::shutdown() {}