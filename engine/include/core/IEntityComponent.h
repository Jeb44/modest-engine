// IEntityComponent.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

class Entity;

class IEntityComponent {
public:
	explicit IEntityComponent();
	virtual ~IEntityComponent();
	
	virtual void OnInit(Entity& go) = 0;
	virtual void OnStart(Entity& go) = 0;
	virtual void OnUpdate(Entity& go) = 0;
	virtual void OnFixedUpdate(Entity& go) = 0;
	virtual void OnEnd(Entity& go) = 0;	
};