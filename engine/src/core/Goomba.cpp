//Goomba.cpp
#include "core/Goomba.h"

Goomba::Goomba()
: Entity() {
	init();
}

Goomba::Goomba(std::string name)
: Entity(name) {
	init();
}

void Goomba::init(){
	walkLeft = false;
	moveSpeed = 1.0f;
	xPos = 0.0f;
}

Goomba::~Goomba() {}

void Goomba::setMovespeed(F32 newSpeed){
	moveSpeed = newSpeed;
}

void Goomba::update(F32 deltaTime) {
	if(walkLeft){
		xPos -= deltaTime * moveSpeed;
		if(xPos <= 0.0f){
			walkLeft = false;
		}
	}
	else{
		xPos += deltaTime * moveSpeed;
		if(xPos >= 10.0f){
			walkLeft = true;
		}
	}
	transform.getPosition()->x = xPos;
}
