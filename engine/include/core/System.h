// System.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

#include <SFML/System/Time.hpp>

#include "core/message/IMessageHandler.h"

class System : public IMessageHandler{
public:
	virtual void Init();
	virtual void Update(sf::Time deltaTime);
	
	virtual IMessageHandler* GetParent() const;
	virtual void SendToChildren(const Message& msg);
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