//Entity.cpp
#include "core/Entity.h"

Entity::Entity()
: position(0.0f, 0.0f), scale(1.0f, 1.0f){
	hasNoComponents = true;
}

Entity::~Entity() {}

void Entity::OnInit(){
	for(size_t i = components.size() - 1, iLen = 0; i <= iLen; i--){
		components[i]->OnInit(*this);
	}
}

void Entity::OnStart(){
	for(size_t i = components.size() - 1, iLen = 0; i <= iLen; i--){
		components[i]->OnStart(*this);
	}
}

void Entity::OnUpdate(){
	for(size_t i = components.size() - 1, iLen = 0; i <= iLen; i--){
		components[i]->OnUpdate(*this);
	}
}

void Entity::OnFixedUpdate(){
	for(size_t i = components.size() - 1, iLen = 0; i <= iLen; i--){
		components[i]->OnFixedUpdate(*this);
	}
}

void Entity::OnEnd(){
	for(size_t i = components.size() - 1, iLen = 0; i <= iLen; i--){
		components[i]->OnEnd(*this);
	}
}

void Entity::AddComponent(IEntityComponent* component){
	components.push_back(component);
	hasNoComponents = false;
}


bool Entity::RemoveComponent(IEntityComponent* component){
	const auto removedComponent = std::find(
		components.begin(), 
		components.end(), 
		component
	);

	const bool isFound = removedComponent != components.end();
	if(isFound){
		components.erase(removedComponent);
	}

	hasNoComponents = components.size() == 0? true : false;

	return isFound;
}

std::vector<IEntityComponent*> Entity::GetComponents(){
	return components;
}

void Entity::setVelocity(sf::Vector2f velocity){
	this->velocity = velocity;
}

void Entity::setVelocity(float vx, float vy){
	velocity.x = vx;
	velocity.y = vy;
}

sf::Vector2f Entity::getVelocty() const{
	return velocity;
}