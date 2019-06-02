//Entity.h
#pragma once

#include "core/Transform.h"
#include "core/IEntityComponent.h"

namespace ME {

#define MAX_COMPONENTS_COUNT 1

	class Entity {
	public:
		explicit Entity();
		virtual ~Entity();
		
		void update();

		Transform getTransform();

		void addComponent(IEntityComponent* component);
		void removeComponent(IEntityComponent* component);
		IEntityComponent** getComponents();
		
	private:
		Transform transform;

		IEntityComponent** components; // Make List
		int countComponents;
		
	};

}