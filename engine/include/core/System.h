// System.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

#include <SFML/System/Time.hpp>

#include "core/message/IMessageHandler.h"

class System : public IMessageHandler{
public:
	virtual void Init() = 0;
	virtual void Update(sf::Time deltaTime) = 0;
	
	virtual IMessageHandler* GetParent() const = 0;
	virtual void SendToChildren(const Message& msg) = 0;
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