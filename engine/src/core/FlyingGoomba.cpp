//FlyingGoomba.cpp
#include "core/FlyingGoomba.h"

FlyingGoomba::FlyingGoomba()
: Entity() {
	init();
}

FlyingGoomba::FlyingGoomba(std::string name)
: Entity(name) {
	init();
}

FlyingGoomba::~FlyingGoomba() {}

void FlyingGoomba::init(){
	flyUp = false;
	yPos = 0.0f;
}


void FlyingGoomba::update(F32 deltaTime) {
	if(flyUp){
		yPos += deltaTime;
		if(yPos >= 10.0f){
			flyUp = false;
		}
	}
	else{
		yPos -= deltaTime;
		if(yPos <= 0.0f){
			flyUp = true;
		}
	}
	transform.getPosition()->y = yPos;
}
