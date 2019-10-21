// TestComponent.h
#pragma once

#include "common/typedef.h"
#include "common/assert.h"

#include "core/IEntityComponent.h"
#include "common/Locator.h"
#include "common/console/Console.h"

class TestComponent : public IEntityComponent {
public:
	explicit TestComponent();
	virtual ~TestComponent();
	
	virtual void OnInit(Entity& go);
	virtual void OnStart(Entity& go);
	virtual void OnUpdate(Entity& go);
	virtual void OnFixedUpdate(Entity& go);
	virtual void OnEnd(Entity& go);
private:
	
};