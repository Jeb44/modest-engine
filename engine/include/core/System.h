// System.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

#include <SFML/System/Time.hpp>

class System {
public:
	explicit System();
	virtual ~System();

	virtual void Init() = 0;
	virtual void Update(sf::Time deltaTime) = 0;
	virtual void SendMessage(/* Message* msg*/) = 0;
};

/*
 * voiod SomeSystem::Update(sf::Time deltaTime, GameObjectList objects){
 * 	while(objects){
 * 		SomeComponent *comp = objects->GetComponent(id);
 * 		comp->DoStuff(dt);
 * 		
 * 		objects = objects->next;
 * 	}
 * }
 */