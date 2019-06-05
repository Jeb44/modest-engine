//Goomba.h
#pragma once

#include "Entity.h"

class Goomba : public ME::Entity {
public:
	explicit Goomba();
	explicit Goomba(std::string name);
	virtual ~Goomba();
	
	void init();

	void setMovespeed(F32 newSpeed);

	void update(F32 deltaTime) override;
	
private:
	B8 walkLeft;
	F32 xPos;
	F32 moveSpeed;
};