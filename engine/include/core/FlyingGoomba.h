//Goomba.h
#pragma once

#include "Entity.h"

class FlyingGoomba : public ME::Entity {
public:
	explicit FlyingGoomba();
	explicit FlyingGoomba(std::string name);
	virtual ~FlyingGoomba();
	
	void init();

	void update(F32 deltaTime) override;
	
private:
	B8 flyUp;
	F32 yPos;
};