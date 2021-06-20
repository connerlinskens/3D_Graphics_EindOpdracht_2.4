#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Components.h"
#include <list>
#include "GameObject.h"
#include "CollisionManager.h"
#include "DebugCamera.h"
#include "Floor.h"
#include "MovingFloor.h"
#include "Enemy.h"

#include <iostream>

using tigl::Vertex;

#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

GLFWwindow* window;
bool running = true;
ObjModel* enemyModel;
Texture* blankTexture;
Texture* floorTexture;

void init();
void update();
void draw();
void resetGame();

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

    enemyModel = new ObjModel("resources/enemy/among_us.obj");
    blankTexture = new Texture("resources/blank_texture.jpg");
    floorTexture = new Texture("resources/floor.jpg");

    init();

	while (!glfwWindowShouldClose(window))
	{
        if (running) {
            update();
            draw();
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        else {
            resetGame();
        }
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
    player->position = glm::vec3(0, 50, 5);
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
        else if (collider->tag == "moving_floor") {
            player->getComponent<PlayerMoveComponent>()->onGround = true;
            player->getComponent<PlayerMoveComponent>()->yVelocity = 0;
            collider->getGameObject()->addChild(player);
        }
        else if (collider->tag == "enemy") {
            //running = false;
            player->position = glm::vec3(0, 0, 5);
        }
    };
    gameObjects.push_back(player);
    
    
    gameObjects.push_back(new Floor(collisionManager, glm::vec3(0, -5, 5), glm::vec3(5, 0.5f, 5), glm::vec4(1, 1, 1, 1), floorTexture, "floor", 5.0f));

    gameObjects.push_back(new MovingFloor(collisionManager, glm::vec3(-5, -5, -2), glm::vec3(1, 0.5f, 1), glm::vec4(1, 1, 1, 1), floorTexture, { glm::vec3(-5, -5, -2), glm::vec3(5, -5, -2) }));

    gameObjects.push_back(new Enemy(collisionManager, glm::vec3(0, -4.5f, 0), enemyModel, glm::vec3(0.4f, 1, 0.4f), { glm::vec3(0, -4.5f, 0), glm::vec3(-3, -4.5f, 0), glm::vec3(-3, -4.5f, 4) }, 3.0f));
}


void update()
{
    double currentFrameTime = glfwGetTime();
    double deltaTime = currentFrameTime - lastFrameTime;
    lastFrameTime = currentFrameTime;

    //camera->update(window);
    for (auto& go : gameObjects) 
        if (go->getComponent<ColliderComponent>())
            collisionManager->isColliding(go->getComponent<ColliderComponent>());
    
    //collisionManager->isColliding(player->getComponent<ColliderComponent>());

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
    tigl::shader->enableTexture(true);

    for (auto& go : gameObjects)
        go->draw();
}

void resetGame() {
    running = true;
    delete player;
    delete collisionManager;
    gameObjects.clear();
    lastFrameTime = glfwGetTime();

    init();
}