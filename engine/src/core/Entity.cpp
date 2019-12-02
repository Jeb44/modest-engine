//Entity.cpp
#include "core/Entity.h"

Entity::Entity(){
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