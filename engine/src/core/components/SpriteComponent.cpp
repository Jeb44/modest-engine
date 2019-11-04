//SpriteComponent.cpp
#include "core/components/SpriteComponent.h"

SpriteComponent::SpriteComponent() {}
SpriteComponent::~SpriteComponent() {}

void SpriteComponent::OnInit(Entity& go){

}

void SpriteComponent::OnStart(Entity& go){

}

void SpriteComponent::OnUpdate(Entity& go){

}

void SpriteComponent::OnFixedUpdate(Entity& go){

}

void SpriteComponent::OnEnd(Entity& go){

}

void SpriteComponent::SetTextureFilePath(std::string filePath){
	ASSERT(filePath != "");
	strTexturePath = filePath;
}