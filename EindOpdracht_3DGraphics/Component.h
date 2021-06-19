#pragma once

class GameObject;

class Component
{
protected:
	GameObject* gameObject;
public:
	Component();
	~Component();

	virtual void update(float deltaTime) {};

	inline GameObject* getGameObject() { return this->gameObject; }
	inline void setGameObject(GameObject* gameObject) { this->gameObject = gameObject; }
};
