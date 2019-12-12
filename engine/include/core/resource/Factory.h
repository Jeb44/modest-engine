// Factory.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

#include "core/System.h"

class Factory : public System {
public:
	virtual ~Factory();
	
	virtual void Init() ;
	virtual void Update(sf::Time deltaTime);
	
	virtual IMessageHandler* GetParent() const;
	virtual void SendToChildren(const Message& msg);
	
private:
	
};