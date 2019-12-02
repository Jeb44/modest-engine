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
	void OnEnd();

	void AddComponent(IEntityComponent* component);
	bool HasComponent(IEntityComponent* component);
	bool RemoveComponent(IEntityComponent* component);	//return true, if successfully delted
	std::vector<IEntityComponent*> GetComponents();

private:
	std::vector<IEntityComponent*> components;
	bool hasNoComponents;

	// unsigned m_handle; //index location
	// unsigned m_components[eNumComponents]; //array of components handles
};