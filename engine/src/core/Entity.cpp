//Entity.cpp
#include "core/Entity.h"

namespace ME {

	Entity::Entity() :
	dead(false){
		name = std::string("empty");
	}
	Entity::Entity(std::string name) :
	dead(false),
	name(name){}
	Entity::~Entity() {}

	// void Entity::update(F32 deltaTime){}

	Transform* Entity::getTransform(){
		return &transform;
	}
	
	void Entity::setName(std::string newName){
		name = newName;
	}
	
	std::string Entity::getName(){
		return name;
	}

	B8 Entity::isDead(){
		return dead;
	}
}