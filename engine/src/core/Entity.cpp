//Entity.cpp
#include "core/Entity.h"

Entity::Entity()
: position(0.0f, 0.0f), scale(1.0f, 1.0f){
	hasNoComponents = true;
}

Entity::~Entity() {}

void Entity::OnInit(){
	
}

void Entity::OnStart(){
	
}

void Entity::OnUpdate(){
	for(size_t i = components.size() - 1, iLen = 0; i <= iLen; i--){
			components[i]->OnUpdate(*this);
		}
}

void Entity::OnFixedUpdate(){
	
}

void Entity::OnEnd(){
	
}

void Entity::AddComponent(IEntityComponent* component){
	components.push_back(component);
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

	return isFound;
}

std::vector<IEntityComponent*> Entity::GetComponents(){
	return components;
}