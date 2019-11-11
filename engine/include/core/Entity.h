// Entity.h
#pragma once

#include <vector>
#include <algorithm>

#include "common/typedef.h"
#include "common/assert.h"

#include "math/Vector2.h"
#include "SFML/Graphics.hpp"
#include "core/IEntityComponent.h"

class Entity {
public:
	explicit Entity();
	virtual ~Entity();
	
	void OnInit();
	void OnStart();
	void OnUpdate();
	void OnFixedUpdate();
	void OnEnd();

	void AddComponent(IEntityComponent* component);
	bool RemoveComponent(IEntityComponent* component);	//return true, if successfull delted
	std::vector<IEntityComponent*> GetComponents();

	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocty() const;

private:
	Vector2 position;
	Vector2 scale;
	sf::Vector2f velocity;

	std::vector<IEntityComponent*> components;
	bool hasNoComponents;
};