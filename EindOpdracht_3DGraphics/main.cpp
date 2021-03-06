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
bool completed = false;
ObjModel* enemyModel;
Texture* blankTexture;
Texture* floorTexture;
Texture* completeTexture;

void init();
void update();
void draw();
void resetGame();

int main(void)
{
    if (!glfwInit())
        throw "Could not initialize glwf";
    window = glfwCreateWindow(1400, 800, "Among Them", NULL, NULL);
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
    completeTexture = new Texture("resources/complete_screen.png");

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
        if (key == GLFW_KEY_SPACE && completed) {
            completed = false;
            player->position = glm::vec3(0, -2, 5);
            player->getComponent<PlayerMoveComponent>()->disabled = false;
            player->getComponent<CameraComponent>()->disabled = false;
        }
    });

    collisionManager = new CollisionManager();

    player = new GameObject();
    player->position = glm::vec3(0, 50, 5);
    //player->position = glm::vec3(-20, 40, -35);
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
            player->position = glm::vec3(0, 0, 5);
        }
        else if (collider->tag == "finish") {
            player->getComponent<PlayerMoveComponent>()->disabled = true;
            player->getComponent<CameraComponent>()->disabled = true;
            completed = true;
        }
    };
    gameObjects.push_back(player);
    
    // Section one
    gameObjects.push_back(new Floor(collisionManager, glm::vec3(0, -5, 5), glm::vec3(5, 0.5f, 5), glm::vec4(1, 1, 1, 1), floorTexture, "floor", 5.0f, 5.0f));
    gameObjects.push_back(new Enemy(collisionManager, glm::vec3(3, -4.5f, 1), enemyModel, glm::vec3(0.5f, 1, 0.5f), { glm::vec3(3, -4.5f, 1), glm::vec3(-3, -4.5f, 1) }, 4.0f));

    gameObjects.push_back(new Floor(collisionManager, glm::vec3(0, -5, -6), glm::vec3(1, 0.5f, 5), glm::vec4(1, 1, 1, 1), floorTexture, "floor", 5.0f));
    gameObjects.push_back(new MovingFloor(collisionManager, glm::vec3(-2, -5, -10), glm::vec3(1, 0.5f, 1), glm::vec4(1, 1, 1, 1), floorTexture, { glm::vec3(-2, -5, -10), glm::vec3(-12, -5, -10) }, 3.0f));
    
    // Section two
    gameObjects.push_back(new Floor(collisionManager, glm::vec3(-14, -5, -19), glm::vec3(1, 0.5f, 10), glm::vec4(1, 1, 1, 1), floorTexture, "floor", 10.0f));
    gameObjects.push_back(new Floor(collisionManager, glm::vec3(-12, -5, -23), glm::vec3(1, 0.5f, 1), glm::vec4(1, 1, 1, 1), floorTexture, "floor"));
    gameObjects.push_back(new Enemy(collisionManager, glm::vec3(-14, -4.5f, -28), enemyModel, glm::vec3(0.5f, 1, 0.5f), { glm::vec3(-14, -4.5f, -28), glm::vec3(-14, -4.5f, -18) }, 2.0f));

    gameObjects.push_back(new Floor(collisionManager, glm::vec3(-15, -5.5f, -28), glm::vec3(1, 0.5f, 1), glm::vec4(1, 1, 1, 1), floorTexture, "floor"));
    gameObjects.push_back(new Floor(collisionManager, glm::vec3(-16, -6.0f, -28), glm::vec3(1, 0.5f, 1), glm::vec4(1, 1, 1, 1), floorTexture, "floor"));
    gameObjects.push_back(new Floor(collisionManager, glm::vec3(-17, -6.5f, -28), glm::vec3(1, 0.5f, 1), glm::vec4(1, 1, 1, 1), floorTexture, "floor"));
    gameObjects.push_back(new Floor(collisionManager, glm::vec3(-18, -7.0f, -28), glm::vec3(1, 0.5f, 1), glm::vec4(1, 1, 1, 1), floorTexture, "floor"));
    gameObjects.push_back(new Floor(collisionManager, glm::vec3(-20, -7.0f, -31), glm::vec3(1, 0.5f, 4), glm::vec4(1, 1, 1, 1), floorTexture, "floor", 4.0f));

    // Section three
    gameObjects.push_back(new Floor(collisionManager, glm::vec3(-20, -7.0f, -39), glm::vec3(4, 0.5f, 4), glm::vec4(1, 1, 1, 1), floorTexture, "floor", 4.0f, 4.0f));
    gameObjects.push_back(new Enemy(collisionManager, glm::vec3(-17, -6.5f, -36), enemyModel, glm::vec3(0.5f, 1, 0.5f), { glm::vec3(-17, -6.5f, -36), glm::vec3(-23, -6.5f, -36), glm::vec3(-23, -6.5f, -42), glm::vec3(-17, -6.5f, -42) }, 5.5f, true));
    gameObjects.push_back(new Enemy(collisionManager, glm::vec3(-23, -6.5f, -36), enemyModel, glm::vec3(0.5f, 1, 0.5f), { glm::vec3(-23, -6.5f, -36), glm::vec3(-23, -6.5f, -42), glm::vec3(-17, -6.5f, -42), glm::vec3(-17, -6.5f, -36) }, 5.5f, true));
    gameObjects.push_back(new Enemy(collisionManager, glm::vec3(-23, -6.5f, -42), enemyModel, glm::vec3(0.5f, 1, 0.5f), { glm::vec3(-23, -6.5f, -42), glm::vec3(-17, -6.5f, -42), glm::vec3(-17, -6.5f, -36), glm::vec3(-23, -6.5f, -36) }, 5.5f, true));

    gameObjects.push_back(new Floor(collisionManager, glm::vec3(-20, -7.0f, -45), glm::vec3(1, 0.5f, 4), glm::vec4(1, 1, 1, 1), floorTexture, "floor", 4.0f));

    GameObject* finish = new GameObject();
    finish->position = glm::vec3(-20, -7.0f, -48);
    finish->addComponent(new ColliderComponent(collisionManager, glm::vec3(2), "finish"));
    gameObjects.push_back(finish);
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
    
    for (auto& go : gameObjects)
        go->update(deltaTime);
}

void draw()
{
    //glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
    glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glm::mat4 projection = glm::perspective(glm::radians(75.0f), viewport[2] / (float)viewport[3], 0.01f, 100.0f);

    tigl::shader->setProjectionMatrix(projection);
    tigl::shader->setViewMatrix(player->getComponent<CameraComponent>()->getViewMatrix());
    tigl::shader->setModelMatrix(glm::mat4(1.0f));

    tigl::shader->enableColor(true);
    tigl::shader->enableTexture(true);
    tigl::shader->enableFog(true);
    tigl::shader->enableLighting(true);

    tigl::shader->setFogColor(glm::vec3(0.7f, 0.7f, 0.7f));
    tigl::shader->setFogExp(0.2f);

    tigl::shader->setLightCount(1);
    tigl::shader->setLightDirectional(0, true);
    tigl::shader->setLightAmbient(0, glm::vec3(0.7f, 0.7f, 0.7f));
    tigl::shader->setLightDiffuse(0, glm::vec3(0.7f, 0.7f, 0.7f));
    tigl::shader->setLightSpecular(0, glm::vec3(0.1f, 0.1f, 0.1f));
    tigl::shader->setShinyness(32.0f);

    for (auto& go : gameObjects)
        go->draw();

    //if (completed) {
    //    tigl::shader->setModelMatrix(player->getComponent<CameraComponent>()->getModelMatrix());
    //    completeTexture->bind();
    //    tigl::begin(GL_QUADS);
    //    tigl::addVertex(Vertex::PT(glm::vec3(0, 0, 0), glm::vec2(0, 0)));
    //    tigl::addVertex(Vertex::PT(glm::vec3(1, 0, 0), glm::vec2(1, 0)));
    //    tigl::addVertex(Vertex::PT(glm::vec3(1, 1, 0), glm::vec2(1, 1)));
    //    tigl::addVertex(Vertex::PT(glm::vec3(0, 1, 0), glm::vec2(0, 1)));
    //    tigl::end();
    //    tigl::shader->setModelMatrix(glm::mat4(1.0f));
    //}
}

void resetGame() {
    delete player;
    delete collisionManager;
    gameObjects.clear();
    lastFrameTime = glfwGetTime();

    init();
}