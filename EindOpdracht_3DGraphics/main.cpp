#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Components.h"
#include <list>
#include "GameObject.h"
#include "CollisionManager.h"
#include "DebugCamera.h"

#include <iostream>

using tigl::Vertex;

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

GLFWwindow* window;

void init();
void update();
void draw();

int main(void)
{
    if (!glfwInit())
        throw "Could not initialize glwf";
    window = glfwCreateWindow(1400, 800, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw "Could not initialize glwf";
    }
    glfwMakeContextCurrent(window);

    tigl::init();

    init();

	while (!glfwWindowShouldClose(window))
	{
		update();
		draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();


    return 0;
}

//Camera* debugCamera;
GameObject* player;
CollisionManager* collisionManager;
std::list<GameObject*> gameObjects;
double lastFrameTime = 0;

void init()
{
    glEnable(GL_DEPTH_TEST);

    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE)
            glfwSetWindowShouldClose(window, true);
    });

    //debugCamera = new DebugCamera(window);
    //debugCamera->position = glm::vec3(0, -10, 0);
    //debugCamera->rotation = glm::vec3(glm::radians(90.0f), 0, 0);

    collisionManager = new CollisionManager();

    player = new GameObject();
    player->position = glm::vec3(0, 0, 5);
    player->scale = glm::vec3(0.5f);
    player->addComponent(new CameraComponent(window));
    player->addComponent(new PlayerMoveComponent(window));
    player->addComponent(new ColliderComponent(collisionManager, glm::vec3(1, 2, 1), "player"));
    player->getComponent<ColliderComponent>()->onCollision =
        [](ColliderComponent* collider) {
        if (collider->tag == "floor") {
            player->getComponent<PlayerMoveComponent>()->onGround = true;
            player->getComponent<PlayerMoveComponent>()->yVelocity = 0;
        }
        std::cout << "Colliding with " << collider->tag << std::endl;
    };
    gameObjects.push_back(player);

    for (int i = 0; i < 6; i++)
    {
        GameObject* go = new GameObject();
        go->position = glm::vec3(-2.5f + i, 0, 0);
        go->addComponent(new CubeComponent(glm::vec3(1, 2, 1) , glm::vec4(0.2f + (0.2f * i), 0, 0, 1)));
        go->addComponent(new ColliderComponent(collisionManager, glm::vec3(1, 2, 1)));
        go->scale = glm::vec3(0.15f);
        gameObjects.push_back(go);
    }

    GameObject* floor = new GameObject();
    floor->position = glm::vec3(0, -5, 0);
    floor->addComponent(new CubeComponent(glm::vec3(5, 0.5f, 5), glm::vec4(0.5f, 0.5f, 0.5f, 1)));
    floor->addComponent(new ColliderComponent(collisionManager, glm::vec3(5, 0.5f, 5), "floor"));
    gameObjects.push_back(floor);
}


void update()
{
    double currentFrameTime = glfwGetTime();
    double deltaTime = currentFrameTime - lastFrameTime;
    lastFrameTime = currentFrameTime;

    //camera->update(window);
    collisionManager->isColliding(player->getComponent<ColliderComponent>());

    for (auto& go : gameObjects)
        go->update(deltaTime);
}

void draw()
{
    glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glm::mat4 projection = glm::perspective(glm::radians(75.0f), viewport[2] / (float)viewport[3], 0.01f, 100.0f);

    tigl::shader->setProjectionMatrix(projection);
    tigl::shader->setViewMatrix(player->getComponent<CameraComponent>()->getViewMatrix());
    tigl::shader->setModelMatrix(glm::mat4(1.0f));

    tigl::shader->enableColor(true);

    for (auto& go : gameObjects)
        go->draw();
}