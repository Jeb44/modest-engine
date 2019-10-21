// Entity.h
#pragma once

#include <vector>
#include <algorithm>

#include "common/typedef.h"
#include "common/assert.h"

#include "math/Vector2.h"
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

private:
	Vector2 position;
	Vector2 scale;

	std::vector<IEntityComponent*> components;
	bool hasNoComponents;
};