//Entity.cpp
#include "core/Entity.h"

namespace ME {

	Entity::Entity() {
		components = new IEntityComponent*[MAX_COMPONENTS_COUNT];
		countComponents = 0;
	}
	Entity::~Entity() {}

	void Entity::update(){
		for(size_t i = 0, iLen = countComponents; i < iLen; i++){
			components[i]->update();
		}
	}

	Transform Entity::getTransform(){
		return transform;
	}

	void Entity::addComponent(IEntityComponent* component){
		components[countComponents] = component;
		countComponents++;
	}

	void Entity::removeComponent(IEntityComponent* component){
		//search for component
		//countComponents--
	}

	IEntityComponent** Entity::getComponents(){
		return components;
	}

}