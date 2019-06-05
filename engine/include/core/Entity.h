//Entity.h
#pragma once

#include <string>
#include "common/typedef.h"
#include "core/Transform.h"

namespace ME {

#define MAX_COMPONENTS_COUNT 1

	class Entity {
	public:
		explicit Entity();
		explicit Entity(std::string name);
		virtual ~Entity();
		
		virtual void update(F32 deltaTime) = 0;

		Transform* getTransform();
		void setName(std::string newName);
		std::string getName();
		B8 markDead();
		B8 isDead();
		
	protected:
		Transform transform;

		std::string name;
		B8 dead;		
	};

}