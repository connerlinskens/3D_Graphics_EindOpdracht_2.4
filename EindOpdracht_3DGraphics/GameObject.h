#pragma once
#include <glm/glm.hpp>
#include <list>

class Component;
class DrawComponent;
class ColliderComponent;

class GameObject
{
private:
	std::list<Component*> components;
	std::list<GameObject*> children;

	DrawComponent* drawComponent = nullptr;
	ColliderComponent* colliderComponent = nullptr;

public:
	glm::vec3 position = glm::vec3(0);
	glm::vec3 rotation = glm::vec3(0);
	glm::vec3 scale = glm::vec3(1);

	void addComponent(Component* component);
	std::list<Component*> getComponents();
	void update(float deltaTime);
	void draw(const glm::mat4 & = glm::mat4(1));

	void addChild(GameObject* child);
	void removeChild(GameObject* child);
	std::list<GameObject*> getChildren();

	template<class T>
	T* getComponent()
	{
		for (auto c : components) {
			T* t = dynamic_cast<T*>(c);
			if (t)
				return t;
		}
		return nullptr;
	}

	template<class T>
	void removeComponent()
	{
		components.remove_if([](Component* c)
		{
			T* t = dynamic_cast<T*>(c);
			return t != nullptr;
		});
	}
};

